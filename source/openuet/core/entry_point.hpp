#pragma once

extern openuet::Application* openuet::CreateApplication();
int main()
{
    auto app = openuet::CreateApplication();
    app->Run();
    delete app;
}