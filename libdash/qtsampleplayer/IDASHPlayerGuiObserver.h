/*
 * IDASHPlayerGuiObserver.h
 *****************************************************************************
 * Copyright (C) 2012, bitmovin Softwareentwicklung OG, All Rights Reserved
 *
 * Email: libdash-dev@vicky.bitmovin.net
 *
 * This source code and its use and distribution, is subject to the terms
 * and conditions of the applicable license agreement.
 *****************************************************************************/
#ifndef IDASHPLAYERGUIOBSERVER_H_
#define IDASHPLAYERGUIOBSERVER_H_

#include <string>
#include "QtSamplePlayerGui.h"
namespace dash {
	namespace sampleplayer {
		class IDASHPlayerGuiObserver
		{
		public:
			virtual ~IDASHPlayerGuiObserver() {}

			virtual void OnSettingsChanged (QtSamplePlayerGui* widget, int video_adaption, int video_representation, int audio_adaption, int audio_representation) = 0;
			virtual void OnURLChanged(QtSamplePlayerGui* widget, const std::string& url) = 0;
		};
	}
}
#endif /* IDASHPLAYERGUIOBSERVER_H_ */
