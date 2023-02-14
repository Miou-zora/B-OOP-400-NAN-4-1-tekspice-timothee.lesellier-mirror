/*
** EPITECH PROJECT, 2023
** B-OOP-400-NAN-4-1-tekspice-timothee.lesellier-mirror
** File description:
** Component2716
*/

#ifndef COMPONENT2716_HPP_
#define COMPONENT2716_HPP_

#include "../AComponent.hpp"

namespace nts
{
    class Component2716 : public virtual nts::AComponent {
        public:
            Component2716();
            ~Component2716();

            nts::Tristate compute(std::size_t pin);
    };
}

#endif /* !COMPONENT2716_HPP_ */
