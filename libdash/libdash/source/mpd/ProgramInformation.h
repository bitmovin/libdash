/*
 * ProgramInformation.h
 *****************************************************************************
 * Copyright (C) 2012, bitmovin Softwareentwicklung OG, All Rights Reserved
 *
 * Email: libdash-dev@vicky.bitmovin.net
 *
 * This source code and its use and distribution, is subject to the terms
 * and conditions of the applicable license agreement.
 *****************************************************************************/

#ifndef PROGRAMINFORMATION_H_
#define PROGRAMINFORMATION_H_

#include "config.h"

#include "IProgramInformation.h"
#include "AbstractMPDElement.h"

namespace dash
{
    namespace mpd
    {
        class ProgramInformation : public IProgramInformation, public AbstractMPDElement
        {
            public:
                ProgramInformation          ();
                virtual ~ProgramInformation ();

                const std::string&  GetTitle                ()  const;
                const std::string&  GetSource               ()  const;
                const std::string&  GetCopyright            ()  const;
                const std::string&  GetLang                 ()  const;
                const std::string&  GetMoreInformationURL   ()  const;

                void    SetTitle                (const std::string& title);
                void    SetSource               (const std::string& source);
                void    SetCopyright            (const std::string& copyright);
                void    SetLang                 (const std::string& lang);
                void    SetMoreInformationURL   (const std::string& moreInformationURL);

            private:
                std::string title;
                std::string source;
                std::string copyright;
                std::string lang;
                std::string moreInformationURL;
        };
    }
}

#endif /* PROGRAMINFORMATION_H_ */
