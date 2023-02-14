/*
** EPITECH PROJECT, 2023
** B-OOP-400-NAN-4-1-tekspice-timothee.lesellier-mirror
** File description:
** Component4081
*/

#ifndef COMPONENT4081_HPP_
#define COMPONENT4081_HPP_

#include "../AComponent.hpp"

namespace nts
{
    class Component4081 : public virtual nts::AComponent {
        public:
            Component4081();
            ~Component4081();

            nts::Tristate compute(std::size_t pin);
    };
}

#endif /* !COMPONENT4081_HPP_ */
