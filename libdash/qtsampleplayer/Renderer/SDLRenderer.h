/*
 * SDLRenderer.h
 *****************************************************************************
 * Copyright (C) 2012, bitmovin Softwareentwicklung OG, All Rights Reserved
 *
 * Email: libdash-dev@vicky.bitmovin.net
 *
 * This source code and its use and distribution, is subject to the terms
 * and conditions of the applicable license agreement.
 *****************************************************************************/

#ifndef SDLRENDERER_H_
#define SDLRENDERER_H_

#include "IVideoObserver.h"

#include <SDL.h>
#include <SDL_thread.h>

namespace sampleplayer
{
    namespace renderer
    {
        class SDLRenderer : public IVideoObserver
        {
            public:
                SDLRenderer            ();
                virtual ~SDLRenderer   ();

                bool init               (int width, int height);
                bool processEvents      ();
                bool isQuitKeyPressed   ();

                virtual void onVideoDataAvailable  (const uint8_t **data, videoFrameProperties* props);

            private:
                SDL_Overlay *bmp;
                SDL_Surface *screen;
                SDL_Rect    rect;
                SDL_Event   sdl_event;
                bool        isInit;
                bool        quitKeyPressed;

                struct SwsContext *imgConvertCtx;
        };
    }
}

#endif /* SDLRENDERER_H_ */