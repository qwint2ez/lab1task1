#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QWidget>

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class Flag : public QWidget
{
    Q_OBJECT
public:
    Flag(QWidget *parent = nullptr);
protected:
    void paintEvent(QPaintEvent *) override;
};

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
    Flag *flag;
    bool isFlagUp;

protected:
    void paintEvent(QPaintEvent*) override;
private slots:
    void on_pushButton_clicked();
};

#endif // MAINWINDOW_H
