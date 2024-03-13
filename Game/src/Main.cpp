#include "Krona/Core/Log.h"
#include "Krona/Core/Application.h"
#include "Krona/Core/Input.h"
#include "Krona/Core/Matrix4.h"
#include "Krona/Renderer/BackendRenderer.h"
#include "Krona/Renderer/Mesh.h"
#include "Krona/Renderer/Renderer2D.h"
#include "Krona/Renderer/Shader.h"
#include "KronaCore.h"
#include <string>
#include <vector>

class MyApplication : public Krona::Application {
    protected:
        bool Create() override {
            Krona::Log::Info("Starting my application...");

            return true;
        }
        
        void Update() override {
            Krona::Renderer2D::SetClearColor(0.2, 0.2, 0.2, 1);
            Krona::Renderer2D::ClearScreen();

            Krona::Renderer2D::DrawRectangle({ 100, 100 }, { 100, 100 }, { 1, 0, 1, 1 });
            Krona::Renderer2D::DrawRectangle({ 200, 300 }, { 200, 100 }, { 0, 1, 1, 1 });
        }
};

int main() {
    Krona::Application* app = new MyApplication();
    app->Run();
    delete app;
}
