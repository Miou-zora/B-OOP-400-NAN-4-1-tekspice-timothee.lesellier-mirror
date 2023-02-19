/*
** EPITECH PROJECT, 2023
** B-OOP-400-NAN-4-1-tekspice-timothee.lesellier-mirror
** File description:
** Output
*/

#pragma once

#include "AIO.hpp"
#include "ComponentFactory.hpp"

namespace nts
{
    class Output : public virtual nts::AIO {
        public:
            Output();
            ~Output();

            nts::Tristate compute(std::size_t pin);

        private:
            // initializer for the factory
            class Initializer {
                public:
                    Initializer() {
                            nts::ComponentFactory::addConstructor("output", []() { return std::make_unique<nts::Output>(); });
                    };
            };
            static inline Initializer initializer;
    };
}
