/*
 * DASHPlayer.h
 *****************************************************************************
 * Copyright (C) 2012, bitmovin Softwareentwicklung OG, All Rights Reserved
 *
 * Email: libdash-dev@vicky.bitmovin.net
 *
 * This source code and its use and distribution, is subject to the terms
 * and conditions of the applicable license agreement.
 *****************************************************************************/

#ifndef DASHPLAYER_H_
#define DASHPLAYER_H_

#include "libdash.h"
#include "IDASHPlayerGuiObserver.h"

class DASHPlayer : public IDASHPlayerGuiObserver
{
public:
	DASHPlayer(void);
	~DASHPlayer(void);

	virtual void OnSettingsChanged (QtSamplePlayerGui* widget, const std::string& v_adaption, const std::string& v_representation, const std::string& a_adaption, const std::string& a_representation);
    virtual void OnURLChanged(QtSamplePlayerGui* widget, const std::string& url);

private:
	dash::IDASHManager* manager;
	dash::mpd::IMPD*		  mpd;
};

#endif /* DASHPLAYER_H_ */
