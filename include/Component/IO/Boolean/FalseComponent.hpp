/*
** EPITECH PROJECT, 2023
** B-OOP-400-NAN-4-1-bootstrap-tekspice
** File description:
** FalseComponent
*/

#pragma once
#include "../AIO.hpp"

namespace nts
{
    class FalseComponent : virtual public nts::AIO {
        public:
            FalseComponent();
            ~FalseComponent();
            nts::Tristate compute(std::size_t pin);
    };
}

