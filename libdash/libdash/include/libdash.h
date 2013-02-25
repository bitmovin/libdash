/**
 *  libdash.h
 *
 *  @brief      The main interface to the libary that should be used to create a IDASHManager
 *  @details    ...
 *
 *  @author     bitmovin Softwareentwicklung OG \n
 *              Email: libdash-dev@vicky.bitmovin.net
 *  @version    2.1
 *  @date       2013
 *  @copyright  bitmovin Softwareentwicklung OG, All Rights Reserved \n\n
 *              This source code and its use and distribution, is subject to the terms
 *              and conditions of the applicable license agreement.
 */

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
