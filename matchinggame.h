#ifndef MATHINGGAME_H
#define MATHINGGAME_H

#include <QWidget>
#include <QMap>
#include <QSignalMapper>
#include <QLabel>
#include <QPushButton>
#include <QTimer>
#include <QStringList>

namespace Ui {
class MatchingGame;
}

class MatchingGame : public QWidget
{
	Q_OBJECT
public:
	explicit MatchingGame(QWidget *parent = 0);
	~MatchingGame();
public slots:
	void start(QStringList *img,int size);
	void clicked(QWidget*wid);
	void timeDown();
private:
	QStringList *images;
	QSignalMapper *signalMapper;
	QMap <QPushButton *, int> map;
	QLabel *label;
	QTimer *timer;
	QPushButton *bt1;
	QPushButton *bt2;
	int cellCount;
	int time;
	int openedCell;
};

#endif // MATHINGGAME_H
