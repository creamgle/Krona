#pragma once

#include "KronaCore.h"
#include "Krona/Core/Vector3.h"
#include <vector>

namespace Krona {

    struct Vertex {
        Vector3 Position;
    };

    class KRAPI Mesh {
        public:
            virtual ~Mesh() = default;

            static Ref<Mesh> Create(std::vector<Vertex> vertices, std::vector<uint32_t> triangles);

            virtual void Draw() = 0;
    };

}