/*
** EPITECH PROJECT, 2023
** B-OOP-400-NAN-4-1-tekspice-timothee.lesellier-mirror
** File description:
** NorComponent
*/

#ifndef NORCOMPONENT_HPP_
#define NORCOMPONENT_HPP_

#include "../AComponent.hpp"

namespace nts
{
    class NorComponent : public virtual nts::AComponent {
        public:
            NorComponent();
            ~NorComponent();

            nts::Tristate compute(std::size_t pin);
    };
}

#endif /* !NORCOMPONENT_HPP_ */
