/*
** EPITECH PROJECT, 2023
** B-OOP-400-NAN-4-1-tekspice-timothee.lesellier-mirror
** File description:
** Input
*/

#pragma once
#include "AIO.hpp"
#include <iostream>
#include "ComponentFactory.hpp"

namespace nts {
    class Input : public virtual nts::AIO {
        public:
            Input();
            ~Input();
            nts::Tristate compute(std::size_t pin);
            void simulate(std::size_t tick);
        private:
            class Initializer {
                public:
                    Initializer() {
                            nts::ComponentFactory::addConstructor("input", []() { return std::make_unique<nts::Input>(); });
                    };
            };
            static inline Initializer initializer;
    };
}
