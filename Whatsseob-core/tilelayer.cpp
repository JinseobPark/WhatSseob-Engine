#include "tilelayer.h"

	TileLayer::TileLayer(whatsseob::graphics::Shader* shader)
		: Layer(new whatsseob::graphics::BatchRenderer2D(), shader, whatsseob::maths::mat4::orthographic(-16.0f, 16.0f, -9.0f, 9.0f, -1.0f, 1.0f))
	{
	}
	TileLayer::~TileLayer()
	{
	}