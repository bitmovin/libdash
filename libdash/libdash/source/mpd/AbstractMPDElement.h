/*
 * AbstractMPDElement.h
 *****************************************************************************
 * Copyright (C) 2013, bitmovin Softwareentwicklung OG, All Rights Reserved
 *
 * Email: libdash-dev@vicky.bitmovin.net
 *
 * This source code and its use and distribution, is subject to the terms
 * and conditions of the applicable license agreement.
 *****************************************************************************/

#ifndef ABSTRACTMPDELEMENT_H_
#define ABSTRACTMPDELEMENT_H_

#include "config.h"

#include "IMPDElement.h"

namespace dash
{
    namespace mpd
    {
        class AbstractMPDElement : public virtual IMPDElement
        {
            public:
                AbstractMPDElement          ();
                virtual ~AbstractMPDElement ();

                virtual const std::vector<xml::INode *>             GetAdditionalSubNodes   ()  const;
                virtual const std::map<std::string, std::string>    GetRawAttributes        ()  const;
                virtual void                                        AddAdditionalSubNode    (xml::INode * node);
                virtual void                                        AddRawAttributes        (std::map<std::string, std::string> attributes);

            private:
                std::vector<xml::INode *>           additionalSubNodes;
                std::map<std::string, std::string>  rawAttributes;
        };
    }
}

#endif /* ABSTRACTMPDELEMENT_H_ */
