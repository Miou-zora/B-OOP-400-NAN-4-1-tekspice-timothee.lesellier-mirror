/*
** EPITECH PROJECT, 2023
** B-OOP-400-NAN-4-1-tekspice-timothee.lesellier-mirror
** File description:
** Component4013
*/

#ifndef COMPONENT4013_HPP_
#define COMPONENT4013_HPP_

#include "../AComponent.hpp"

namespace nts
{
    class Component4013 : public virtual nts::AComponent {
        public:
            Component4013();
            ~Component4013();

            nts::Tristate compute(std::size_t pin);
    };
}

#endif /* !COMPONENT4013_HPP_ */
