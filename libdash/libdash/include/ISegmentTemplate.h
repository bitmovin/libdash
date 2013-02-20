/**
 *  @class      dash::mpd::ISegmentTemplate
 *  @brief      This interface is needed for accessing the attributes and elements of the <tt><b>SegmentTemplate</b></tt> element 
 *              as specified in <em>ISO/IEC 23009-1, Part 1, 2012</em>, section 5.3.9.4.2, table 15
 *  @details    The Segment template is defined by the <tt><b>SegmentTemplate</b></tt> element. In this case, specific identifiers that are substituted by dynamic values assigned to Segments, 
 *              to create a list of Segments. The substitution rules are provided in section 5.3.9.4.4 of <em>ISO/IEC 23009-1, Part 1, 2012</em>.
 *  @see        dash::mpd::ISegment dash::mpd::IMultipleSegmentBase
 *
 *  @author     bitmovin Softwareentwicklung OG \n
 *              Email: libdash-dev@vicky.bitmovin.net
 *  @version    2.1
 *  @date       2013
 *  @copyright  bitmovin Softwareentwicklung OG, All Rights Reserved \n\n
 *              This source code and its use and distribution, is subject to the terms
 *              and conditions of the applicable license agreement.
 */


#ifndef ISEGMENTTEMPLATE_H_
#define ISEGMENTTEMPLATE_H_

#include "config.h"

#include "IMultipleSegmentBase.h"

namespace dash
{
    namespace mpd
    {
        class ISegmentTemplate : public virtual IMultipleSegmentBase
        {
            public:
                virtual ~ISegmentTemplate(){}

                /**
                 *  Returns a reference to a string that specifies the template to create the Media Segment List.\n
                 *  For more details on template-based segment URL construction refer to section 5.3.9.4.4 of <em>ISO/IEC 23009-1, Part 1, 2012</em>.
                 *  @return     a reference to a string
                 */
                virtual const std::string&  Getmedia                    ()  const = 0;

                /**
                 *  Returns a reference to a string that specifies the template to create the Index Segment List. If neither the \em \$Number\$ nor the \em \$Time\$ identifier 
                 *  is included, this provides the URL to a Representation Index. \n
                 *  For more details on template-based segment URL construction refer to section 5.3.9.4.4 of <em>ISO/IEC 23009-1, Part 1, 2012</em>.
                 *  @return     a reference to a string
                 */
                virtual const std::string&  Getindex                    ()  const = 0;

                /**
                 *  Returns a reference to a string that specifies the template to create the Initialization Segment. Neither \em \$Number\$ nor the \em \$Time\$ identifier 
                 *  shall be included. \n
                 *  For more details on template-based segment URL construction refer to section 5.3.9.4.4 of <em>ISO/IEC 23009-1, Part 1, 2012</em>.
                 *  @return     a reference to a string
                 */
                virtual const std::string&  Getinitialization           ()  const = 0;

                /**
                 *  Returns a reference to a string that specifies the template to create the Bitstream Switching Segment. Neither \em \$Number\$ nor the \em \$Time\$ identifier shall be included.\n
                 *  For more details on template-based segment URL construction refer to section 5.3.9.4.4 of <em>ISO/IEC 23009-1, Part 1, 2012</em>.
                 *  @return     a reference to a string
                 */
                virtual const std::string&  GetbitstreamSwitching       ()  const = 0;

                /**
                 *  Returns a pointer to a dash::mpd::ISegment object that represents an initialization segment and can be downloaded.
                 *  @param      baseurls            a vector of pointers to dash::mpd::IBaseUrl objects that represent the path to the Initialization Segment (template).
                 *  @param      representationID    a string containing the representation ID that will replace the identifier \em \$RepresentationID\$ in the Initialization template. \n
                 *                                  \b NOTE:    If there is no identifier \em \$RepresentationID\$ in the template then this parameter will not be used and can be set to \"\".
                 *  @param      bandwidth           an integer specifying the bandwidth that will replace the identifier \em \$Bandwidth\$ in the initialization template.
                 *                                  This integer will be formated according to a possibly contained format tag in the \em \$Bandwidth\$ identifier. \n
                 *                                  \b NOTE:    If there is no identifier \em \$bandwidth\$ in the template then this parameter will not be used and can be set to 0.
                 *  @return     a pointer to a dash::mpd::ISegment object
                 */
                virtual ISegment*           ToInitializationSegment     (const std::vector<IBaseUrl *>& baseurls, const std::string& representationID, uint32_t bandwidth) const = 0;

                /**
                 *  Returns a pointer to a dash::mpd::ISegment object that represents a Bitstream Switching Segment and can be downloaded.
                 *  @param      baseurls            a vector of pointers to dash::mpd::IBaseUrl objects that represent the path to the Bitstream Switching Segment (template).
                 *  @param      representationID    a string containing the representation ID that will replace the identifier \em \$RepresentationID\$ in the Bitstream Switching template. \n
                 *                                  \b NOTE:    If there is no identifier \em \$RepresentationID\$ in the template then this parameter will not be used and can be set to \"\".
                 *  @param      bandwidth           an integer specifying the bandwidth that will replace the identifier \em \$Bandwidth\$ in the Bitstream Switching template.
                 *                                  This integer will be formated according to a possibly contained format tag in the \em \$Bandwidth\$ identifier.\n
                 *                                  \b NOTE:    If there is no identifier \em \$bandwidth\$ in the template then this parameter will not be used and can be set to 0.
                 *  @return     a pointer to a dash::mpd::ISegment object
                 */
                virtual ISegment*           ToBitstreamSwitchingSegment (const std::vector<IBaseUrl *>& baseurls, const std::string& representationID, uint32_t bandwidth) const = 0;

                /**
                 *  Returns a pointer to a dash::mpd::ISegment object that represents a Media Segment and can be downloaded.
                 *  @param      baseurls            a vector of pointers to dash::mpd::IBaseUrl objects that represent the path to the Media Segment (template).
                 *  @param      representationID    a string containing the representation ID that will replace the identifier \em \$RepresentationID\$ in the Media template.\n
                 *                                  \b NOTE:    If there is no identifier \em \$RepresentationID\$ in the template then this parameter will not be used and can be set to \"\".
                 *  @param      bandwidth           an integer specifying the bandwidth that will replace the identifier \em \$Bandwidth\$ in the Media template.
                 *                                  This integer will be formated according to a possibly contained format tag in the \em \$Bandwidth\$ identifier. \n
                 *                                  \b NOTE:    If there is no identifier \em \$bandwidth\$ in the template then this parameter will not be used and can be set to 0.
                 *  @param      number              an integer specifying the desired Segment number that will replace the identifier \em \$Number\$ in the Media template. 
                 *                                  This integer will be formated according to a possibly contained format tag in the \em \$Number\$ identifier.
                 *  @return     a pointer to a dash::mpd::ISegment object
                 */
                virtual ISegment*           GetMediaSegmentFromNumber   (const std::vector<IBaseUrl *>& baseurls, const std::string& representationID, uint32_t bandwidth, uint32_t number) const = 0;

                /**
                 *  Returns a pointer to a dash::mpd::ISegment object that represents a Index Segment and can be downloaded.
                 *  @param      baseurls            a vector of pointers to dash::mpd::IBaseUrl objects that represent the path to the Index Segment (template).
                 *  @param      representationID    a string containing the representation ID that will replace the identifier \em \$RepresentationID\$ in the Index template.\n
                 *                                  \b NOTE:    If there is no identifier \em \$RepresentationID\$ in the template then this parameter will not be used and can be set to \"\".
                 *  @param      bandwidth           an integer specifying the bandwidth that will replace the identifier \em \$Bandwidth\$ in the Index template.
                 *                                  This integer will be formated according to a possibly contained format tag in the \em \$Bandwidth\$ identifier.\n
                 *                                  \b NOTE:    If there is no identifier \em \$bandwidth\$ in the template then this parameter will not be used and can be set to 0.
                 *  @param      number              an integer specifying the desired Segment number that will replace the identifier \em \$Number\$ in the Index template. 
                 *                                  This integer will be formated according to a possibly contained format tag in the \em \$Number\$ identifier.
                 *  @return     a pointer to a dash::mpd::ISegment object
                 */
                virtual ISegment*           GetIndexSegmentFromNumber   (const std::vector<IBaseUrl *>& baseurls, const std::string& representationID, uint32_t bandwidth, uint32_t number) const = 0;

                /**
                 *  Returns a pointer to a dash::mpd::ISegment object that represents a Media Segment and can be downloaded.
                 *  @param      baseurls            a vector of pointers to dash::mpd::IBaseUrl objects that represent the path to the Media Segment (template).
                 *  @param      representationID    a string containing the representation ID that will replace the identifier \em \$RepresentationID\$ in the Media template.
                 *                                  \b NOTE:    If there is no identifier \em \$RepresentationID\$ in the template then this parameter will not be used and can be set to \"\".
                 *  @param      bandwidth           an integer specifying the bandwidth that will replace the identifier \em \$Bandwidth\$ in the Media template.
                 *                                  This integer will be formated according to a possibly contained format tag in the \em \$Bandwidth\$ identifier.\n
                 *                                  \b NOTE:    If there is no identifier \em \$bandwidth\$ in the template then this parameter will not be used and can be set to 0.
                 *  @param      time                an integer corresponding to the <tt><b>SegmentTimeline</b>\@t</tt> attribute that will replace the identifier \em \$Time\$ in the Media template. 
                 *                                  This integer will be formated according to a possibly contained format tag in the \em \$Time\$ identifier.
                 *  @return     a pointer to a dash::mpd::ISegment object
                 */
                virtual ISegment*           GetMediaSegmentFromTime     (const std::vector<IBaseUrl *>& baseurls, const std::string& representationID, uint32_t bandwidth, uint32_t time) const = 0;

                /**
                 *  Returns a pointer to a dash::mpd::ISegment object that represents a Index Segment and can be downloaded.
                 *  @param      baseurls            a vector of pointers to dash::mpd::IBaseUrl objects that represent the path to the Index Segment (template).
                 *  @param      representationID    a string containing the representation ID that will replace the identifier \em \$RepresentationID\$ in the Index template.\n
                 *                                  \b NOTE:    If there is no identifier \em \$RepresentationID\$ in the template then this parameter will not be used and can be set to \"\".
                 *  @param      bandwidth           an integer specifying the bandwidth that will replace the identifier \em \$Bandwidth\$ in the Index template.
                 *                                  This integer will be formated according to a possibly contained format tag in the \em \$Bandwidth\$ identifier.\n
                 *                                  \b NOTE:    If there is no identifier \em \$bandwidth\$ in the template then this parameter will not be used and can be set to 0.
                 *  @param      time                an integer corresponding to the <tt><b>SegmentTimeline</b>\@t</tt> attribute that will replace the identifier \em \$Time\$ in the Index template. 
                 *                                  This integer will be formated according to a possibly contained format tag in the \em \$Time\$ identifier.
                 *  @return     a pointer to a dash::mpd::ISegment object
                 */
                virtual ISegment*           GetIndexSegmentFromTime     (const std::vector<IBaseUrl *>& baseurls, const std::string& representationID, uint32_t bandwidth, uint32_t time) const = 0;
        };
    }
}

#endif /* ISEGMENTTEMPLATE_H_ */