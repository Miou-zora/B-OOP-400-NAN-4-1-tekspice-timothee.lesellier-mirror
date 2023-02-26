/*
** EPITECH PROJECT, 2023
** B-OOP-400-NAN-4-1-tekspice-timothee.lesellier-mirror
** File description:
** SRLatchComponent
*/

#pragma once

#include "../AComponent.hpp"

namespace nts {
    class SRLatchComponent : public virtual nts::AComponent {
        public:
            SRLatchComponent();
            ~SRLatchComponent();

            nts::Tristate compute(std::size_t pin);
            void simulate(std::size_t tick);

        private:
            nts::Tristate _stateQ;
            nts::Tristate _stateQBar;
    };
}
