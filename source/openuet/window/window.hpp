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
            void Init(const WindowProp& window_props = WindowProp(800, 600, "sexy", true));
            void Terminate();
        
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