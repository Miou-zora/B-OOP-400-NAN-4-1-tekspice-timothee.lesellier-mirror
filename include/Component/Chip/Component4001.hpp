/*
** EPITECH PROJECT, 2023
** B-OOP-400-NAN-4-1-tekspice-timothee.lesellier-mirror
** File description:
** Component4001
*/

#ifndef COMPONENT4001_HPP_
#define COMPONENT4001_HPP_

#include "../AComponent.hpp"

namespace nts
{
    class Component4001 : public virtual nts::AComponent {
        public:
            Component4001();
            ~Component4001();

            nts::Tristate compute(std::size_t pin);
    };
}

#endif /* !COMPONENT4001_HPP_ */
