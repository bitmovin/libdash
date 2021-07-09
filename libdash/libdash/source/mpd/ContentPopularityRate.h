/*
 * ContentPopularityRate.h
 ***************************************************************************** *
 * Name: Daniele Lorenzi
 * Email: lorenzidaniele.97@gmail.com
 * Date: 2021
 *
 * This source code and its use and distribution, is subject to the terms
 * and conditions of the applicable license agreement.
 *****************************************************************************/
 
#ifndef CONTENTPOPULARITYRATE_H_
#define CONTENTPOPULARITYRATE_H_

#include "config.h"

#include "IContentPopularityRate.h"
#include "PopularityRate.h"
#include "AbstractMPDElement.h"

namespace dash
{
    namespace mpd
    {
        class ContentPopularityRate : public IContentPopularityRate, public AbstractMPDElement
        {
            public:
                ContentPopularityRate             ();
                virtual ~ContentPopularityRate    ();

                const std::vector<IPopularityRate *>&   GetPopularityRates                 () const;
                const std::string&                      GetSource                          () const;
                const std::string&                      GetSourceDescription               () const;

                void    AddPopularityRate        (PopularityRate *popularityRate);
                void    SetSource                (const std::string& source);
                void    SetSourceDescription     (const std::string& sourceDescription);

            private:
                std::vector<PopularityRate*>       popularityRates;
                std::string                        source;
                std::string                        sourceDescription;
        };
    }
}

#endif /* CONTENTPOPULARITYRATE_H_ */
