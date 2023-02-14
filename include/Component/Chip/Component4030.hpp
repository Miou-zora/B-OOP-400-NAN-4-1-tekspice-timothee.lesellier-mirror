/*
** EPITECH PROJECT, 2023
** B-OOP-400-NAN-4-1-tekspice-timothee.lesellier-mirror
** File description:
** Component4030
*/

#ifndef COMPONENT4030_HPP_
#define COMPONENT4030_HPP_

#include "../AComponent.hpp"

namespace nts
{
    class Component4030 : public virtual nts::AComponent {
        public:
            Component4030();
            ~Component4030();

            nts::Tristate compute(std::size_t pin);
    };
}

#endif /* !COMPONENT4030_HPP_ */
