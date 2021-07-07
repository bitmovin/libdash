/**
 *  @class      dash::mpd::IMPD
 *  @brief      This interface is needed for accessing the attributes and elements of the <tt><b>MPD</b></tt> element 
 *              as specified in <em>ISO/IEC 23009-1, Part 1, 2012</em>, section 5.3.1.2, table 3
 *  @details    A Media Presentation as described in the <tt><b>MPD</b></tt> consists of (all sections refer to <em>ISO/IEC 23009-1, Part 1, 2012</em>)
 *              <ul>
 *                  <li>A sequence of one or more Periods as described in section 5.3.2.
 *                  <li>Each Period contains one or more Adaptation Sets as described in 5.3.3.
 *                      In case an Adaptation Set contains multiple media content components, then each media content component is described individually 
 *                      as defined in 5.3.4.
 *                  <li>Each Adaptation Set contains one or more Representations as described in 5.3.5.
 *                  <li>A Representation may contain one or more Sub-Representations as described in 5.3.6.
 *                  <li>Adaptation Sets, Representations and Sub-Representations share common attributes and elements that are described in 5.3.7.
 *                  <li>Each Period may contain one or more Subsets that restrict combination of Adaptation Sets for presentation. Subsets are described in 5.3.8.
 *                  <li>Each Representation consists of one or more Segments described in 6. Segment Information is introduced in 5.3.9.
 *                      Segments contain media data and/or metadata to access, decode and present the included media content.
 *                      Representations may also include Sub-Representations as defined in 5.3.6 to describe and extract partial information from a Representation.
 *                  <li>Each Segment consists of one or more Subsegments. Subsegments are described in 6.2.3.2.
 *              </ul>
 *  @see        dash::mpd::IMPDElement dash::mpd::IProgramInformation dash::mpd::IBaseUrl dash::mpd::IDescriptor dash::mpd::IContentProtection dash::mpd::IPeriod dash::mpd::IMetrics
 *              dash::mpd::IRepresentationBase dash::mpd::IServiceDescription dash::mpd::ILeapSecondInformation dash::mpd::IPatchLocation dash::mpd::IInitializationSet
 *              dash::mpd::IUIntVWithID
 *
 *  @author     bitmovin Softwareentwicklung OG \n
 *              Email: libdash-dev@vicky.bitmovin.net
 *  @version    2.1
 *  @date       2013
 *  @copyright  bitmovin Softwareentwicklung OG, All Rights Reserved \n\n
 *              This source code and its use and distribution, is subject to the terms
 *              and conditions of the applicable license agreement.
 *
 * @contributor        Daniele Lorenzi
 * @contributoremail   lorenzidaniele.97@gmail.com
 * @contributiondate   2021
 */

#ifndef IMPD_H_
#define IMPD_H_

#include "config.h"

#include "IMPDElement.h"
#include "IProgramInformation.h"
#include "IBaseUrl.h"
#include "IContentProtection.h"
#include "IDescriptor.h"
#include "IPeriod.h"
#include "IMetrics.h"
#include "IDASHMetrics.h"
#include "IServiceDescription.h"
#include "ILeapSecondInformation.h"
#include "IPatchLocation.h"
#include "IInitializationSet.h"
#include "IUIntVWithID.h"

namespace dash
{
    namespace mpd
    {
        class IMPD : public virtual IMPDElement, public dash::metrics::IDASHMetrics
        {
            public:
                virtual ~IMPD(){}

                /**
                 *  Returns a reference to a vector of pointers to dash::mpd::IProgramInformation objects that specify descriptive information about the program.\n
                 *  For more details refer to the description in section 5.7. of <em>ISO/IEC 23009-1, Part 1, 2012</em>.
                 *  @return     a reference to a vector of pointers to dash::mpd::IProgramInformation objects
                 */
                virtual const std::vector<IProgramInformation *>&   GetProgramInformations          ()  const = 0;

                /**
                 *  Returns a reference to a vector of pointers to dash::mpd::IBaseUrl objects that specify Base URLs that can be used for reference resolution 
                 *  and alternative URL selection. \n
                 *  For more details refer to the description in section 5.6. of <em>ISO/IEC 23009-1, Part 1, 2012</em>.
                 *  @return     a reference to a vector of pointers to dash::mpd::IBaseUrl objects
                 */
                virtual const std::vector<IBaseUrl *>&              GetBaseUrls                     ()  const = 0;

                /**
                 *  Returns a reference to a vector of strings that specify locations at which the MPD is available.
                 *  @return     a reference to a vector of strings
                 */
                virtual const std::vector<std::string>&             GetLocations                    ()  const = 0;
                
                /**
                 *  Returns a reference to a vector of pointers to dash::mpd::IPatchLocation objects that specify a location at which the MPD patch document is available. Details on the MPD patch document, this element, and expected processing models are available in subclause 5.15. of <em>ISO/IEC 23009-1</em>. \n
                 *  If this element is present, the <b>MPD</b><em>@id</em> attribute and the <b>MPD</b><em>@publishTime</em> shall be present. \n
                 *  When \c @type is 'static' or the \c @minimumUpdatePeriod attribute is not present, then value of the element is undefined and may be ignored. \n
                 *  If this element is not present, no MPD patch document is available. \n
                 *  If multiple elements are present, any <b>PatchLocation</b> element may be used.
                 *  
                 *  @return     a reference to a vector of pointers to dash::mpd::IPatchLocation objects
                 */
                virtual const std::vector<IPatchLocation *>&        GetPatchLocations               ()  const = 0;
                
                /**
                 *  Returns a reference to a vector of pointers to dash::mpd::IServiceDescription objects that specify the service descriptions.
                 *  For more details refer to the description in section K.4.1 of <em>ISO/IEC 23009-1</em>.
                 *
                 *  @return     a reference to a vector of pointers to dash::mpd::IServiceDescription objects
                 */
                virtual const std::vector<IServiceDescription *>&   GetServiceDescriptions          ()  const = 0;
                
                /**
                 *  Returns a reference to a vector of pointers to dash::mpd::IInitializationSet objects that specify suitable initializations for specific media types for the presentation. 
                 *  For more details refer to the description in section 5.3.12.2, of <em>ISO/IEC 23009-1</em>.
                 *
                 *  @return     a reference to a vector of pointers to dash::mpd::IInitializationSet objects
                 */
                virtual const std::vector<IInitializationSet *>&    GetInitializationSets            ()  const = 0;
                
                /**
                 *  Returns a reference to a vector of pointers to dash::mpd::IUIntVWithID objects that specify white space separated lists of ids of Initialization Sets of the same content type.
                 *    This indicates that any Period in the Media Presentation has at least one Adaptation Set that conforms to one of the Initialization Sets referenced in this element.\n
                 *  For details, see subclause 5.3.12, of <em>ISO/IEC 23009-1</em>.
                 *
                 *  @return     a reference to a vector of pointers to dash::mpd::IUIntVWithID objects
                 */
                virtual const std::vector<IUIntVWithID *>&          GetInitializationGroups          ()  const = 0;
                
                /**
                 *  Returns a reference to a vector of pointers to dash::mpd::IUIntVWithID objects that specify white space separated lists of ids of Initialization Sets and Initialization Groups to indicate a combination which creates a complete presentation.\n
                 *  A client supporting all listed Initialization Sets and Initialization Groups of an Initialization Presentation is expected to be able to play the entire Media Presentation as intended by the service provider.\n
                 *  For details, see subclause 5.3.12, of <em>ISO/IEC 23009-1</em>.
                 *
                 *  @return     a reference to a vector of pointers to dash::mpd::IUIntVWithID objects
                 */
                virtual const std::vector<IUIntVWithID *>&          GetInitializationPresentations   ()  const = 0;
                
                /**
                 *  Returns a reference to a vector of pointers to dash::mpd::IContentProtection objects that specifies information about content protection
                 *  and encryption schemes used in this Media Presentation. If present on this level, it shall include the \c @refId attribute. \n
                 *  For details, see subclauses 5.8.1 and 5.8.4.1 of <em>ISO/IEC 23009-1</em>. \n
                 *
                 *  @return     a reference to a vector of pointers to dash::mpd::IContentProtection objects
                 */
                virtual const std::vector<IContentProtection *>&    GetContentProtections            ()  const = 0;

                /**
                 *  Returns a reference to a vector of pointers to dash::mpd::IPeriod objects that specify the information of a Period.\n
                 *  For more details refer to the description in section 5.3.2. of <em>ISO/IEC 23009-1, Part 1, 2012</em>.
                 *  @return     a reference to a vector of pointers to dash::mpd::IPeriod objects
                 */
                virtual const std::vector<IPeriod *>&               GetPeriods                      ()  const = 0;

                /**
                 *  Returns a reference to a vector of pointers to dash::mpd::IDescriptor objects that specify information about the containing element that is considered 
                 *  essential by the Media Presentation author for processing the containing element. \n    
                 *  For details, see subclause 5.8.4.8. of <em>ISO/IEC 23009-1</em>.
                 *
                 *  @return     a reference to a vector of pointers to dash::mpd::IDescriptor objects
                 */
                virtual const std::vector<IDescriptor *>&           GetEssentialProperties          ()  const = 0;
                
                /**
                 *  Returns a reference to a vector of pointers to dash::mpd::IDescriptor objects that specify supplemental information about the containing element 
                 *  that may be used by the DASH Client optimizing the processing. \n
                 *  For details, see subclause 5.8.4.9. of <em>ISO/IEC 23009-1</em>.
                 *
                 *  @return     a reference to a vector of pointers to dash::mpd::IDescriptor objects
                 */
                virtual const std::vector<IDescriptor *>&           GetSupplementalProperties       ()  const = 0;
                
                /**
                 *  Returns a reference to a vector of pointers to dash::mpd::IDescriptor objects that specify information on ways to obtain a synchronization to wall-clock time
                 *  as used in this Media Presentation. The order of the elements expresses a preference of choice by the Media Presentation author. \n
                 *    For more details, refer to subclause 5.8.4.11. of <em>ISO/IEC 23009-1</em>.
                 *
                 *  @return     a reference to a vector of pointers to dash::mpd::IDescriptor objects
                 */
                virtual const std::vector<IDescriptor *>&           GetUTCTimings                   ()  const = 0;
                
                /**
                 *  Returns a reference to a vector of pointers to dash::mpd::IMetrics objects that specify the DASH Metrics.\n
                 *  For more details see section 5.9. of <em>ISO/IEC 23009-1, Part 1, 2012</em>.
                 *  @return     a reference to a vector of pointers to dash::mpd::IPeriod objects
                 */
                virtual const std::vector<IMetrics *>&              GetMetrics                      ()  const = 0;
                
                /**
                 *  Returns a reference to a dash::mpd::ILeapSecondInformation object that specifies leap second information affecting MPD timing calculations.\n
                 *  For details, refer to clause 5.13. of <em>ISO/IEC 23009-1</em>.
                 *  
                 *  @return     a reference to a dash::mpd::ILeapSecondInformation object
                 */
                virtual const ILeapSecondInformation *              GetLeapSecondInformation        ()  const = 0;

                /**
                 *  Returns a reference to a string that specifies an identifier for the Media Presentation. It is recommended to use an identifier that is unique within 
                 *  the scope in which the Media Presentation is published. \n
                 *  If not specified, no MPD-internal identifier is provided. However, for example the URL to the MPD may be used as an identifier for the Media Presentation.
                 *  @return     a reference to a string
                 */
                virtual const std::string&                          GetId                           ()  const = 0;

                /**
                 *  Returns a reference to a vector of strings that specifies a list of Media Presentation profiles as described in section 8 of <em>ISO/IEC 23009-1, Part 1, 2012</em>.\n
                 *  The contents of this attribute shall conform to either the \c pro-simple or \c pro-fancy productions of RFC6381, Section 4.5, without the enclosing \c DQUOTE characters, 
                 *  i.e. including only the \c unencodedv or \c encodedv elements respectively. 
                 *  As profile identifier the URI defined for the conforming Media Presentation profiles as described in section 8 shall be used.
                 *  @return     a reference to a vector of pointers to dash::mpd::IProgramInformation objects
                 */
                virtual const std::vector<std::string>&             GetProfiles                     ()  const = 0;

                /**
                 *  Returns a reference to a string that specifies whether the Media Presentation Description may be updated (<tt>\@type=\"dynamic\"</tt>) or not (<tt>\@type=\"static\"</tt>).\n
                 * \b NOTE:     Static MPDs are typically used for On-Demand services, whereas dynamic MPDs are used for live services.
                 *  @return     a reference to a string
                 */
                virtual const std::string&                          GetType                         ()  const = 0;

                /**
                 *  Returns a reference to a string that specifies
                 *  <ul>
                 *      <li>the anchor for the computation of the earliest availability time (in UTC) for any Segment in the Media Presentation if <tt>\@type=\"dynamic\"</tt>.
                 *      <li>the Segment availability start time for all Segments referred to in this MPD if <tt>\@type=\"static\"</tt>.
                 *  </ul>
                 *  If not present, all Segments described in the MPD shall become available at the time the MPD becomes available.\n
                 *  For <tt>\@type=\"dynamic\"</tt> this attribute shall be present.
                 *  @return     a reference to a string
                 */
                virtual const std::string&                          GetAvailabilityStarttime        ()  const = 0;

                /**
                 *  Returns a reference to a string that specifies the latest Segment availability end time for any Segment in the Media Presentation. When not present, the value is unknown.
                 *  @return     a reference to a string
                 */
                virtual const std::string&                          GetAvailabilityEndtime          ()  const = 0;
                
                /**
                 *  Returns a reference to a string that specifies the time at which the MPD file was published. When not present, the value is unknown.
                 *  @return     a reference to a string
                 */
                virtual const std::string&                          GetPublishTime                  ()  const = 0;

                /**
                 *  Returns a reference to a string that specifies the duration of the entire Media Presentation. If the attribute is not present, the duration of the Media Presentation is unknown.
                 *  In this case the attribute <tt><b>MPD</b>\@minimumUpdatePeriod</tt> shall be present.\n
                 *  This attribute shall be present when the attribute <tt><b>MPD</b>\@minimumUpdatePeriod</tt> is not present.
                 *  @return     a reference to a string
                 */
                virtual const std::string&                          GetMediaPresentationDuration    ()  const = 0;

                /**
                 *  Returns a reference to a string that specifies the smallest period between potential changes to the MPD.
                 *  This can be useful to control the frequency at which a client checks for updates. \n
                 *  If this attribute is not present it indicates that the MPD does not change.
                 *  If <tt><b>MPD</b>\@type</tt> is \c \"static\", \c \@minimumUpdatePeriod shall not be present.\n
                 *  Details on the use of the value of this attribute are specified in section 5.4. of <em>ISO/IEC 23009-1, Part 1, 2012</em>.
                 *  @return     a reference to a string
                 */
                virtual const std::string&                          GetMinimumUpdatePeriod          ()  const = 0;

                /**
                 *  Returns a reference to a string that specifies a common duration used in the definition of the Representation data rate 
                 *  (see \c \@bandwidth attribute in section 5.3.5.2 of <em>ISO/IEC 23009-1, Part 1, 2012</em>).
                 *  @return     a reference to a string
                 */
                virtual const std::string&                          GetMinBufferTime                ()  const = 0;


                /**
                 *  Returns a reference to a string that specifies the duration of the time shifting buffer that is guaranteed to be available for a Media Presentation 
                 *  with type \c \"dynamic\". When not present, the value is infinite. This value of the attribute is undefined if the type attribute is equal to \c \"static\".
                 *  @return     a reference to a string
                 */
                virtual const std::string&                          GetTimeShiftBufferDepth         ()  const = 0;

                /**
                 *  Returns a reference to a string that specifies
                 *  <ul>
                 *      <li>when \c \@type is \c \"dynamic\", a fixed delay offset in time from the presentation time of each access unit that is suggested to be used for presentation of each access unit.\n
                            For more details refer to 7.2.1. \n
                            When not specified, then no value is provided and the client is expected to choose a suitable value.
                        <li>when \c \@type is \c \"static\" the value of the attribute is undefined and may be ignored.
                    </ul>
                 *  @return     a reference to a string
                 */
                virtual const std::string&                          GetSuggestedPresentationDelay   ()  const = 0;

                /**
                 *  Returns a reference to a string that specifies the maximum duration of any Segment in any Representation in the Media Presentation, 
                 *  i.e. documented in this MPD and any future update of the MPD. If not present, then the maximum Segment duration shall be the maximum duration of any Segment documented in this MPD. 
                 *  @return     a reference to a string
                 */
                virtual const std::string&                          GetMaxSegmentDuration           ()  const = 0;

                /**
                 *  Returns a reference to a string that specifies the maximum duration of any Media Subsegment in any Representation in the Media Presentation. 
                 *  If not present, the same value as for the maximum Segment duration is implied.
                 *  @return     a reference to a string
                 */
                virtual const std::string&                          GetMaxSubsegmentDuration        ()  const = 0;

                /**
                 *  Returns a pointer to a dash::mpd::IBaseUrl that specifies the absolute path to the MPD file. \n
                 *  This absolute path is needed if there is no BaseURL specified and all other BaseURLs are relative.
                 *  @return     a pointer to a dash::mpd::IBaseUrl
                 */
                virtual IBaseUrl*                                   GetMPDPathBaseUrl               ()  const = 0;

                /**
                 *  Returns the UTC time in seconds when the MPD was fetched.\n
                 *  It is up to the client to check that this value has been set accordingly. \n
                 *  See SetFetchTime() for further details.
                 *  @return     an unsigned integer
                 */
                virtual uint32_t                                    GetFetchTime                    ()  const = 0;
        };
    }
}

#endif /* IMPD_H_ */