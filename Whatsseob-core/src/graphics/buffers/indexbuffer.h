#pragma once

#include <GL/glew.h>

namespace whatsseob {
	namespace graphics {

		// 6vertex > 4 vertex
		class IndexBuffer
		{
		private:
			GLuint m_BufferID;
			GLuint m_Count;
		public:
			IndexBuffer(GLuint* data, GLsizei count);
			IndexBuffer(GLushort* data, GLsizei count);
			~IndexBuffer();

			void bind() const;
			void unbind() const;

			inline GLuint getCount() const { return m_Count; }

		};

	}
}