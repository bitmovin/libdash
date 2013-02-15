#include "ForcedLogic.h"

using namespace dash::mpd;
using namespace libdash::framework::adaptation;

ForcedLogic::ForcedLogic                                (dash::mpd::IAdaptationSet *adaptationSet, dash::mpd::IMPD *mpd, uint32_t startSegment) : 
                                        AbstractAdaptationLogic(adaptationSet, mpd, startSegment)
{
    this->baseurls.push_back(this->mpd->GetBaseUrls().at(0));
    this->currentRep = this->adaptationSet->GetRepresentation().at(0);
}
ForcedLogic::       ~ForcedLogic                        (void)
{
}
MediaObject*        ForcedLogic::GetSegment             ()
{
    ISegment *seg = NULL;

    if(this->segmentNumber >= this->currentRep->GetSegmentList()->GetSegmentURLs().size() + 1)
        return NULL;

    if(this->segmentNumber == 0)
        seg = this->currentRep->GetSegmentBase()->GetInitialization()->ToSegment(this->baseurls);
    else
        seg = this->currentRep->GetSegmentList()->GetSegmentURLs().at(this->segmentNumber - 1)->ToMediaSegment(this->baseurls);

    MediaObject *media = new MediaObject(seg, this->currentRep);

    this->segmentNumber++;

    return media;
}
void                ForcedLogic::SetRepresentation      (dash::mpd::IRepresentation* newRepresentation)
{
    //TODO: implement
}