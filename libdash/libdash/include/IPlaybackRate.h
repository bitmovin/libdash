/**
 *  @class      dash::mpd::IPlaybackRate
 *  @brief      This interface is needed for accessing the attributes of <tt><b>PlaybackRate</b></tt>
 *              as specified in <em>ISO/IEC 23009-1</em>, subclause K.3.3.
 *  @details    Table K.2 defines the service description parameters for non-nominal playback rate.
 *              The keys in Table K.2 shall be used to refer to the non-nominal playback rate as defined in Table K.2.
 *  @see        dash::mpd::IMPDElement
 *
 *  @author     Daniele Lorenzi \n
 *              Email: lorenzidaniele.97@gmail.com
 *  @version    2.1
 *  @date       2021
 */
 
#ifndef IPLAYBACKRATE_H_
#define IPLAYBACKRATE_H_

#include "config.h"

#include "IMPDElement.h"

namespace dash
{
    namespace mpd
    {
        class IPlaybackRate : public virtual IMPDElement
        {
            public:
                virtual ~IPlaybackRate(){}
                
                /**
                 *  Returns a double that specifies the maximum playback rate that the content provider indicates is appropriate for the purposes of automatically adjusting 
                 *  playback latency and buffer occupancy during normal playback, where 1.0 is normal playback speed.            
                 *  
                 *  @return     a double
                 */
                virtual double                             GetMax                    ()  const = 0;
                
                /**
                 *  Returns a double that specifies the minimum playback rate that the content provider indicates is appropriate for the purposes of automatically adjusting 
                 *  playback latency and buffer occupancy during normal playback, where 1.0 is normal playback speed.    
                 *  
                 *  @return     a double
                 */
                virtual double                             GetMin                    ()  const = 0;
        };
    }
}

#endif /* IPLAYBACKRATE_H_ */