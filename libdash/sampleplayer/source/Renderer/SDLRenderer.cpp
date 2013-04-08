/*
 * SDLRenderer.cpp
 *****************************************************************************
 * Copyright (C) 2012, bitmovin Softwareentwicklung OG, All Rights Reserved
 *
 * Email: libdash-dev@vicky.bitmovin.net
 *
 * This source code and its use and distribution, is subject to the terms
 * and conditions of the applicable license agreement.
 *****************************************************************************/

#include "SDLRenderer.h"

using namespace sampleplayer::renderer;
using namespace sampleplayer::buffer;

SDLRenderer::SDLRenderer    (AVFrameBuffer* frameBuffer) :
             frameBuffer    (frameBuffer),
             bmp            (NULL),
             screen         (NULL),
             imgConvertCtx  (NULL),
             isInit         (false),
             quitKeyPressed (false),
             run            (false)
{
}
SDLRenderer::~SDLRenderer   ()
{
}

bool    SDLRenderer::Start                  ()
{
    this->run = true;

    this->threadHandle = CreateThreadPortable (Render, this);

    if(this->threadHandle == NULL)
        return false;

    return true;
}
void    SDLRenderer::Stop   ()
{
    this->run = false;
    WaitForSingleObject(this->threadHandle, INFINITE);
}
bool    SDLRenderer::init                   (int width, int height)
{
    this->screen = SDL_SetVideoMode(width, height, 0, 0);

    if(!screen)
        return false;

    this->bmp = SDL_CreateYUVOverlay(width, height, SDL_YV12_OVERLAY, this->screen);
    
    return true;
}
bool    SDLRenderer::processEvents          ()
{
    SDL_Event sdlEvent;
    while(SDL_PollEvent(&sdlEvent))
    {
        switch(sdlEvent.type)
        {
            case SDL_KEYDOWN:
                if(sdlEvent.key.keysym.sym == SDLK_ESCAPE)
                    this->quitKeyPressed = true;
                break;
            case SDL_QUIT: this->quitKeyPressed = true; break;
        }
    }

    return true;
}
bool    SDLRenderer::isQuitKeyPressed       ()
{
    return this->quitKeyPressed;
}
bool    SDLRenderer::DisplayFrame           (AVFrame *frame)
{
    if(!this->isInit)
        this->isInit = this->init(frame->width, frame->height);

    SDL_LockYUVOverlay(bmp);

    AVPicture pict;
    pict.data[0] = bmp->pixels[0];
    pict.data[1] = bmp->pixels[2];
    pict.data[2] = bmp->pixels[1];

    pict.linesize[0] = bmp->pitches[0];
    pict.linesize[1] = bmp->pitches[2];
    pict.linesize[2] = bmp->pitches[1];

    // Convert the image into YUV format that SDL uses
    if(imgConvertCtx == NULL)
    {
        int w = frame->width;
        int h = frame->height;

        imgConvertCtx = sws_getContext(frame->width, frame->height, (PixelFormat)frame->format, w, h, PIX_FMT_YUV420P, SWS_BICUBIC, NULL, NULL, NULL);

        if(imgConvertCtx == NULL)
        {
            fprintf(stderr, "Cannot initialize the conversion context!\n");
            return false;
        }
    }

    sws_scale(imgConvertCtx, frame->data, frame->linesize, 0, frame->height, pict.data, pict.linesize);

    SDL_UnlockYUVOverlay(bmp);

    rect.x = 0;
    rect.y = 0;
    rect.w = frame->width;
    rect.h = frame->height;

    SDL_DisplayYUVOverlay(bmp, &rect);

    av_freep(frame);

    return true;
}
void*   SDLRenderer::Render (void *data)
{
    SDLRenderer *renderer = (SDLRenderer *) data;

    AVFrame *frame = renderer->frameBuffer->GetFront();
    while(renderer->displayFrame && renderer->run) 
    {
        renderer->displayFrame = renderer->DisplayFrame(frame);
        Sleep(40);

        frame = renderer->frameBuffer->GetFront();
    }

    return NULL;
}
