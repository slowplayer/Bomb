#include "widget.h"
#include <QtWidgets>
#include <QDebug>
Widget::Widget(QWidget *parent)
    : QWidget(parent)
{
    maintime=new QTimeEdit(this);
    countbt=new QPushButton(tr("定时"));
    quitbt=new QPushButton(tr("退出"));

    mainlayout=new QVBoxLayout(this);
    btlayout=new QHBoxLayout;

    btlayout->addWidget(countbt);
    btlayout->addWidget(quitbt);
    mainlayout->addWidget(maintime);
    mainlayout->addLayout(btlayout);
    setLayout(mainlayout);

    maintime->setDisplayFormat("hh:mm:ss");
    maintime->setTime(QTime::currentTime());
    connect(countbt,SIGNAL(clicked()),this,SLOT(count()));
    connect(quitbt,SIGNAL(clicked()),qApp,SLOT(quit()));
}
void Widget::count()
{
    ctime=new QTime(QTime::currentTime());
    dtime=new QTime(maintime->time());
    h=dtime->hour()-ctime->hour();
    m=dtime->minute()-ctime->minute();
    s=dtime->second()-ctime->second();
    ms=dtime->msec()-ctime->msec();
    if(ms<0)
    {
        ms+=1000;
        s++;
    }
    if(s<0)
    {
        s+=60;
        m--;
    }
    if(m<0)
    {
        m+=60;
        h--;
    }
    if(h<0)
        h+=24;
    maintime->setReadOnly(true);
    maintime->setTime(QTime(h,m,s,ms));
    maintime->selectAll();
    timer=new QTimer;
    connect(timer,SIGNAL(timeout()),this,SLOT(work()));
    timer->start(1000);
}
void Widget::work()
{
    s--;
    if(s<0)
    {
        s+=60;
        m--;
        if(m<0)
        {
            m+=60;
            h--;
        }
    }
    maintime->setTime(QTime(h,m,s,0));
    if(!h&&!m&&!s)
    {
        timer->stop();
        qDebug()<<"hello2";
        p->start("Notepad.exe");
    }
}

