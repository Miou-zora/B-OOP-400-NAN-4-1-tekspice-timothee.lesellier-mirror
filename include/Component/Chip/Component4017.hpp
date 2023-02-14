/*
** EPITECH PROJECT, 2023
** B-OOP-400-NAN-4-1-tekspice-timothee.lesellier-mirror
** File description:
** Component4017
*/

#ifndef COMPONENT4017_HPP_
#define COMPONENT4017_HPP_

#include "../AComponent.hpp"

namespace nts
{
    class Component4017 : public virtual nts::AComponent {
        public:
            Component4017();
            ~Component4017();

            nts::Tristate compute(std::size_t pin);
    };
}

#endif /* !COMPONENT4017_HPP_ */
