/*
 * ProducerReferenceTime.cpp
 *****************************************************************************
 * Name: Daniele Lorenzi
 * Email: lorenzidaniele.97@gmail.com
 * Date: 2021
 *
 * This source code and its use and distribution, is subject to the terms
 * and conditions of the applicable license agreement.
 *****************************************************************************/

#include "ProducerReferenceTime.h"

using namespace dash::mpd;

ProducerReferenceTime::ProducerReferenceTime    ()  :
                 utcTiming(NULL),
                 inband(false),
                 type("encoder")
{
}
ProducerReferenceTime::~ProducerReferenceTime   ()
{
    delete(utcTiming);
}

const IDescriptor*                      ProducerReferenceTime::GetUTCTiming             () const 
{
    return this->utcTiming;
}
void                                    ProducerReferenceTime::SetUTCTiming             (Descriptor *utcTiming) 
{
    this->utcTiming = utcTiming;
}
uint32_t                                ProducerReferenceTime::GetId                    ()  const
{
    return this->id;
}
void                                    ProducerReferenceTime::SetId                    (uint32_t id)
{
    this->id = id;
}
bool                                    ProducerReferenceTime::IsInband                 ()  const
{
    return this->inband;
}
void                                    ProducerReferenceTime::SetInband                (bool inband)
{
    this->inband = inband;
}
const std::string&                      ProducerReferenceTime::GetType                  ()  const
{
    return this->type;
}
void                                    ProducerReferenceTime::SetType                  (const std::string& type)
{
    this->type = type;
}
const std::string&                      ProducerReferenceTime::GetApplicationScheme     ()  const
{
    return this->applicationScheme;
}
void                                    ProducerReferenceTime::SetApplicationScheme     (const std::string& applicationScheme)
{
    this->applicationScheme = applicationScheme;
}
const std::string&                      ProducerReferenceTime::GetWallClockTime         ()  const
{
    return this->wallClockTime;
}
void                                    ProducerReferenceTime::SetWallClockTime         (const std::string& wallClockTime)
{
    this->wallClockTime = wallClockTime;
}
uint64_t                                ProducerReferenceTime::GetPresentationTime      ()  const
{
    return this->presentationTime;
}
void                                    ProducerReferenceTime::SetPresentationTime      (uint64_t presentationTime)
{
    this->presentationTime = presentationTime;
}