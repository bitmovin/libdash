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
}
DecodingThread::~DecodingThread ()
{
}

bool DecodingThread::Start  ()
{
    this->threadHandle = CreateThreadPortable (Decode, this);

    if(this->threadHandle == NULL)
        return false;

    return false;
}
void DecodingThread::Stop   ()
{
    //TODO
}

void* DecodingThread::Decode (void *data)
{
    DecodingThread  *decodingThread = (DecodingThread *) data;
    LibavDecoder    *decoder        = new LibavDecoder(decodingThread->receiver); // TODO move to stack after first successfull decoding

    decoder->AttachVideoObserver(decodingThread->videoObserver);
    decoder->SetFrameRate(24);
    decoder->Init();
    
    bool eos = false;

    while(!eos)
    {
        eos = !decoder->Decode();
    }

    decoder->Stop();

    delete decoder;

    return NULL;
}
