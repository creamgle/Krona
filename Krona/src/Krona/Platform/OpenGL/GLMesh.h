#pragma once

#include "KronaCore.h"
#include "Krona/Renderer/Mesh.h"

#include <vector>

namespace Krona {

    class GLMesh : public Mesh {
        public:
            GLMesh(std::vector<Vertex> vertices, std::vector<uint32_t> triangles);
            ~GLMesh() override;

            void Draw() override;

        private:
            void Generate();

            std::vector<Vertex> mVertices;
            std::vector<uint32_t> mTriangles;

            uint32_t mVao;
    };

}