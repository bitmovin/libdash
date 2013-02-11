/*
 * qtsampleplayer.h
 *****************************************************************************
 * Copyright (C) 2012, bitmovin Softwareentwicklung OG, All Rights Reserved
 *
 * Email: libdash-dev@vicky.bitmovin.net
 *
 * This source code and its use and distribution, is subject to the terms
 * and conditions of the applicable license agreement.
 *****************************************************************************/

#ifndef QTSAMPLEPLAYER_H
#define QTSAMPLEPLAYER_H

#include <QtMultimedia/qmediaplayer.h>
#include <QtMultimediaWidgets/qvideowidget.h>
#include <QtGui/QMovie>
#include <QtWidgets/QMainWindow>
#include "ui_qtsampleplayer.h"

namespace dash {
	namespace sampleplayer {

		class IDASHPlayerGuiObserver;

		class QtSamplePlayerGui : public QMainWindow
		{
			Q_OBJECT

		public:
			QtSamplePlayerGui(QWidget *parent = 0);
			~QtSamplePlayerGui();

			void setGuiFields(std::map<std::string, std::vector<std::string> > video, std::map<std::string, std::vector<std::string> > audio);

			virtual void updateKeyValue(const std::string& key, const std::string& value);
			virtual void removeAllKeyValues();

			virtual void setBufferFillState(int percentage);

			virtual void addWidgetObserver(IDASHPlayerGuiObserver* observer);
			virtual void removeWidgetObserver(IDASHPlayerGuiObserver* observer);

			virtual void setStatusBar(const std::string& text);
    
		private slots:
			void on_cb_video_adaption_currentIndexChanged(const QString &arg1);

			void on_cb_video_representation_currentIndexChanged(const QString &arg1);

			void on_cb_audio_adaption_currentIndexChanged(const QString &arg1);

			void on_cb_audio_representation_currentIndexChanged(const QString &arg1);

			void on_lineEdit_returnPressed();

		private:
				std::map<std::string, std::string> keyValues;
				std::map<std::string, int> keyIndices;

				std::map<std::string, std::vector<std::string> > video;
				std::map<std::string, std::vector<std::string> > audio;

				Ui::QtSamplePlayerClass* ui;
				QVideoWidget* videoWidget;
				QMediaPlayer player;

				std::vector<IDASHPlayerGuiObserver*> observer;

				void settingsChanged();
				void lockUI();
				void unlockUI();
		};

	}
}

#endif // QTSAMPLEPLAYER_H
