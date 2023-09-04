#pragma once

#include "pch.hpp"

#include <glad/glad.h>
#include <GLFW/glfw3.h>

namespace openuet {
    struct WindowProp
    {
        int Width;
        int Height;
        std::string Title;
        bool Resizable;

        WindowProp(int width, int height, const std::string& title, bool resizable)
            : Width(width), Height(height), Title(title), Resizable(resizable)
        {
        }
    };

    class Window
    {
        public:
            static void Init(const WindowProp& window_props = WindowProp(800, 600, "Game Engine (openuet)", true));
            static void Terminate();

            static void OnClear();
            static void OnUpdate();
            static void SetVSync(bool enabled);

            static inline bool IsAlive() { return m_WindowData.Alive; }

            static void WindowTerminateCallback(GLFWwindow* window);
        
        private:
            struct WindowData
            {
                int Width;
                int Height;
                std::string Title;

                bool Alive;
                bool VSync;
            };

            static GLFWwindow* m_Window;
            static WindowData m_WindowData;
    };
}
