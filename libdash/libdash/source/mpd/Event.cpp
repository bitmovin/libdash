/*
 * Event.cpp
 *****************************************************************************
 * Name: Daniele Lorenzi
 * Email: lorenzidaniele.97@gmail.com
 * Date: 2021
 *
 * This source code and its use and distribution, is subject to the terms
 * and conditions of the applicable license agreement.
 *****************************************************************************/

#include "Event.h"

using namespace dash::mpd;

Event::Event    ()  :
    presentationTime(0),
    contentEncoding(""),
    messageData("")
    
{
}
Event::~Event   ()
{
}

uint64_t            Event::GetPresentationTime    ()  const
{
    return this->presentationTime;
}
void                Event::SetPresentationTime    (uint64_t presentationTime) 
{
    this->presentationTime = presentationTime;
}
const std::string&  Event::GetDuration            ()  const
{
    return this->duration;
}
void                Event::SetDuration            (const std::string& duration) 
{
    this->duration = duration;
}
uint32_t            Event::GetId                  ()  const
{
    return this->id;
}
void                Event::SetId                  (uint32_t id) 
{
    this->id = id;
}
const std::string&  Event::GetContentEncoding     ()  const
{
    return this->contentEncoding;
}
void                Event::SetContentEncoding     (const std::string& contentEncoding) 
{
    this->contentEncoding = contentEncoding;
}
const std::string&  Event::GetMessageData         ()  const
{
    return this->messageData;
}
void                Event::SetMessageData         (const std::string& messageData) 
{
    this->messageData = messageData;
}