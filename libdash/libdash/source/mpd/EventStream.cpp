/*
 * EventStream.cpp
 *****************************************************************************
 * Name: Daniele Lorenzi
 * Email: lorenzidaniele.97@gmail.com
 * Date: 2021
 *
 * This source code and its use and distribution, is subject to the terms
 * and conditions of the applicable license agreement.
 *****************************************************************************/

#include "EventStream.h"

using namespace dash::mpd;

EventStream::EventStream    ()  :
                 xlinkHref(""),
                 xlinkActuate("onRequest"),
                 schemeIdUri(""),
                 value(""),
                 presentationTimeOffset(0),
                 timescale(1)
{
}
EventStream::~EventStream   ()
{
    for (size_t i=0; i < this->events.size(); i++)
        delete(this->events.at(i));
}

const std::vector<IEvent *>&   EventStream::GetEvents                  ()  const
{
    return (std::vector<IEvent*> &) this->events;
}
void                           EventStream::AddEvent                   (Event *event)
{
    this->events.push_back(event);
}
const std::string&             EventStream::GetXlinkHref               ()  const
{
    return this->xlinkHref;
}
void                           EventStream::SetXlinkHref               (const std::string& xlinkHref)
{
    this->xlinkHref = xlinkHref;
}
const std::string&             EventStream::GetXlinkActuate            ()  const
{
    return this->xlinkActuate;
}
void                           EventStream::SetXlinkActuate            (const std::string& xlinkActuate)
{
    this->xlinkActuate = xlinkActuate;
}
const std::string&             EventStream::GetSchemeIdUri             ()  const
{
    return this->schemeIdUri;
}
void                           EventStream::SetSchemeIdUri             (const std::string& schemeIdUri)
{
    this->schemeIdUri = schemeIdUri;
}
const std::string&             EventStream::GetValue                   ()  const
{
    return this->value;
}
void                           EventStream::SetValue                   (const std::string& value)
{
    this->value = value;
}
uint32_t                       EventStream::GetTimescale               ()  const
{
    return this->timescale;
}
void                           EventStream::SetTimescale               (uint32_t timescale)
{
    this->timescale = timescale;
}
uint64_t                       EventStream::GetPresentationTimeOffset  ()  const
{
    return this->presentationTimeOffset;
}
void                           EventStream::SetPresentationTimeOffset  (uint64_t presentationTimeOffset)
{
    this->presentationTimeOffset = presentationTimeOffset;
}