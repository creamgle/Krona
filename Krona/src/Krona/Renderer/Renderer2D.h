#pragma once

#include "Krona/Core/Vector2.h"
#include "Krona/Renderer/Color.h"
#include "Krona/Renderer/Mesh.h"
#include "Krona/Renderer/Shader.h"
#include "KronaCore.h"
#include "BackendRenderer.h"

namespace Krona {

    class KRAPI Renderer2D {
        public:
            static bool Initialize();

            static void SetViewport(uint32_t x, uint32_t y, uint32_t width, uint32_t height);
            static void SetClearColor(float r, float g, float b, float a);

            static void ClearScreen();

            static void DrawRectangle(Vector2 position, Vector2 size, Color color);

        private:
            Renderer2D() = default;
            ~Renderer2D() = default;

            inline static Ref<BackendRenderer> mBackend = nullptr;

            inline static Ref<Mesh> mQuadMesh;
            inline static Ref<Shader> mShader;
    };

}