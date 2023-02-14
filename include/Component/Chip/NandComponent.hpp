/*
** EPITECH PROJECT, 2023
** B-OOP-400-NAN-4-1-tekspice-timothee.lesellier-mirror
** File description:
** NandComponent
*/

#ifndef NANDCOMPONENT_HPP_
#define NANDCOMPONENT_HPP_

#include "../AComponent.hpp"

namespace nts
{
    class NandComponent : public virtual nts::AComponent {
        public:
            NandComponent();
            ~NandComponent();

            nts::Tristate compute(std::size_t pin);
    };
}

#endif /* !NANDCOMPONENT_HPP_ */
