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

SDLRenderer::SDLRenderer    () :
             bmp            (NULL),
             screen         (NULL),
             imgConvertCtx  (NULL),
             isInit         (false),
             quitKeyPressed (false)
{
}
SDLRenderer::~SDLRenderer   ()
{
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
void    SDLRenderer::onVideoDataAvailable   (const uint8_t **data, videoFrameProperties* props)
{
    if(!this->isInit)
        this->isInit = this->init(props->width, props->height);

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
        int w = props->width;
        int h = props->height;

        imgConvertCtx = sws_getContext(props->width, props->height, (PixelFormat)props->pxlFmt, w, h, PIX_FMT_YUV420P, SWS_BICUBIC, NULL, NULL, NULL);

        if(imgConvertCtx == NULL)
        {
            fprintf(stderr, "Cannot initialize the conversion context!\n");
            exit(1);
        }
    }

    sws_scale(imgConvertCtx, data, props->linesize, 0, props->height, pict.data, pict.linesize);

    SDL_UnlockYUVOverlay(bmp);

    rect.x = 0;
    rect.y = 0;
    rect.w = props->width;
    rect.h = props->height;

    SDL_DisplayYUVOverlay(bmp, &rect);
}