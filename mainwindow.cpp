#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QPainter>
#include <QPropertyAnimation>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    flag = new Flag(this);
    flag->move(445, 220);
    isFlagUp = false;
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::paintEvent(QPaintEvent *)
{
    QPainter painter(this);
    painter.setRenderHint(QPainter::Antialiasing);
    painter.setBrush(QBrush(QColorConstants::Svg::turquoise, Qt::SolidPattern));
    painter.drawRect(this->rect());

    QRectF rectangle(250.0, 220.0, 380.0, 200.0);
    int startAngle = 180 * 16;
    int spanAngle = 180 * 16;

    painter.setBrush(QBrush(QColorConstants::Svg::brown, Qt::SolidPattern));
    painter.drawPie(rectangle, startAngle, spanAngle);

    QPen pen(Qt::black, 10);
    painter.setPen(pen);
    painter.drawLine(440, 315, 440, 120);

    painter.end();
}

void MainWindow::on_pushButton_clicked()
{
    QPropertyAnimation *animation = new QPropertyAnimation(flag, "pos");
    animation->setDuration(1000);
    animation->setStartValue(flag->pos());
    if (!isFlagUp) {
        animation->setEndValue(QPoint(flag->x(), flag->y() - 100));
        isFlagUp = true;
    } else {
        animation->setEndValue(QPoint(flag->x(), flag->y() + 100));
        isFlagUp = false;
    }
    animation->start(QAbstractAnimation::DeleteWhenStopped);
}
