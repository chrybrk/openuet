
#pragma once

#include "pch.hpp"

#include "layer/layer_stack.hpp"

namespace openuet{
    class Application
    {
        public:
            Application();
            ~Application();

            void PushLayer(Layer* layer);

            void Run();

        private:
            LayerStack m_LayerStack;
    };
    Application *CreateApplication();
}
