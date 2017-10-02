
#include "gamewindow.h"

#include <QApplication>
#include <QStringList>

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);

	GameWindow *w = new GameWindow();
	w->show();

	return a.exec();
}
