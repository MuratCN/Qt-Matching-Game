#include "gamewindow.h"
#include "ui_gamewindow.h"
#include <stdlib.h>
#include <time.h>
#include <QStringList>
#include <QPushButton>
#include <QSignalMapper>
#include <QGridLayout>
#include <QList>
#include <QDebug>
#include <QTime>
#include <QLabel>
#include <QTimer>
#include <QMessageBox>

GameWindow::GameWindow(const QStringList *images,int size, QWidget *parent):
    QTabWidget(parent),
    ui(new Ui::GameWindow)
{
    //    qDebug() << QTime::currentTime().msec();
    srand(QTime::currentTime().msec());
    //	qDebug() << QTime(0, 0, 0).secsTo(QTime::currentTime());
    ui->setupUi(this);

    int selected=0;
    QPushButton *tmp=0;
    label = new QLabel();

    signalMapper = new QSignalMapper(this);
    cellCount = size;
    openedCell = 0;
    bt1 = 0;
    bt2 = 0;
    time = 28;


    QGridLayout *gridLayout = new QGridLayout;
    QList<QPushButton*> *buttonlist = new QList<QPushButton*>() ;
    for (int i = 0, n = cellCount/2; i < n; i++) {
        QPushButton *button1 = new QPushButton();
        QPushButton *button2 = new QPushButton();
        button1->setStyleSheet(QString("border-image: url(%1);height: 100;width:100").arg(images->at(0)));
        button2->setStyleSheet(QString("border-image: url(%1);height: 100;width:100").arg(images->at(0)));
        button1->setText(QString::number(i));
        button2->setText(QString::number(i));
        connect(button1, SIGNAL(pressed()), signalMapper, SLOT(map())); // QSignalMapper map
        connect(button2, SIGNAL(pressed()), signalMapper, SLOT(map())); // QSignalMapper map
        signalMapper->setMapping(button1, i);
        signalMapper->setMapping(button2, i);
        buttonlist->append(button1);
        buttonlist->append(button2);
    }


    for(int i = 0, n = buttonlist->size(); i < n; i++) {
        selected = rand()%n;
        tmp = buttonlist->at(selected);
        buttonlist->replace(selected, buttonlist->at(i));
        buttonlist->replace(i, tmp);
    }
    label->setText("Time:"+QString::number(time));
    gridLayout->addWidget(label,0,0,1,3);
    for(int i = 0; i < buttonlist->size(); i++)
        gridLayout->addWidget(buttonlist->at(i), (i / 3)+1, i % 3);//3x3lük

    connect(signalMapper, SIGNAL(mapped(int)), this, SLOT(clicked(int)));

    timer = new QTimer;
    connect(timer,SIGNAL(timeout()),this,SLOT(timeDown()));
    timer->start(1000);
    setLayout(gridLayout);

}

void GameWindow::clicked(int value)
{
//    qDebug()<<QString::number(value);
    openedCell++;
    qDebug()<<QString::number(openedCell);

    if(openedCell%2){ //tek
        if(bt1 && bt2)
        {
            //close both button
            qDebug()<<QString("ikisi de kapandı");
            bt1 = 0;
            bt2 = 0;
        }
        bt1 = (QPushButton*)sender();
        prev_value = value;
        qDebug()<<QString("Teki açıldı");
    }
    else { //çift

        qDebug()<<QString("ikinci buton açıldı kontrol edildi");
        bt2 = (QPushButton*)sender();
        if(prev_value != value){
            //eğer iki değer eşit değilse açılan sayısını 2 azalt
            openedCell -= 2;

        }else{
            bt1->setText(QString("(+)"));
            bt2->setText(QString("(+)"));
            bt1 = 0;
            bt2 = 0;
        }
    }
    if(openedCell==cellCount)
    {
        timer->stop();//Eğer süre bittiyse bunu kontrol etmeyecek
        delete timer;
        QMessageBox::information(this,"Tebrikler","Kazandınız.");
    }


}

void GameWindow::timeDown()
{
    if(time>0)
    {
        label->setText(QString("Time:")+QString::number(time));
        time--;
    }
    else
    {
        timer->stop();
        delete timer;
        label->setText(QString("Time:")+QString::number(0));
        QMessageBox::information(this,"Oyun Sonu","Süre doldu!");
    }


}


GameWindow::~GameWindow()
{
    delete ui;
}
