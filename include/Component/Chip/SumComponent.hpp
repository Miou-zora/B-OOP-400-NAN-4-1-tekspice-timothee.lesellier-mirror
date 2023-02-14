/*
** EPITECH PROJECT, 2023
** B-OOP-400-NAN-4-1-tekspice-timothee.lesellier-mirror
** File description:
** SumComponent
*/

#ifndef SUMCOMPONENT_HPP_
#define SUMCOMPONENT_HPP_

#include "../AComponent.hpp"

namespace nts
{
    class SumComponent : public virtual nts::AComponent {
        public:
            SumComponent();
            ~SumComponent();

            nts::Tristate compute(std::size_t pin);
    };
}

#endif /* !SUMCOMPONENT_HPP_ */
