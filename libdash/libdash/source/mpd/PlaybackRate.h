/*
 * PlaybackRate.h
 *****************************************************************************
 * Name: Daniele Lorenzi
 * Email: lorenzidaniele.97@gmail.com
 * Date: 2021
 *
 * This source code and its use and distribution, is subject to the terms
 * and conditions of the applicable license agreement.
 *****************************************************************************/

#ifndef PLAYBACKRATE_H_
#define PLAYBACKRATE_H_

#include "config.h"

#include "IPlaybackRate.h"
#include "AbstractMPDElement.h"

namespace dash
{
    namespace mpd
    {
        class PlaybackRate : public IPlaybackRate, public AbstractMPDElement
        {
            public:
                PlaybackRate             ();
                virtual ~PlaybackRate    ();

                double                                   GetMax                        ()  const;
                double                                   GetMin                        ()  const;

                void    SetMax                   (double max);
                void    SetMin                   (double min);

            private:
                double                          max;
                double                          min;
                
        };
    }
}

#endif /* PLAYBACKRATE_H_ */
