/*
** EPITECH PROJECT, 2023
** B-OOP-400-NAN-4-1-tekspice-timothee.lesellier-mirror
** File description:
** Component4801
*/

#ifndef COMPONENT4801_HPP_
#define COMPONENT4801_HPP_

#include "../AComponent.hpp"

namespace nts
{
    class Component4801 : public virtual nts::AComponent {
        public:
            Component4801();
            ~Component4801();

            nts::Tristate compute(std::size_t pin);
    };
}

#endif /* !COMPONENT4801_HPP_ */
