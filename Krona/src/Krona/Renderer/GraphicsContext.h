#pragma once

#include "KronaCore.h"

namespace Krona {

    class KRAPI GraphicsContext {
        public:
            virtual ~GraphicsContext() = default;

            static Ref<GraphicsContext> Create(void* handle);

            virtual bool Initialize() = 0;
            virtual void SwapBuffers() = 0;
    };

}