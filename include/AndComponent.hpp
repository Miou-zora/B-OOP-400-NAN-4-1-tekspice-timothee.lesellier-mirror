/*
** EPITECH PROJECT, 2023
** B-OOP-400-NAN-4-1-bootstrap-tekspice
** File description:
** AndComponent
*/

#pragma once
#include "AComponent.hpp"

namespace nts
{
    class AndComponent : virtual public nts::AComponent {
        public:
            AndComponent();
            ~AndComponent();
            nts::Tristate compute(std::size_t pin);
    };
} // namespace nts
