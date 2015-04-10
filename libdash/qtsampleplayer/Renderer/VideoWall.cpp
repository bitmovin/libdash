#include "VideoWall.h"

using namespace sampleplayer::renderer;

VideoWall::VideoWall()
{
	this->color = QColor::fromCmykF(0.39, 0.39, 0.0, 0.0);
	this->texture = 0;
}


VideoWall::~VideoWall()
{
}

void	VideoWall::draw() const
{
	glBindTexture(GL_TEXTURE_2D, this->texture);
	//FRONT
	glBegin(GL_QUADS);
	glNormal3f(0, 0, -1);
	glTexCoord2f(0, 1);
	glVertex3f(-1, 1, 1);
	glTexCoord2f(0, 0);
	glVertex3f(-1, -1, 1);
	glTexCoord2f(1, 0);
	glVertex3f(1, -1, 1);
	glTexCoord2f(1, 1);
	glVertex3f(1, 1, 1);
	glEnd();

	//RIGHT
	glBegin(GL_QUADS);
	glNormal3f(0, 0, -1);
	glTexCoord2f(0, 1);
	glVertex3f(1, 1, 1);
	glTexCoord2f(0, 0);
	glVertex3f(1, -1, 1);
	glTexCoord2f(1, 0);
	glVertex3f(1, -1, -1);
	glTexCoord2f(1, 1);
	glVertex3f(1, 1, -1);
	glEnd();

	//TOP
	glBegin(GL_QUADS);
	glNormal3f(0, 0, -1);
	glTexCoord2f(1, 0);
	glVertex3f(1, 1, 1);
	glTexCoord2f(1, 1);
	glVertex3f(1, 1, -1);
	glTexCoord2f(0, 1);
	glVertex3f(-1, 1, -1);
	glTexCoord2f(0, 0);
	glVertex3f(-1, 1, 1);
	glEnd();

	//LEFT
	glBegin(GL_QUADS);
	glNormal3f(0, 0, -1);
	glTexCoord2f(1, 1);
	glVertex3f(-1, 1, 1);
	glTexCoord2f(0, 1);
	glVertex3f(-1, 1, -1);
	glTexCoord2f(0, 0);
	glVertex3f(-1, -1, -1);
	glTexCoord2f(1, 0);
	glVertex3f(-1, -1, 1);
	glEnd();

	//BOTTOM
	glBegin(GL_QUADS);
	glNormal3f(0, 0, -1);
	glTexCoord2f(0, 1);
	glVertex3f(-1, -1, 1);
	glTexCoord2f(0, 0);
	glVertex3f(-1, -1, -1);
	glTexCoord2f(1, 0);
	glVertex3f(1, -1, -1);
	glTexCoord2f(1, 1);
	glVertex3f(1, -1, 1);
	glEnd();

	//BACK
	glBegin(GL_QUADS);
	glNormal3f(0, 0, -1);
	glTexCoord2f(0, 0);
	glVertex3f(1, -1, -1);
	glTexCoord2f(1, 0);
	glVertex3f(-1, -1, -1);
	glTexCoord2f(1, 1);
	glVertex3f(-1, 1, -1);
	glTexCoord2f(0, 1);
	glVertex3f(1, 1, -1);
	glEnd();
}

void	VideoWall::setPosition(int xPos, int yPos, int zPos)
{

}

void	VideoWall::setSize(int width, int size, int depth)
{

}

void	VideoWall::setTexture(GLuint *texture)
{
	this->texture = *texture;
}

QColor	VideoWall::getColor()
{
	return this->color;
}
