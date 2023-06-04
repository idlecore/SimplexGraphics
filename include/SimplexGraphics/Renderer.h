#ifndef SIMPLEX_GRAPHICS_RENDERER
#define SIMPLEX_GRAPHICS_RENDERER

#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <vector>
#include "simplexgraphics_export.h"
#include "SimplexCommon/Object.h"

namespace Simplex
{
    namespace Graphics
    {
        class SIMPLEXGRAPHICS_EXPORT Renderer
        {
            public:
                Renderer(int width, int height);
                ~Renderer();

                void Render(std::vector<Simplex::Common::Object> *objects);

            private:
                GLFWwindow* m_window;
                int m_width;
                int m_height;

        };
    }
}

#endif