/*
** EPITECH PROJECT, 2023
** B-OOP-400-NAN-4-1-tekspice-timothee.lesellier-mirror
** File description:
** XorComponent
*/

#ifndef XORCOMPONENT_HPP_
#define XORCOMPONENT_HPP_

#include "../AComponent.hpp"

namespace nts
{
    class XorComponent : public virtual nts::AComponent {
        public:
            XorComponent();
            ~XorComponent();

            nts::Tristate compute(std::size_t pin);
    };
}
#endif /* !XORCOMPONENT_HPP_ */
