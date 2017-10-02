#include "matchinggame.h"
#include <stdlib.h>
#include <time.h>
#include <QStringList>
#include <QPushButton>
#include <QSignalMapper>
#include <QGridLayout>
#include <QList>
#include <QDebug>
#include <QTime>
#include <QTimer>
#include <QLabel>
#include <QMessageBox>

MatchingGame::MatchingGame(QWidget *parent):
	QWidget(parent){
}

void MatchingGame::start(QStringList *img,int size)
{
	images = img;
	//    qDebug() << QTime::currentTime().msec();
	srand(QTime::currentTime().msec());
	//	qDebug() << QTime(0, 0, 0).secsTo(QTime::currentTime());

	int selected=0;
	QPushButton *tmp=0;
	label = new QLabel();

	signalMapper = new QSignalMapper(this);
	cellCount = size;
	openedCell = 0;
	bt1 = 0;
	bt2 = 0;
	time = 18;


	QGridLayout *gridLayout = new QGridLayout;
	QList<QPushButton*> *buttonlist = new QList<QPushButton*>() ;
	for (int i = 0, n = cellCount/2; i < n; i++) {
		QPushButton *button1 = new QPushButton();
		QPushButton *button2 = new QPushButton();
		button1->setStyleSheet(QString("border-image: url(%1);height: 100;width:100").arg(images->at(0)));
		button2->setStyleSheet(QString("border-image: url(%1);height: 100;width:100").arg(images->at(0)));
		//        button1->setProperty("image",QString("url(%1)").arg(images->at(0)));

		//        button1->setText(QString::number(i));
		//        button2->setText(QString::number(i));


		connect(button1, SIGNAL(clicked()), signalMapper, SLOT(map())); // QSignalMapper map
		connect(button2, SIGNAL(clicked()), signalMapper, SLOT(map())); // QSignalMapper map

		map.insert(button1, i+1);
		map.insert(button2, i+1);
		signalMapper->setMapping(button1, button1);
		signalMapper->setMapping(button2, button2);
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
	label->setGeometry(0,0,200,10);
	gridLayout->addWidget(label,0,0,1,3);
	for(int i = 0; i < buttonlist->size(); i++)
		gridLayout->addWidget(buttonlist->at(i), (i / 3)+1, i % 3);//3x3lük

	connect(signalMapper, SIGNAL(mapped(QWidget*)), this, SLOT(clicked(QWidget*)));

	timer = new QTimer;
	connect(timer,SIGNAL(timeout()),this,SLOT(timeDown()));
	timer->start(1000);

	timer2 = new QTimer();
	connect(timer2,SIGNAL(timeout()),this,SLOT(closeCells()));

	setLayout(gridLayout);
}


void MatchingGame::clicked(QWidget *wid)
{
	QPushButton *button = (QPushButton *)wid;
	if(bt1 == button && !bt2) {
		return;
	}
	openedCell++;
	qDebug()<<QString::number(openedCell);
	if(openedCell%2){ //tek
//		if(bt1 && bt2) {
//			bt1->setStyleSheet(QString("border-image: url(%1);height: 100;width:100").arg(images->at(0)));
//			bt2->setStyleSheet(QString("border-image: url(%1);height: 100;width:100").arg(images->at(0)));
//			bt1 = 0;
//			bt2 = 0;
//		}
		bt1 = button;
		bt1->setStyleSheet(QString("border-image: url(%1);height: 100;width:100").arg(images->at(map[bt1])));
	}
	else {
		bt2 = button;
		bt2->setStyleSheet(QString("border-image: url(%1);height: 100;width:100").arg(images->at(map[bt2])));
		if(map[bt1] !=  map[bt2]){
			openedCell -= 2;
			timer2->start(500);

		}else{
			bt1 = 0;
			bt2 = 0;
		}
	}
	if(openedCell==cellCount)
	{
		timer->stop();
		delete timer;
		QMessageBox::information(this,"Tebrikler","Kazandınız.");
		this->setEnabled(false);
		// TODO süre bittiğinde kontrol ettirme
	}


}


void MatchingGame::timeDown()
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
		//TODO pasif yap
		this->setEnabled(false);
	}


}

void MatchingGame::closeCells(){
	timer2->stop();
	bt1->setStyleSheet(QString("border-image: url(%1);height: 100;width:100").arg(images->at(0)));
	bt2->setStyleSheet(QString("border-image: url(%1);height: 100;width:100").arg(images->at(0)));
}


MatchingGame::~MatchingGame()
{
	delete this;
}

