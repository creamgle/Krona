#include "Application.h"
#include "Log.h"
#include "Input.h"

namespace Krona {

    bool Application::Run() {
        mWindow = Window::Create();

        if (!Create()) {
            Log::Fatal("Application->Create() returned false");
            return false;
        }

        while (!mWindow->ShouldClose()) {
            Update();
			
			Input::LateUpdate();
			mWindow->PollEvents();
        }

        return true;
    }

}
