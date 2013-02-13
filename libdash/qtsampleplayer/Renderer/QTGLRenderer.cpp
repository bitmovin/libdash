/*
 * QTGLRenderer.cpp
 *****************************************************************************
 * Copyright (C) 2013, bitmovin Softwareentwicklung OG, All Rights Reserved
 *
 * Email: libdash-dev@vicky.bitmovin.net
 *
 * This source code and its use and distribution, is subject to the terms
 * and conditions of the applicable license agreement.
 *****************************************************************************/

#include "QTGLRenderer.h"

using namespace sampleplayer::renderer;

QTGLRenderer::QTGLRenderer  (QWidget *parent) :
              QGLWidget     (QGLFormat(QGL::SampleBuffers), parent)
{
    InitializeCriticalSection (&this->monitorMutex);
    setAutoBufferSwap(true);
    setAutoFillBackground(false);
}
QTGLRenderer::~QTGLRenderer ()
{
    DeleteCriticalSection (&this->monitorMutex);
}

void QTGLRenderer::setImage(const QImage& image)
{
    EnterCriticalSection(&this->monitorMutex);
    img = image;
    LeaveCriticalSection(&this->monitorMutex);
}
void    QTGLRenderer::paintEvent            (QPaintEvent *paintEvent)
{
    /* http://stackoverflow.com/questions/1242005/what-is-the-most-efficient-way-to-display-decoded-video-frames-in-qt 
     * http://programanddesign.com/cpp/qt-opengl-code-example/
     * http://qt-project.org/doc/qt-5.0/qtopengl/qglwidget.html
     */
    EnterCriticalSection(&this->monitorMutex);

    QPainter p;
    p.begin(this);
    p.drawImage(paintEvent->rect(), this->img);
    p.end();

    LeaveCriticalSection(&this->monitorMutex);

}
