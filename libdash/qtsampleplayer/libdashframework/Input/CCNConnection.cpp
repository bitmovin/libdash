/*
 * CCNConnection.cpp
 *****************************************************************************
 * Copyright (C) 2012, bitmovin Softwareentwicklung OG, All Rights Reserved
 *
 * Email: libdash-dev@vicky.bitmovin.net
 *
 * This source code and its use and distribution, is subject to the terms
 * and conditions of the applicable license agreement.
 *****************************************************************************/

#include "CCNConnection.h"

using namespace libdash::framework::input;

using namespace dash;
using namespace dash::network;
using namespace dash::metrics;

CCNConnection::CCNConnection  () :
                peekBufferLen   (0),
                contentLength   (0),
                isInit          (false),
                isScheduled     (false),
                isConn          (false),
                i_name              (NULL),
                p_name              (NULL),
                interest_template   (NULL),
                ccn_get_timeout     (CCN_DEFAULT_TIMEOUT),
                b_last              (false),
                ccnConn             (NULL)
    {

    this->peekBuffer = new uint8_t[PEEKBUFFER];
    std::cout << "create CCN connection";
}

CCNConnection::~CCNConnection ()
{
    delete[] this->peekBuffer;
    if(this->i_name != NULL)
        ccn_charbuf_destroy(&this->i_name);

    if(this->p_name != NULL)
        ccn_charbuf_destroy(&this->p_name);

    if(this->interest_template != NULL)
        ccn_charbuf_destroy(&this->interest_template);

    if(this->cf != NULL)
        ccn_fetch_destroy(cf);

    if(ccnConn != NULL)
    {
        ccn_disconnect(ccnConn);
        ccn_destroy(&ccnConn);
    }
}

int             CCNConnection::Read            (uint8_t *data, size_t len, IChunk *chunk)
{
    int                  rc;
        size_t               length=0;
        const unsigned char  *ptr;
        intmax_t             rcfr;

        if (b_last)
            return 0;

        while(true)
        {
            rc = ccn_fetch_poll(cf);

            rcfr = ccn_fetch_read(fs, data, len/*CCN_CHUNK_SIZE*/);
            if(rcfr == CCN_FETCH_READ_END)
            {
                b_last = true;
                return 0;
            }
            else if(rcfr > 0)
            {
                return (int) rcfr;
            }
            else if(rcfr == CCN_FETCH_READ_TIMEOUT)
            {
                ccn_reset_timeout(fs);
            }
        }
        return rcfr;
}
int             CCNConnection::Peek            (uint8_t *data, size_t len, IChunk *chunk)
{
    return -1;
}
std::string     CCNConnection::PrepareRequest  (IChunk *chunk)
{

    std::string request;

    request = "ccnx:/" + chunk->Host() + chunk->Path();
    b_last = 0;

    return request;
}
bool            CCNConnection::Init            (IChunk *chunk)
{
    std::cout << "init connection" << std::endl;
  /*  if(this->isInit)
        return false;

    if(!this->Connect())
        return false;
    this->isInit = true;
    return this->isInit;*/


    if( this->isConn ){
        std::cout << "already connected" << std::endl;
           return true;
    }

    if( (this->ccnConn = ccn_create()) == NULL )
    {
        std::cout <<"could not get ccn handle with ccn_create()" << std::endl;
        return false;
    }
    if( ccn_connect(this->ccnConn, NULL) == -1)
    {
        std::cout << "could not get connection to local ccn with ccn_connect()" << std::endl;
        return false;
    }
    if( (this->cf = ccn_fetch_new(this->ccnConn)) == NULL){
        std::cout << "fetch new error" << std::endl;
        return false;
    }
    this->isInit = true;
    this->isConn = true;
    return true;
}
bool            CCNConnection::SendData        (std::string data)
{
    std::cout << "GEN INTEREST %s\n" << data.c_str() << std::endl;

  /*  if( !this->isInit)
       if(this->Connect())
           this->isInit = true;
       else
           return false;

    this->i_name = ccn_charbuf_create();

    if( this->i_name == NULL)
       return false;

    printf("CCnX URI: %s  --- already read: %d \n", data.c_str(), sum);

    if(ccn_name_from_uri(this->i_name, data.c_str()) < 0)
    {
       return false;
    }

    fs = ccn_fetch_open(this->cf, this->i_name, data.c_str(), NULL, CCN_FETCH_MAX_PIPELINE, CCN_V_HIGH, 1);

    return true;*/

    struct     ccn_header *c_header;
    int        rc;
    size_t     i_size = 0;

    if( !this->isConn)
        if(this->Init(NULL))
            this->isConn = true;
        else
            return false;

    this->i_name = ccn_charbuf_create();

    if( this->i_name == NULL)
        return false;

    printf("CCnX URI: %s \n", data.c_str());

    if(ccn_name_from_uri(this->i_name, data.c_str()) < 0)
    {
        return false;
    }

    fs = ccn_fetch_open(this->cf, this->i_name, data.c_str(), NULL, CCN_FETCH_MAX_BUFFERS, CCN_V_HIGH, 1);

    return true;
}
bool            CCNConnection::Connect   ()
{
    printf("INIT\n");

    if( this->isConn )
       return true;
    if( (this->ccnConn = ccn_create()) == NULL )
       return false;
    if( ccn_connect(this->ccnConn, NULL) == -1)
       return false;
    if( (this->cf = ccn_fetch_new(this->ccnConn)) == NULL)
       return false;
    return true;
}
bool            CCNConnection::Schedule        (IChunk *chunk)
{
    std::cout <<"Start Scheudle, check conn" << std::endl;
    if(!this->isInit)
        return false;

    std::cout <<"Start Scheudle, check schedule" << std::endl;
    if(this->isScheduled)
        return false;

    std::cout <<"Start Expression of Interest" << std::endl;

    if(this->SendData(this->PrepareRequest(chunk)))
    {
        return this->isScheduled;
    }

    return false;
}

const std::vector<ITCPConnection *>&        CCNConnection::GetTCPConnectionList    () const
{
    return tcpConnections;
}
const std::vector<IHTTPTransaction *>&      CCNConnection::GetHTTPTransactionList  () const
{
    return httpTransactions;
}
