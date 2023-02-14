/*
** EPITECH PROJECT, 2023
** B-OOP-400-NAN-4-1-tekspice-timothee.lesellier-mirror
** File description:
** Component4011
*/

#ifndef COMPONENT4011_HPP_
#define COMPONENT4011_HPP_

#include "../AComponent.hpp"

namespace nts
{
    class Component4011 : public virtual nts::AComponent {
        public:
            Component4011();
            ~Component4011();

            nts::Tristate compute(std::size_t pin);
    };
}

#endif /* !COMPONENT4011_HPP_ */
