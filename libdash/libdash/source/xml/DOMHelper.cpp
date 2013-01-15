/*
 * DOMHelper.cpp
 *****************************************************************************
 * Copyright (C) 2012, bitmovin Softwareentwicklung OG, All Rights Reserved
 *
 * Email: libdash-dev@vicky.bitmovin.net
 *
 * This source code and its use and distribution, is subject to the terms
 * and conditions of the applicable license agreement.
 *****************************************************************************/

#include "DOMHelper.h"

using namespace dash::xml;

std::vector<Node *> DOMHelper::GetElementByTagName      (Node *root, const std::string &name, bool selfContain)
{
    std::vector<Node *> elements;

    for(unsigned int i = 0; i < root->GetSubNodes().size(); i++)
    {
        GetElementsByTagName(root->GetSubNodes().at(i), name, &elements, selfContain);
    }

    return elements;
}
std::vector<Node *> DOMHelper::GetChildElementByTagName (Node *root, const std::string &name)
{
    std::vector<Node *> elements;

    for(unsigned int i = 0; i < root->GetSubNodes().size(); i++)
    {
        if(!root->GetSubNodes().at(i)->GetName().compare(name))
            elements.push_back(root->GetSubNodes().at(i));
    }

    return elements;
}
void                DOMHelper::GetElementsByTagName     (Node *root, const std::string &name, std::vector<Node*> *elements, bool selfContain)
{
    if(!selfContain && !root->GetName().compare(name))
    {
        elements->push_back(root);
        return;
    }

    if(!root->GetName().compare(name))
        elements->push_back(root);

    for(unsigned int i = 0; i < root->GetSubNodes().size(); i++)
    {
        GetElementsByTagName(root->GetSubNodes().at(i), name, elements, selfContain);
    }
}
