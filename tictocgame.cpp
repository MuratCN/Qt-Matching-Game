#include "tictocgame.h"
#include "ui_tictocgame.h"
#include <QList>
#include <QGridLayout>
#include <QPushButton>
#include <QDebug>

TicTocGame::TicTocGame(QWidget *parent) :
	QWidget(parent),
	ui(new Ui::TicTocGame)
{
	ui->setupUi(this);


//		qmap.insert(0,{{1,2},{3,6},{4,8}});
//		qmap.insert(1,{{0,2},{4,7}});
//		qmap.insert(2,{{0,1},{4,6},{5,8}});
//		qmap.insert(3,{{0,6},{4,5}});
//		qmap.insert(4,{{0,8},{1,7},{2,6},{3,5}});
//		qmap.insert(5,{{2,8},{3,4}});
//		qmap.insert(6,{{0,3},{2,4},{7,8}});
//		qmap.insert(7,{{1,4},{6,8}});
//		qmap.insert(8,{{0,4},{2,5},{6,7}});


//	qmap.insert(0,{1,2,3,6,4,8});
//	qmap.insert(1,{0,2,4,7});
//	qmap.insert(2,{0,1,4,6,5,8});
//	qmap.insert(3,{0,6,4,5});
//	qmap.insert(4,{0,8,1,7,2,6,3,5});
//	qmap.insert(5,{2,8,3,4});
//	qmap.insert(6,{0,3,2,4,7,8});
//	qmap.insert(7,{1,4,6,8});
//	qmap.insert(8,{0,4,2,5,6,7});

//	QList<int*> *l1 = new QList<int*>();
//	l1->append({1,3});

	for (int i = 0; i < 9; ++i) {
		cells[i]=' ';
	}

	//	int row = 3;
	int col = 3;
	clickCount = 0;

	QGridLayout *gridLayout = new QGridLayout;
	buttonlist = new QList<QPushButton*>();
	smapper = new QSignalMapper(this);


	for (int i = 0; i < 9; ++i) {
		QPushButton *button = new QPushButton();
		button->setStyleSheet(QString("height: 100;width:100"));
		//		button->setFixedSize(100,100);
		button->setText(QString::number(i));
		connect(button,SIGNAL(pressed()),smapper,SLOT(map()));
		smapper->setMapping(button,i);
		buttonlist->append(button);
	}

	for (int i = 0, n=buttonlist->size(); i < n; ++i){
		gridLayout->addWidget(buttonlist->at(i),i/col,i%col);
	}

	connect(smapper, SIGNAL(mapped(int)), this, SLOT(click(int)));

	setLayout(gridLayout);
}

void TicTocGame::click(int index){
//	qDebug()<<QString::number(index);
//	qDebug()<<buttonlist->at(index);
	qDebug()<<QString::number(clickCount);
	if(cells[index]!=' ')
		return;
	clickCount++;
	if(clickCount%2)//tek
	{
		cells[index] = 'x';
	} else {
		cells[index] = 'o';
	}
//	int r[][]=qmap[index];
	// kontrol

	buttonlist->at(index)->setText(QString(cells[index]));

}

TicTocGame::~TicTocGame()
{
	delete ui;
}
