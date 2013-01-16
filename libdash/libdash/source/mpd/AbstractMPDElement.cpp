/*
 * AbstractMPDElement.cpp
 *****************************************************************************
 * Copyright (C) 2013, bitmovin Softwareentwicklung OG, All Rights Reserved
 *
 * Email: libdash-dev@vicky.bitmovin.net
 *
 * This source code and its use and distribution, is subject to the terms
 * and conditions of the applicable license agreement.
 *****************************************************************************/

#include "AbstractMPDElement.h"

using namespace dash::mpd;
using namespace dash::xml;

AbstractMPDElement::AbstractMPDElement      ()
{
}
AbstractMPDElement::~AbstractMPDElement     ()
{
    for(size_t i = 0; i < this->additionalSubNodes.size(); i++)
        delete(this->additionalSubNodes.at(i));
}

const std::vector<INode *>                  AbstractMPDElement::GetAdditionalSubNodes   ()  const
{
    return this->additionalSubNodes;
}
const std::map<std::string, std::string>    AbstractMPDElement::GetRawAttributes        ()  const
{
    return this->rawAttributes;
}
void                                        AbstractMPDElement::AddAdditionalSubNode    (INode *node)
{
    this->additionalSubNodes.push_back(node);
}
void                                        AbstractMPDElement::AddRawAttributes        (std::map<std::string, std::string> attributes)
{
    this->rawAttributes = attributes;
}