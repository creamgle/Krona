#include "BackendRenderer.h"
#include "Krona/Core/Log.h"

#ifdef KR_OPENGL
    #include "Krona/Platform/OpenGL/GLBackend.h"
#endif

namespace Krona {

    Ref<BackendRenderer> BackendRenderer::Create() {
        #ifdef KR_OPENGL
            return CreateRef<GLBackend>();
        #endif
        
        Log::Fatal("Cannot create backend renderer! no rendering api is defined, use KR_OPENGL to use opengl!");
        return nullptr;
    }

}