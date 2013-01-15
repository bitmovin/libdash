/*
 * RepresentationBase.cpp
 *****************************************************************************
 * Copyright (C) 2012, bitmovin Softwareentwicklung OG, All Rights Reserved
 *
 * Email: libdash-dev@vicky.bitmovin.net
 *
 * This source code and its use and distribution, is subject to the terms
 * and conditions of the applicable license agreement.
 *****************************************************************************/

#include "RepresentationBase.h"

using namespace dash::mpd;

RepresentationBase::RepresentationBase  () :
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
                    scanType("")
{
}
RepresentationBase::~RepresentationBase ()
{
    for(size_t i = 0; i < this->framePacking.size(); i++)
        delete(this->framePacking.at(i));
    for(size_t i = 0; i < this->audioChannelConfiguration.size(); i++)
        delete(this->audioChannelConfiguration.at(i));
    for(size_t i = 0; i < this->contentProtection.size(); i++)
        delete(this->contentProtection.at(i));
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
const std::vector<IDescriptor*>&    RepresentationBase::GetContentProtection            () const
{
    return (std::vector<IDescriptor*> &) this->contentProtection;
}
void                                RepresentationBase::AddContentProtection            (Descriptor *contentProtection)
{
    this->contentProtection.push_back(contentProtection);
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
