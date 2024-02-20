#ifndef FLAG_H
#define FLAG_H

#include <QMainWindow>
#include <QWidget>

class Flag : public QWidget
{
    Q_OBJECT
public:
    Flag(QWidget *parent = nullptr);
protected:
    void paintEvent(QPaintEvent *) override;
};


#endif // FLAG_H
