/*
 * DecodingThread.cpp
 *****************************************************************************
 * Copyright (C) 2013, bitmovin Softwareentwicklung OG, All Rights Reserved
 *
 * Email: libdash-dev@vicky.bitmovin.net
 *
 * This source code and its use and distribution, is subject to the terms
 * and conditions of the applicable license agreement.
 *****************************************************************************/

#include "DecodingThread.h"

using namespace sampleplayer::managers;
using namespace sampleplayer::decoder;
using namespace libdash::framework::input;

DecodingThread::DecodingThread  (IDataReceiver *receiver, IAudioObserver *audioObserver, IVideoObserver *videoObserver) : 
                receiver        (receiver),
                audioObserver   (audioObserver),
                videoObserver   (videoObserver)
{
    this->decoder = new LibavDecoder(this->receiver);

    decoder->AttachVideoObserver(this->videoObserver);
    decoder->AttachAudioObserver(this->audioObserver);
    decoder->SetFrameRate(24);
}
DecodingThread::~DecodingThread ()
{
    this->Stop();
    delete(this->decoder);
}

bool DecodingThread::Start  ()
{
    if(!decoder->Init())
        return false;

    this->run = true;
    this->threadHandle = CreateThreadPortable (Decode, this);

    if(this->threadHandle == NULL)
        return false;

    return true;
}
void DecodingThread::Stop   ()
{
    this->run = false;
    WaitForSingleObject(this->threadHandle, INFINITE);
}

void* DecodingThread::Decode (void *data)
{
    DecodingThread  *decodingThread = (DecodingThread *) data;

    bool eos = false;

    while(decodingThread->decoder->Decode() && decodingThread->run);

    decodingThread->decoder->Stop();

    return NULL;
}
