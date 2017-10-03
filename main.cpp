
#include "gamewindow.h"

#include <typeinfo>
#include <QApplication>
#include <QStringList>
#include <QDebug>
#include <QString>

int main(int argc, char *argv[])
{
	Q_INIT_RESOURCE(assets);

	QApplication a(argc, argv);

	GameWindow *w = new GameWindow();
	w->show();

	return a.exec();
}
