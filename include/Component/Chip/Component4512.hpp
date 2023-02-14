/*
** EPITECH PROJECT, 2023
** B-OOP-400-NAN-4-1-tekspice-timothee.lesellier-mirror
** File description:
** Component4512
*/

#ifndef COMPONENT4512_HPP_
#define COMPONENT4512_HPP_

#include "../AComponent.hpp"

namespace nts
{
    class Component4512 : public virtual nts::AComponent {
        public:
            Component4512();
            ~Component4512();

            nts::Tristate compute(std::size_t pin);
    };
}

#endif /* !COMPONENT4512_HPP_ */
