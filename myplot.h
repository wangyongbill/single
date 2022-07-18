#ifndef MYPLOT_H
#define MYPLOT_H
#include <QObject>
#include "qcustomplot.h"
#include <QMouseEvent>
#include <QMap>
#include "qDebug.h"
#include <QWidget>
#include "qcustomplot.h"

class MyPlot : public QCustomPlot
{
    Q_OBJECT
public:
    MyPlot(QWidget *parent = 0);
    //bool if_fangda;

private:

    /*游标相关组件*/
    QCPItemTracer *tracer;//游标
    QCPGraph *traceGraph;//游标要吸附哪个graph
    QCPItemText *tracerXText;//用于实时显示游标X值
    QCPItemText *tracerYText;//用于实时显示游标Y值
    QCPItemLine *tracerArrow;
    bool tracerEnable;//是否使能游标

};

#endif // MYPLOT_H
