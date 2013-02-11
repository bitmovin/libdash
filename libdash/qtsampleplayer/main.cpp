#include "qtsampleplayer.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	QtSamplePlayer w;
	w.show();
	return a.exec();
}
