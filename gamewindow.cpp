#include "gamewindow.h"
#include "matchinggame.h"
#include "tictocgame.h"
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
#include <QTimer>
#include <QLabel>
#include <QMessageBox>

GameWindow::GameWindow(QWidget *parent):
	QTabWidget(parent),
	ui(new Ui::GameWindow)
{
//	ui->setupUi(this);
	QStringList *images = new QStringList();
	images->append("game-assets/default.png");
	images->append("game-assets/1337491 - game go open play pokeba.png");
	images->append("game-assets/1337492 - game go mobile phone pla.png");
	images->append("game-assets/1337493 - game go heal paralyz pla.png");
	images->append("game-assets/1337494 - game go mew play pokemon.png");
	images->append("game-assets/1337495 - game go moltres play pok.png");
	images->append("game-assets/1337496 - game go pidgey play poke.png");
	images->append("game-assets/1337497 - game go pikachu play pok.png");
	images->append("game-assets/1337498 - game go play poke pokemo.png");
	images->append("game-assets/1337499 - game go play pokemon zub.png");
	images->append("game-assets/1337500 - game go play pokemon zap.png");

	MatchingGame *mg = new MatchingGame(this);
	mg->setGeometry(0,0,600,480);
	mg->start(images,8);
//	TicTocGame *ttg = new TicTocGame(this);

	this->setGeometry(0,0,600,480);

}


GameWindow::~GameWindow()
{
	delete ui;
}
