#include "app.hpp"

#include "window/window.hpp"

namespace openuet{
    Application::Application()
    {
        Window::Init();
    }

    Application::~Application()
    {
        Window::Terminate();
    }

    void Application::PushLayer(Layer* layer)
    {
        m_LayerStack.PushLayer(layer);
        layer->OnAttach();
    }

    void Application::Run()
    {
        while (Window::IsAlive())
        {
            Window::OnClear();

            for (Layer* layer : m_LayerStack)
            {
                layer->OnUpdate();
            }

            Window::OnUpdate();
        }
    }
}
