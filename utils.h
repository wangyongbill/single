#ifndef UTILS_H
#define UTILS_H


#include <QObject>
#include <QDoubleValidator>
#include <QFile>
#include <QLineEdit>
#include <QComboBox>
#include <qfilesystemwatcher.h>

class Utils
{
public:
    Utils();
    QString str(int mun);
    QDoubleValidator* regular(int mun1,int mun2,int mun3,QObject * obj);
    QValidator* minusRegular(int mun1,int mun2,int mun3,QObject * obj);

    QString strJoin(QString str,QString str2);
    QString strJoin(QString str,QString str2,QString str3);
    void LoadFonts();
    bool copyFileToPath(QString sourceDir ,QString toDir, bool coverFileIfExist);

    void sleep(int time);

    bool equals(QString str1, QString str2);

    void createFile(QString filePath, QString fileName);

    QList<QList<QLineEdit *> > initList(QList<QLineEdit *> lineEdit, int initSize);
    void clicksaveFile(QString filePath, QString fileName, QList<QString> allValueNameList, QList<QString> allValueList);





    QList<QString> readFile(QString fileAllPath);

    int findChar(QString str, QString str2);
    QString valueConvert(QString value);



    void clicksaveFile(QString filePath, QString fileName, QString resourcePath, QString resourceName);


    void clicksaveFile(QString filePath, QString fileName, QList<QList<QString> > allValueNameList, QList<QList<QString> > allValueList);

    void clicksaveFile(QString allPath, QList<double> lineWidget);


    QList<QList<QLineEdit *> > initlineEdit(int initSize);
    QList<QList<QString> > initList(QList<QList<QString> > list, int initSize);


    void writeXml(QString allPathName, QList<QList<QLineEdit *> > lineEdit);

    void clicksaveInFile(QString filePath, QString fileName, QList<QList<QLineEdit *> > lineEditList);

    QList<QList<QComboBox *> > initcomboBoxList(int initSize);
    void clicksaveFile(QString filePath, QString fileName, QList<QList<QString> > allValueNameList, QList<QList<QString> > allValueList, QList<QString> strlist);
    void clicksaveFile(QString allPathName, QMap<QString, QString> t);

    void clicksaveInFile(QString filePath, QString fileName, QList<QList<QLineEdit *> > lineEditList, QList<QList<QComboBox *> > comboBoxList);
    QString textProcessing(QString str);
    QString intProcessing(QString str);

    QList<QString> dataProcessing();
    void clicksaveFile(QString filePath, QString fileName, QList<QLineEdit *> lineEdits, QList<QComboBox *> comboBoxs);
    void clicksaveFile(QString filePathName, QList<QString> allValueNameList, QList<QString> allValueList);
    QList<QMap<QString, QString> > readImportFile(QString fileAllPath);
    QList<QMap<QString, QString> > millReadImportFile(QString fileAllPath);
    QList<QMap<QString, QString> > hifiReadImportFile(QString fileAllPath);
    QList<QMap<QString, QString> > interReadImportFile(QString fileAllPath);
    QList<QMap<QString, QString> > starReadImportFile(QString fileAllPath);
    QList<QString> readTerminalFile(QString fileAllPath);
    QDoubleValidator *regular(double mun1, int mun2, int mun3, QObject *obj);

    QValidator *minusRegular(double mun1, QObject *obj);
    QValidator *constantValue(int mun1, QObject *obj);


    QValidator *signValue(int mun1, QObject *obj);

    QValidator *positiveValue(int mun1, QObject *obj);
    QValidator *constantValue(double mun1, QObject *obj);
    QDoubleValidator *regular(double mun1, double mun2, int mun3, QObject *obj);
    QValidator *constantValue(QString mun1, QObject *obj);
    QList<QStringList> dataFileDispose(QString allPath);

    QList<double> strToDouble(QStringList strs);
    double averageDouble(QList<double> dbe);
    QList<double> sortDouble(QList<double> localStrToDouble);
    QList<int> sortDouble(QList<int> localStrToDouble);
    double averageInt(QList<int> dbes);
    QList<int> strToInt(QStringList strs);


    QString setTextColor(QString str);
    QList<double> folderTraverse(QString path);



    QList<QList<double> > readEnvXlsFile(QString filePath, int datasize, bool flag);
    QList<QList<double> > folderTraverses(QString path);
    QVector<double> sortDouble(QVector<double> localStrToDouble);
    QList<double> disposeStrData(QList<QStringList> qsl, int mun, bool flag);

    double getMaxumn(double mun1, double mun2);
    double getMinumn(double mun1, double mun2);

    QList<double> listSunData(QList<QStringList> qsl);
    QList<double> listSunData(QList<QList<double> > qsl);
     QList<double> listSunData2(QList<QList<double> > qsl);
    double doubleSun(QList<double> qsl);
    double medianDouble(QList<double> dbes);
    QList<double> disposeStrDatax(QList<QStringList> qsl, int mun, bool flag);

    QMap<QString, int> statisticalRepetition(QList<QString> m_ListStr);
    void callBat(QString path, QString filename);

    void fileSent(QString allpath);
    /**
     * @brief getAbsolutePath
     * @param allpath
     * 得到绝对路径
     */
    QString getAbsolutePath(QString allpath);
    void openMonitor();

    /**
       * @brief initmonitor
       * 初始化监听
       */
    int initmonitor=0;

    QString sta_bat_path="D:/meteor/demo/QTdemo/TestDome2/config/config/bat/";
    QString sta_bat_filename1="startserver.bat";
    QString sta_bat_filename2="shopserver.bat";
    QString sta_bat_filename3="startclient.bat";
    QString sta_bat_filename4="shopclient.bat";

    QString sta_bat_filename5="startclientfile.bat";
    QString sta_bat_filename6="startclient_mfile.bat";

    QString getDir();

    QStringList getFileNames(const QString &path);
    QFileSystemWatcher *initFileMonitor(QStringList qsl);
    bool fileMove(QString source_path, QString dest_path);
    bool fileMove(QString source_path, QString dest_path, QString file_name);
    bool isFileExist(QString fullFileName);
    void clicksaveFile(QString filePathName, QList<QString> allValueList);

    QList<double> getdoubleListSun(QList<double> dbs1, QList<double> dbs2);
    bool newFolder(QString filePath);
    bool isListInclude(QList<QString> dbs1, QString str);
    bool isNum(QString str);
    bool removeFolderContent(const QString &folderDir);
    bool copyDir(const QString &source, const QString &destination, bool override);
    bool copyFile(QString srcPath, QString dstPath, bool coverFileIfExist);
    void emptyServer();
    void fileSent2(QString allpath);
    void getDialog(QString title, QString data);
    void fileSent3(QString allpath);

    double getDecimalPlaces(double dbe, int num);
    QList<QColor> *getColors();
    void fileSent6(QString allpath);
    void fileSent4();
    /**
     * @brief openDirFile
     * @param filePath
     * 定位指定文件
     */
    void openDirFile(QString filePath);
    int getRandom(int min, int max);
    void hificlicksaveFile(QString filePath, QString fileName, QList<QString> allValueNameList, QList<QString> allValueList);
    bool fileCopy(QString source_path, QString dest_path, QString file_name);
    void createFile(QString filePath);
    void clicksaveFile(QString filePathName, QString strs);
    QList<QStringList> proDataFileDispose(QString allPath);
    bool DelDir(const QString &path);
    bool copyDirectoryFiles(const QString &fromDir, const QString &toDir, bool coverFileIfExist);

    QString replaceStyle(QString str1, QString str2, QString str3);
};



#endif // UTILS_H
