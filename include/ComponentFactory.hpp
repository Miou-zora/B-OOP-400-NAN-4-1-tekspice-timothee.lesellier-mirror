/*
** EPITECH PROJECT, 2023
** B-OOP-400-NAN-4-1-tekspice-timothee.lesellier-mirror
** File description:
** ComponentFactory
*/

#pragma once

#include <unordered_map>
#include <functional>
#include "Component/IComponent.hpp"
#include <memory>
#include <string>

namespace nts
{
    class ComponentFactory {
        public:
            static void addConstructor(std::string const& key, std::function<std::unique_ptr<nts::IComponent>()> const& creator)
            {
                if (m_creators.find(key) != m_creators.end())
                    throw std::runtime_error("Component already exists");
                if (creator == nullptr)
                    throw std::runtime_error("Creator is null");
                m_creators[key] = creator;
            }

            static std::unique_ptr<nts::IComponent> create(std::string const& key)
            {
                if (m_creators.find(key) == m_creators.end())
                    throw std::runtime_error("Component doesn't exist");
                return m_creators[key]();
            }

        private:
            inline static std::unordered_map<std::string, std::function<std::unique_ptr<nts::IComponent>()>> m_creators;
    };
}
