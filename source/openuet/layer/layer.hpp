#pragma once

#include "pch.hpp"

namespace openuet {

    class Layer
    {
        public:
            Layer();
            virtual ~Layer();
            virtual void OnAttach() {}
            virtual void OnDetach() {}
            virtual void OnUpdate() {}
    };
}
