#include "myplot.h"

MyPlot::MyPlot(QWidget *parent):
    QCustomPlot(parent),tracer(new QCPItemTracer(this))
{
    //游标以及游标文本框设置
    this->setMouseTracking(true);
    tracer->setInterpolating(false);//禁用插值
    tracer->setPen(QPen(Qt::DashLine));//虚线游标
    tracer->setStyle(QCPItemTracer::tsCrosshair);//游标样式：十字星、圆圈、方框等
    //游标的X值文本框
    tracerXText = new QCPItemText(this);
    tracerXText->setPositionAlignment(Qt::AlignBottom|Qt::AlignRight);
    tracerXText->position->setType(QCPItemPosition::ptAxisRectRatio);//位置类型（当前轴范围的比例）
    tracerXText->position->setCoords(0, 0.99); // 在plot中的位置
    tracerXText->position->setParentAnchorX(tracer->position);//X位置锚定到游标的X位置
    tracerXText->setText("no curves..");
    tracerXText->setFont(QFont(font().family(), 12));
    tracerXText->setPen(QPen(Qt::black));
    // tracerXText->setBackgroundColor(Qt::green);
    tracerXText->setPadding(QMargins(2,2,2,2));//边界宽度
    tracerXText->setVisible(false);
    //游标的Y值文本框
    tracerYText = new QCPItemText(this);
    tracerYText->setPositionAlignment(Qt::AlignTop|Qt::AlignLeft);
    tracerYText->position->setType(QCPItemPosition::ptAxisRectRatio);//位置类型（当前轴范围的比例）
    tracerYText->position->setCoords(0.01, 0); // 在plot中的位置
    tracerYText->setText("no curves..");
    tracerYText->position->setParentAnchorY(tracer->position);//Y位置锚定到游标的Y位置
    tracerYText->setFont(QFont(font().family(), 12));
    tracerYText->setPen(QPen(Qt::black));
    // tracerYText->setBackgroundColor(Qt::green);
    tracerYText->setPadding(QMargins(2,2,2,2));//边界宽度
    tracerYText->setVisible(false);

}
