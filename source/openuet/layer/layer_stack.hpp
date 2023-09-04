#pragma once

#include "layer.hpp"

namespace openuet {

    class LayerStack
    {
        public:
            LayerStack();
            ~LayerStack();

            void PushLayer(Layer* layer);
            void PopLayer(Layer* layer);

            inline std::vector<Layer*>::iterator begin() { return m_Layers.begin(); }
            inline std::vector<Layer*>::iterator end() { return m_Layers.end(); }

        private:
            std::vector<Layer*> m_Layers;
            unsigned int m_LayerInsertIndex = 0;
    };
}
