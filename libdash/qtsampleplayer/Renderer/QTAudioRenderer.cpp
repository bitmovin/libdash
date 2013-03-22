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
                 parent         (parent)
{
    this->Init();
}
QTAudioRenderer::~QTAudioRenderer()
{
    delete this->audioOutput;
    delete this->buffer;
}

void                    QTAudioRenderer::SetAudioFormat (const QAudioFormat& format)
{
    /* NOT implemented YET */
}
const QAudioFormat&     QTAudioRenderer::AudioFormat    () const
{
    return this->format;
}
void                    QTAudioRenderer::StartPlayback  () const
{
    this->audioOutput->start(this->buffer);
}
void                    QTAudioRenderer::StopPlayback   () const
{
    if (this->audioOutput->state() == QAudio::ActiveState)
        this->audioOutput->stop();

    this->buffer->close();
}
void                    QTAudioRenderer::WriteToBuffer  (const char *data, qint64 len)
{
    this->byteArray.append(data, len);
}
void                    QTAudioRenderer::Init           ()
{
    this->buffer      = new QBuffer(&byteArray);
    this->deviceInfo  = QAudioDeviceInfo(QAudioDeviceInfo::defaultOutputDevice());

    this->buffer->open(QIODevice::ReadWrite);

    this->format.setSampleRate(48000);
    this->format.setChannelCount(2);
    this->format.setSampleSize(16);
    this->format.setCodec("audio/pcm");
    this->format.setByteOrder(QAudioFormat::LittleEndian);
    this->format.setSampleType(QAudioFormat::SignedInt);

    if (!this->deviceInfo.isFormatSupported(this->format))
        format = this->deviceInfo.nearestFormat(this->format);

    this->audioOutput = new QAudioOutput(this->deviceInfo, this->format, this->parent);
}
