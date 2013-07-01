/*
 * MultimediaStream.cpp
 *****************************************************************************
 * Copyright (C) 2013, bitmovin Softwareentwicklung OG, All Rights Reserved
 *
 * Email: libdash-dev@vicky.bitmovin.net
 *
 * This source code and its use and distribution, is subject to the terms
 * and conditions of the applicable license agreement.
 *****************************************************************************/

#include "MultimediaStream.h"

using namespace sampleplayer::managers;
using namespace sampleplayer::decoder;
using namespace libdash::framework::adaptation;
using namespace libdash::framework::input;
using namespace libdash::framework::buffer;
using namespace dash::mpd;

MultimediaStream::MultimediaStream  (StreamType type, IMPD *mpd, uint32_t bufferSize, uint32_t frameBufferSize, uint32_t sampleBufferSize) :
                  type              (type),
                  segmentBufferSize (bufferSize),
                  frameBufferSize   (frameBufferSize),
                  sampleBufferSize  (sampleBufferSize),
                  dashManager       (NULL),
                  mpd               (mpd)
{
    this->Init();
}
MultimediaStream::~MultimediaStream ()
{
    this->Stop();
    delete this->dashManager;

    this->frameBuffer->Clear();
    delete this->frameBuffer;

    this->sampleBuffer->Clear();
    delete this->sampleBuffer;
}

uint32_t    MultimediaStream::GetPosition               ()
{
    return this->dashManager->GetPosition();
}
void        MultimediaStream::SetPosition               (uint32_t segmentNumber)
{
    this->dashManager->SetPosition(segmentNumber);
}
void        MultimediaStream::SetPositionInMsec         (uint32_t milliSecs)
{
    this->dashManager->SetPositionInMsec(milliSecs);
}
void        MultimediaStream::Init                      ()
{
    this->dashManager   = new DASHManager(this->segmentBufferSize, this, this->mpd);
    this->frameBuffer   = new Buffer<QImage>(this->frameBufferSize, libdash::framework::buffer::VIDEO);
    this->sampleBuffer  = new Buffer<AudioChunk>(this->sampleBufferSize, libdash::framework::buffer::AUDIO);

    this->frameBuffer->AttachObserver(this);
    this->sampleBuffer->AttachObserver(this);
}
bool        MultimediaStream::Start                     ()
{
    if(!this->StartDownload())
        return false;

    return true;
}
bool        MultimediaStream::StartDownload             ()
{
    if(!dashManager->Start())
        return false;

    return true;
}
void        MultimediaStream::Stop                      ()
{
    this->frameBuffer->SetEOS(true);
    this->sampleBuffer->SetEOS(true);

    this->StopDownload();

    this->frameBuffer->Clear();
    this->sampleBuffer->Clear();
}
void        MultimediaStream::StopDownload              ()
{
    this->dashManager->Stop();
}
void        MultimediaStream::Clear                     ()
{
    this->dashManager->Clear();
}
void        MultimediaStream::AddFrame                  (QImage *frame)
{
    this->frameBuffer->PushBack(frame);
}
QImage*     MultimediaStream::GetFrame                  ()
{
    return this->frameBuffer->GetFront();
}
void        MultimediaStream::AddSamples                (AudioChunk *samples)
{
    this->sampleBuffer->PushBack(samples);
}
AudioChunk* MultimediaStream::GetSamples                ()
{
    return this->sampleBuffer->GetFront();
}
void        MultimediaStream::AttachStreamObserver      (IStreamObserver *observer)
{
    this->observers.push_back(observer);
}
void        MultimediaStream::SetRepresentation         (IPeriod *period, IAdaptationSet *adaptationSet, IRepresentation *representation)
{
    this->dashManager->SetRepresentation(period, adaptationSet, representation);
}
void        MultimediaStream::EnqueueRepresentation     (IPeriod *period, IAdaptationSet *adaptationSet, IRepresentation *representation)
{
    this->dashManager->EnqueueRepresentation(period, adaptationSet, representation);
}
void        MultimediaStream::SetAdaptationLogic        (libdash::framework::adaptation::IAdaptationLogic *logic)
{
    this->logic = logic;
}
void        MultimediaStream::OnSegmentBufferStateChanged   (uint32_t fillstateInPercent)
{
    for (size_t i = 0; i < observers.size(); i++)
        this->observers.at(i)->OnSegmentBufferStateChanged(this->type, fillstateInPercent);
}
void        MultimediaStream::OnBufferStateChanged          (BufferType type, uint32_t fillstateInPercent)
{
    switch(type)
    {
        case libdash::framework::buffer::AUDIO:
            for (size_t i = 0; i < observers.size(); i++)
                this->observers.at(i)->OnAudioBufferStateChanged(fillstateInPercent);
            break;
        case libdash::framework::buffer::VIDEO:
            for (size_t i = 0; i < observers.size(); i++)
                this->observers.at(i)->OnVideoBufferStateChanged(fillstateInPercent);
        default:
            break;
    }
}
