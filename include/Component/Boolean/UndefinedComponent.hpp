/*
** EPITECH PROJECT, 2023
** B-OOP-400-NAN-4-1-tekspice-timothee.lesellier-mirror
** File description:
** UndefinedComponent
*/

#pragma once
#include "../AComponent.hpp"

namespace nts {
    class UndefinedComponent : virtual public nts::AComponent {
        public:
            UndefinedComponent();
            ~UndefinedComponent();
            nts::Tristate compute(std::size_t pin);
    };
}
