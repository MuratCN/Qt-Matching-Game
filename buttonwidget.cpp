#include "buttonwidget.h"
#include <QStringList>
#include <QPushButton>
#include <QSignalMapper>
#include <QGridLayout>
#include <QDebug>


ButtonWidget::ButtonWidget(const QStringList *images,int size, QWidget *parent)
	: QWidget(parent)
{
	signalMapper = new QSignalMapper(this);
	QGridLayout *gridLayout = new QGridLayout;
	for (int i = 0; i < size; i++) {
		QPushButton *button = new QPushButton();
		button->setStyleSheet(QString("border-image: url(%1);height: 100;width:100").arg("defaultImage"));
		connect(button, SIGNAL(pressed()), signalMapper, SLOT(map())); // QSignalMapper map
		signalMapper->setMapping(button, i);
		gridLayout->addWidget(button, i / 3, i % 3);//3x3lük
	}

	connect(signalMapper, SIGNAL(mapped(int)),
			this, SIGNAL(clicked(int)));

	setLayout(gridLayout);


}


void clicked(int value){
	qDebug()<<QString::number(value);
}
