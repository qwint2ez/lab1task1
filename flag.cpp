#include "flag.h"
#include <QPainter>
#include <QPropertyAnimation>

Flag::Flag(QWidget *parent) : QWidget(parent)
{
    setFixedSize(100, 100);
}

void Flag::paintEvent(QPaintEvent *)
{
    QPainter painter(this);
    painter.setRenderHint(QPainter::Antialiasing);

    int flagWidth = width();
    int flagHeight = flagWidth / 3;
    QRect flagRect(0, 0, flagWidth, flagHeight);

    painter.fillRect(flagRect, Qt::white);

    flagRect.translate(0, flagHeight);
    painter.fillRect(flagRect, QColorConstants::Svg::dodgerblue);

    flagRect.translate(0, flagHeight);
    painter.fillRect(flagRect, Qt::red);
}
