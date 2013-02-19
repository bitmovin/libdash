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
#include "libdash.h"


namespace sampleplayer
{
    class IDASHPlayerGuiObserver;

    class QtSamplePlayerGui : public QMainWindow
    {
        Q_OBJECT

        public:
            QtSamplePlayerGui           (QWidget *parent = 0);
            virtual ~QtSamplePlayerGui  ();

            void                                    SetGuiFields            (dash::mpd::IMPD* mpd);
            virtual void                            UpdateKeyValue          (const std::string& key, const std::string& value);
            virtual void                            RemoveAllKeyValues      ();
            virtual void                            AddWidgetObserver       (IDASHPlayerGuiObserver* observer);
            virtual void                            RemoveWidgetObserver    (IDASHPlayerGuiObserver* observer);
            virtual void                            SetStatusBar            (const std::string& text);
            virtual std::string                     GetUrl                  ();
            virtual bool                            GetAutomatic            ();
            sampleplayer::renderer::QTGLRenderer*   GetVideoElement         ();
      
        private slots:
            void on_cb_video_adaption_currentIndexChanged       (const QString &arg1);
            void on_cb_video_representation_currentIndexChanged (const QString &arg1);
            void on_cb_audio_adaption_currentIndexChanged       (const QString &arg1);
            void on_cb_audio_representation_currentIndexChanged (const QString &arg1);
            void on_button_start_clicked                        ();
            void on_button_stop_clicked                         ();
            void on_ckb_automatic_toggled                       (bool checked);


        public slots:
            virtual void    SetBufferFillState      (int percentage);

        private:
            std::map<std::string, std::string>                  keyValues;
            std::map<std::string, int>                          keyIndices;
            std::map<std::string, std::vector<std::string> >    video;
            std::map<std::string, std::vector<std::string> >    audio;

            Ui::QtSamplePlayerClass                 *ui;
            std::vector<IDASHPlayerGuiObserver*>    observer;
            dash::mpd::IMPD                         *mpd;

            void settingsChanged        ();
            void lockUI                 ();
            void unlockUI               ();
            void updateRepresentation   (dash::mpd::IAdaptationSet* adaption, QComboBox* cb);
    };
}

#endif // QTSAMPLEPLAYER_H
