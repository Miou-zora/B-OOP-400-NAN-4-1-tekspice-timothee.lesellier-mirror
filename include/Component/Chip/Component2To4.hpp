/*
** EPITECH PROJECT, 2023
** B-OOP-400-NAN-4-1-tekspice-timothee.lesellier-mirror
** File description:
** Component2To4
*/

#ifndef COMPONENT2TO4_HPP_
#define COMPONENT2TO4_HPP_

#include "../AComponent.hpp"

namespace nts
{
    class Component2To4 : public virtual nts::AComponent {
        public:
            Component2To4();
            ~Component2To4();

            nts::Tristate compute(std::size_t pin);
    };
}

#endif /* !COMPONENT2TO4_HPP_ */
