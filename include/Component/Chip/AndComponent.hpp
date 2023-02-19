/*
** EPITECH PROJECT, 2023
** B-OOP-400-NAN-4-1-bootstrap-tekspice
** File description:
** AndComponent
*/

#pragma once

#include "../AComponent.hpp"
#include "ComponentFactory.hpp"

namespace nts
{
    class AndComponent : virtual public nts::AComponent {
        public:
            AndComponent();
            ~AndComponent();

            nts::Tristate compute(std::size_t pin);
        private:
            // initializer for the factory
            class Initializer {
                public:
                    Initializer() {
                            nts::ComponentFactory::addConstructor("and", []() { return std::make_unique<nts::AndComponent>(); });
                    };
            };
            static inline Initializer initializer;
    };
}
