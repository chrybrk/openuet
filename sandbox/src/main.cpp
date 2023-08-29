#include "openuet.hpp"

class Sandbox : public openuet::Application
{
    public:
        Sandbox()
        {
            window = std::make_shared<openuet::Window>();
            window->Init();
        };

        ~Sandbox()
        {
        };

    private:
        std::shared_ptr<openuet::Window> window;

};

openuet::Application* openuet::CreateApplication()
{
    Sandbox* app = new Sandbox();
    return app;
}
