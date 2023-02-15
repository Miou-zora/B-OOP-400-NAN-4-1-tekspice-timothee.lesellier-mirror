/*
** EPITECH PROJECT, 2023
** B-OOP-400-NAN-4-1-tekspice-timothee.lesellier-mirror
** File description:
** ComponentFactory
*/

#ifndef COMPONENTFACTORY_HPP_
#define COMPONENTFACTORY_HPP_

#include <unordered_map>
#include <functional>
#include "Component/IComponent.hpp"
#include <memory>
#include <string>

namespace nts {
    class ComponentFactory {
        public:
            void addConstructor(std::string const& key, std::function<std::unique_ptr<nts::IComponent>()> const& creator);

            std::unique_ptr<nts::IComponent> create(std::string const& key);

        private:
            std::unordered_map<std::string, std::function<std::unique_ptr<nts::IComponent>()>> m_creators;
    };
}

#endif /* !COMPONENTFACTORY_HPP_ */
