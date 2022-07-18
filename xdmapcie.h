#ifndef XDMAPCIE_H
#define XDMAPCIE_H

#include <QObject>
#include <xdma_public.h>

static const GUID GUID_Device = {0x74c7e4a9, 0x6d5d, 0x4a70, {0xbc, 0x0d, 0x20, 0x69, 0x1d, 0xff, 0x9e, 0x9d}};

#define CXDmaPcie_FileNodeBarNumber		3
#define CXDmaPcie_FileNodeEventNumber	16
#define CXDmaPcie_FileNodeH2CNumber		4
#define CXDmaPcie_FileNodeC2HNumber		4
#define CXDmaPcie_AllFileNodeNumber		(CXDmaPcie_FileNodeBarNumber+CXDmaPcie_FileNodeEventNumber+CXDmaPcie_FileNodeH2CNumber+CXDmaPcie_FileNodeC2HNumber)

#define CXDmaPcie_Invilid_Handle INVALID_HANDLE_VALUE

typedef enum _CXDmaPcieErrCode{
    CXDmaPcie_Success = 0,  // incremental
    CXDmaPcie_NoDevice_Found,
    CXDmaPcie_hDevice_Invild,
    CXDmaPcie_Pointer_Invild,
    CXDmaPcie_FileOpetare_Failed
} CXDmaPcieErrCode;

typedef enum _CXDmaPcieFileSeek{
    CXDmaPcie_FILE_BEGIN = 0,  // incremental
    CXDmaPcie_FILE_CURRENT,
    CXDmaPcie_FILE_END,
} CXDmaPcieFileSeek;

extern int DeviceCount(unsigned int Vid,unsigned int Pid);
extern int g_Devices;
extern unsigned int g_Vid;
extern unsigned int g_Pid;
extern LPCWSTR g_FileNode[CXDmaPcie_AllFileNodeNumber];

class XDMaPcie : public QObject
{
    Q_OBJECT
public:
    explicit XDMaPcie(QObject *parent = nullptr);
    HANDLE	  hDeviceBar[CXDmaPcie_FileNodeBarNumber];
    HANDLE	  hDeviceEvent[CXDmaPcie_FileNodeEventNumber];
    HANDLE	  hDeviceH2C[CXDmaPcie_FileNodeH2CNumber];
    HANDLE	  hDeviceC2H[CXDmaPcie_FileNodeC2HNumber];
    //**************************************************
    bool	  Open(UCHAR dev);
    void      Close(void);
    int       SetBarData(unsigned int BarSel, long Offset, unsigned int Value);
    int       GetBarData(unsigned int BarSel,long Offset,unsigned int *Value);
    int       H2CDMASeeK(unsigned int H2CSel,long OffsetLow,long OffsetHigh,CXDmaPcieFileSeek seek);
    int       C2HMASeeK (unsigned int C2HSel,long OffsetLow,long OffsetHigh,CXDmaPcieFileSeek seek);
    int       H2CDMAData(unsigned int H2CSel,unsigned char *Data,unsigned int Len,unsigned int *LenWritten,LPOVERLAPPED lpOverlapped);
    int       C2HDMAData(unsigned int C2HSel,unsigned char *Data,unsigned int Len,unsigned int *LenRead,LPOVERLAPPED lpOverlapped);
    //**************************************************
    QString GetBar1ConfigInfo(void);

protected:
    GUID      DrvGuid;		 //设备的GUID
    UCHAR     DevNum;		 //当前打开的设备检索值从0开始
    WCHAR     DevPath[256];  //当前打开的设备的设备路径

private:
    QString   m_str;
    void      read_block(long addr, size_t size, void* buffer);
    void      print_block(long base);
    void      print_channel_module(long module_base);
    void      print_irq_module(long base);
    void	  print_config_module(long offset);
    void	  print_sgdma_module(long offset);
    void	  print_sgdma_common_module(long offset);
    bool      CreateHandle(UCHAR dev);
signals:

public slots:
};

#endif // XDMAPCIE_H
