#pragma once

#include "KronaCore.h"
#include "Krona/Renderer/GraphicsContext.h"

/**
    OpenGL context currently only supports GLFW windows
    there is currently no plan to change this, so mobile OpenGL is 
    not possible, but that doesnt really matter, as Android supports Vulkan,
    and IOS only supports Metal
*/

namespace Krona {

    class GLGraphicsContext : public GraphicsContext {
        public:
            GLGraphicsContext(void* handle);
            ~GLGraphicsContext() override;

            bool Initialize() override;
            void SwapBuffers() override;

        private:
            void* mHandle;
    };

}