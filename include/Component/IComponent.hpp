/*
** EPITECH PROJECT, 2023
** B-OOP-400-NAN-4-1-tekspice-timothee.lesellier-mirror
** File description:
** IComponent
*/

#pragma once

#include <memory>
#include <iostream>

namespace nts
{
    enum Tristate {
        Undefined = (-true),
        True = true,
        False = false
    };

    class IComponent {
        public:
            IComponent() = default;
            virtual ~IComponent() = default;

            virtual void simulate(std::size_t tick) = 0;
            virtual nts::Tristate compute(std::size_t pin) = 0;
            virtual void setLink(std::size_t pin, std::shared_ptr<nts::IComponent> other, std::size_t otherPin) = 0;
            virtual void resetUpdate(void) = 0;
    };
}

inline std::ostream& operator<<(std::ostream& stream, nts::Tristate v)
{
    switch (v) {
        case nts::Tristate::True:
            stream << "1";
            break;
        case nts::Tristate::False:
            stream << "0";
            break;
        case nts::Tristate::Undefined:
            stream << "U";
            break;
    }
    return stream;
}