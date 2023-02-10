/*
** EPITECH PROJECT, 2023
** B-OOP-400-NAN-4-1-bootstrap-tekspice
** File description:
** TrueComponent
*/

#pragma once

#include "../AIO.hpp"

namespace nts
{

    class TrueComponent : virtual public nts::AComponent {
        public:
            TrueComponent();
            ~TrueComponent();
            nts::Tristate compute(std::size_t pin);
    };
}

