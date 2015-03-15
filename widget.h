#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QPushButton>
#include <QTimeEdit>
#include <QLayout>
#include <QProcess>
class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = 0);
private slots:
    void count();
    void work();
private:
    QPushButton *countbt;
    QPushButton *quitbt;
    QTimeEdit *maintime;
    QVBoxLayout *mainlayout;
    QHBoxLayout *btlayout;
    QTime *ctime;
    QTime *dtime;
    int h,m,s,ms;
    QTimer *timer;
    QProcess *p;
};

#endif // WIDGET_H
