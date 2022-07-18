#include "xdmapcie.h"
#include <cassert>
#include <iostream>
#include <string>
#include <system_error>
#include <vector>

#include <assert.h>
#include <stdlib.h>
#include <stdio.h>
#include <strsafe.h>

#include <windows.h>
#include <initguid.h>
#include <winioctl.h>
#include <QDebug>
#include <cwchar>
#include <setupapi.h>
#include "strsafe.h"

//#pragma comment(lib,"setupapi.lib")
//#include "global.h"

int g_Devices = 0; //设备的总数量
unsigned int g_Vid = 0;
unsigned int g_Pid = 0;



LPCWSTR g_FileNode[CXDmaPcie_AllFileNodeNumber] = {

    XDMA_FILE_USER		,
    XDMA_FILE_CONTROL	,
    XDMA_FILE_BYPASS	,

    XDMA_FILE_EVENT_0	,
    XDMA_FILE_EVENT_1	,
    XDMA_FILE_EVENT_2	,
    XDMA_FILE_EVENT_3	,
    XDMA_FILE_EVENT_4	,
    XDMA_FILE_EVENT_5	,
    XDMA_FILE_EVENT_6	,
    XDMA_FILE_EVENT_7	,
    XDMA_FILE_EVENT_8	,
    XDMA_FILE_EVENT_9	,
    XDMA_FILE_EVENT_10	,
    XDMA_FILE_EVENT_11	,
    XDMA_FILE_EVENT_12	,
    XDMA_FILE_EVENT_13	,
    XDMA_FILE_EVENT_14	,
    XDMA_FILE_EVENT_15	,

    XDMA_FILE_H2C_0		,
    XDMA_FILE_H2C_1		,
    XDMA_FILE_H2C_2		,
    XDMA_FILE_H2C_3		,

    XDMA_FILE_C2H_0		,
    XDMA_FILE_C2H_1		,
    XDMA_FILE_C2H_2		,
    XDMA_FILE_C2H_3
};

XDMaPcie::XDMaPcie(QObject *parent) : QObject(parent)
{
    DrvGuid = GUID_Device;
    for(int i=0;i<CXDmaPcie_FileNodeBarNumber;i++)
        hDeviceBar[i] = INVALID_HANDLE_VALUE;
    for(int i=0;i<CXDmaPcie_FileNodeEventNumber;i++)
        hDeviceEvent[i] = INVALID_HANDLE_VALUE;
    for(int i=0;i<CXDmaPcie_FileNodeH2CNumber;i++)
        hDeviceH2C[i] = INVALID_HANDLE_VALUE;
    for(int i=0;i<CXDmaPcie_FileNodeC2HNumber;i++)
        hDeviceC2H[i] = INVALID_HANDLE_VALUE;
}

int DeviceCount(unsigned int Vid,unsigned int Pid)
{
    GUID DrvGuid = GUID_Device;
    g_Vid = Vid;g_Pid = Pid;
    SP_DEVICE_INTERFACE_DATA  devInterfaceData;
    //Open a handle to the plug and play dev node.
    //SetupDiGetClassDevs() returns a device information set that contains info on all
    // installed devices of a specified class which are present.
    HDEVINFO hwDeviceInfo = SetupDiGetClassDevs (static_cast<LPGUID>(&DrvGuid),nullptr,nullptr,DIGCF_PRESENT|DIGCF_INTERFACEDEVICE);
    g_Devices = 0;
    if (hwDeviceInfo != INVALID_HANDLE_VALUE)
    {
        SP_DEVINFO_DATA psp_device_info;
        DWORD  PropertyRegDataType;
        BYTE  PropertyBuffer[1000] = {0};
        DWORD  PropertyBufferSize = 1000;
        DWORD  RequiredSize=0;

        memset(&psp_device_info, 0,sizeof(SP_DEVINFO_DATA)); // 初始化psp_device_info，当然这只是范例，
        psp_device_info.cbSize = sizeof(SP_DEVINFO_DATA);
        //SetupDiEnumDeviceInterfaces() returns information about device interfaces
        // exposed by one or more devices. Each call returns information about one interface.
        //The routine can be called repeatedly to get information about several interfaces
        // exposed by one or more devices.
        devInterfaceData.cbSize = sizeof(devInterfaceData);
        char Str[1000],PIDStr[32],VIDStr[32];
        for (DWORD i = 0; SetupDiEnumDeviceInfo ( hwDeviceInfo, i, &psp_device_info ); i++ )
        {
            //用来获取设备的详细信息，如设备管理器下属性里面的设备详细信息，设备描述符、设备的硬件ID等
            bool bRetVal = SetupDiGetDeviceRegistryProperty(hwDeviceInfo,&psp_device_info,SPDRP_HARDWAREID,&PropertyRegDataType,PropertyBuffer,PropertyBufferSize,&RequiredSize);
            for(long j=0;j<(PropertyBufferSize/2);j++)
            {
                Str[j]=PropertyBuffer[2*j];
            }
            memcpy(PIDStr,Str+8,4);
            memcpy(VIDStr,Str+17,4);
            PIDStr[4]=0x0;VIDStr[4]=0x0;
            unsigned int DevVid,DevPid ;
            QString des = QString::fromLocal8Bit(PIDStr);
            QString des1 = QString::fromLocal8Bit(VIDStr);
            DevVid=des.toUInt(nullptr,16);
            DevPid=des1.toUInt(nullptr,16);

            if (bRetVal)
            {
                if((DevVid==g_Vid)&&(DevPid==g_Pid))
                {
                    qDebug() << "InsMod";
                    g_Devices++;
                }else{
                    qDebug() <<"Vid,Pid Dismatch,Not InsMod";
                }
            }
            else
            {
                qDebug() << "Not InsMod";
            }

        }
        SetupDiDestroyDeviceInfoList(hwDeviceInfo);
    }
    return g_Devices;
}

bool XDMaPcie::CreateHandle(UCHAR dev)
{
    int i=0;
    int Vid_Pid_Match = 0;
    if (g_Devices <= 0)
        return false;
    if (dev > (g_Devices - 1))
        return false; //dev = Devices-1;

    SP_DEVINFO_DATA devInfoData;
    SP_DEVICE_INTERFACE_DATA  devInterfaceData;
    PSP_INTERFACE_DEVICE_DETAIL_DATA functionClassDeviceData;
    SP_INTERFACE_DEVICE_DETAIL_DATA tmpInterfaceDeviceDetailData;

    SP_DEVINFO_DATA psp_device_info;
    DWORD  PropertyRegDataType;
    BYTE  PropertyBuffer[1000] = {0};
    DWORD  PropertyBufferSize = 1000;
    DWORD  RequiredSize=0;

    memset(&psp_device_info, 0,sizeof(SP_DEVINFO_DATA)); // 初始化psp_device_info，当然这只是范例，
    psp_device_info.cbSize = sizeof(SP_DEVINFO_DATA);

    ULONG requiredLength = 0;
    int deviceNumber     = 0;
    int deviceIndex      = 0;

    HANDLE hFile;

    //Open a handle to the plug and play dev node.
    //SetupDiGetClassDevs() returns a device information set that contains info on all
    // installed devices of a specified class which are present.
    HDEVINFO hwDeviceInfo = SetupDiGetClassDevs (static_cast<LPGUID>(&DrvGuid),nullptr,nullptr,
        DIGCF_PRESENT|DIGCF_INTERFACEDEVICE);

    if (hwDeviceInfo != INVALID_HANDLE_VALUE)
    {
        char Str1[1000],PIDStr1[32],VIDStr1[32];
        for (i = 0; SetupDiEnumDeviceInfo ( hwDeviceInfo,static_cast<DWORD>(i), &psp_device_info ); i++ )
        {
            //用来获取设备的详细信息，如设备管理器下属性里面的设备详细信息，设备描述符、设备的硬件ID等
            bool bRetVal = SetupDiGetDeviceRegistryProperty(hwDeviceInfo,&psp_device_info,SPDRP_HARDWAREID,&PropertyRegDataType,PropertyBuffer,PropertyBufferSize,&RequiredSize);
            for(long j=0;j<PropertyBufferSize/2;j++)
            {
                Str1[j]=PropertyBuffer[2*j];
            }
            memcpy(PIDStr1,Str1+8,4);
            memcpy(VIDStr1,Str1+17,4);
            PIDStr1[4]=0x0;VIDStr1[4]=0x0;
            unsigned int DevVid,DevPid ;
            QString des = QString::fromLocal8Bit(PIDStr1);
            QString des1 = QString::fromLocal8Bit(VIDStr1);
            DevVid=des.toUInt(nullptr,16);
            DevPid=des1.toUInt(nullptr,16);

            if (bRetVal)
            {
                if((DevVid==g_Vid)&&(DevPid==g_Pid))
                {
                    qDebug() <<"InsMod";
                    if(deviceNumber >= dev)
                    {
                        deviceIndex   = i;
                        Vid_Pid_Match = 1;
                        break;
                    }
                    deviceNumber++;
                }else
                {
                    qDebug() << "Vid,Pid Dismatch,Not InsMod";
                }
            }else
            {
                qDebug() << "Not InsMod";
            }

        }

        if(Vid_Pid_Match ==  0)
            return false;
        //SetupDiEnumDeviceInterfaces() returns information about device interfaces
        // exposed by one or more devices. Each call returns information about one interface.
        //The routine can be called repeatedly to get information about several interfaces
        // exposed by one or more devices.

        devInterfaceData.cbSize = sizeof(devInterfaceData);

        if (SetupDiEnumDeviceInterfaces ( hwDeviceInfo,nullptr,static_cast<LPGUID>(&DrvGuid),static_cast<DWORD>(deviceIndex), &devInterfaceData))
        {
            //Allocate a function class device data structure to receive the goods about this
            // particular device.
            SetupDiGetInterfaceDeviceDetail ( hwDeviceInfo, &devInterfaceData, nullptr, 0,
                &requiredLength, nullptr);

            ULONG predictedLength = requiredLength;

            functionClassDeviceData = (PSP_INTERFACE_DEVICE_DETAIL_DATA) malloc (predictedLength);
            functionClassDeviceData->cbSize =  sizeof (SP_INTERFACE_DEVICE_DETAIL_DATA);
            devInfoData.cbSize = sizeof(devInfoData);
            //Retrieve the information from Plug and Play
            if (SetupDiGetInterfaceDeviceDetail (hwDeviceInfo,
                &devInterfaceData,
                functionClassDeviceData,
                predictedLength,
                &requiredLength,
                &devInfoData))
            {
                // NOTE : x64 packing issue ,requiredLength return 5byte size of the (SP_INTERFACE_DEVICE_DETAIL_DATA) and functionClassDeviceData needed sizeof functionClassDeviceData 8byte
                unsigned long long pathLen = requiredLength - (sizeof (tmpInterfaceDeviceDetailData.cbSize)+sizeof (tmpInterfaceDeviceDetailData.DevicePath));
                //int pathLen = requiredLength - functionClassDeviceData->cbSize;
                for( i=0;i<CXDmaPcie_AllFileNodeNumber;i++)
                {
                    memset(DevPath,0,sizeof(DevPath));
                    memcpy (DevPath, functionClassDeviceData->DevicePath, pathLen); 
                    //wcscat(DevPath,(LPCWSTR)g_FileNode[i]);
                    StringCbCat(DevPath,sizeof (DevPath),g_FileNode[i]);
                    //memcpy(DevPath+sizeof(DevPath),g_FileNode[i],sizeof(g_FileNode[i]));
                    hFile= CreateFile (DevPath,
                    GENERIC_WRITE | GENERIC_READ,
                    FILE_SHARE_WRITE | FILE_SHARE_READ,
                    nullptr,
                    OPEN_EXISTING,
                    FILE_ATTRIBUTE_NORMAL,
                    nullptr);

                    if(i<CXDmaPcie_FileNodeBarNumber)
                        hDeviceBar[i] = hFile;
                    else if(i<(CXDmaPcie_FileNodeBarNumber+CXDmaPcie_FileNodeEventNumber))
                        hDeviceEvent[i-CXDmaPcie_FileNodeBarNumber] = hFile;
                    else if(i<(CXDmaPcie_FileNodeBarNumber+CXDmaPcie_FileNodeEventNumber+CXDmaPcie_FileNodeH2CNumber))
                        hDeviceH2C[i-CXDmaPcie_FileNodeBarNumber-CXDmaPcie_FileNodeEventNumber] = hFile;
                    else
                        hDeviceC2H[i-CXDmaPcie_FileNodeBarNumber-CXDmaPcie_FileNodeEventNumber-CXDmaPcie_FileNodeH2CNumber] = hFile;
                }

                free(functionClassDeviceData);
                SetupDiDestroyDeviceInfoList(hwDeviceInfo);

                if (hDeviceBar[1] == INVALID_HANDLE_VALUE)
                {
                    return false;
                }
                return true;
            }
        }

        SetupDiDestroyDeviceInfoList(hwDeviceInfo);
    }
    // Got here by failing at some point
    hDeviceBar[1] = INVALID_HANDLE_VALUE;
    DevNum = 0;
    return false;
}

bool XDMaPcie::Open(UCHAR dev)
{
    // If this Device object already has the driver open, close it.
    if (hDeviceBar[1] != INVALID_HANDLE_VALUE)
    {
        return true;
    }
    if (CreateHandle(dev)) {
        DevNum = dev;
        return true;
    }
    hDeviceBar[1] = INVALID_HANDLE_VALUE;
    DevNum = 0;
    return false;
}

void XDMaPcie::Close(void)
{
    int i=0;
    for(i=0;i<CXDmaPcie_FileNodeBarNumber;i++)
    {
        if ( hDeviceBar[i] != INVALID_HANDLE_VALUE )
        {
            if (! CloseHandle(hDeviceBar[i]))
            {
                qDebug() << "Failed to close handle to driver.";
                hDeviceBar[i] = INVALID_HANDLE_VALUE;
            }
        }
    }
    for(i=0;i<CXDmaPcie_FileNodeEventNumber;i++)
    {
        if ( hDeviceEvent[i] != INVALID_HANDLE_VALUE )
        {
            if (! CloseHandle(hDeviceEvent[i]))
            {
                qDebug() << "Failed to close handle to driver.";
                hDeviceEvent[i] = INVALID_HANDLE_VALUE;
            }
        }
    }
    for(i=0;i<CXDmaPcie_FileNodeH2CNumber;i++)
    {
        if ( hDeviceH2C[i] != INVALID_HANDLE_VALUE )
        {
            if (! CloseHandle(hDeviceH2C[i]))
            {
                qDebug() << "Failed to close handle to driver.";
                hDeviceH2C[i] = INVALID_HANDLE_VALUE;
            }
        }
    }
    for(i=0;i<CXDmaPcie_FileNodeC2HNumber;i++)
    {
        if ( hDeviceC2H[i] != INVALID_HANDLE_VALUE )
        {
            if (! CloseHandle(hDeviceC2H[i]))
            {
                qDebug() << "Failed to close handle to driver.";
                hDeviceC2H[i] = INVALID_HANDLE_VALUE;
            }
        }
    }
}

int XDMaPcie::SetBarData(unsigned int BarSel,long Offset,unsigned int Value)
{
    DWORD num_bytes_read;

    if(BarSel >= CXDmaPcie_FileNodeBarNumber)
        return CXDmaPcie_hDevice_Invild;

    if(hDeviceBar[BarSel] == INVALID_HANDLE_VALUE)
        return CXDmaPcie_hDevice_Invild;

    if (INVALID_SET_FILE_POINTER == SetFilePointer(hDeviceBar[BarSel], Offset, nullptr, FILE_BEGIN))
    {
        return -1;
    }
    if (!WriteFile(hDeviceBar[BarSel], &Value, 4,static_cast<LPDWORD>(&num_bytes_read), nullptr))
    {
        return -1;
    }
    return CXDmaPcie_Success;
}

int XDMaPcie::GetBarData(unsigned int BarSel,long Offset,unsigned int *Value)
{
    DWORD num_bytes_read;

    if(BarSel >= CXDmaPcie_FileNodeBarNumber)
        return CXDmaPcie_hDevice_Invild;


    if(hDeviceBar[BarSel] == INVALID_HANDLE_VALUE)
        return CXDmaPcie_hDevice_Invild;
    if(!Value)
        return CXDmaPcie_Pointer_Invild;
    if (INVALID_SET_FILE_POINTER == SetFilePointer(hDeviceBar[BarSel], Offset, nullptr, FILE_BEGIN))
    {
        return -1;
    }
    if (!ReadFile(hDeviceBar[BarSel], Value, 4,static_cast<LPDWORD>(&num_bytes_read), nullptr))
    {
        return -1;
    }
    return CXDmaPcie_Success;
}

int XDMaPcie::H2CDMASeeK(unsigned int H2CSel,long OffsetLow,long OffsetHigh,CXDmaPcieFileSeek seek)
{
    if(H2CSel >= CXDmaPcie_FileNodeH2CNumber)
        return CXDmaPcie_hDevice_Invild;


    if(hDeviceH2C[H2CSel] == INVALID_HANDLE_VALUE)
        return CXDmaPcie_hDevice_Invild;

    if (INVALID_SET_FILE_POINTER == SetFilePointer(hDeviceH2C[H2CSel], OffsetLow, &OffsetHigh, seek))
    {
        return CXDmaPcie_FileOpetare_Failed;
    }
    return CXDmaPcie_Success;
}

int XDMaPcie::C2HMASeeK(unsigned int C2HSel,long OffsetLow,long OffsetHigh,CXDmaPcieFileSeek seek)
{
    if(C2HSel >= CXDmaPcie_FileNodeC2HNumber)
        return CXDmaPcie_hDevice_Invild;


    if(hDeviceC2H[C2HSel] == INVALID_HANDLE_VALUE)
        return CXDmaPcie_hDevice_Invild;

    if (INVALID_SET_FILE_POINTER == SetFilePointer(hDeviceC2H[C2HSel], OffsetLow, &OffsetHigh, seek))
    {
        return CXDmaPcie_FileOpetare_Failed;
    }
    return CXDmaPcie_Success;
}

int XDMaPcie::H2CDMAData (unsigned int H2CSel,unsigned char *Data,unsigned int Len,unsigned int *LenWritten,LPOVERLAPPED lpOverlapped)
{
    if(H2CSel >= CXDmaPcie_FileNodeH2CNumber)
        return CXDmaPcie_hDevice_Invild;

    if(hDeviceH2C[H2CSel] == INVALID_HANDLE_VALUE)
        return CXDmaPcie_hDevice_Invild;
    //从文件的设定处写下数据，每次写的位置不变，
    //如果要更换地址，需要重新设定指针位置
    if (!WriteFile(hDeviceH2C[H2CSel],Data, Len, reinterpret_cast<DWORD*>(LenWritten), lpOverlapped))
    {
        return CXDmaPcie_FileOpetare_Failed;
    }
    return CXDmaPcie_Success;
}

int XDMaPcie::C2HDMAData (unsigned int C2HSel,unsigned char *Data,unsigned int Len,unsigned int *LenRead,LPOVERLAPPED lpOverlapped)
{
    if(C2HSel >= CXDmaPcie_FileNodeH2CNumber)
        return CXDmaPcie_hDevice_Invild;

    if(hDeviceC2H[C2HSel] == INVALID_HANDLE_VALUE)
        return CXDmaPcie_hDevice_Invild;
    //从文件的设定处读取数据，每次读取的位置不变，
    //如果要更换地址，需要重新设定指针位置
    if (!ReadFile(hDeviceC2H[C2HSel],Data, Len, reinterpret_cast<DWORD*>(LenRead), lpOverlapped))
    {
        return CXDmaPcie_FileOpetare_Failed;
    }
    return CXDmaPcie_Success;
}

