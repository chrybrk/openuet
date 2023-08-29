
#pragma once

#include "pch.hpp"

namespace openuet{
    class Application
    {
        public:
            Application();
            ~Application();

            void Run();
    };
    Application *CreateApplication();
}