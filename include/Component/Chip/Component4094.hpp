/*
** EPITECH PROJECT, 2023
** B-OOP-400-NAN-4-1-tekspice-timothee.lesellier-mirror
** File description:
** Component4094
*/

#ifndef COMPONENT4094_HPP_
#define COMPONENT4094_HPP_

#include "../AComponent.hpp"

namespace nts
{
    class Component4094 : public virtual nts::AComponent {
        public:
            Component4094();
            ~Component4094();

            nts::Tristate compute(std::size_t pin);
    };
}

#endif /* !COMPONENT4094_HPP_ */
