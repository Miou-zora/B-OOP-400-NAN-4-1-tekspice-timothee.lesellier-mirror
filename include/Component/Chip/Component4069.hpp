/*
** EPITECH PROJECT, 2023
** B-OOP-400-NAN-4-1-tekspice-timothee.lesellier-mirror
** File description:
** Component4069
*/

#ifndef COMPONENT4069_HPP_
#define COMPONENT4069_HPP_

#include "../AComponent.hpp"

namespace nts
{
    class Component4069 : public virtual nts::AComponent {
        public:
            Component4069();
            ~Component4069();

            nts::Tristate compute(std::size_t pin);
    };
}

#endif /* !COMPONENT4069_HPP_ */
