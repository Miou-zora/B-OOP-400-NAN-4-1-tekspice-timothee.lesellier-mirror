/*
** EPITECH PROJECT, 2023
** B-OOP-400-NAN-4-1-bootstrap-tekspice
** File description:
** TrueComponent
*/

#pragma once

#include "../AComponent.hpp"

namespace nts
{
    class TrueComponent : virtual public nts::AComponent {
        public:
            TrueComponent() {_pinMax = 1;};
            ~TrueComponent() {};

            nts::Tristate compute(std::size_t pin)
            {
                if (pin != 1)
                    throw std::invalid_argument("Pin out of range");
                return nts::Tristate::True;
            };
    };
}

