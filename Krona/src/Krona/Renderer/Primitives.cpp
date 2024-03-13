#include "Primitives.h"
#include "Krona/Renderer/Mesh.h"
#include <vector>

namespace Krona::Primitives {

    Ref<Mesh> CreateQuad(float left, float right, float bottom, float top) {
        std::vector<Vertex> vertices = {
            { { left,  bottom, 0 } },
            { { right, bottom, 0 } },
            { { left,  top,    0 } },
            { { right, top,    0 } }
        };

        std::vector<uint32_t> triangles = {
            0, 1, 2,
            2, 3, 1
        };

        return Mesh::Create(vertices, triangles);
    }

}