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
	this->xRot = 0;
	this->yRot = 0;
	this->zRot = 0;
	this->curTex = 0;
	this->qtGreen = QColor::fromCmykF(0.40f, 0.0f, 1.0f, 0.0f);
	this->qtPurple = QColor::fromCmykF(0.39f, 0.39f, 0.0f, 0.0f);

    InitializeCriticalSection (&this->monitorMutex);
	this->initializeGL();
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

void QTGLRenderer::initializeGL()
{
	this->videoWall = new VideoWall();

	//glMatrixMode(GL_PROJECTION);
	//glLoadIdentity();
	//glMatrixMode(GL_MODELVIEW);
	//glLoadIdentity();
	glEnable(GL_DEPTH_TEST);
	glEnable(GL_CULL_FACE);
	glShadeModel(GL_SMOOTH);
	//glEnable(GL_LIGHTING);
	//glEnable(GL_LIGHT0);
	glEnable(GL_TEXTURE_2D);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);

	//static GLfloat lightPosition[4] = { 0.5f, 0.5f, 0.0f, 0.0f };
	//glLightfv(GL_LIGHT0, GL_POSITION, lightPosition);
	//this->qglClearColor(this->qtPurple);
	this->img = QImage("C:\\Users\\David\\Pictures\\tileable9a.png");


}
void QTGLRenderer::paintGL()
{
	EnterCriticalSection(&this->monitorMutex);

	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glLoadIdentity();
	glScalef(0.3f, 0.3f, 0.5f);
	glTranslatef(0.0f, 0.0f, -10.0f);
	glRotatef(xRot / 16.0f, 1.0f, 0.0f, 0.0f);
	glRotatef(yRot / 16.0f, 0.0f, 1.0f, 0.0f);
	glRotatef(zRot / 16.0f, 0.0f, 0.0f, 1.0f);
	deleteTexture(curTex);
	curTex = bindTexture(this->img);
	videoWall->setTexture(&curTex);
	videoWall->draw();

	LeaveCriticalSection(&this->monitorMutex);

}
void QTGLRenderer::resizeGL(int width, int height)
{
	int side = qMin(width, height);
	glViewport((width - side) / 2, (height - side) / 2, side, side);

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
#ifdef QT_OPENGL_ES_1
	glOrthof(-0.5f, +0.5f, -0.5f, +0.5f, 4.0f, 15.0f);
#else
	glOrtho(-0.5f, +0.5f, -0.5f, +0.5f, 4.0f, 15.0f);
#endif
	glMatrixMode(GL_MODELVIEW);
}
QSize QTGLRenderer::minimumSizeHint() const
{
	return QSize(50, 50);
}
QSize QTGLRenderer::sizeHint() const
{
	return QSize(760, 577);
}
static void qNormalizeAngle(int &angle)
{
	while (angle < 0)
		angle += 360 * 16;
	while (angle > 360)
		angle -= 360 * 16;
}
void QTGLRenderer::setXRotation(int angle)
{
	qNormalizeAngle(angle);
	if (angle != xRot) {
		xRot = angle;
		emit xRotationChanged(angle);
		updateGL();
	}
}
void QTGLRenderer::setYRotation(int angle)
{
	qNormalizeAngle(angle);
	if (angle != yRot) {
		yRot = angle;
		emit yRotationChanged(angle);
		updateGL();
	}
}

void QTGLRenderer::setZRotation(int angle)
{
	qNormalizeAngle(angle);
	if (angle != zRot) {
		zRot = angle;
		emit zRotationChanged(angle);
		updateGL();
	}
}
void QTGLRenderer::mousePressEvent(QMouseEvent *event)
{
	lastPos = event->pos();
}
void QTGLRenderer::mouseMoveEvent(QMouseEvent *event)
{
	int dx = event->x() - lastPos.x();
	int dy = event->y() - lastPos.y();

	if (event->buttons() & Qt::LeftButton) {
		setXRotation(xRot + 8 * dy);
		setYRotation(yRot + 8 * dx);
	}
	else if (event->buttons() & Qt::RightButton) {
		setXRotation(xRot + 8 * dy);
		setZRotation(zRot + 8 * dx);
	}

	lastPos = event->pos();
}