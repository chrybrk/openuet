#include "openuet.hpp"

class Sandbox : public openuet::Application
{
    public:
        Sandbox()
        {
            std::cout << "Hello, First!" << std::endl;
        };

        ~Sandbox()
        {

        };
};

openuet::Application* openuet::CreateApplication()
{
    Sandbox* app = new Sandbox();
    return app;
}
