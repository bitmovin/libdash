/*
 * HTTPTransaction.h
 *****************************************************************************
 * Copyright (C) 2012, bitmovin Softwareentwicklung OG, All Rights Reserved
 *
 * Email: libdash-dev@vicky.bitmovin.net
 *
 * This source code and its use and distribution, is subject to the terms
 * and conditions of the applicable license agreement.
 *****************************************************************************/

#ifndef HTTPTRANSACTION_H_
#define HTTPTRANSACTION_H_

#include "IHTTPTransaction.h"
#include "ThroughputMeasurement.h"

namespace dash
{
    namespace metrics
    {
        class HTTPTransaction : public IHTTPTransaction
        {
            public:
                HTTPTransaction          ();
                virtual ~HTTPTransaction ();

                uint32_t                                        TCPId                   () const;
                HTTPTransactionType                             Type                    () const;
                const std::string&                              OriginalUrl             () const;
                const std::string&                              ActualUrl               () const;
                const std::string&                              Range                   () const;
                const std::string&                              RequestSentTime         () const;
                const std::string&                              ResponseReceivedTime    () const;
                uint16_t                                        ResponseCode            () const;
                uint64_t                                        Interval                () const;
                const std::vector<IThroughputMeasurement *>&    ThroughputTrace         () const;
                const std::string&                              HTTPHeader              () const;

                void    SetTCPId                    (uint32_t tcpId);
                void    SetType                     (HTTPTransactionType type);
                void    SetOriginalUrl              (const std::string& origUrl);
                void    SetActualUrl                (const std::string& actUrl);
                void    SetRange                    (const std::string& range);
                void    SetRequestSentTime          (std::string tRequest);
                void    SetResponseReceivedTime     (std::string tResponse);
                void    SetResponseCode             (uint16_t respCode);
                void    SetInterval                 (uint64_t interval);
                void    AddThroughputMeasurement    (ThroughputMeasurement *throuputEntry);
                void    AddHTTPHeaderLine           (std::string headerLine);

            private:
                uint32_t                                tcpId;
                HTTPTransactionType                     type;
                std::string                             url;
                std::string                             actualUrl;
                std::string                             range;
                std::string                             tRequest;
                std::string                             tResponse;
                uint16_t                                responseCode;
                uint64_t                                interval;
                std::vector<ThroughputMeasurement *>    trace;
                std::string                             httpHeader;
        };
    }
}

#endif /* HTTPTRANSACTION_H_ */
