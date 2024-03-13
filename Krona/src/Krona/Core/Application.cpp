#include "Application.h"
#include "Krona/Renderer/Renderer2D.h"
#include "Log.h"
#include "Input.h"

namespace Krona {

    bool Application::Run() {
        mWindow = Window::Create();
        Renderer2D::Initialize();

        if (!Create()) {
            Log::Fatal("Application->Create() returned false");
            return false;
        }

        while (!mWindow->ShouldClose()) {
            Update();
			
			Input::LateUpdate();
            mWindow->SwapBuffers();
			mWindow->PollEvents();
        }

        return true;
    }

}
