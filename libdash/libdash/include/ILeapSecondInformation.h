/**
 *  @class      dash::mpd::ILeapSecondInformation
 *  @brief      This interface is needed for accessing the attributes of <tt><b>LeapSecondInformation</b></tt>
 *              as specified in <em>ISO/IEC 23009-1</em>, subclause 5.13.2, Table 42.
 *  @details    Information on the occurrence of leap seconds and their relationship with \cMPD\b@availabilityStartTime can be expressed using the \b LeapSecondInformation element.\n
 *              This information allows a client to perform time calculations accurately without an external source of information on the timing of past and future leap seconds.
 *              It also allows a service provider to express any correction for leap seconds that has already been made.\n
 *              With this information, a client may perform timing calculations by assuming a constant day length of 86400 seconds if it first applies the relevant offset from the \b LeapSecondInformation element to the value of the \bMPD\c@availabilityStartTime attribute.
 *              The client can then correctly play a Media Presentation for which \bMPD\c@type is 'dynamic' when leap seconds have occurred since the time of \bMPD\c@availabilityStartTime and even when leap seconds occur during playback.\n
 *              The offset specified in \c @availabilityStartLeapOffset applies if the current time is before \c @nextLeapChangeTime. \c @nextAvailabilityStartLeapOffset applies if the current time is equal to or after \c @nextLeapChangeTime, but its use may need to be delayed if the client’s internal wall-clock has not yet processed the leap second.\n
 *              \b NOTE 1 If a particular client’s wall-clock is synchronized solely by means of a one-shot protocol, e.g. using the scheme \c urn:mpeg:dash:utc:http-xsdate:2014 defined in subclause 5.8.5.7, the value of \c @availabilityStartLeapOffset remains appropriate for that client until its clock is next synchronized after the leap second has occurred. \n
 *              \b NOTE 2 Leap seconds can occur at any of four possible times each year and can add or remove a second from the UTC timeline. Whilst leap seconds always occur immediately before midnight UTC, they can occur during the day in other time zones. 
 *              Even within the Greenwich Mean Time (GMT) zone, the most common time for a leap second has been 23:59:60 on New Year's Eve, when many people may be watching live video streams. It is therefore important that leap seconds are handled correctly.\n
 *              Some operating systems allow leap seconds to be handled by "smearing" the leap second over a longer period of time. Care should be taken to ensure that availability times in a published MPD are not affected by this.\n
 *              The semantics of the attributes within the \b LeapSecondInformation element are provided in subclause 5.13.2, Table 42. The XML syntax of the \b LeapSecondInformation element is provided in subclause 5.13.3. of <em>ISO/IEC 23009-1</em>.
 *  @see        dash::mpd::IMPDElement
 *
 *  @author     Daniele Lorenzi \n
 *              Email: lorenzidaniele.97@gmail.com
 *  @version    2.1
 *  @date       2021
 */
 
#ifndef ILEAPSECONDINFORMATION_H_
#define ILEAPSECONDINFORMATION_H_

#include "config.h"

#include "IMPDElement.h"

namespace dash
{
    namespace mpd
    {
        class ILeapSecondInformation : public virtual IMPDElement
        {
            public:
                virtual ~ILeapSecondInformation(){}

                /**
                 *  Returns an integer that specifies the number of seconds applying at the time of MPD publication that a client would need to subtract 
                 *  from \bMPD\c@availabilityStartTime in order to perform timing calculations without further consideration of leap seconds.\n
                 *  If a leap second correction has already been applied, the \b LeapSecondInformation element should still be present but this attribute should be set to 0.    
                 *
                 *  @return     an integer
                 */
                virtual int32_t              GetAvailabilityStartLeapOffset        ()  const = 0;
                
                /**
                 *  Returns an integer that specifies the number of seconds that will apply from the time of the next leap second (indicated by the \c @nextLeapChangeTime) 
                 *  that a client would need to subtract from \bMPD\c@availabilityStartTime in order to perform timing calculations without further consideration of leap seconds.\n
                 *  If the timing of the next leap second is unknown, this attribute shall be omitted.    
                 *
                 *  @return     an integer
                 */
                virtual int32_t              GetNextAvailabilityStartLeapOffset    ()  const = 0;
                
                /**
                 *  Returns a reference to a string that specifies the UTC time at which a leap second will occur. Before this time, \c @availabilityStartLeapOffset applies.
                 *  On or after this time, \c @nextAvailabilityStartLeapOffset applies for timing calculations made against a wall-clock that has processed the leap second.\n
                 *  If the timing of the next leap second is unknown, this attribute shall be omitted.    
                 *
                 *  @return     a reference to a string
                 */
                virtual const std::string&   GetNextLeapChangeTime                 ()  const = 0;
        };
    }
}

#endif /* ILEAPSECONDINFORMATION_H_ */