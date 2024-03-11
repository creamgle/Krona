#include "Window.h"
#include "Krona/Core/Log.h"
#include "KronaCore.h"

#ifdef KR_PLATFORM_MAC
    #include "Krona/Platform/Mac/Mac_Window.h"
#endif

namespace Krona {

    Scope<Window> Window::Create(const WindowData& data) {
        #ifdef KR_PLATFORM_MAC
            return CreateScope<Mac_Window>(data);
        #endif
        Log::Fatal("Cannot create window, unrecognized platform!");
        return nullptr;
    }

}