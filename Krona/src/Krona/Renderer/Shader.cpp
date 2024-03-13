#include "Shader.h"
#include "KronaCore.h"

#ifdef KR_OPENGL
    #include "Krona/Platform/OpenGL/GLShader.h"
#endif

namespace Krona {

    Ref<Shader> Shader::Create(const std::string& name, const std::string& vertexSource, const std::string& fragmentSource) {
        #ifdef KR_OPENGL
            return CreateRef<GLShader>(name, vertexSource, fragmentSource);
        #endif
        Log::Fatal("Failed to create shader! no graphics api is selected!");
        return nullptr;
    }

}