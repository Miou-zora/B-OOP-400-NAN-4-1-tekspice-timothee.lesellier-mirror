/*
** EPITECH PROJECT, 2023
** B-OOP-400-NAN-4-1-tekspice-timothee.lesellier-mirror
** File description:
** Component4040
*/

#ifndef COMPONENT4040_HPP_
#define COMPONENT4040_HPP_

#include "../AComponent.hpp"

namespace nts
{
    class Component4040 : public virtual nts::AComponent {
        public:
            Component4040();
            ~Component4040();

            nts::Tristate compute(std::size_t pin);
    };
}

#endif /* !COMPONENT4040_HPP_ */
