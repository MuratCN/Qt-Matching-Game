
#include "gamewindow.h"

#include <QApplication>
#include <QStringList>

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);

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

    GameWindow *w = new GameWindow(images,10,0); // TODO change size
	w->show();

	return a.exec();
}
