/**
 *  @class      dash::IDASHManager
 *  @brief      This interface is needed for generating an IMPD object from the information found in a MPD file
 *  @details    By invoking the method Open(char *path) all the information found in the MPD file specified by \em path is mapped to corresponding IMPD objects.
 *  @see        dash::mpd::IMPD
 *
 *  @author     bitmovin Softwareentwicklung OG \n
 *              Email: libdash-dev@vicky.bitmovin.net
 *  @version    2.1
 *  @date       2013
 *  @copyright  bitmovin Softwareentwicklung OG, All Rights Reserved \n\n
 *              This source code and its use and distribution, is subject to the terms
 *              and conditions of the applicable license agreement.
 */

#ifndef IDASHMANAGER_H_
#define IDASHMANAGER_H_

#include "config.h"

#include "IMPD.h"
#include "IConnection.h"

namespace dash
{
    class IDASHManager
    {
        public:
            virtual ~IDASHManager(){}

            /**
             *  Returns a pointer to dash::mpd::IMPD object representing the the information found in the MPD file specified by \em path
             *  @param      path    A URI to a MPD file
             *  @return     a pointer to an dash::mpd::IMPD object
             */
            virtual mpd::IMPD* Open (char *path) = 0;

            /**
             *  Frees allocated memory and deletes the DashManager
             */
            virtual void        Delete  () = 0;
    };
}

#endif /* IDASHMANAGER_H_ */
