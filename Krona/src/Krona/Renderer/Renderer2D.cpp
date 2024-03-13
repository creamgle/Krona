#include "Renderer2D.h"
#include "Krona/Core/Matrix4.h"
#include "Krona/Renderer/BackendRenderer.h"
#include "Krona/Renderer/Primitives.h"

namespace Krona {

    bool Renderer2D::Initialize() {
        const std::string& vSource = R"(
            #version 400

            layout(location=0) in vec3 aPosition;
            uniform mat4 uModel;
            uniform mat4 uProjection;

            void main() {
                gl_Position = uProjection * uModel * vec4(aPosition, 1.0);
            }
        )";
            
        const std::string& fSource = R"(
            #version 400

            layout(location=0) out vec4 oFragColor;

            uniform vec4 uColor;

            void main() {
                oFragColor = vec4(uColor);
            }
        )";

        mBackend = BackendRenderer::Create();
        mQuadMesh = Primitives::CreateQuad(0, 1, 0, 1);

        mShader = Krona::Shader::Create("My Shader", vSource, fSource);
        return true;
    }

    void Renderer2D::SetViewport(uint32_t x, uint32_t y, uint32_t width, uint32_t height) {
        mBackend->SetViewport(x, y, width, height);
    }

    void Renderer2D::SetClearColor(float r, float g, float b, float a) {
        mBackend->SetClearColor(r, g, b, a);
    }

    void Renderer2D::ClearScreen() {
        mBackend->ClearScreen();
    }

    void Renderer2D::DrawRectangle(Vector2 position, Vector2 size, Color color) {
        mShader->Bind();

        mShader->SetUniformMatrix4("uModel", Matrix4::Translate(position.x, position.y, 0) * Matrix4::Scale(size.x, size.y, 0));
        mShader->SetUniformMatrix4("uProjection", Matrix4::Ortho(0, 800, 0, 450, 0.0f, 100.0f));
        mShader->SetUniformFloat4("uColor", color.r, color.g, color.b, color.a);

        mQuadMesh->Draw();
        mShader->Unbind();
    }

}