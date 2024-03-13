#pragma once

#include "KronaCore.h"
#include <string>

namespace Krona {

    struct WindowData {
        std::string Title;
        uint32_t Width;
        uint32_t Height;

        WindowData (
            const std::string& title = "Made with Krona engine!",
            uint32_t width = 800,
            uint32_t height = 450
        ) : Title(title), Width(width), Height(height) { }   
    };

    class KRAPI Window {
        public:
            virtual ~Window() = default;

            static Scope<Window> Create(const WindowData& data = WindowData());

            virtual void PollEvents() = 0;
            virtual void SwapBuffers() = 0;
            virtual bool ShouldClose() = 0;
    };

}