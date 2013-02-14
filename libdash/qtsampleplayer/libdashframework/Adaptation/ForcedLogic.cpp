#include "ForcedLogic.h"

using namespace libdash::framework::adaptation;

ForcedLogic::ForcedLogic(dash::mpd::IAdaptationSet *adaptationSet, dash::mpd::IMPD *mpd, uint32_t startSegment) : 
                    AbstractAdaptationLogic(adaptationSet, mpd, startSegment)
{
}
ForcedLogic::~ForcedLogic(void)
{
}
MediaObject* ForcedLogic::GetSegment ()
{
    return NULL;
}