#include "GLGraphicsContext.h"

#include "Krona/Core/Log.h"

#include "glad/glad.h"
#include "GLFW/glfw3.h"

namespace Krona {

    GLGraphicsContext::GLGraphicsContext(void* handle) : mHandle(handle) {

    }

    GLGraphicsContext::~GLGraphicsContext() { }

    bool GLGraphicsContext::Initialize() {
        glfwMakeContextCurrent((GLFWwindow*)mHandle);

        if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
            Log::Fatal("Failed to load opengl context!");
            return false;
        }

        Log::Info("Successfully created OpenGL context");
        return true;
    }

    void GLGraphicsContext::SwapBuffers() {
        glfwSwapBuffers((GLFWwindow*)mHandle);
    }

}