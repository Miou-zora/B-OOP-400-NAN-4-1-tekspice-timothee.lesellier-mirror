/*
** EPITECH PROJECT, 2023
** B-OOP-400-NAN-4-1-tekspice-timothee.lesellier-mirror
** File description:
** Component4071
*/

#ifndef COMPONENT4071_HPP_
#define COMPONENT4071_HPP_

#include "../AComponent.hpp"

namespace nts
{
    class Component4071 : public virtual nts::AComponent {
        public:
            Component4071();
            ~Component4071();

            nts::Tristate compute(std::size_t pin);
    };
}

#endif /* !COMPONENT4071_HPP_ */
