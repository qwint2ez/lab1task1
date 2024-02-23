#ifndef FLAG_H
#define FLAG_H

#include <QMainWindow>
#include <QWidget>

class MovingRectangle : public QWidget
{
    Q_OBJECT
public:
    MovingRectangle(QWidget *parent = nullptr) : QWidget(parent) {}
};

class Flag : public MovingRectangle
{
    Q_OBJECT
public:
    Flag(QWidget *parent = nullptr);
protected:
    void paintEvent(QPaintEvent *) override;
};



#endif // FLAG_H
