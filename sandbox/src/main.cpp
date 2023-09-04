#include "openuet.hpp"

class Sandbox : public openuet::Application
{
    public:
        Sandbox()
        {
        };

        ~Sandbox()
        {
        };

    private:

};

openuet::Application* openuet::CreateApplication()
{
    Sandbox* app = new Sandbox();
    return app;
}
