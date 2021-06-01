/*
 * Label.cpp
 *****************************************************************************
 * Name: Daniele Lorenzi
 * Email: lorenzidaniele.97@gmail.com
 * Date: 2021
 *
 * This source code and its use and distribution, is subject to the terms
 * and conditions of the applicable license agreement.
 *****************************************************************************/

#include "Label.h"

using namespace dash::mpd;

Label::Label    ()  :
    id(0)
    
{
}
Label::~Label   ()
{
}

uint32_t            Label::GetId         ()  const
{
    return this->id;
}
void                Label::SetId         (uint32_t id) 
{
    this->id = id;
}
const std::string&  Label::GetLang       ()  const
{
    return this->lang;
}
void                Label::SetLang       (const std::string& lang) 
{
    this->lang = lang;
}