#include "layer_stack.hpp"

namespace openuet {

    LayerStack::LayerStack()
    {
        m_Layers.begin();
    }

    LayerStack::~LayerStack()
    {
        for ( Layer* layer : m_Layers )
            delete layer;
    }

    void LayerStack::PushLayer(Layer* layer)
    {
        m_Layers.emplace(m_Layers.begin() + m_LayerInsertIndex, layer);
        m_LayerInsertIndex++;
    }

    void LayerStack::PopLayer(Layer* layer)
    {
        auto element = std::find(m_Layers.begin(), m_Layers.end(), layer);
        if (element != m_Layers.end())
        {
            m_Layers.erase(element);
            m_LayerInsertIndex--;
        }
    }
}
