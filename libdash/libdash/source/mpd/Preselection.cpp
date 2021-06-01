/*
 * Preselection.cpp
 *****************************************************************************
 * Name: Daniele Lorenzi
 * Email: lorenzidaniele.97@gmail.com
 * Date: 2021
 *
 * This source code and its use and distribution, is subject to the terms
 * and conditions of the applicable license agreement.
 *****************************************************************************/

#include "Preselection.h"

using namespace dash::mpd;

Preselection::Preselection    () :
                id("1"),
                lang(""),
                order("undefined")
{
}
Preselection::~Preselection   ()
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

const std::vector<IDescriptor *>&       Preselection::GetAccessibility                 ()  const
{
    return (std::vector<IDescriptor *> &) this->accessibility;
}
void                                    Preselection::AddAccessibity                   (Descriptor *accessibility)
{
    this->accessibility.push_back(accessibility);
}
const std::vector<IDescriptor *>&       Preselection::GetRole                          ()  const
{
    return (std::vector<IDescriptor *> &) this->role;
}
void                                    Preselection::AddRole                          (Descriptor *role)
{
    this->role.push_back(role);
}
const std::vector<IDescriptor *>&       Preselection::GetRating                        ()  const
{
    return (std::vector<IDescriptor *> &) this->rating;
}
void                                    Preselection::AddRating                        (Descriptor *rating)
{
    this->rating.push_back(rating);
}
const std::vector<IDescriptor *>&       Preselection::GetViewpoint                     ()  const
{
    return (std::vector<IDescriptor *> &) this->viewpoint;
}
void                                    Preselection::AddViewpoint                     (Descriptor *viewpoint)
{
    this->viewpoint.push_back(viewpoint);
}
const std::string&                      Preselection::GetId                            ()  const
{
    return this->id;
}
void                                    Preselection::SetId                            (const std::string& id)
{
    this->id = id;
}
const std::vector<std::string>&         Preselection::GetPreselectionComponents        ()  const
{
    return this->preselectionComponents;
}
void                                    Preselection::SetPreselectionComponents        (const std::string& preselectionComponents)
{
    dash::helpers::String::Split(preselectionComponents, ' ', this->preselectionComponents);
}
const std::string&                      Preselection::GetLang                          ()  const
{
    return this->lang;
}
void                                    Preselection::SetLang                          (const std::string& lang)
{
    this->lang = lang;
}
const std::string&                      Preselection::GetOrder                         ()  const
{
    return this->order;
}
void                                    Preselection::SetOrder                         (const std::string& order)
{
    this->order = order;
}