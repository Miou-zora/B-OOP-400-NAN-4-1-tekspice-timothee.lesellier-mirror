/*
** EPITECH PROJECT, 2023
** B-OOP-400-NAN-4-1-tekspice-timothee.lesellier-mirror
** File description:
** OrComponent
*/

#ifndef ORCOMPONENT_HPP_
#define ORCOMPONENT_HPP_

#include "../AComponent.hpp"

namespace nts
{
    class OrComponent : public virtual nts::AComponent {
        public:
            OrComponent();
            ~OrComponent();

            nts::Tristate compute(std::size_t pin);
    };
}
#endif /* !ORCOMPONENT_HPP_ */
