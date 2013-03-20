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
#include <qobject.h>
#include "QtSamplePlayerGui.h"

namespace sampleplayer
{
    class IDASHPlayerGuiObserver : public QObject
    {
        Q_OBJECT

        public:
            virtual ~IDASHPlayerGuiObserver() {}

            virtual void OnSettingsChanged      (int period, int videoAdaptationSet, int videoRepresentation, int audioAdaptationSet, int audioRepresentation)  = 0;
            virtual void OnStartButtonPressed   (int period, int videoAdaptationSet, int videoRepresentation, int audioAdaptationSet, int audioRepresentation)  = 0;
            virtual void OnStopButtonPressed    ()                                                                                                              = 0;
            virtual void OnDownloadMPDPressed   (const std::string &url)                                                                                        = 0;
    };
}
#endif /* IDASHPLAYERGUIOBSERVER_H_ */
