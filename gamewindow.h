#ifndef GAMEWINDOW_H
#define GAMEWINDOW_H

#include <QTabWidget>
#include <QSignalMapper>
#include <QLabel>
#include <QTimer>
#include <QPushButton>


namespace Ui {
class GameWindow;
}

class GameWindow : public QTabWidget
{
	Q_OBJECT

public:
	explicit GameWindow(const QStringList *images,int size, QWidget *parent = 0);
	~GameWindow();
public slots:
	void clicked(int value);
	void timeDown();
private:
	Ui::GameWindow *ui;
	QSignalMapper *signalMapper;
	QLabel *label;
	QTimer *timer;
	QPushButton *bt1;
	QPushButton *bt2;
	int cellCount;
	int time;
	int openedCell;
    int prev_value; // previous value
};

#endif // GAMEWINDOW_H
