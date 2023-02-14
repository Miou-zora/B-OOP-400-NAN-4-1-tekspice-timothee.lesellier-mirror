/*
** EPITECH PROJECT, 2023
** B-OOP-400-NAN-4-1-tekspice-timothee.lesellier-mirror
** File description:
** FlipFlopComponent
*/

#ifndef FLIPFLOPCOMPONENT_HPP_
#define FLIPFLOPCOMPONENT_HPP_

#include "../AComponent.hpp"

namespace nts
{
    class FlipFlopComponent : public virtual nts::AComponent {
        public:
            FlipFlopComponent();
            ~FlipFlopComponent();

            nts::Tristate compute(std::size_t pin);
    };
}

#endif /* !FLIPFLOPCOMPONENT_HPP_ */
