/*
 * libdash.h
 *****************************************************************************
 * Copyright (C) 2012, bitmovin Softwareentwicklung OG, All Rights Reserved
 *
 * Email: libdash-dev@vicky.bitmovin.net
 *
 * This source code and its use and distribution, is subject to the terms
 * and conditions of the applicable license agreement.
 *****************************************************************************/

#ifndef LIBDASH_H_
#define LIBDASH_H_

#include "config.h"

#if defined _WIN32 || defined _WIN64
#else
#define __declspec(dllexport)
#define __cdecl
#endif

#include "IDASHManager.h"

__declspec(dllexport) dash::IDASHManager* __cdecl CreateDashManager();

#endif /* LIBDASH_H_ */
