#include "Krona/Core/Log.h"
#include "Krona/Core/Application.h"
#include "Krona/Core/Input.h"
#include <string>

class MyApplication : public Krona::Application {
    protected:
        bool Create() override {
            Krona::Log::Info("Starting my application...");
            return true;
        }
        
        void Update() override {
			if (Krona::Input::GetKeyDown(Krona::KeyCode::E)) {
				Krona::Log::Debug("x: " + std::to_string(Krona::Input::GetX()));
                Krona::Log::Debug("y: " + std::to_string(Krona::Input::GetY()));
            }
        }
};

int main() {
    Krona::Application* app = new MyApplication();
    app->Run();
    delete app;
}
