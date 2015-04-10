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
#include "VideoWall.h"
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
				VideoWall *videoWall;

				int xRot;
				int yRot;
				int zRot;

				GLuint curTex;

				QPoint lastPos;
				QColor qtGreen;
				QColor qtPurple;

			public slots:
			void setXRotation(int angle);
			void setYRotation(int angle);
			void setZRotation(int angle);

			signals:
				void xRotationChanged(int angle);
				void yRotationChanged(int angle);
				void zRotationChanged(int angle);

            protected:
                //void paintEvent (QPaintEvent *paintEvent);
				void initializeGL();
				void paintGL();
				void resizeGL(int width, int height);

				void mousePressEvent(QMouseEvent *event);
				void mouseMoveEvent(QMouseEvent *event);

				QSize minimumSizeHint() const;
				QSize sizeHint() const;
        };
    }
}

#endif /* QTGLRENDERER_H_ */
