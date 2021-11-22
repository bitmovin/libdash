/*
 * ServiceDescription.cpp
 *****************************************************************************
 * Name: Daniele Lorenzi
 * Email: lorenzidaniele.97@gmail.com
 * Date: 2021
 *
 * This source code and its use and distribution, is subject to the terms
 * and conditions of the applicable license agreement.
 *****************************************************************************/

#include "ServiceDescription.h"

using namespace dash::mpd;

ServiceDescription::ServiceDescription    ()
{
}
ServiceDescription::~ServiceDescription   ()
{
    for (size_t i=0; i < this->scope.size(); i++)
        delete(this->scope.at(i));
    for (size_t i=0; i < this->latency.size(); i++)
        delete(this->latency.at(i));
    for (size_t i=0; i < this->playbackRate.size(); i++)
        delete(this->playbackRate.at(i));
    for (size_t i=0; i < this->operatingQuality.size(); i++)
        delete(this->operatingQuality.at(i));
    for (size_t i=0; i < this->operatingBandwidth.size(); i++)
        delete(this->operatingBandwidth.at(i));
}

const std::vector<IDescriptor *>&          ServiceDescription::GetScope               ()  const
{
    return (std::vector<IDescriptor *> &) this->scope;
}
void                                       ServiceDescription::AddScope               (Descriptor* scope)
{
    this->scope.push_back(scope);
}
const std::vector<ILatency *>&             ServiceDescription::GetLatency             ()  const
{
    return (std::vector<ILatency *> &) this->latency;
}
void                                       ServiceDescription::AddLatency             (Latency* latency)
{
    this->latency.push_back(latency);
}
const std::vector<IPlaybackRate *>&        ServiceDescription::GetPlaybackRate        ()  const
{
    return (std::vector<IPlaybackRate *> &) this->playbackRate;
}
void                                       ServiceDescription::AddPlaybackRate        (PlaybackRate* playbackRate)
{
    this->playbackRate.push_back(playbackRate);
}
const std::vector<IOperatingQuality *>&    ServiceDescription::GetOperatingQuality    ()  const
{
    return (std::vector<IOperatingQuality *> &) this->operatingQuality;
}
void                                       ServiceDescription::AddOperatingQuality    (OperatingQuality* operatingQuality)
{
    this->operatingQuality.push_back(operatingQuality);
}
const std::vector<IOperatingBandwidth *>&  ServiceDescription::GetOperatingBandwidth  ()  const
{
    return (std::vector<IOperatingBandwidth *> &) this->operatingBandwidth;
}
void                                       ServiceDescription::AddOperatingBandwidth  (OperatingBandwidth* operatingBandwidth)
{
    this->operatingBandwidth.push_back(operatingBandwidth);
}
uint32_t                                   ServiceDescription::GetId                  ()  const
{
    return this->id;
}
void                                       ServiceDescription::SetId                  (uint32_t id)
{
    this->id = id;
}