
#include "gamewindow.h"

#include <QApplication>
#include <QStringList>

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);

	QStringList *images = new QStringList();
	images->append("game-assets/default.png");
	images->append("game-assets/alien.png");
	images->append("game-assets/bone.png");
	images->append("game-assets/dices.png");
	images->append("game-assets/donkey.png");
	images->append("game-assets/flower.png");
	images->append("game-assets/ghost.png");
	images->append("game-assets/helmet.png");
	images->append("game-assets/ingot.png");
	images->append("game-assets/mushroom-1.png");
	images->append("game-assets/mushroom-2.png");

	GameWindow *w = new GameWindow(images,8,0); // TODO change size
	w->show();

	return a.exec();
}
