/*
** EPITECH PROJECT, 2023
** B-OOP-400-NAN-4-1-bootstrap-tekspice
** File description:
** FalseComponent
*/

#pragma once

#include "../AComponent.hpp"

namespace nts
{
    class FalseComponent : virtual public nts::AComponent {
        public:
            FalseComponent() {_pinMax = 1;};
            ~FalseComponent() {};

            nts::Tristate compute(std::size_t pin)
            {
                if (pin != 1)
                    throw std::invalid_argument("Pin out of range");
                return nts::Tristate::False;
            };
    };
}

