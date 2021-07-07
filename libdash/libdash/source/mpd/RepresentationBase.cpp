/*
 * RepresentationBase.cpp
 *****************************************************************************
 * Copyright (C) 2012, bitmovin Softwareentwicklung OG, All Rights Reserved
 *
 * Email: libdash-dev@vicky.bitmovin.net
 *
 * @contributor        Daniele Lorenzi
 * @contributoremail   lorenzidaniele.97@gmail.com
 * @contributiondate   2021
 * 
 * This source code and its use and distribution, is subject to the terms
 * and conditions of the applicable license agreement.
 *****************************************************************************/

#include "RepresentationBase.h"

using namespace dash::mpd;

RepresentationBase::RepresentationBase  () :
                    outputProtection(NULL),
                    width(0),
                    height(0),
                    sar(""),
                    frameRate(""),
                    audioSamplingRate(""),
                    mimeType(""),
                    maximumSAPPeriod(0.0),
                    startWithSAP(0),
                    maxPlayoutRate(0.0),
                    codingDependency(false),
                    scanType(""),
                    selectionPriority(1)
{
}
RepresentationBase::~RepresentationBase ()
{
    for(size_t i = 0; i < this->framePacking.size(); i++)
        delete(this->framePacking.at(i));
    for(size_t i = 0; i < this->audioChannelConfiguration.size(); i++)
        delete(this->audioChannelConfiguration.at(i));
    for(size_t i = 0; i < this->contentProtections.size(); i++)
        delete(this->contentProtections.at(i));
    for(size_t i = 0; i < this->essentialProperties.size(); i++)
        delete(this->essentialProperties.at(i));
    for(size_t i = 0; i < this->supplementalProperties.size(); i++)
        delete(this->supplementalProperties.at(i));
    for(size_t i = 0; i < this->eventStreams.size(); i++)
        delete(this->eventStreams.at(i));
    for(size_t i = 0; i < this->switchings.size(); i++)
        delete(this->switchings.at(i));
    for(size_t i = 0; i < this->randomAccesses.size(); i++)
        delete(this->randomAccesses.at(i));
    for(size_t i = 0; i < this->groupLabels.size(); i++)
        delete(this->groupLabels.at(i));
    for(size_t i = 0; i < this->labels.size(); i++)
        delete(this->labels.at(i));
    for(size_t i = 0; i < this->contentPopularityRates.size(); i++)
        delete(this->contentPopularityRates.at(i));
    for(size_t i = 0; i < this->producerReferenceTimes.size(); i++)
        delete(this->producerReferenceTimes.at(i));
    for(size_t i = 0; i < this->resyncs.size(); i++)
        delete(this->resyncs.at(i));
    delete(outputProtection);
}

const std::vector<IDescriptor*>&    RepresentationBase::GetFramePacking                 () const 
{
    return (std::vector<IDescriptor*> &) this->framePacking;
}
void                                RepresentationBase::AddFramePacking                 (Descriptor *framePacking) 
{
    this->framePacking.push_back(framePacking);
}
const std::vector<IDescriptor*>&    RepresentationBase::GetAudioChannelConfiguration    () const
{
    return (std::vector<IDescriptor*> &) this->audioChannelConfiguration;
}
void                                RepresentationBase::AddAudioChannelConfiguration    (Descriptor *audioChannelConfiguration)
{
    this->audioChannelConfiguration.push_back(audioChannelConfiguration);
}
const std::vector<IContentProtection*>&    RepresentationBase::GetContentProtections    () const
{
    return (std::vector<IContentProtection*> &) this->contentProtections;
}
void                                RepresentationBase::AddContentProtection            (ContentProtection *contentProtection)
{
    this->contentProtections.push_back(contentProtection);
}
const IDescriptor*                  RepresentationBase::GetOutputProtection             () const
{
    return this->outputProtection;
}
void                                RepresentationBase::SetOutputProtection             (Descriptor *outputProtection)
{
    this->outputProtection = outputProtection;
}
const std::vector<IDescriptor *>&   RepresentationBase::GetEssentialProperties          () const 
{
    return (std::vector<IDescriptor *> &) this->essentialProperties;
}
void                                RepresentationBase::AddEssentialProperty            (Descriptor *essentialProperty)
{
    this->essentialProperties.push_back(essentialProperty);
}
const std::vector<IDescriptor *>&   RepresentationBase::GetSupplementalProperties       () const 
{
    return (std::vector<IDescriptor *> &) this->supplementalProperties;
}
void                                RepresentationBase::AddSupplementalProperty         (Descriptor *supplementalProperty)
{
    this->supplementalProperties.push_back(supplementalProperty);
}
const std::vector<IEventStream *>&  RepresentationBase::GetEventStreams                 ()  const
{
    return (std::vector<IEventStream *> &) this->eventStreams;
}
void                                RepresentationBase::AddEventStream                  (EventStream *eventStream)
{
    this->eventStreams.push_back(eventStream);
}
const std::vector<ISwitching *>&    RepresentationBase::GetSwitchings                   ()  const
{
    return (std::vector<ISwitching *> &) this->switchings;
}
void                                RepresentationBase::AddSwitching                    (Switching *switching)
{
    this->switchings.push_back(switching);
}
const std::vector<IRandomAccess *>&    RepresentationBase::GetRandomAccesses            ()  const
{
    return (std::vector<IRandomAccess *> &) this->randomAccesses;
}
void                                   RepresentationBase::AddRandomAccess              (RandomAccess *randomAccess)
{
    this->randomAccesses.push_back(randomAccess);
}
const std::vector<ILabel *>&        RepresentationBase::GetGroupLabels                  ()  const
{
    return (std::vector<ILabel *> &) this->groupLabels;
}
void                                RepresentationBase::AddGroupLabel                   (Label *groupLabel)
{
    this->groupLabels.push_back(groupLabel);
}
const std::vector<ILabel *>&        RepresentationBase::GetLabels                       ()  const
{
    return (std::vector<ILabel *> &) this->labels;
}
void                                RepresentationBase::AddLabel                        (Label *label)
{
    this->labels.push_back(label);
}
const std::vector<IContentPopularityRate *>&   RepresentationBase::GetContentPopularityRates   ()  const
{
    return (std::vector<IContentPopularityRate *> &) this->contentPopularityRates;
}
void                                           RepresentationBase::AddContentPopularityRate    (ContentPopularityRate *contentPopularityRate)
{
    this->contentPopularityRates.push_back(contentPopularityRate);
}
const std::vector<IProducerReferenceTime *>&   RepresentationBase::GetProducerReferenceTimes   ()  const
{
    return (std::vector<IProducerReferenceTime *> &) this->producerReferenceTimes;
}
void                                           RepresentationBase::AddProducerReferenceTime    (ProducerReferenceTime *producerReferenceTime)
{
    this->producerReferenceTimes.push_back(producerReferenceTime);
}
const std::vector<IResync *>&                  RepresentationBase::GetResyncs                  ()  const
{
    return (std::vector<IResync *> &) this->resyncs;
}
void                                           RepresentationBase::AddResync                   (Resync *resync)
{
    this->resyncs.push_back(resync);
}
const std::vector<std::string>&     RepresentationBase::GetProfiles                     () const
{
    return this->profiles;
}
void                                RepresentationBase::SetProfiles                     (const std::string& profiles)
{
    dash::helpers::String::Split(profiles, ',', this->profiles);
}
uint32_t                            RepresentationBase::GetWidth                        () const
{
    return this->width;
}
void                                RepresentationBase::SetWidth                        (uint32_t width)
{
    this->width = width;
}
uint32_t                            RepresentationBase::GetHeight                       () const
{
    return this->height;
}
void                                RepresentationBase::SetHeight                       (uint32_t height)
{
    this->height = height;
}
std::string                         RepresentationBase::GetSar                          () const
{
    return this->sar;
}
void                                RepresentationBase::SetSar                          (const std::string& sar)
{
    this->sar = sar;
}
std::string                         RepresentationBase::GetFrameRate                    () const
{
    return this->frameRate;
}
void                                RepresentationBase::SetFrameRate                    (const std::string& frameRate)
{
    this->frameRate = frameRate;
}
std::string                         RepresentationBase::GetAudioSamplingRate            () const
{
    return this->audioSamplingRate;
}
void                                RepresentationBase::SetAudioSamplingRate            (const std::string& audioSamplingRate)
{
    this->audioSamplingRate = audioSamplingRate;
}
std::string                         RepresentationBase::GetMimeType                     () const
{
    return this->mimeType;
}
void                                RepresentationBase::SetMimeType                     (const std::string& mimeType)
{
    this->mimeType = mimeType;
}
const std::vector<std::string>&     RepresentationBase::GetSegmentProfiles              () const
{
    return this->segmentProfiles;
}
void                                RepresentationBase::SetSegmentProfiles              (const std::string& segmentProfiles)
{
    dash::helpers::String::Split(segmentProfiles, ',', this->segmentProfiles);
}
const std::vector<std::string>&     RepresentationBase::GetCodecs                       () const
{
    return this->codecs;
}
void                                RepresentationBase::SetCodecs                       (const std::string& codecs)
{
    dash::helpers::String::Split(codecs, ',', this->codecs);
}
const std::vector<std::string>&     RepresentationBase::GetContainerProfiles            () const
{
    return this->containerProfiles;
}
void                                RepresentationBase::SetContainerProfiles            (const std::string& containerProfiles)
{
    dash::helpers::String::Split(containerProfiles, ',', this->containerProfiles);
}
double                              RepresentationBase::GetMaximumSAPPeriod             () const
{
    return this->maximumSAPPeriod;
}
void                                RepresentationBase::SetMaximumSAPPeriod             (double maximumSAPPeriod)
{
    this->maximumSAPPeriod = maximumSAPPeriod;
}
uint8_t                             RepresentationBase::GetStartWithSAP                 () const
{
    return this->startWithSAP;
}
void                                RepresentationBase::SetStartWithSAP                 (uint8_t startWithSAP)
{
    this->startWithSAP = startWithSAP;
}
double                              RepresentationBase::GetMaxPlayoutRate               () const
{
    return this->maxPlayoutRate;
}
void                                RepresentationBase::SetMaxPlayoutRate               (double maxPlayoutRate)
{
    this->maxPlayoutRate = maxPlayoutRate;
}
bool                                RepresentationBase::HasCodingDependency             () const
{
    return this->codingDependency;
}
void                                RepresentationBase::SetCodingDependency             (bool codingDependency)
{
    this->codingDependency = codingDependency;
}
std::string                         RepresentationBase::GetScanType                     () const
{
    return this->scanType;
}
void                                RepresentationBase::SetScanType                     (const std::string& scanType)
{
    this->scanType = scanType;
}
uint32_t                             RepresentationBase::GetSelectionPriority            () const
{
    return this->selectionPriority;
}
void                                RepresentationBase::SetSelectionPriority            (uint32_t selectionPriority)
{
    this->selectionPriority = selectionPriority;
}
std::string                          RepresentationBase::GetTag                             () const
{
    return this->tag;
}
void                                RepresentationBase::SetTag                             (const std::string& tag)
{
    this->tag = tag;
}