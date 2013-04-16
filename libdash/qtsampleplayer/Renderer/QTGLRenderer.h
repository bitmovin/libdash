/*
 * QTGLRenderer.h
 *****************************************************************************
 * Copyright (C) 2013, bitmovin Softwareentwicklung OG, All Rights Reserved
 *
 * Email: libdash-dev@vicky.bitmovin.net
 *
 * This source code and its use and distribution, is subject to the terms
 * and conditions of the applicable license agreement.
 *****************************************************************************/

#ifndef QTGLRENDERER_H_
#define QTGLRENDERER_H_

#include "../libdashframework/Portable/MultiThreading.h"
#include <qimage.h>
#include <QtOpenGL/QGLWidget>
#include <QPaintEvent>

namespace sampleplayer
{
    namespace renderer
    {
        class QTGLRenderer : public QGLWidget
        {
            Q_OBJECT

            public:
                QTGLRenderer            (QWidget *parent = NULL);
                virtual ~QTGLRenderer   ();

                void SetImage   (QImage *image);

            private:
                QImage              img;
                CRITICAL_SECTION    monitorMutex;

            protected:
                void paintEvent (QPaintEvent *paintEvent);
        };
    }
}

#endif /* QTGLRENDERER_H_ */
