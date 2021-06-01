/*
 * LeapSecondInformation.h
 *****************************************************************************
 * Name: Daniele Lorenzi
 * Email: lorenzidaniele.97@gmail.com
 * Date: 2021
 *
 * This source code and its use and distribution, is subject to the terms
 * and conditions of the applicable license agreement.
 *****************************************************************************/

#ifndef LEAPSECONDINFORMATION_H_
#define LEAPSECONDINFORMATION_H_

#include "config.h"

#include "ILeapSecondInformation.h"
#include "AbstractMPDElement.h"

namespace dash
{
    namespace mpd
    {
        class LeapSecondInformation : public ILeapSecondInformation, public AbstractMPDElement
        {
            public:
                LeapSecondInformation             ();
                virtual ~LeapSecondInformation    ();

                int32_t              GetAvailabilityStartLeapOffset        ()  const;
                int32_t              GetNextAvailabilityStartLeapOffset    ()  const;
                const std::string&   GetNextLeapChangeTime                 ()  const;

                void    SetAvailabilityStartLeapOffset         (int32_t availabilityStartLeapOffset);
                void    SetNextAvailabilityStartLeapOffset     (int32_t nextAvailabilityStartLeapOffset);
                void    SetNextLeapChangeTime                  (const std::string&  nextLeapChangeTime);

            private:
                int32_t      availabilityStartLeapOffset;
                int32_t      nextAvailabilityStartLeapOffset;
                std::string  nextLeapChangeTime;
                
        };
    }
}

#endif /* LEAPSECONDINFORMATION_H_ */
