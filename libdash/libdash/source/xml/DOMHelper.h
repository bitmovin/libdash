/*
 * DOMHelper.h
 *****************************************************************************
 * Copyright (C) 2012, bitmovin Softwareentwicklung OG, All Rights Reserved
 *
 * Email: libdash-dev@vicky.bitmovin.net
 *
 * This source code and its use and distribution, is subject to the terms
 * and conditions of the applicable license agreement.
 *****************************************************************************/

#ifndef DOMHELPER_H_
#define DOMHELPER_H_

#include "config.h"

#include "Node.h"

namespace dash
{
    namespace xml
    {
        class DOMHelper
        {
            public:
                static std::vector<Node *> GetElementByTagName      (Node *root, const std::string &name, bool selfContain);
                static std::vector<Node *> GetChildElementByTagName (Node *root, const std::string &name);

            private:
                static void GetElementsByTagName(Node *root, const std::string &name, std::vector<Node *> *elements, bool selfContain);
        };
    }
}

#endif /* DOMHELPER_H_ */
