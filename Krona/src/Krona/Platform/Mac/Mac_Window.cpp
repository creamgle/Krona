#include "Mac_Window.h"

#include "Krona/Core/Log.h"
#include "Krona/Core/Window.h"
#include "Krona/Core/Input.h"
#include "GLFW/glfw3.h"

namespace Krona {

    void GLFWKeyCallback(GLFWwindow* window, int key, int scancode, int action, int mods) {
        Input::SetKey(key, action != GLFW_RELEASE);
    }

    void GLFWCursorPosCallback(GLFWwindow* window, double xpos, double ypos) {
        Input::SetCursorPos(
            static_cast<float>(xpos),
            static_cast<float>(ypos)
        );
    }

    Mac_Window::Mac_Window(const WindowData& data) : mData(data) {
        Initialize();
    }

    Mac_Window::~Mac_Window() {
        Destroy();
    }

    void Mac_Window::Initialize() {
        if (!glfwInit()) {
            Log::Fatal("Failed to initialize GLFW backend!");
            return;
        }

        glfwDefaultWindowHints();

        mWindow = glfwCreateWindow(mData.Width, mData.Height, mData.Title.c_str(), nullptr, nullptr);
        if (!mWindow) {
            Log::Fatal("Failed to create GLFW window!");
            return;
        }
        
        glfwSetKeyCallback(mWindow, GLFWKeyCallback);
        glfwSetCursorPosCallback(mWindow, GLFWCursorPosCallback);
    }

    void Mac_Window::PollEvents() {
        glfwPollEvents();
    }

    void Mac_Window::Destroy() {
        glfwDestroyWindow(mWindow);
        glfwTerminate();
    }

    bool Mac_Window::ShouldClose() {
        return glfwWindowShouldClose(mWindow);
    }

}
