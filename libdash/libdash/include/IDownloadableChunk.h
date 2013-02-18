/**
 *  @class      dash::network::IDownloadableChunk
 *  @brief      This interface is needed for starting and abortinng downloads, reading, peeking and attaching dash::network::IDownloadObservers to this Chunk
 *  @details    ...
 *  @see        dash::network::IDownloadObserver dash::network::IConnection dash::network::IChunk
 *
 *  @author     bitmovin Softwareentwicklung OG \n
 *              Email: libdash-dev@vicky.bitmovin.net
 *  @version    2.1
 *  @date       2013
 *  @copyright  bitmovin Softwareentwicklung OG, All Rights Reserved \n\n
 *              This source code and its use and distribution, is subject to the terms
 *              and conditions of the applicable license agreement.
 */

#ifndef IDOWNLOADABLECHUNK_H_
#define IDOWNLOADABLECHUNK_H_

#include "config.h"

#include "IDownloadObserver.h"
#include "IConnection.h"
#include "IChunk.h"

namespace dash
{
    namespace network
    {
        class IDownloadableChunk : public IChunk
        {
            public:
                virtual ~IDownloadableChunk(){}

                /**
                 *  Starts the download of this chunk and returns a bool value whether the starting of the download was possible or not
                 *  @return     a bool value
                 */
                virtual bool    StartDownload           ()                              = 0;

                /**
                 *  Starts the download of this chunk and returns a bool value whether the starting of the download was possible or not
                 *  @param      connection      the dash::network::IConnection that shall be used for downloading
                 *  @return     a bool value
                 */
                virtual bool    StartDownload           (IConnection *connection)       = 0;

                /**
                 *  Aborts the download of a chunk
                 */
                virtual void    AbortDownload           ()                              = 0;

                /**
                 *  Reads
                 *  @param      data    ...
                 *  @param      len     ...
                 *  @return     ...
                 */
                virtual int     Read                    (uint8_t *data, size_t len)     = 0;

                /**
                 *  Reads
                 *  @param      data    ...
                 *  @param      len     ...
                 *  @return     an integer
                 */
                virtual int     Peek                    (uint8_t *data, size_t len)     = 0;

                /**
                 *  Attaches a dash::network::IDownloadObserver to this Chunk
                 *  @param      observer    a dash::network::IDownloadObserver
                 */
                virtual void    AttachDownloadObserver  (IDownloadObserver *observer)   = 0;
        };
    }
}

#endif /* IDOWNLOADABLECHUNK_H_ */