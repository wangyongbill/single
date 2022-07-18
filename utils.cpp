#include "utils.h"
#include <QValidator>
#include <QMessageBox>
#include <QDebug>
#include <QString>
#include <QIntValidator>
#include <QFontDatabase>
#include <QCoreApplication>
#include <QFile>
#include <QFileInfo>
#include <QDir>
#include <QApplication>
#include <QPushButton>
#include <QTime>
#include <QString>
#include <QFileDialog>
#include <QTextCodec>
#include <QLineEdit>
#include <QXmlStreamWriter>
#include <QComboBox>
#include <array>
#include <QProcess>
#include <QFileSystemWatcher>

Utils::Utils()
{

}

QString Utils:: str(int mun){

    switch  (mun){
    //取消参数样式
    case    1:
    {
        return "color: rgba(255, 255, 255);background-color: rgba(0, 0, 255, 0);background:transparent;border-width:0;border-style:outset;font:24px;font-family: 思源黑体 CN Regular; background-repeat:no-repeat;background-position: top;padding-top: -20px;padding-left: -65px;";
    }
    case    2:
    {
        return "font:21px;font-family: 思源黑体 CN Regular;text-align: left;";
    }
    case    3:
    {
        return "color: rgba(255, 255, 255);background-color: rgba(0, 0, 255, 0);background:transparent;border-width:0;border-style:outset;font:21px;font-family: 思源黑体 CN Regular;text-align: left;border-image: url(:/images/cinfig_img/submenu_icon.png);";
    }
    case    4:
    {
        return "border-image:url(:/images/projecthome/index_btn.png);color:rgb(255, 255, 255);font:24px; text-align:center;";
    }
    case    5:
    {
        return "color: rgba(255, 255, 255);background-color: rgba(0, 0, 255, 0);background:transparent;border-width:0;border-style:outset;font:24px;font-family: 思源黑体 CN Regular; background-repeat:no-repeat;background-position: top;padding-top: -20px;padding-left: -65px;padding-right: 25px;";
    }
    }

    return "";

}

/**
 * @brief Utils::constantValue
 * @param mun1
 * @param obj
 * @return
 * 固定整数正则
 */
QValidator* Utils:: constantValue(int mun1,QObject * obj){


    QString str=QString("^(%1$").arg(mun1);
    QRegExp regx(str);
    QValidator *validator = new QRegExpValidator(regx, obj);
    return validator;
}
/**
 * @brief Utils::constantValue
 * @param mun1
 * @param obj
 * @return
 * 固定小数正则
 */
QValidator* Utils:: constantValue(double mun1,QObject * obj){

    QString str=QString("^(%1$").arg(mun1);
    QRegExp regx(str);
    QValidator *validator = new QRegExpValidator(regx, obj);
    return validator;
}

QValidator* Utils:: constantValue(QString mun1,QObject * obj){

    QString str=QString("^(%1$").arg(mun1);
    QRegExp regx(str);
    QValidator *validator = new QRegExpValidator(regx, obj);
    return validator;
}

QValidator* Utils:: minusRegular(int mun1,int mun2,int mun3,QObject * obj){


    QString str=QString("^(%1|%2|(^\\-[1-4][0-9]?(\\.\\d{1,%3})?))$").arg(mun1).arg(mun2).arg(mun3);
    QRegExp regx(str);
    QValidator *validator = new QRegExpValidator(regx, obj);
    return validator;
}
/**
 * @brief Utils::signValue
 * @param mun1
 * @param obj
 * @return
 * 正负值范围，只支持两位数
 */
QValidator* Utils:: signValue(int mun1,QObject * obj){

    int mun2=mun1/10-1;
    QString str=QString("^%1|-%1|-?[0-%2][0-9]?(\\.\\d\\d?)?$").arg(mun1).arg(mun2);
    QRegExp regx(str);
    QValidator *validator = new QRegExpValidator(regx, obj);
    return validator;
}


/**
 * @brief Utils::signValue
 * @param mun1
 * @param obj
 * @return
 * 正值范围，只支持两位数
 */
QValidator* Utils:: positiveValue(int mun1,QObject * obj){

    int mun2=mun1/10-1;
    QString str=QString("^%1|-?[0-%2][0-9]?(\\.\\d\\d?)?$").arg(mun1).arg(mun2);
    QRegExp regx(str);
    QValidator *validator = new QRegExpValidator(regx, obj);
    return validator;
}

QValidator* Utils:: minusRegular(double mun1,QObject * obj){


    QString str=QString("1|^0\\.[%1-9][0-9]$").arg(mun1);
    QRegExp regx(str);
    QValidator *validator = new QRegExpValidator(regx, obj);
    return validator;
}



bool Utils::copyFileToPath(QString sourceDir ,QString toDir, bool coverFileIfExist)
{
    sourceDir=this->getAbsolutePath(sourceDir);

    toDir.replace("\\","/");
    if (sourceDir == toDir){
        return true;
    }
    if (!QFile::exists(sourceDir)){
        return false;
    }
    QFileInfo fi(toDir);
    QString dirPath=fi.absolutePath();//取路径
    QDir *createfile = new QDir;
    bool exist=createfile->exists(dirPath);
    if(!exist)
    {
        createfile->mkdir(dirPath);
    }
    exist = createfile->exists(toDir);
    if (exist){
        if(coverFileIfExist){
            createfile->remove(toDir);
        }
    }//end if

    if(!QFile::copy(sourceDir, toDir))
    {
        return false;
    }
    return true;
}
/**
 * @brief Utils::sleep
 * @param time
 * 延时方法
 */
void Utils::sleep(int time)
{
    QTime dieTime = QTime::currentTime().addMSecs(time);
    while( QTime::currentTime() < dieTime )
        QCoreApplication::processEvents(QEventLoop::AllEvents, time);
}
bool Utils::equals(QString str1,QString str2)
{
    int localCompare = str1.compare(str2);

    if(localCompare ==0)
    {
        return  true;
    }else {
        return  false;
    }
}

/**
 * @brief Utils::createFile
 * 判断是否存在文件，如果不存在创建文件
 */
void  Utils::createFile(QString filePath,QString fileName)
{

    QDir tempDir;
    //临时保存程序当前路径
    QString currentDir = tempDir.currentPath();


    //如果filePath路径不存在，创建它
    if(!tempDir.exists(filePath))
    {
        qDebug()<<"不存在该路径"<<endl;
        tempDir.mkpath(filePath);
    }
    QFile *tempFile = new QFile;
    //将程序的执行路径设置到filePath下
    tempDir.setCurrent(filePath);
    qDebug()<<tempDir.currentPath();
    tempFile->setFileName(fileName);
    //检查filePath路径下是否存在文件fileName,如果停止操作。
    if(tempFile->exists(fileName))
    {
        qDebug()<<"文件存在";
        tempFile->remove();

    }
    //此时，路径下没有fileName文件，使用下面代码在当前路径下创建文件

    if(!tempFile->open(QIODevice::WriteOnly|QIODevice::Text))
    {
        qDebug()<<"打开失败";
    }
    tempFile->close();
    //将程序当前路径设置为原来的路径
    tempDir.setCurrent(currentDir);
    qDebug()<<tempDir.currentPath();
}
/**
 * @brief Utils::createFile
 * 创建文件夹
 */
void  Utils::createFile(QString filePath)
{

    QDir tempDir;
    //临时保存程序当前路径
    QString currentDir = tempDir.currentPath();


    //如果filePath路径不存在，创建它
    if(!tempDir.exists(filePath))
    {
        qDebug()<<"不存在该路径"<<endl;
        tempDir.mkpath(filePath);
    }

    //将程序当前路径设置为原来的路径
    tempDir.setCurrent(currentDir);

}



/**
 * @brief Utils::intProcessing
 * @param str
 * @return
 * 保存值处理
 */
QString Utils::intProcessing(QString str)

{
    char ask ='\'';

    QString pattern("^(\\-|\\+)?\\d+(\\.\\d+)?$"); //Qt匹配正数、负数、浮点数
    QRegExp rx(pattern);

    bool flag=rx.exactMatch(str.trimmed()); //trimmed() 去除字符串前后的空白字符
    if(!flag){

        str= ask+str+ask;

    }

    return str;
}

void Utils::clicksaveFile(QString filePath,QString fileName,QList<QLineEdit *> lineEdits, QList<QComboBox *> comboBoxs)
{
    Utils utils;
    QFile file(filePath+"/"+fileName); //参数就是读取文件的路径
    file.open(QIODevice::Truncate); //用重写方式进行写
    QTextStream out(&file);  //创建写入流
    out.setCodec("utf-8");

    for (int i=0;i<lineEdits.size();i++) {

        if(utils.equals(lineEdits.at(i)->text(),"")){
            lineEdits.at(i)->text()="-1";

        }
        out <<lineEdits.at(i)->objectName()<<"="<<lineEdits.at(i)->text()<<"\n";//写入数据
    }
    //qDebug() << lineEdits.size(); qDebug() << "lineEdits.size()";
    for (int i=0;i<comboBoxs.size();i++) {

        out <<comboBoxs.at(i)->objectName()<<"="<<comboBoxs.at(i)->currentIndex()<<"\n";//写入数据


    }
    //qDebug() << comboBoxs.size(); qDebug() << "comboBoxs.size()";

    file.open(QIODevice::ReadWrite);
    file.close();
}
/**
 * @brief Utils::clicksaveFile
 * @param filePath  写入文件的路径
 * @param fileName  写入文件的名称
 * @param allValueList  写入参数的值
 * @param allValueNameList  读取参数的名称
 * 文件写入
 */
void Utils::clicksaveFile(QString filePath,QString fileName,QList<QList<QString>> allValueNameList,QList<QList<QString>> allValueList)
{


    QFile file(filePath+"/"+fileName); //参数就是读取文件的路径
    file.open(QIODevice::Truncate); //用追加方式进行写
    QTextStream out(&file);  //创建写入流
    out.setCodec("utf-8");

    for (int i=0;i<allValueNameList.size();i++) {
        for (int j=0;j<allValueNameList[i].size();j++) {
            out << "&\t"<<allValueNameList[i].at(j)+"\t\t\t"<<allValueList[i].at(j)  <<"\n";//写入数据
        }

        out <<"\n";//写入数据
        out <<"\n";//写入数据

    }

    file.open(QIODevice::ReadWrite);
    file.close();


}
/**
 * @brief Utils::clicksaveFile
 * @param filePath  写入文件的路径
 * @param fileName  写入文件的名称
 * @param allValueList  写入参数的值
 * @param allValueNameList  读取参数的名称
 * 文件写入
 */
void Utils::clicksaveFile(QString filePath,QString fileName,QList<QList<QString>> allValueNameList,QList<QList<QString>> allValueList,QList <QString>strlist)
{
    qDebug() << "filePathDSAFA++fileName："; qDebug() << filePath+"/"+fileName;


    QFile file(filePath+"/"+fileName); //参数就是读取文件的路径

    file.open(QIODevice::Append); //用追加方式进行写
    QTextStream out(&file);  //创建写入流
    out.setCodec("utf-8");
    /**
     * @brief mun
     * 计数器
     */
    int mun=0;

    for (int i=0;i<allValueNameList.size();i++) {
        for (int j=0;j<allValueNameList[i].size();j++) {
            out << "&\t"<<allValueNameList[i].at(j)+"\t\t\t"<<allValueList[i].at(j) <<"\n";//写入数据
            out <<""+strlist[mun] <<"\n";
            qDebug() << "allValueNameList[i].at(j)："; qDebug() << allValueNameList[i].at(j);
            qDebug() << "allValueList[i].at(j)："; qDebug() << allValueList[i].at(j);

            mun++;
        }

        out <<"\n";//写入数据
        out <<"\n";//写入数据

    }

    file.open(QIODevice::ReadWrite);
    file.close();


}
void Utils::clicksaveFile(QString filePath,QString fileName,QList<QString> allValueNameList,QList<QString> allValueList)
{
    QFile file(filePath+"/"+fileName); //参数就是读取文件的路径
    file.open(QIODevice::Truncate); //用追加方式进行写
    QTextStream out(&file);  //创建写入流

    out.setCodec("utf-8");

    for (int i=0;i<allValueNameList.size();i++) {
        out << "&\t"<<allValueNameList.at(i)+"\t\t\t"<<allValueList.at(i)  <<"\n";//写入数据
        out <<"\n";//写入数据
    }



    file.open(QIODevice::ReadWrite);
    file.close();

}
void Utils::hificlicksaveFile(QString filePath,QString fileName,QList<QString> allValueNameList,QList<QString> allValueList)
{
    QFile file(filePath+"/"+fileName); //参数就是读取文件的路径
    file.open(QIODevice::Truncate); //用追加方式进行写
    QTextStream out(&file);  //创建写入流
    out.setCodec("utf-8");


    for (int i=0;i<allValueNameList.size();i++) {
        out <<allValueNameList.at(i)+"\t\t\t"<<allValueList.at(i)  <<"\n";//写入数据

    }



    file.open(QIODevice::ReadWrite);
    file.close();

}
void Utils::clicksaveFile(QString filePathName,QList<QString> allValueNameList,QList<QString> allValueList)
{
    QFile file(filePathName); //参数就是读取文件的路径
    file.open(QIODevice::Truncate); //用重写方式进行写
    QTextStream out(&file);  //创建写入流
    out.setCodec("utf-8");
    for (int i=0;i<allValueNameList.size();i++) {
        out <<allValueNameList.at(i)+"\t\t\t"<<allValueList.at(i)  <<"\n";//写入数据

    }



    file.open(QIODevice::ReadWrite);
    file.close();
}

void Utils::clicksaveFile(QString filePathName,QList<QString> allValueList)
{

    QFile file(filePathName); //参数就是读取文件的路径
    file.open(QIODevice::ReadWrite | QIODevice::Truncate); //用重写方式进行写

    QTextStream out(&file);  //创建写入流
    out.setCodec("utf-8");
    for (int i=0;i<allValueList.size();i++) {
        out <<allValueList.at(i) <<"\n";//写入数据

    }



    file.open(QIODevice::ReadWrite);
    file.close();
}
void Utils::clicksaveFile(QString filePathName,QString strs)
{

    qDebug() << "strs："; qDebug() << strs;

    QFile file(filePathName); //参数就是读取文件的路径
    file.open(QIODevice::Append); //用追加方式进行写

    QTextStream out(&file);  //创建写入流
    out.setCodec("utf-8");
    out <<strs<<"\n";//写入数据



    file.open(QIODevice::ReadWrite);
    file.close();
}



void Utils::clicksaveFile(QString filePathName,QList<double> allValueList)
{
    qDebug() << "filePathName："; qDebug() << filePathName;

    QFile file(filePathName); //参数就是读取文件的路径
    file.open(QIODevice::ReadWrite | QIODevice::Truncate); //用重写方式进行写
    QTextStream out(&file);  //创建写入流
    out.setCodec("utf-8");
    for (int i=0;i<allValueList.size();i++) {
        out <<allValueList.at(i) <<"\n";//写入数据

    }



    file.open(QIODevice::ReadWrite);
    file.close();
}


void Utils::clicksaveFile(QString filePathName,QMap<QString, QString>localReadImportFile)
{
    QFile file(filePathName); //参数就是读取文件的路径
    file.open(QIODevice::Truncate); //用重写方式进行写
    QTextStream out(&file);  //创建写入流
    out.setCodec("utf-8");
    QMap<QString, QString>::iterator iter = localReadImportFile.begin();
    while (iter != localReadImportFile.end())
    {

        out <<iter.key()+"\t\t\t"<<iter.value()  <<"\n";//写入数据
        iter++;
    }
    file.open(QIODevice::ReadWrite);
    file.close();
}




/**
 * @brief Utils::clicksaveFile
 * @param resourcePath  读取文件的路径
 * @param resourceName  读取文件的名称
 * @param filePath      写入文件的路径
 * @param fileName      写入文件的路径
 *
 */
void Utils::clicksaveFile(QString resourcePath,QString resourceName,QString filePath,QString fileName)
{
    Utils utils;
    QList<QString> localReadFile = utils.readFile(resourcePath+resourceName);
    QFile file(filePath+"/"+fileName); //参数就是读取文件的路径
    file.open(QIODevice::Append); //用追加方式进行写
    QTextStream out(&file);  //创建写入流
    out.setCodec("utf-8");
    for (int i=0;i<localReadFile.size();i++) {
        out << localReadFile[i] <<"\n";//写入数据
    }
    file.open(QIODevice::ReadWrite);
    file.close();

}

/**
 * @brief Utils::readFile
 * @param fileAllPath
 * @return
 * 文件读取  按行读
 */
QList<QString> Utils::readFile(QString fileAllPath)
{
    QList<QString> list;
    QFileInfo fileinfo(fileAllPath);
    QFile file(fileinfo.absoluteFilePath());
    if (file.open(QIODevice::ReadOnly | QIODevice::Text))
    {
        while (!file.atEnd())
        {
            QByteArray line = file.readLine();

            //            QTextCodec *codec = QTextCodec::codecForName("gb18030");
            QTextCodec *codec = QTextCodec::codecForName("utf-8");
            QString str = codec->toUnicode(line);
            str.replace("\n","");

            list.append(str);

        }

        file.close();
    }

    return list;

}


/**
 * @brief Utils::ProDataFileDispose
 * @param allPath
 * @return
 * 工程文件读取
 */
QList<QStringList> Utils::proDataFileDispose(QString allPath){
    QFileInfo Fileinfo(allPath);


    QList<QString> localFilePath = this->readFile(Fileinfo.absoluteFilePath());

    QList<QStringList> strs;
    QStringList qsl;

    for (int i=0;i<localFilePath.size();i++) {
        /**
         * @brief localAt
         * 每一行的值
         */
        QString localAt = localFilePath.at(i);
        QStringList localSplit = localAt.split("&$ ");
        strs.append(localSplit);


    }

    return strs;
}


/**
 * @brief Utils::initList
 * @param list 要处理的集合
 * @param initSize小集合数量
 * @return
 * 初始化配置文件集合
 */
QList <QList<QString>> Utils::initList(QList <QList<QString>>list ,int initSize){


    list.clear();
    list.reserve(0);
    for (int i=0;i<initSize;i++) {
        list.append(QList<QString>());

    }
    return list;

}

QList <QList<QLineEdit *>> Utils::initlineEdit(int initSize){
    QList <QList<QLineEdit*>>list ;

    list.clear();
    list.reserve(0);
    for (int i=0;i<initSize;i++) {
        list.append(QList<QLineEdit *>());

    }
    qDebug() << list.size(); qDebug() << "list.size()";
    return list;

}

QList <QList<QComboBox *>> Utils::initcomboBoxList(int initSize){
    QList <QList<QComboBox*>>list ;

    list.clear();
    list.reserve(0);
    for (int i=0;i<initSize;i++) {
        list.append(QList<QComboBox *>());

    }
    qDebug() << list.size(); qDebug() << "list.size()";
    return list;

}
/**
 * @brief findChar
 * @param str
 * @param str2
 * @return
 * 计算字符串中重复出现的字符
 */
int Utils::findChar(QString str,QString str2){

    //存放每个字符的数组
    QList<QString> list;
    //计数该字符出现了多少次
    int count = 0;
    //先把字符串转换成数组
    for(int i = 0;i<str.length();i++){
        list.append(str.at(i));
    }
    //挨个字符进行查找，查找到之后count++
    for(int i = 0;i<list.length();i++){
        int localCompare = list.at(i).compare(str2);

        if(localCompare ==0)
        {
            count++;
        }
    }
    return count;

}

/**
 * @brief Utils::strToDouble
 * @param strs
 * @return
 * 字符串转double
 */
QList<double> Utils::strToDouble(QStringList strs){
    QList<double> des;
    for (int i=0;i<strs.size();i++) {

        QString localAt = strs.at(i);
        bool localIsNum = this->isNum(localAt);
        if(localIsNum){
            double doubles = localAt.toDouble();
            des.append(doubles);

        }
    }
    return des;
}
/**
 * @brief Utils::isNum
 * @param str
 * @return
 * 判断是否是数字
 */
bool Utils::isNum(QString str){
    bool localContains = str.contains(QRegExp("[A-Za-z]/g"));

    return !localContains;
}
/**
 * @brief Utils::strToInt
 * @param strs
 * @return
 * 字符串转int
 */
QList<int> Utils::strToInt(QStringList strs){
    QList<int> des;
    for (int i=0;i<strs.size()  ;i++) {
        des.append(strs[i].toDouble());
    }
    return des;
}
/**
 * @brief Utils::medianDouble
 * @param dbes
 * @return
 * 中位值
 */
double Utils::medianDouble(QList<double> dbes){
    int localSize = dbes.size();

    double dbe=0;
    if(localSize%2 == 0){
        dbe = (dbes[localSize/2]+dbes[localSize/2-1])/2;

    }else{
        dbe=dbes[localSize/2];
    }
    return dbe;
}

/**
 * @brief Utils::averageDouble
 * @param dbe
 * @return
 * 求double集合平均值
 */
double Utils::averageDouble(QList<double> dbes){
    double dbe=0;
    for (int i=0;i<dbes.size() ;i++) {
        dbe=dbe+dbes[i];

    }
    return dbe/dbes.size();
}


double Utils::averageInt(QList<int> dbes){
    int dbe=0;
    for (int i=0;i<dbes.size() ;i++) {
        dbe=dbe+dbes[i];

    }
    return dbe/dbes.size();
}


QList<double> Utils::sortDouble(QList<double> localStrToDouble){
    for(int i = 0; i<localStrToDouble.length()-1; i++)
    {
        for (int j = 0; j < localStrToDouble.length()-1-i; j++)
        {

            //排序算法
            //判断arr[j]是否大于arr[j+1]
            if(localStrToDouble[j]>localStrToDouble[j+1]){

                /*将大的值放在后面一位*/
                double temp=localStrToDouble[j];
                localStrToDouble[j]=localStrToDouble[j+1];
                localStrToDouble[j+1]=temp;

            }

        }
    }
    return localStrToDouble;
}
QVector<double> Utils::sortDouble(QVector<double> localStrToDouble){
    for(int i = 0; i<localStrToDouble.length()-1; i++)
    {
        for (int j = 0; j < localStrToDouble.length()-1-i; j++)
        {

            //排序算法
            //判断arr[j]是否大于arr[j+1]
            if(localStrToDouble[j]>localStrToDouble[j+1]){

                /*将大的值放在后面一位*/
                double temp=localStrToDouble[j];
                localStrToDouble[j]=localStrToDouble[j+1];
                localStrToDouble[j+1]=temp;

            }

        }
    }
    return localStrToDouble;
}


QList<int> Utils::sortDouble(QList<int> localStrToDouble){
    for(int i = 0; i<localStrToDouble.length()-1; i++)
    {
        for (int j = 0; j < localStrToDouble.length()-1-i; j++)
        {

            //排序算法
            //判断arr[j]是否大于arr[j+1]
            if(localStrToDouble[j]>localStrToDouble[j+1]){

                /*将大的值放在后面一位*/
                int temp=localStrToDouble[j];
                localStrToDouble[j]=localStrToDouble[j+1];
                localStrToDouble[j+1]=temp;

            }

        }
    }
    return localStrToDouble;
}




/**
 * @brief Utils::disposeStrData
 * @param qsl  待处理的集合
 * @param mun  要取集合中的哪一组
 * @param flag 是否去表头
 * @return
 *
 */



QList<double> Utils::disposeStrDatax( QList<QStringList> qsl,int mun,bool flag){

    QStringList localAt = qsl.at(mun);
    if(flag)
        localAt.removeAt(0);

    /**
         * @brief localSortDouble
         * 不排序后的double集合
         */
    QList<double> localSortDouble = this->strToDouble(localAt);
    return localSortDouble;
}


double Utils::getMinumn(double mun1,double mun2){
    if(mun1>mun2){
        return mun2;
    }else{
        return mun1;
    }
}
double Utils::getMaxumn(double mun1,double mun2){
     if(mun1>mun2){
        return mun1;
    }else{
        return mun2;
    }
}

/**
 * @brief Utils::addMcsData
 * @param qsl
 * @return
 * 集合求和
 */
QList<double>  Utils::listSunData(QList<QStringList> qsl){
    QList<double>   qslSunData;
    double mun=0;
    for (int i=0;i<qsl.size();i++) {
        QStringList localAt = qsl.at(i);
        //去表头
        localAt.removeAt(0);
        QList<double> localStrToDouble = this->strToDouble(localAt);
        for (int i=0;i<localStrToDouble.size()  ;i++) {
            //求和
            mun=mun+localStrToDouble.at(i);

        }
        qslSunData.append(mun);

    }
    return qslSunData;

}

QList<double>  Utils::listSunData(QList<QList<double>> qsl){
    QList<double> qslSunData;

    for (int i=0;i<qsl.size()  ;i++) {
        QList<double> localAt = qsl.at(i);
        //去表头
        localAt.removeAt(0);
        double mun=0;

        for (int i=0;i<localAt.size()  ;i++) {
            //求和
            mun=mun+localAt.at(i);

        }
        qslSunData.append(mun);

    }
    return qslSunData;

}

QList<double>  Utils::listSunData2(QList<QList<double>> qsl){
    QList<double> qslSunData;

    for (int i=0;i<qsl.size()  ;i++) {
        QList<double> localAt = qsl.at(i);
        //去表头
        localAt.removeAt(0);
        double mun=0;

        for (int j=0;j<localAt.size();j++) {

            //求和
            mun=mun+localAt.at(j);

        }
        mun=mun*(i+1);
        qslSunData.append(mun);

    }
    return qslSunData;

}
double Utils::doubleSun(QList<double> qsl){
    double mun=0;
    for (int i=0;i<qsl.size();i++) {
        double localAt = qsl.at(i);
        mun=mun+localAt;
    }
    return mun;

}
QMap<QString,int> Utils::statisticalRepetition(QList<QString> m_ListStr){

    QMap<QString, int> mapStrInt;
    int count=1;
    for(int i=0; i<m_ListStr.size(); i++)
    {
        if( nullptr != mapStrInt.find(m_ListStr.at(i)).key())
        {
            mapStrInt.insert(m_ListStr[i], mapStrInt.find(m_ListStr[i]).value()+1);
        }
        else
        {
            mapStrInt.insert(m_ListStr[i], count);
        }


    }


    //    qDebug() << "mapStrInt:";
    //    QMap<QString, int>::Iterator it = mapStrInt.begin();
    //    while(it!=mapStrInt.end())
    //    {
    //        qDebug() << it.key() << it.value();
    //        it++;
    //    }

    return mapStrInt;


}
/**
 * @brief Utils::callBat
 * @param path
 * @param filename
 * 调用bat文件
 */
void Utils::callBat(QString path, QString filename){
    QProcess p(NULL);
    p.setWorkingDirectory(path);
    QString command =path+filename;
    qDebug() << "comma11nd："; qDebug() << command;

    //   QString absolutePath = this->getAbsolutePath(command);
    p.start(command);
    //    qDebug() << "absolutePath："; qDebug() << absolutePath;

    p.waitForFinished();

}

/**
 * @brief Utils::fileSent
 * @param allpath
 * 文件传输
 */
void Utils::fileSent(QString allpath){


    QString dir= QCoreApplication::applicationDirPath();
    QString str=dir+"/config/config/client/needToSend.txt";
    sta_bat_path=dir+"/config/config/bat/";
    QList<QString>  strs ;

    qDebug() << "allpath："; qDebug() << allpath;

    strs.append(allpath);
    this->clicksaveFile(str,strs);
    this->callBat(sta_bat_path,sta_bat_filename3);
    this->sleep(5000);
    this->callBat(sta_bat_path,sta_bat_filename4);


}
/**
 * @brief Utils::getAbsolutePath
 * @param allpath
 * @return
 * 得到绝对路径
 */
QString Utils::getAbsolutePath(QString allpath)
{
    QFile file(allpath);
    QString localAbsolutePath = QFileInfo(file).absolutePath();
    return localAbsolutePath;
}
/**
 * @brief Utils::initMonitor
 * 开启监听服务端
 */
void Utils::openMonitor(){
    if(initmonitor==0){
        qDebug() << "initMonitor进来了initmonitor："; qDebug() << initmonitor;
        initmonitor++;
        QList<QString> strs1;
        QList<QString> strs2;
        QList<QString> strs3;
        QList<QString> strs4;
        QList<QString> strs5;
        QList<QString> strs6;

        QString dir= QCoreApplication::applicationDirPath();
        sta_bat_path=dir+"/config/config/bat/";
        QString str1="start "+dir+"/config/config/server/server.exe";
        QString str3="start "+dir+"/config/config/client/client.exe";
        QString str5="start "+dir+"/config/config/client_file/client_for_tran_file.exe";
        QString str6="start "+dir+"/config/config/client_file_for_mmw/client_for_tran_file.exe";

        this->createFile(sta_bat_path,sta_bat_filename1);
        this->createFile(sta_bat_path,sta_bat_filename2);
        this->createFile(sta_bat_path,sta_bat_filename3);
        this->createFile(sta_bat_path,sta_bat_filename4);
        this->createFile(sta_bat_path,sta_bat_filename5);
        this->createFile(sta_bat_path,sta_bat_filename6);

        strs1.append(str1);
        strs2.append("@echo off");
        strs2.append("taskkill /f /im server.exe");
        strs3.append(str3);
        strs4.append("@echo off");
        strs4.append("taskkill /f /im client.exe");
        strs5.append(str5);
        strs6.append(str6);


        this->clicksaveFile(sta_bat_path+sta_bat_filename1,strs1);

        this->clicksaveFile(sta_bat_path+sta_bat_filename2,strs2);
        this->clicksaveFile(sta_bat_path+sta_bat_filename3,strs3);
        this->clicksaveFile(sta_bat_path+sta_bat_filename4,strs4);
        this->clicksaveFile(sta_bat_path+sta_bat_filename5,strs5);
        this->clicksaveFile(sta_bat_path+sta_bat_filename6,strs6);

        this->callBat(sta_bat_path,sta_bat_filename1);
    }
}
/**
 * @brief Utils::getDir
 * @return
 * 获取程序根路径
 */
QString  Utils::getDir(){

    QString dir= QCoreApplication::applicationDirPath();
    return dir;
}

/**
 * @brief ProjectHome::initFileMonitor
 * 初始化文件监听
 */
QFileSystemWatcher * Utils::initFileMonitor(QStringList qsl){
    qDebug() << "开启监听"; qDebug() << "";

    QFileSystemWatcher *jt = new QFileSystemWatcher();


    jt->addPaths(qsl);
    for (int i=0;i< qsl.size();i++) {
        QString localAt = qsl.at(i);
        qDebug() << "localAt："; qDebug() << localAt;


    }

    return jt;
}
/**
 * @brief getFileNames
 * @param path
 * @return
 * 获取文件夹下所有文件
 */
QStringList Utils:: getFileNames(const QString &path)
{
    QDir dir(path);
    QStringList nameFilters;
    nameFilters << "*.txt" << "*.xls"<< "*.xlsx";
    QStringList files = dir.entryList(nameFilters, QDir::Files|QDir::Readable, QDir::Name);
    return files;
}
/**
 * @brief Utils::fileMove
 * @param source_path
 * @param dest_path
 * @return
 * 文件移动
 */
bool Utils:: fileMove( QString source_path,QString dest_path,QString file_name)
{

    QString absolutePath = this->getAbsolutePath(dest_path+"/"+file_name);
    QFile file(source_path+file_name);
    bool FE1 = file.exists();
    qDebug() << "待移动文件是否存在："; qDebug() << FE1;

    QFile file2(dest_path+file_name);
    file.close ();
    //    如果文件己存在  删除它
    file2.remove();
    bool localRename = file.copy(dest_path+"/"+file_name);
    bool localExists = file2.exists();
    qDebug() << "己移动文件是否存在："; qDebug() << localExists;

    file.remove();




    return localRename;
}
/**
 * @brief Utils::fileCopy
 * @param source_path
 * @param dest_path
 * @param file_name
 * @return
 * 文件复制
 */
bool Utils:: fileCopy( QString source_path,QString dest_path,QString file_name)
{
    qDebug() << "source_path："; qDebug() << source_path;
    qDebug() << "dest_path："; qDebug() << dest_path;

    QString absolutePath = this->getAbsolutePath(dest_path+file_name);
    QFile file(source_path+file_name);
    bool FE1 = file.exists();
    qDebug() << "待移动文件是否存在："; qDebug() << FE1;

    QFile file2(dest_path+file_name);
    file.close ();
    //    如果文件己存在  删除它
    file2.remove();
    bool localRename = file.copy(dest_path+file_name);
    bool localExists = file2.exists();
    qDebug() << "己移动文件是否存在："; qDebug() << localExists;





    return localRename;
}

/**
 * @brief Utils::newFolder
 * @param filePath
 * @return
 * 新建文件夹
 */
bool Utils::newFolder(QString filePath){
    QDir tempDir;
    //临时保存程序当前路径
    QString currentDir = tempDir.currentPath();

    if(!tempDir.exists(filePath))
    {
        qDebug()<<"不存在该路径"<<endl;
        tempDir.mkpath(filePath);
        return true;
    }
    return false;

}


bool Utils::isFileExist(QString fullFileName)

{
    QFileInfo fileInfo(fullFileName);
    if(fileInfo.isFile())
    {
        return true;
    }
    return false;

}
/**
 * @brief Utils::getdoubleListSun
 * @param dbs1
 * @param dbs2
 * @return
 * 得到两个double集合每一项求和后的结果
 */
QList<double> Utils::getdoubleListSun(QList<double> dbs1,QList<double> dbs2){
    QList<double> doubleSun;
    int localSize = dbs1.size();
    int localSize2 = dbs2.size();
    double minumn = this->getMinumn(localSize,localSize2);

    for (int i=0;i<minumn;i++) {
        double dbe=  dbs1.at(i)+ dbs2.at(i);
        doubleSun.append(dbe);
    }
    return doubleSun;
}

/**
 * @brief Utils::isListInclude
 * @param dbs1
 * @param str
 * @return
 * 判断集合中是否包含某此元素
 */
bool Utils::isListInclude(QList<QString> strs,QString str){
    bool falg =false;
    for (int i=0;i< strs.size();i++) {
        QString localAt = strs.at(i);
        falg= this->equals(localAt,str);
        if(falg){
            qDebug() << "falg："; qDebug() << falg;

            return falg;

        }

    }
    qDebug() << "localIsLisefsfatInclude";

    return falg;
}


bool Utils::removeFolderContent(const QString &folderDir)
{
    QDir dir(folderDir);
    QFileInfoList fileList;
    QFileInfo curFile;

    if(!dir.exists())  {return false;}//文件不存，则返回false
    fileList=dir.entryInfoList(QDir::Dirs|QDir::Files
                               |QDir::Readable|QDir::Writable
                               |QDir::Hidden|QDir::NoDotAndDotDot
                               ,QDir::Name);
    while(fileList.size()>0)
    {
        int infoNum=fileList.size();
        for(int i=infoNum-1;i>=0;i--)
        {
            curFile=fileList[i];
            if(curFile.isFile())//如果是文件，删除文件
            {
                QFile fileTemp(curFile.filePath());
                fileTemp.remove();
                fileList.removeAt(i);
            }
            if(curFile.isDir())//如果是文件夹
            {
                QDir dirTemp(curFile.filePath());
                QFileInfoList fileList1=dirTemp.entryInfoList(QDir::Dirs|QDir::Files
                                                              |QDir::Readable|QDir::Writable
                                                              |QDir::Hidden|QDir::NoDotAndDotDot
                                                              ,QDir::Name);
                if(fileList1.size()==0)//下层没有文件或文件夹
                {
                    dirTemp.rmdir(".");
                    fileList.removeAt(i);
                }
                else//下层有文件夹或文件
                {
                    for(int j=0;j<fileList1.size();j++)
                    {
                        if(!(fileList.contains(fileList1[j])))
                            fileList.append(fileList1[j]);
                    }
                }
            }
        }
    }
    dir.removeRecursively();
    return true;
}

//source源文件目录路径，destination目的文件目录，override文件存在是否覆盖
bool Utils:: copyDir(const QString &source,const QString &destination, bool override)
{

    QDir directory(source);
    if (!directory.exists())
    {
        qDebug()<<"不存在";
        return false;
    }


    QString srcPath = QDir::toNativeSeparators(source);
    if (!srcPath.endsWith(QDir::separator()))
        srcPath += QDir::separator();
    QString dstPath = QDir::toNativeSeparators(destination);
    if (!dstPath.endsWith(QDir::separator()))
        dstPath += QDir::separator();


    bool error = false;
    QStringList fileNames = directory.entryList(QDir::AllEntries | QDir::NoDotAndDotDot | QDir::Hidden);
    for (QStringList::size_type i=0; i != fileNames.size(); ++i)
    {
        QString fileName = fileNames.at(i);
        QString srcFilePath = srcPath + fileName;
        QString dstFilePath = dstPath + fileName;
        QFileInfo fileInfo(srcFilePath);
        if (fileInfo.isFile() || fileInfo.isSymLink())
        {
            if (override)
            {
                QFile::setPermissions(dstFilePath, QFile::WriteOwner);
            }
            QFile::copy(srcFilePath, dstFilePath);
        }
        else if (fileInfo.isDir())
        {
            QDir dstDir(dstFilePath);
            dstDir.mkpath(dstFilePath);
            if (!copyDir(srcFilePath, dstFilePath, override))
            {
                error = true;
            }
        }
    }
    return !error;
}

//srcPath源文件文件路径，dstPath目的文件路径，coverFileIfExist文件存在是否覆盖
bool Utils::copyFile(QString srcPath, QString dstPath, bool coverFileIfExist)
{
    srcPath.replace("\\", "/");
    dstPath.replace("\\", "/");
    if (srcPath == dstPath) {
        return true;
    }

    if (!QFile::exists(srcPath)) {  //源文件不存在
        return false;
    }

    if (QFile::exists(dstPath)) {
        if (coverFileIfExist) {
            QFile::remove(dstPath);
        }
    }

    if (!QFile::copy(srcPath, dstPath)){
        return false;
    }
    return true;
}

/**
 * @brief Utils::emptyServer
 * @return
 * 清空server文件夹
 */
void Utils::emptyServer(){
    QString dir = this->getDir()+"/config/config/server/";
    qDebug() << "d3232ir："; qDebug() << dir;

    //this->createFile(dir,"end.ini");
    QStringList fileNames = this->getFileNames(dir);
    for (int i=0;i< fileNames.size();i++) {
        QFile ::remove(dir+fileNames.at(i));


    }


}
/**
 * @brief Utils::getDialog
 *
 */
void Utils::getDialog(QString title,QString data){

    QMessageBox::critical(0 , title , data, QMessageBox::Ok | QMessageBox::Default);

}


/**
 * @brief MainWindow::tostr
 * @param num
 * @return
 * 设置小数位有效值
 */
double Utils::getDecimalPlaces(double dbe,int num){
    QString str=  QString::number(dbe, 'f', 100);
    bool falg=true;
    //不是小数
    if( str.indexOf(".")==-1){
        return dbe;
    }

    /**
  * @brief staindex
  * 小数点后不为0的下标
  */
    int staindex=0;
    int localIndexOf = str.indexOf(".")+1;

    for (int i=localIndexOf;i< str.size();i++) {
        QString localAt = str.at(i);
        int intf = localAt.toInt();
        if(falg){
            if(intf!=0){
                falg=false;
                staindex=i+num-localIndexOf;
            }
        }
    }


    QString strs=  QString::number(dbe, 'f', staindex);
    double db = strs.toDouble();
    return db;

}

QList<QColor > * Utils::getColors(){
    QList<QColor > *  colors = new QList<QColor >();

    colors->append(QColor(207 , 113 , 175));
    colors->append(QColor(0 , 255 , 205));
    colors->append(QColor(0 , 103 , 165));
    colors->append(Qt::yellow);
    colors->append(QColor(128 , 70 , 27));
    colors->append(QColor(103 , 146 , 103));
    colors->append(Qt::red);
    colors->append(Qt::green);
    colors->append(Qt::blue);
    colors->append(Qt::cyan);
    colors->append(Qt::magenta);



    colors->append(Qt::transparent);
    return colors;
}
void  Utils::openDirFile(QString filePath){
    QProcess process;
    filePath.replace("/", "\\"); // 只能识别 "\"
    QString cmd = QString("explorer.exe /select,\"%1\"").arg(filePath);
    qDebug() << cmd;
    process.startDetached(cmd);

}


int Utils::getRandom(int min,int max)
{
    qsrand(QTime(0, 0, 0).secsTo(QTime::currentTime()));

    int random = qrand()%(max-min);
    return random;

}
//source源文件目录路径，destination目的文件目录，override文件存在是否覆盖


//删除文件夹
bool Utils::DelDir(const QString &path)
{
    if (path.isEmpty()){
        return false;
    }
    QDir dir(path);
    if(!dir.exists()){
        return true;
    }
    dir.setFilter(QDir::AllEntries | QDir::NoDotAndDotDot); //设置过滤
    QFileInfoList fileList = dir.entryInfoList(); // 获取所有的文件信息
    foreach (QFileInfo file, fileList){ //遍历文件信息
        if (file.isFile()){ // 是文件，删除
            file.dir().remove(file.fileName());
        }else{ // 递归删除
            DelDir(file.absoluteFilePath());
        }
    }
    return dir.rmdir(dir.absolutePath()); // 删除文件夹
}

bool Utils::copyDirectoryFiles(const QString &fromDir, const QString &toDir, bool coverFileIfExist)
{
    QDir sourceDir(fromDir);
    QDir targetDir(toDir);
    if(!targetDir.exists()){    /**< 如果目标目录不存在，则进行创建 */
        if(!targetDir.mkdir(targetDir.absolutePath()))
            return false;
    }

    QFileInfoList fileInfoList = sourceDir.entryInfoList();
    foreach(QFileInfo fileInfo, fileInfoList){
        if(fileInfo.fileName() == "." || fileInfo.fileName() == "..")
            continue;

        if(fileInfo.isDir()){    /**< 当为目录时，递归的进行copy */
            if(!copyDirectoryFiles(fileInfo.filePath(),
                targetDir.filePath(fileInfo.fileName()),
                coverFileIfExist))
                return false;
        }
        else{            /**< 当允许覆盖操作时，将旧文件进行删除操作 */
            if(coverFileIfExist && targetDir.exists(fileInfo.fileName())){
                targetDir.remove(fileInfo.fileName());
            }

            /// 进行文件copy
            if(!QFile::copy(fileInfo.filePath(),
                targetDir.filePath(fileInfo.fileName()))){
                    return false;
            }
        }
    }
    return true;
}

QString Utils::replaceStyle(QString str1, QString str2, QString str3)
{
    QString style = str1.replace(str2,str3);
    return style;
}
