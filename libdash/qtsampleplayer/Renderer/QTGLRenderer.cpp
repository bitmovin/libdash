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
    this->setGeometry(9+10,35+30,582,401);
}
QTGLRenderer::~QTGLRenderer ()
{
    DeleteCriticalSection (&this->monitorMutex);
}

void    QTGLRenderer::SetImage      (QImage *image)
{
    EnterCriticalSection(&this->monitorMutex);
    img = *image;
    LeaveCriticalSection(&this->monitorMutex);
}
void    QTGLRenderer::paintEvent    (QPaintEvent *paintEvent)
{
    EnterCriticalSection(&this->monitorMutex);

    QPainter p;
    p.begin(this);
    p.drawImage(this->rect(), this->img);
    p.end();

    LeaveCriticalSection(&this->monitorMutex);
}
