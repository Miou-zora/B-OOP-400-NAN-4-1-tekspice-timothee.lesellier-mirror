/*
** EPITECH PROJECT, 2023
** B-OOP-400-NAN-4-1-tekspice-timothee.lesellier-mirror
** File description:
** BinaryCellComponent
*/

#ifndef BINARYCELLCOMPONENT_HPP_
#define BINARYCELLCOMPONENT_HPP_

#include "../AComponent.hpp"

namespace nts
{
    class BinaryCellComponent : public virtual nts::AComponent {
        public:
            BinaryCellComponent();
            ~BinaryCellComponent();

            nts::Tristate compute(std::size_t pin);
    };
}

#endif /* !BINARYCELLCOMPONENT_HPP_ */
