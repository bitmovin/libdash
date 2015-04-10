#ifndef VIDEOWALL_H_
#define VIDEOWALL_H_

#include "../libdashframework/Portable/MultiThreading.h"
#include <qimage.h>
#include <QtOpenGL/QGLWidget>
#include <QPaintEvent>

namespace sampleplayer
{
	namespace renderer
	{
		class VideoWall : public QObject
		{
		public:
			VideoWall();
			~VideoWall();
			void draw() const;
			void setPosition(int xPos, int yPos, int zPos);
			void setSize(int width, int height, int depth);
			void setTexture(GLuint *texture);
			QColor getColor();


		private:
			int xPos;
			int yPos;
			int zPos;

			int xRot;
			int yRot;
			int zRot;

			int width;
			int height;
			int depth;
			QColor color;
			QVector<QVector2D> textureCoordinates;
			GLuint texture;
		};
	}
}
#endif

