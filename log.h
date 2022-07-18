
#pragma once



#include <QMutex>

#include <QString>



#define LOG_FILE_NAME QString("/Log/") + QDateTime::currentDateTime().toString("yyyy-MM-dd-hh-mm-ss") + QString(".txt")



static int s_logLevel = QtDebugMsg;

static QMutex s_logMutex;

static QString s_logPath;



void setLogPath(const QString &path);

void setLogLevel(int level);

void customLogMessageHandler(QtMsgType type, const QMessageLogContext& ctx, const QString& msg);
