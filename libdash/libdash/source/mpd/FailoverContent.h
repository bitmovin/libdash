/*
 * FailoverContent.h
 ***************************************************************************** *
 * Name: Daniele Lorenzi
 * Email: lorenzidaniele.97@gmail.com
 * Date: 2021
 *
 * This source code and its use and distribution, is subject to the terms
 * and conditions of the applicable license agreement.
 *****************************************************************************/
 
#ifndef FAILOVERCONTENT_H_
#define FAILOVERCONTENT_H_

#include "config.h"

#include "IFailoverContent.h"
#include "AbstractMPDElement.h"
#include "FCS.h"

namespace dash
{
    namespace mpd
    {
        class FailoverContent : public IFailoverContent, public AbstractMPDElement
        {
            public:
                FailoverContent             ();
                virtual ~FailoverContent    ();

                std::vector<IFCS *>&          GetFCS           ()  const;
                bool                          IsValid          ()  const;

                void    AddFCS              (FCS *fcs_el);
                void    SetValid            (bool valid);

            protected:
                std::vector<IFCS *> fcs;
                bool                valid;
        };
    }
}

#endif /* FAILOVERCONTENT_H_ */
