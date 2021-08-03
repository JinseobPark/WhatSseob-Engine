#pragma once

#include "src/graphics/layers/layer.h"
#include "src/graphics/batchRenderer2D.h"

	class TileLayer : public whatsseob::graphics::Layer
	{
	public:
		TileLayer(whatsseob::graphics::Shader* shader);
		~TileLayer();
		//virtual ~TileLayer();
		//virtual void add(Renderable2D* renderable);
		//virtual void render();
	};
