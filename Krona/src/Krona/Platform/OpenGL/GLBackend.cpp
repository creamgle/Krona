#include "GLBackend.h"

#include <glad/glad.h>

namespace Krona {

    void GLBackend::SetViewport(uint32_t x, uint32_t y, uint32_t width, uint32_t height) {
        glViewport(x, y, width, height);
    }

    void GLBackend::SetClearColor(float r, float g, float b, float a) {
        glClearColor(r, g, b, a);
    }

    void GLBackend::ClearScreen() {
        glClear(GL_COLOR_BUFFER_BIT);
    }

}