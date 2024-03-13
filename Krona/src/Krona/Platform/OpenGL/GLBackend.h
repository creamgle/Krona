#pragma once

#include "KronaCore.h"
#include "Krona/Renderer/BackendRenderer.h"

namespace Krona {

    class GLBackend : public BackendRenderer {
        public:
            GLBackend() = default;
            ~GLBackend() override = default;

            void SetViewport(uint32_t x, uint32_t y, uint32_t width, uint32_t height) override;
            void SetClearColor(float r, float g, float b, float a) override;

            void ClearScreen() override;
    };

}