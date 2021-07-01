#pragma once
#include "renderable2d.h"
namespace whatsseob {
	namespace graphics {


		class Sprite : public Renderable2D
		{
		private:

		public:
			Sprite(float x, float y, float width, float height, maths::vec4 color);


		};
	}
}