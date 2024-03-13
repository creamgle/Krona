#include "GraphicsContext.h"
#include "Krona/Core/Log.h"
#include "KronaCore.h"

#ifdef KR_OPENGL
    #include "Krona/Platform/OpenGL/GLGraphicsContext.h"
#endif

namespace Krona {

    Ref<GraphicsContext> GraphicsContext::Create(void* handle) {
        #ifdef KR_OPENGL
            return CreateRef<GLGraphicsContext>(handle);
        #endif
        Log::Fatal("Failed to get graphics context, use define 'KR_OPENGL' to use opengl!");
        return nullptr;
    }

}