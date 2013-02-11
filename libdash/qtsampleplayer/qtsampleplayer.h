#ifndef QTSAMPLEPLAYER_H
#define QTSAMPLEPLAYER_H

#include <QtWidgets/QMainWindow>
#include "ui_qtsampleplayer.h"

class QtSamplePlayer : public QMainWindow
{
	Q_OBJECT

public:
	QtSamplePlayer(QWidget *parent = 0);
	~QtSamplePlayer();

private:
	Ui::QtSamplePlayerClass ui;
};

#endif // QTSAMPLEPLAYER_H
