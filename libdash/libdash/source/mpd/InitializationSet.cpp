/*
 * InitializationSet.cpp
 *****************************************************************************
 * Name: Daniele Lorenzi
 * Email: lorenzidaniele.97@gmail.com
 * Date: 2021
 *
 * This source code and its use and distribution, is subject to the terms
 * and conditions of the applicable license agreement.
 *****************************************************************************/

#include "InitializationSet.h"

using namespace dash::mpd;

InitializationSet::InitializationSet    () :
                xlinkHref(""),
                xlinkActuate("onRequest"),
                xlinkType("simple"),
                contentType(""),
                par(""),
                maxWidth(0),
                maxHeight(0),
                maxFrameRate(""),
                inAllPeriods(true),
                initialization("")
{
}
InitializationSet::~InitializationSet   ()
{
    for(size_t i = 0; i < this->accessibility.size(); i++)
        delete(this->accessibility.at(i));
    for(size_t i = 0; i < this->role.size(); i++)
        delete(this->role.at(i));
    for(size_t i = 0; i < this->rating.size(); i++)
        delete(this->rating.at(i));
    for(size_t i = 0; i < this->viewpoint.size(); i++)
        delete(this->viewpoint.at(i));
}

const std::vector<IDescriptor *>&       InitializationSet::GetAccessibility                 ()  const
{
    return (std::vector<IDescriptor *> &) this->accessibility;
}
void                                    InitializationSet::AddAccessibity                   (Descriptor *accessibility)
{
    this->accessibility.push_back(accessibility);
}
const std::vector<IDescriptor *>&       InitializationSet::GetRole                          ()  const
{
    return (std::vector<IDescriptor *> &) this->role;
}
void                                    InitializationSet::AddRole                          (Descriptor *role)
{
    this->role.push_back(role);
}
const std::vector<IDescriptor *>&       InitializationSet::GetRating                        ()  const
{
    return (std::vector<IDescriptor *> &) this->rating;
}
void                                    InitializationSet::AddRating                        (Descriptor *rating)
{
    this->rating.push_back(rating);
}
const std::vector<IDescriptor *>&       InitializationSet::GetViewpoint                     ()  const
{
    return (std::vector<IDescriptor *> &) this->viewpoint;
}
void                                    InitializationSet::AddViewpoint                     (Descriptor *viewpoint)
{
    this->viewpoint.push_back(viewpoint);
}
const std::string&                      InitializationSet::GetXlinkHref                     ()  const
{
    return this->xlinkHref;
}
void                                    InitializationSet::SetXlinkHref                     (const std::string& xlinkHref)
{
    this->xlinkHref = xlinkHref;
}
const std::string&                      InitializationSet::GetXlinkActuate                  ()  const
{
    return this->xlinkActuate;
}
void                                    InitializationSet::SetXlinkActuate                  (const std::string& xlinkActuate)
{
    this->xlinkActuate = xlinkActuate;
}
const std::string&                      InitializationSet::GetXlinkType                     ()  const
{
    return this->xlinkType;
}
void                                    InitializationSet::SetXlinkType                     (const std::string& xlinkType)
{
    this->xlinkType = xlinkType;
}
uint32_t                                InitializationSet::GetId                            ()  const
{
    return this->id;
}
void                                    InitializationSet::SetId                            (uint32_t id)
{
    this->id = id;
}
bool                                    InitializationSet::IsInAllPeriods                   () const
{
    return this->inAllPeriods;
}
void                                    InitializationSet::SetInAllPeriods                  (bool inAllPeriods)
{
    this->inAllPeriods = inAllPeriods;
}
const std::string&                      InitializationSet::GetContentType                   ()  const
{
    return this->contentType;
}
void                                    InitializationSet::SetContentType                   (const std::string& contentType)
{
    this->contentType = contentType;
}
const std::string&                      InitializationSet::GetPar                           ()  const
{
    return this->par;
}
void                                    InitializationSet::SetPar                           (const std::string& par)
{
    this->par = par;
}
uint32_t                                InitializationSet::GetMaxWidth                      ()  const
{
    return this->maxWidth;
}
void                                    InitializationSet::SetMaxWidth                      (uint32_t maxWidth)
{
    this->maxWidth = maxWidth;
}
uint32_t                                InitializationSet::GetMaxHeight                     ()  const
{
    return this->maxHeight;
}
void                                    InitializationSet::SetMaxHeight                     (uint32_t maxHeight)
{
    this->maxHeight = maxHeight;
}
const std::string&                      InitializationSet::GetMaxFrameRate                  ()  const
{
    return this->maxFrameRate;
}
void                                    InitializationSet::SetMaxFrameRate                  (const std::string& maxFrameRate)
{
    this->maxFrameRate = maxFrameRate;
}
const std::string&                      InitializationSet::GetInitialization                ()  const
{
    return this->initialization;
}
void                                    InitializationSet::SetInitialization                (const std::string& initialization)
{
    this->initialization = initialization;
}