#ifndef GAMEWINDOW_H
#define GAMEWINDOW_H

#include <QMap>
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
    explicit GameWindow(QStringList *images,int size, QWidget *parent = 0);
	~GameWindow();
public slots:
    void clicked(QWidget*wid);
	void timeDown();
private:
	Ui::GameWindow *ui;
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

#endif // GAMEWINDOW_H
