/*
 * QTAudioRenderer.cpp
 *****************************************************************************
 * Copyright (C) 2013, bitmovin Softwareentwicklung OG, All Rights Reserved
 *
 * Email: libdash-dev@vicky.bitmovin.net
 *
 * This source code and its use and distribution, is subject to the terms
 * and conditions of the applicable license agreement.
 *****************************************************************************/

#include "QTAudioRenderer.h"

using namespace sampleplayer::renderer;

QTAudioRenderer::QTAudioRenderer(QWidget *parent) :
                 QWidget        (parent),
                 parent         (parent),
                 audioOutput    (NULL),
                 output         (NULL)
{
    this->Init();
}
QTAudioRenderer::~QTAudioRenderer()
{
    delete this->audioOutput;
    this->audioOutput = NULL;
}

void                    QTAudioRenderer::SetAudioFormat (const QAudioFormat& format)
{
    /* NOT implemented YET */
}
const QAudioFormat&     QTAudioRenderer::AudioFormat    () const
{
    return this->format;
}
void                    QTAudioRenderer::StartPlayback  ()
{
    this->Reset();
}
void                    QTAudioRenderer::StopPlayback   ()
{
    if (!this->audioOutput)
        return;

    if (this->audioOutput->state() == QAudio::ActiveState)
        this->audioOutput->stop();

    delete this->audioOutput;
    this->audioOutput = NULL;
}
void                    QTAudioRenderer::WriteToBuffer  (const char *data, qint64 len)
{
    while (len > 0)
    {
        qint64 written = this->output->write(data, len);
        len -= written;
        data += written;
    }
}
void                    QTAudioRenderer::Init           ()
{
    this->deviceInfo  = QAudioDeviceInfo(QAudioDeviceInfo::defaultOutputDevice());

    this->format.setSampleRate(48000);
    this->format.setChannelCount(2);
    this->format.setSampleSize(16);
    this->format.setCodec("audio/pcm");
    this->format.setByteOrder(QAudioFormat::LittleEndian);
    this->format.setSampleType(QAudioFormat::SignedInt);

    if (!this->deviceInfo.isFormatSupported(this->format))
        format = this->deviceInfo.nearestFormat(this->format);
}
void                    QTAudioRenderer::Reset          ()
{
    this->audioOutput = new QAudioOutput(this->deviceInfo, this->format, this->parent);
    this->output = this->audioOutput->start();
}
