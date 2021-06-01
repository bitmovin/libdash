/**
 *  @class      dash::mpd::IProducerReferenceTime
 *  @brief      This interface is needed for accessing the common elements and attributes of <tt><b>ProducerReferenceTime</b></tt>
 *  @details    The Producer Reference Time supplies media correlation between media timestamps and wall clock production time. 
 *              This information permits the following, among others:
 *              <ul>
 *                  <li> it provides media clients with information to enable consumption and production to proceed at equivalent rates, thus avoiding possible buffer overflow or underflow;
 *                  <li> it enables measuring and potentially controlling the latency between the production of the media time and the playout.
 *              </ul>
 *              The definition follows the Producer Reference Time ('prft') as defined in ISO/IEC 14496-12.\n
 *              The information may be provided inband as part of the Segments in the ('prft'), in the MPD or both.\n
 *              The semantics of the attributes and elements for producer reference time are provided in subclause 5.12.2, Table 41. 
 *              The XML syntax of the Producer Reference Time is provided in subclause 5.12.3. of <em>ISO/IEC 23009-1</em>.    
 *  @see        dash::mpd::IDescriptor dash::mpd::IMPDElement
 *
 *  @author     Daniele Lorenzi \n
 *              Email: lorenzidaniele.97@gmail.com
 *  @version    2.1
 *  @date       2021
 */
 
#ifndef IPRODUCERREFERENCETIME_H_
#define IPRODUCERREFERENCETIME_H_

#include "config.h"

#include "IMPDElement.h"
#include "IDescriptor.h"

namespace dash
{
    namespace mpd
    {
        class IProducerReferenceTime : public virtual IMPDElement
        {
            public:
                virtual ~IProducerReferenceTime(){}
                
                /**
                 *  Returns a pointer to a dash::mpd::IDescriptor object.
                 *  If present, then the wall-clock times provided in this context are synchronized with the timing anchor provided in this descriptor.
                 *  The same UTC Timing descriptor shall also be present in the MPD.    
                 *  
                 *  @return     a pointer to a dash::mpd::IDescriptor object
                 */
                virtual const IDescriptor *     GetUTCTiming            () const = 0;
                
                /**
                 *  Returns an unsigned integer that identifies the Producer Reference Time documented in the MPD.    
                 *  
                 *  @return     an unsigned integer
                 */
                virtual uint32_t                GetId                   () const = 0;
                
                /**
                 *  Returns a bool value that signals if every segment or subsegment contains a 'prft' of the type below.
                 *  If set to true, every segment or subsegment shall contain the 'prft' as defined in ISO/IEC 14496-12:—,
                 *  subclause 8.16.5 and the flags set according to the \c @type attribute of this element.
                 *  
                 *  @return     a bool value
                 */
                virtual bool                    IsInband                () const = 0;
                
                /**
                 *  Returns a reference to a string that specifies the type of the Producer Reference Time from the following list:    
                 *  <ul>
                 *      <li> \c encoder provides a reference when the media time was input to an encoder following the exact definition in subclause 8.16.5 of ISO/IEC 14496-12 for flags set to 0.
                 *      <li> \c captured provides a reference when the media time was captured following the exact definition in ISO/IEC 14496-12:—, subclause 8.16.5 for both flag 8 and flag 16 being set.
                 *      <li> \c application provides a reference of the media time related to wall-clock time based on an application defined relation. In this case, following ISO/IEC 14496-12:—, subclause 8.16.5, flag 16 shall be set and flag 8 shall be unset.
                 *  </ul>            
                 *  
                 *  @return     a reference to a string
                 */
                virtual const std::string&      GetType                 () const = 0;
                
                /**
                 *  Returns a reference to a string that specifies the application scheme to which the time conforms if \c @type is set to \b application.\n
                 *  If the \c @type is set to \b application, this attribute should be present.\n
                 *  If the \c @type is set other than \b application, this attribute shall not be present.    
                 *  
                 *  @return     a reference to a string
                 */
                virtual const std::string&      GetApplicationScheme    () const = 0;
                
                /**
                 *  Returns a reference to a string that specifies a wall-clock time in the following format:
                 *  <ul>
                 *      <li> if \b UTCTiming element is absent, the NTP format associated to \c @media as defined in ISO/IEC 14496-12:—, 8.16.5 for \c ntp_timestamp;
                 *      <li> if \b UTCTiming element is present, the format is identical to the format as defined in the UTC Timing scheme.
                 *  </ul>
                 *  If the MPD Generator extracts the information from the producer reference time box, the value needs to be converted to the correct scheme.        
                 *  
                 *  @return     a reference to a string
                 */
                virtual const std::string&      GetWallClockTime        () const = 0;
                
                /**
                 *  Returns an unsigned integer that specifies a presentation time in timescale of the Representation that relates to the value of the \c @wallClockTime.\n
                 *  \b NOTE If the data is extracted from the producer reference time box, then this value is derived by the \c media_time field.    
                 *  
                 *  @return     an unsigned integer
                 */
                virtual uint64_t                GetPresentationTime     () const = 0;
                
        };
    }
}

#endif /* IPRODUCERREFERENCETIME_H_ */