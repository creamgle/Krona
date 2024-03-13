#pragma once

#include "KronaCore.h"

namespace Krona {

    class KRAPI BackendRenderer {
        public:
            virtual ~BackendRenderer() = default;

            static Ref<BackendRenderer> Create();

            virtual void SetViewport(uint32_t x, uint32_t y, uint32_t width, uint32_t height) = 0;
            virtual void SetClearColor(float r, float g, float b, float a) = 0;

            virtual void ClearScreen() = 0;
    };

}