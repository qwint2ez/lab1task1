#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QPainter>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::paintEvent(QPaintEvent *)
{

    QPainter painter;
    painter.begin(this);

    QRectF rectangle(250.0, 220.0, 380.0, 220.0);
    int startAngle = 180 * 16;
    int spanAngle = 180 * 16;

    painter.setBrush(QBrush(Qt::red, Qt::SolidPattern));
    painter.drawPie(rectangle, startAngle, spanAngle);


    painter.end();
}
