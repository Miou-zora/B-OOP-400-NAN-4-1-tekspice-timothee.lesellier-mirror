/*
** EPITECH PROJECT, 2023
** B-OOP-400-NAN-4-1-tekspice-timothee.lesellier-mirror
** File description:
** Component4008
*/

#ifndef COMPONENT4008_HPP_
#define COMPONENT4008_HPP_

#include "../AComponent.hpp"

namespace nts
{
    class Component4008 : public virtual nts::AComponent {
        public:
            Component4008();
            ~Component4008();

            nts::Tristate compute(std::size_t pin);
    };
}

#endif /* !COMPONENT4008_HPP_ */
