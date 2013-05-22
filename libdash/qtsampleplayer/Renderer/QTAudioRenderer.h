/*
 * QTAudioRenderer.h
 *****************************************************************************
 * Copyright (C) 2013, bitmovin Softwareentwicklung OG, All Rights Reserved
 *
 * Email: libdash-dev@vicky.bitmovin.net
 *
 * This source code and its use and distribution, is subject to the terms
 * and conditions of the applicable license agreement.
 *****************************************************************************/

#ifndef QTAUDIORENDERER_H_
#define QTAUDIORENDERER_H_

#include <QtMultimedia/qaudiooutput.h>
#include <QtMultimedia/qaudioformat.h>
#include <qbuffer.h>
#include <qwidget.h>
#include <QtMultimedia/qaudiodeviceinfo.h>

namespace sampleplayer
{
    namespace renderer
    {
        class QTAudioRenderer : public QWidget
        {
            Q_OBJECT

            public:
                QTAudioRenderer            (QWidget *parent = NULL);
                virtual ~QTAudioRenderer   ();

                void                    SetAudioFormat  (const QAudioFormat& format);
                const QAudioFormat&     AudioFormat     () const;
                void                    StartPlayback   ();
                void                    StopPlayback    ();
                void                    WriteToBuffer   (const char *data, qint64 len);

            private:
                QAudioOutput        *audioOutput;
                QAudioFormat        format;
                QAudioDeviceInfo    deviceInfo;
                QObject             *parent;
                QIODevice           *output;

                void    Init();
                void    Reset();
        };
    }
}

#endif /* QTAUDIORENDERER_H_ */
