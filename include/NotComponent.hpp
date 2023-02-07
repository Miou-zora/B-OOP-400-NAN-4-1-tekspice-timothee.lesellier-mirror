/*
** EPITECH PROJECT, 2023
** B-OOP-400-NAN-4-1-bootstrap-tekspice
** File description:
** NotComponent
*/

#pragma once
#include "AComponent.hpp"

namespace nts
{
    class NotComponent : virtual public nts::AComponent {
        public:
            NotComponent();
            ~NotComponent();

            nts::Tristate compute(std::size_t pin);
    };
} // namespace nts
