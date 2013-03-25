/*
 * TCPConnection.cpp
 *****************************************************************************
 * Copyright (C) 2012, bitmovin Softwareentwicklung OG, All Rights Reserved
 *
 * Email: libdash-dev@vicky.bitmovin.net
 *
 * This source code and its use and distribution, is subject to the terms
 * and conditions of the applicable license agreement.
 *****************************************************************************/

#include "TCPConnection.h"

using namespace dash::metrics;

TCPConnection::TCPConnection ()
{
}
TCPConnection::~TCPConnection()
{
}

uint32_t            TCPConnection::TCPId                    () const
{
    return this->tcpId;
}
void                TCPConnection::SetTCPId                 (uint32_t tcpId)
{
    this->tcpId = tcpId;
}
const std::string&  TCPConnection::DestinationAddress       () const
{
    return this->dest;
}
void                TCPConnection::SetDestinationAddress    (const std::string& destAddress)
{
    this->dest = destAddress;
}
double              TCPConnection::ConnectionOpenedTime     () const
{
    return this->tOpen;
}
void                TCPConnection::SetConnectionOpenedTime  (double tOpen)
{
    this->tOpen = tOpen;
}
double              TCPConnection::ConnectionClosedTime     () const
{
    return this->tClose;
}
void                TCPConnection::SetConnectionClosedTime  (double tClose)
{
    this->tClose = tClose;
}
uint64_t            TCPConnection::ConnectionTime           () const
{
    return this->tConnect;
}   
void                TCPConnection::SetConnectionTime        (uint64_t tConnect)
{
    this->tConnect = tConnect;
}
