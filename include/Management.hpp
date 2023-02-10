/*
** EPITECH PROJECT, 2023
** B-OOP-400-NAN-4-1-tekspice-timothee.lesellier-mirror
** File description:
** Management
*/

#ifndef MANAGEMENT_HPP_
#define MANAGEMENT_HPP_

#include <memory>
#include "Component/Component.h"
#include "ComponentFactory.hpp"

namespace nts {
    class Management {
        public:
            Management();
            ~Management();

            std::unique_ptr<nts::IComponent> createComponent(const std::string &type);
            void loop(void) const;
        protected:
        private:
            ComponentFactory<std::string, std::unique_ptr<nts::IComponent>, std::string> _factory;
    };
}

#endif /* !MANAGEMENT_HPP_ */
