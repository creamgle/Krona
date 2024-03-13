#include "Mesh.h"
#include "Krona/Core/Log.h"
#include "KronaCore.h"

#ifdef KR_OPENGL
    #include "Krona/Platform/OpenGL/GLMesh.h"
#endif

namespace Krona {

    Ref<Mesh> Mesh::Create(std::vector<Vertex> vertices, std::vector<uint32_t> triangles) {
        #ifdef KR_OPENGL
            return CreateRef<GLMesh>(vertices, triangles);
        #endif
        
        Log::Fatal("failed to create mesh! no rendering api is selected!");
        return nullptr;
    }

}