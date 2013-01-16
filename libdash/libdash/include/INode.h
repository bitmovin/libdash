/*
 * INode.h
 *****************************************************************************
 * Copyright (C) 2013, bitmovin Softwareentwicklung OG, All Rights Reserved
 *
 * Email: libdash-dev@vicky.bitmovin.net
 *
 * This source code and its use and distribution, is subject to the terms
 * and conditions of the applicable license agreement.
 *****************************************************************************/

#ifndef INODE_H_
#define INODE_H_

#include "config.h"

namespace dash
{
    namespace xml
    {
        class INode
        {
            public:
                virtual ~INode (){}

                virtual const std::vector<INode *>&                 GetNodes            ()  const = 0;
                virtual std::vector<std::string>                    GetAttributeKeys    ()  const = 0;
                virtual const std::string&                          GetName             ()  const = 0;
                virtual std::string                                 GetText             ()  const = 0;
                virtual const std::map<std::string, std::string>&   GetAttributes       ()  const = 0;
                virtual int                                         GetType             ()  const = 0;
                virtual const std::string&                          GetAttributeValue   (std::string key) const = 0;
                virtual bool                                        HasAttribute        (const std::string& name) const = 0;
                virtual bool                                        HasText             ()  const = 0;
        };
    }
}

#endif /* INODE_H_ */