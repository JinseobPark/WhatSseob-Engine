#pragma once

#include "layer.h"
#include "../batchRenderer2D.h"

namespace whatsseob {
	namespace graphics {
		class TileLayer : public Layer
		{
		public:
			TileLayer(Shader* shader);
			~TileLayer();
			//virtual ~TileLayer();
			//virtual void add(Renderable2D* renderable);
			//virtual void render();
		};

	}
}