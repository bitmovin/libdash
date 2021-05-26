/*
 * DASHManager.cpp
 *****************************************************************************
 * Copyright (C) 2012, bitmovin Softwareentwicklung OG, All Rights Reserved
 *
 * Email: libdash-dev@vicky.bitmovin.net
 *
 * @contributor        Daniele Lorenzi
 * @contributiondate   2021
 * 
 * This source code and its use and distribution, is subject to the terms
 * and conditions of the applicable license agreement.
 *****************************************************************************/

#include "DASHManager.h"

using namespace dash;
using namespace dash::xml;
using namespace dash::mpd;
using namespace dash::network;
using namespace dash::helpers;

DASHManager::DASHManager            ()
{
}
DASHManager::~DASHManager           ()
{
}
IMPD*           DASHManager::Open   (char *path)
{
    DOMParser parser(path);

    uint32_t fetchTime = Time::GetCurrentUTCTimeInSec();

    if (!parser.Parse())
        return NULL;

    MPD* mpd = parser.GetRootNode()->ToMPD();

    std::cout << "Variables check:" << std::endl;
    
    /*
     * EssentialProperty in https://dash.akamaized.net/dash264/TestCasesIOP41/MultiTrack/alternative_content/4/manifest_alternative_Essentialproperty_live.mpd
     */
    
    /*
    const Descriptor* ep = (Descriptor*) mpd->GetPeriods()[0]->GetAdaptationSets()[2]->GetEssentialProperties()[0];
    std::cout << "EssentialProperty: " << std::endl;
    std::cout << "   SchemeIdUri: " << ep->GetSchemeIdUri() << std::endl;
    std::cout << "   Value: " << ep->GetValue() << std::endl;
    std::cout << "   Id: " << ep->GetId() << std::endl;
    */

    /*
     * AssetIdentifier in https://dash.akamaized.net/dash264/TestCasesIOP33/multiplePeriods/2/manifest_multiple_Periods_Add_Remove_AdaptationSet.mpd
     */

    /*
    const Descriptor* ai = (Descriptor*) mpd->GetPeriods()[0]->GetAssetIdentifier();
    std::cout << "AssetIdentifier: " << std::endl;
    std::cout << "   SchemeIdUri: " << ai->GetSchemeIdUri() << std::endl;
    std::cout << "   Value: " << ai->GetValue() << std::endl;
    std::cout << "   Id: " << ai->GetId() << std::endl;
    */

    /*
     * SupplementalProperty in https://dash.akamaized.net/dash264/TestCasesIOP33/adapatationSetSwitching/5/manifest.mpd
     */

    /*
    const Descriptor* sp = (Descriptor*) mpd->GetPeriods()[0]->GetAdaptationSets()[0]->GetSupplementalProperties()[0];
    //std::cout << "SupplementalProperty: " << std::endl;
    std::cout << "   SchemeIdUri: " << sp->GetSchemeIdUri() << std::endl;
    std::cout << "   Value: " << sp->GetValue() << std::endl;
    std::cout << "   Id: " << sp->GetId() << std::endl;
    */

    /*
     * Switching in https://dash.akamaized.net/dash264/TestCasesIOP33/adapatationSetSwitching/5/manifest.mpd
     */

    /*
    const Switching* sw = (Switching*) mpd->GetPeriods()[0]->GetAdaptationSets()[0]->GetSwitchings()[0];
    std::cout << "Switching: " << std::endl;
    std::cout << "   Interval: " << sw->GetInterval() << std::endl;
    std::cout << "   Type: " << sw->GetType() << std::endl;
    */

    /*
     * Label in https://dash.akamaized.net/dash264/TestCasesIOP41/MultiTrack/alternative_content/6/manifest_alternative_lang.mpd
     */

    /*
    const Label* label = (Label*) mpd->GetPeriods()[0]->GetAdaptationSets()[1]->GetLabels()[0];
    std::cout << "Label: " << std::endl;
    std::cout << "   Id: " << label->GetId() << std::endl;
    std::cout << "   Lang: " << label->GetLang() << std::endl;
    */

    /*
     * InbandEventStream in https://livesim.dashif.org/livesim/scte35_2/testpic_2s/Manifest.mpd
     */

    /*
    const EventStream* es = (EventStream*) mpd->GetPeriods()[0]->GetAdaptationSets()[1]->GetEventStreams()[0];
    std::cout << "InbandEventStream: " << std::endl;
    std::cout << "   XlinkHref: " << es->GetXlinkHref() << std::endl;
    std::cout << "   XlinkActuate: " << es->GetXlinkActuate() << std::endl;
    std::cout << "   SchemeIdUri: " << es->GetSchemeIdUri() << std::endl;
    std::cout << "   Value: " << es->GetValue() << std::endl;
    std::cout << "   Timescale: " << es->GetTimescale() << std::endl;
    std::cout << "   PresentationTimeOffset: " << es->GetPresentationTimeOffset() << std::endl;
    */

    /*
     * EventStream, Event in https://github.com/MPEGGroup/DASHSchema/blob/5th-Ed/example_G9.mpd
     */
    
    /*
    const EventStream* es = (EventStream*) mpd->GetPeriods()[0]->GetEventStreams()[0];
    std::cout << "EventStream: " << std::endl;
    std::cout << "   XlinkHref: " << es->GetXlinkHref() << std::endl;
    std::cout << "   XlinkActuate: " << es->GetXlinkActuate() << std::endl;
    std::cout << "   SchemeIdUri: " << es->GetSchemeIdUri() << std::endl;
    std::cout << "   Value: " << es->GetValue() << std::endl;
    std::cout << "   Timescale: " << es->GetTimescale() << std::endl;
    std::cout << "   PresentationTimeOffset: " << es->GetPresentationTimeOffset() << std::endl;
    for (size_t i=0; i < es->GetEvents().size(); i++){
        std::cout << "   Event: " << std::endl;
        std::cout << "       presentationTime: " << es->GetEvents().at(i)->GetPresentationTime() << std::endl;
        std::cout << "       duration: " << es->GetEvents().at(i)->GetDuration() << std::endl;
        std::cout << "       id: " << es->GetEvents().at(i)->GetId() << std::endl;
        std::cout << "       contentEncoding: " << es->GetEvents().at(i)->GetContentEncoding() << std::endl;
        std::cout << "       messageData: " << es->GetEvents().at(i)->GetMessageData() << std::endl;
    }
    */

    /*
     * ServiceDescription, Latency, PlaybackRate, UTCTiming, ProducerReferenceTime in https://livesim.dashif.org/livesim/chunkdur_1/ato_7/testpic4_8s/Manifest300.mpd
     */
    
    /*
    const ServiceDescription* sd = (ServiceDescription*) mpd->GetServiceDescriptions()[0];
    std::cout << "ServiceDescription: " << std::endl;
    std::cout << "   id: " << sd->GetId() << std::endl;
    const Latency* lat = (Latency*) sd->GetLatency()[0];
    std::cout << "   Latency: " << std::endl;
    std::cout << "       referenceId: " << lat->GetReferenceId() << std::endl;
    std::cout << "       target: " << lat->GetTarget() << std::endl;
    std::cout << "       max: " << lat->GetMax() << std::endl;
    std::cout << "       min: " << lat->GetMin() << std::endl;
    const PlaybackRate* pbr = (PlaybackRate*) sd->GetPlaybackRate()[0];
    std::cout << "   PlaybackRate: " << std::endl;
    std::cout << "       max: " << pbr->GetMax() << std::endl;
    std::cout << "       min: " << pbr->GetMin() << std::endl;

    const ProducerReferenceTime* prt = (ProducerReferenceTime*) mpd->GetPeriods()[0]->GetAdaptationSets()[0]->GetProducerReferenceTimes()[0];
    std::cout << "   ProducerReferenceTime: " << std::endl;
    std::cout << "       id: " << prt->GetId() << std::endl;
    std::cout << "       IsInband: " << prt->IsInband() << std::endl;
    std::cout << "       type: " << prt->GetType() << std::endl;
    std::cout << "       applicationScheme: " << prt->GetApplicationScheme() << std::endl;
    std::cout << "       wallClockTime: " << prt->GetWallClockTime() << std::endl;
    std::cout << "       presentationTime: " << prt->GetPresentationTime() << std::endl;
    
    const Descriptor* utcTiming = (Descriptor*) prt->GetUTCTiming();
    if(utcTiming != NULL){
        std::cout << "       UTCTiming: " << std::endl;
        std::cout << "           SchemeIdUri: " << utcTiming->GetSchemeIdUri() << std::endl;
        std::cout << "           Value: " << utcTiming->GetValue() << std::endl;
        std::cout << "           Id: " << utcTiming->GetId() << std::endl;
    }
    */

    /*
     * LeapSecondInformation in https://github.com/MPEGGroup/DASHSchema/blob/5th-Ed/example_G14.mpd
     */
    
    /*
    const LeapSecondInformation* lsi = (LeapSecondInformation*) mpd->GetLeapSecondInformation();
    if(lsi != NULL){
        std::cout << "LeapSecondInformation: " << std::endl;
        std::cout << "   availabilityStartLeapOffset: " << lsi->GetAvailabilityStartLeapOffset() << std::endl;
        std::cout << "   nextAvailabilityStartLeapOffset: " << lsi->GetNextAvailabilityStartLeapOffset() << std::endl;
        std::cout << "   nextLeapChangeTime: " << lsi->GetNextLeapChangeTime() << std::endl;
    }
    */

    /*
     * Preselection in https://github.com/MPEGGroup/DASHSchema/blob/5th-Ed/example_G16.mpd
     */

    /*
    const Preselection* pres = (Preselection*) mpd->GetPeriods()[0]->GetPreselections()[0];
    std::cout << "Preselection: " << std::endl;
    std::cout << "   id: " << pres->GetId() << std::endl;
    std::cout << "   PreselectionComponents: ";
    for (size_t i=0; i < pres->GetPreselectionComponents().size(); i++){
        std::cout << pres->GetPreselectionComponents().at(i) << " ";
    }
    std::cout << std::endl;
    std::cout << "   lang: " << pres->GetLang() << std::endl;
    std::cout << "   order: " << pres->GetOrder() << std::endl;
    */

    /*
     * Resync in https://github.com/MPEGGroup/DASHSchema/blob/5th-Ed/example_G20.mpd
     */

    /*
    const Resync* res = (Resync*) mpd->GetPeriods()[0]->GetAdaptationSets()[0]->GetRepresentation()[2]->GetResyncs()[0];
    std::cout << "Resync: " << std::endl;
    std::cout << "   type: " << res->GetType() << std::endl;
    std::cout << "   dT: " << res->GetDT() << std::endl;
    std::cout << "   dIMax: " << res->GetDIMax() << std::endl;
    std::cout << "   dIMin: " << res->GetDIMin() << std::endl;
    std::cout << "   marker: " << res->HasMarker() << std::endl;
    std::cout << "   rangeAccess: " << res->HasRangeAccess() << std::endl;
    std::cout << "   index: " << res->GetIndex() << std::endl;
    */

    /*
     * FailoverContent, FCS in https://github.com/MPEGGroup/DASHSchema/blob/5th-Ed/example_G20.mpd
     */

    /*
    const FailoverContent* fc = (FailoverContent*) mpd->GetPeriods()[0]->GetAdaptationSets()[0]->GetRepresentation()[2]->GetSegmentBase()->GetFailoverContent();
    std::cout << "FailoverContent: " << std::endl;
    std::cout << "   isValid: " << fc->IsValid() << std::endl;
    for (size_t i=0; i < fc->GetFCS().size(); i++){
        std::cout << "FCS: " << std::endl;
        std::cout << "    presentationTime: " << fc->GetFCS().at(i)->GetPresentationTime() << std::endl;
        std::cout << "    duration: " << fc->GetFCS().at(i)->GetDuration() << std::endl;
    }
    */

    if (mpd)
        mpd->SetFetchTime(fetchTime);

    return mpd;
}
void            DASHManager::Delete ()
{
    delete this;
}
