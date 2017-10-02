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
	explicit GameWindow(QWidget *parent = 0);
	~GameWindow();
public slots:
private:
	Ui::GameWindow *ui;
};

#endif // GAMEWINDOW_H
