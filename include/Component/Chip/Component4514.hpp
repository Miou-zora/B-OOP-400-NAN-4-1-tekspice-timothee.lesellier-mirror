/*
** EPITECH PROJECT, 2023
** B-OOP-400-NAN-4-1-tekspice-timothee.lesellier-mirror
** File description:
** Component4514
*/

#ifndef COMPONENT4514_HPP_
#define COMPONENT4514_HPP_

#include "../AComponent.hpp"

namespace nts {
    class Component4514 : public virtual nts::AComponent {
        public:
            Component4514();
            ~Component4514();

            nts::Tristate compute(std::size_t pin);
    };
}

#endif /* !COMPONENT4514_HPP_ */
