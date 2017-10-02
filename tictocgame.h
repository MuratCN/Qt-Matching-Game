#ifndef TICTOCGAME_H
#define TICTOCGAME_H

#include <QWidget>
#include <QSignalMapper>
#include <QMap>
#include <QPushButton>
#include <QList>

namespace Ui {
class TicTocGame;
}

class TicTocGame : public QWidget
{
	Q_OBJECT

public:
	explicit TicTocGame(QWidget *parent = 0);
	~TicTocGame();
public slots:
	void click(int);
private:
	Ui::TicTocGame *ui;
	QList<QPushButton*> *buttonlist;
	QSignalMapper *smapper;
	QMap<int,int*> qmap;
	char cells[9];
	short clickCount;

};

#endif // TICTOCGAME_H
