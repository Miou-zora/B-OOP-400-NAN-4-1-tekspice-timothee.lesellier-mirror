/*
** EPITECH PROJECT, 2023
** B-OOP-400-NAN-4-1-tekspice-timothee.lesellier-mirror
** File description:
** IComponent
*/


#include <cstddef>
#include <stdexcept>
#include <ostream>
#include <iostream>

namespace nts
{
    // Types from the namespace
    enum Tristate {
        Undefined = (-true),
        True = true,
        False = false
    };

    // Class from the namespace
    class IComponent {
    public:
            IComponent() = default;
            virtual ~IComponent() = default;

            virtual void simulate(std::size_t tick) = 0;
            virtual nts::Tristate compute(std::size_t pin) = 0;
            virtual void setLink(std::size_t pin, nts::IComponent& other, std::size_t otherPin) = 0;
    };
}

std::ostream& operator<<(std::ostream& stream, nts::Tristate v);

nts::Tristate ntsAnd(nts::Tristate v, nts::Tristate v2);

nts::Tristate ntsNot(nts::Tristate v);