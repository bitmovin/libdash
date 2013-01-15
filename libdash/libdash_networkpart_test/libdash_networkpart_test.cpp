/*
 * libdash_networkpart_test.cpp
 *****************************************************************************
 * Copyright (C) 2012, bitmovin Softwareentwicklung OG, All Rights Reserved
 *
 * Email: libdash-dev@vicky.bitmovin.net
 *
 * This source code and its use and distribution, is subject to the terms
 * and conditions of the applicable license agreement.
 *****************************************************************************/

#include "libdash.h"
#include "TestChunk.h"
#include "PersistentHTTPConnection.h"

#include <iostream>
#include <fstream>

#if defined _WIN32 || defined _WIN64
    #include <Windows.h>
#endif

using namespace dash;
using namespace dash::network;
using namespace libdashtest;
using namespace std;

void download(IConnection *connection, IChunk *chunk, ofstream *file)
{
    int     len     = 32768;
    uint8_t *p_data = new uint8_t[32768];

    int ret = 0;
    do
    {
        ret = connection->Read(p_data, len, chunk);
        if(ret > 0)
            file->write((char *)p_data, ret);
    }while(ret > 0);
}

int main()
{
    IDASHManager    *manager        = CreateDashManager();
    HTTPConnection  *httpconnection = new HTTPConnection();

    TestChunk test1chunk("www-itec.uni-klu.ac.at", 80, "/~cmueller/libdashtest/network/test1.txt", 0, 0, false);
    TestChunk test2chunk("www-itec.uni-klu.ac.at", 80, "/~cmueller/libdashtest/network/sintel_trailer-480p.mp4", 0, 0, false);

    httpconnection->Init(&test1chunk);
    httpconnection->Schedule(&test1chunk);

    ofstream file;
    std::cout << "*****************************************" << std::endl;
    std::cout << "* Download files with external HTTP 1.0 *" << std::endl;
    std::cout << "*****************************************" << std::endl;
    std::cout << "Testing download of text file:\t";
    file.open("test1_http_1_0.txt", ios::out | ios::binary);
    download(httpconnection, &test1chunk, &file);
    file.close();
    std::cout << "finished!" << std::endl;

    delete(httpconnection);

    httpconnection = new HTTPConnection();
    httpconnection->Init(&test2chunk);
    httpconnection->Schedule(&test2chunk);
    std::cout << "Testing download of video file:\t";
    file.open("sintel_trailer-480p_http_1_0.mp4", ios::out | ios::binary);
    download(httpconnection, &test2chunk, &file);
    file.close();
    std::cout << "finished!" << std::endl << std::endl;

    std::cout << "*****************************************" << std::endl;
    std::cout << "* Download files with external HTTP 1.1 *" << std::endl;
    std::cout << "*****************************************" << std::endl;
    std::cout << "Testing download of text file:\t";
    PersistentHTTPConnection *peristenthttpconnection = new PersistentHTTPConnection();
    peristenthttpconnection->Init(&test1chunk);
    peristenthttpconnection->Schedule(&test1chunk);
    file.open("test1_http_1_1.txt", ios::out | ios::binary);
    download(peristenthttpconnection, &test1chunk, &file);
    file.close();
    std::cout << "finished!" << std::endl;

    std::cout << "Testing download of video file:\t";
    peristenthttpconnection->Schedule(&test2chunk);
    file.open("sintel_trailer-480p_http_1_1.mp4", ios::out | ios::binary);
    download(peristenthttpconnection, &test2chunk, &file);
    file.close();
    std::cout << "finished!" << std::endl << std::endl;

    delete(peristenthttpconnection);

    getchar();
}
