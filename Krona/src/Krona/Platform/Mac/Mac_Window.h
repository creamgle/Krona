#pragma once

#include "Krona/Renderer/GraphicsContext.h"
#include "KronaCore.h"
#include "Krona/Core/Window.h"

// macOS windows use GLFW
struct GLFWwindow;

namespace Krona {

    class Mac_Window : public Window {
        public:
            Mac_Window(const WindowData& data);
            ~Mac_Window() override;

            void PollEvents() override;
            void SwapBuffers() override;
            bool ShouldClose() override;

        private:
            void Initialize();
            void Destroy();

            WindowData mData;
            GLFWwindow* mWindow;

            Ref<GraphicsContext> mContext;
    };

}