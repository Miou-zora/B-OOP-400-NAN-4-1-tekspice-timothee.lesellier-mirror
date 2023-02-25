/*
** EPITECH PROJECT, 2023
** B-OOP-400-NAN-4-1-tekspice-timothee.lesellier-mirror
** File description:
** DLatchComponent
*/

#pragma once

#include "../AComponent.hpp"
#include <map>
#include <vector>

namespace nts
{
    class DLatchComponent : virtual public nts::AComponent {
        public:
            DLatchComponent();
            ~DLatchComponent();

            nts::Tristate compute(std::size_t pin);
            void simulate(std::size_t tick);

        private:
            nts::Tristate _state;
    };
}
