/*
 * DOMParser.cpp
 *****************************************************************************
 * Copyright (C) 2012, bitmovin Softwareentwicklung OG, All Rights Reserved
 *
 * Email: libdash-dev@vicky.bitmovin.net
 *
 * This source code and its use and distribution, is subject to the terms
 * and conditions of the applicable license agreement.
 *****************************************************************************/

#include "DOMParser.h"

using namespace dash::xml;
using namespace dash::helpers;

DOMParser::DOMParser    (std::string url) :
           url          (url),
           reader       (NULL),
           root         (NULL)
{
    this->Init();
}
DOMParser::~DOMParser   ()
{
    xmlCleanupParser();
    delete(this->root);
}

Node*   DOMParser::GetRootNode              () const
{
    return this->root;
}
bool    DOMParser::Parse                    ()
{
    this->reader = xmlReaderForFile(this->url.c_str(), NULL, 0);

    if(this->reader == NULL)
        return false;

    if(xmlTextReaderRead(this->reader)) 
        this->root = this->ProcessNode();

    if(this->root == NULL)
        return false;

    xmlFreeTextReader(this->reader);

    return true;
}
Node*   DOMParser::ProcessNode              ()
{
    int type = xmlTextReaderNodeType(this->reader);

    if(type != WhiteSpace && type != Text)
    {
        while (type == Comment || type == WhiteSpace)
        {
            xmlTextReaderRead(this->reader);
            type = xmlTextReaderNodeType(this->reader);
        }

        Node *node = new Node();
        node->SetType(type);
        node->SetMPDPath(Path::GetDirectoryPath(url));

        if(xmlTextReaderConstName(this->reader) == NULL)
        {
            delete node;
            return NULL;
        }

        std::string name    = (const char *) xmlTextReaderConstName(this->reader);
        int         isEmpty = xmlTextReaderIsEmptyElement(this->reader);

        node->SetName(name);

        this->AddAttributesToNode(node);

        if(isEmpty)
            return node;

        Node    *subnode    = NULL;
        int     ret         = xmlTextReaderRead(this->reader);

        while(ret == 1)
        {
            if(!strcmp(name.c_str(), (const char *) xmlTextReaderConstName(this->reader)))
            {
                return node;
            }

            subnode = this->ProcessNode();

            if(subnode != NULL)
                node->AddSubNode(subnode);

            ret = xmlTextReaderRead(this->reader);
        }

        return node;
    } else if (type == Text)
    {
       const char* text = (const char *) xmlTextReaderReadString(this->reader);

       if(text != NULL)
       {
           Node *node = new Node();
           node->SetType(type);
           node->SetText(text);
           return node;
       }
    }
    return NULL;
}
void    DOMParser::AddAttributesToNode      (Node *node)
{
    if(xmlTextReaderHasAttributes(this->reader))
    {
        while(xmlTextReaderMoveToNextAttribute(this->reader))
        {
            std::string key      = (const char *) xmlTextReaderConstName(this->reader);
            std::string value    = (const char *) xmlTextReaderConstValue(this->reader);
            node->AddAttribute(key, value);
        }
    }
}
void    DOMParser::Print                    (Node *node, int offset)
{
    std::stringstream ss;
    for(int i = 0; i < offset; i++)
        ss << " ";
    ss << node->GetName();

    std::vector<std::string> keys = node->GetAttributeKeys();

    ss.clear();
    for(unsigned int i = 0; i < keys.size(); i++)
    {
        ss << " " << keys.at(i) << "=" << node->GetAttributeValue(keys.at(i));
    }

    offset++;

    for(unsigned int i = 0; i < node->GetSubNodes().size(); i++)
    {
        this->Print(node->GetSubNodes().at(i), offset);
    }
}
void    DOMParser::Init                     ()
{
    this->root      = NULL;
    this->reader    = NULL;
}
void    DOMParser::Print                    ()
{
    this->Print(this->root, 0);
}
