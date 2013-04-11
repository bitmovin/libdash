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
#include "../Buffer/AVFrameBuffer.h"
#include "../helpers/Timing.h"
#include "../Input/IRendererObserver.h"

#include <SDL.h>
#include <SDL_thread.h>

namespace sampleplayer
{
    namespace renderer
    {
        class SDLRenderer
        {
            public:
                SDLRenderer            (buffer::AVFrameBuffer *frameBuffer, input::IRendererObserver *obs);
                virtual ~SDLRenderer   ();

                bool init               (int width, int height);
                bool processEvents      ();
                bool isQuitKeyPressed   ();
                bool Start              ();
                void Stop               ();

            private:
                THREAD_HANDLE           threadHandle;
                SDL_Overlay             *bmp;
                SDL_Surface             *screen;
                SDL_Rect                rect;
                SDL_Event               sdl_event;
                bool                    isInit;
                bool                    run;
                bool                    displayFrame;
                bool                    quitKeyPressed;
                bool                    isFirstFrame;
                buffer::AVFrameBuffer   *frameBuffer;
                input::IRendererObserver *observer;

                struct SwsContext       *imgConvertCtx;

                static void* Render         (void *data);
                bool         DisplayFrame   (AVFrame *frame);

        };
    }
}

#endif /* SDLRENDERER_H_ */