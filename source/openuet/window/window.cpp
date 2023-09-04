#include "window.hpp"

namespace openuet{

    static bool isGLFWWindowCreated = false;

    GLFWwindow* Window::m_Window = nullptr;
    Window::WindowData Window::m_WindowData;

    void Window::Init(const WindowProp& window_props) 
    {  
        m_WindowData.Width = window_props.Width;
        m_WindowData.Height = window_props.Height;
        m_WindowData.Title = window_props.Title;
        m_WindowData.Alive = true;
        m_WindowData.VSync = true;

        if (!isGLFWWindowCreated)
        {
            int glfwIniti = glfwInit();
            isGLFWWindowCreated = true;
        }

        glfwWindowHint(GLFW_SAMPLES, 4);
        glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
        glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
        glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

        m_Window = glfwCreateWindow((int)m_WindowData.Width, (int)m_WindowData.Height, m_WindowData.Title.c_str(), nullptr, nullptr);
        glfwSetWindowUserPointer(m_Window, &m_WindowData);

        glfwMakeContextCurrent(m_Window);
        int status = gladLoadGLLoader((GLADloadproc)glfwGetProcAddress);

        glViewport(0, 0, (int)m_WindowData.Width, (int)m_WindowData.Height);
        glfwSetWindowCloseCallback(m_Window, WindowTerminateCallback);
    }

    void Window::OnClear()
    {
        glClear( GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT );
    }

    void Window::OnUpdate() 
    {
        glfwPollEvents();
        glfwSwapBuffers(m_Window);
    }

    void Window::Terminate()
    {
        glfwDestroyWindow(m_Window);
        glfwTerminate();
    }

    void Window::WindowTerminateCallback(GLFWwindow* window)
    {
        m_WindowData.Alive = false;
    }
}
