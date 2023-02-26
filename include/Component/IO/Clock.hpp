/*
** EPITECH PROJECT, 2023
** B-OOP-400-NAN-4-1-tekspice-timothee.lesellier-mirror
** File description:
** Clock
*/

#pragma once

#include "AIO.hpp"

namespace nts
{
    class Clock : public virtual nts::AIO {
        public:
            Clock();
            ~Clock();

            nts::Tristate compute(std::size_t pin);
            void simulate(std::size_t tick);
    };
}