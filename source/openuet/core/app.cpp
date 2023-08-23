#include "app.hpp"

namespace openuet{
    Application::Application()
    {

        std::cout << "Hello Second!" << std::endl;

    }

    Application::~Application()
    {

    }

    void Application::Run()
    {
        std::cout << "Blah" << std::endl;
    }
}