/*
** EPITECH PROJECT, 2023
** B-OOP-400-NAN-4-1-tekspice-timothee.lesellier-mirror
** File description:
** Component4008
*/

#include "Component/Chip/Component4008.hpp"
#include "Component/Chip/AndComponent.hpp"
#include <iostream>

/*
# 4-bits Adder (4008)
#
#                  +-14- out_c
#                  |
#           +-4008-^------+
#           |      |      |
# in_b4 -15->---+--^--+   |
#           |   | sum |--->-13- out_3
# in_a4  -1->---+--+--+   |
#           |      |      |
# in_b3  -2->---+--^--+   |
#           |   | sum |--->-12- out_2
# in_a3  -3->---+--+--+   |
#           |      |      |
# in_b2  -4->---+--^--+   |
#           |   | sum |--->-11- out_1
# in_a2  -5->---+--+--+   |
#           |      |      |
# in_b1  -6->---+--^--+   |
#           |   | sum |--->-10- out_0
# in_a1  -7->---+--+--+   |
#           |      |      |
# in_c   -9->------+      |
#           |             |
#           +-------------+
*/

nts::Component4008::Component4008()
{
    _pinMax= 13;
    _components = {
                        std::make_shared<nts::SAdder>(),
                        std::make_shared<nts::SAdder>(),
                        std::make_shared<nts::SAdder>(),
                        std::make_shared<nts::SAdder>()
                    };

    _outputs = {
                {10, *_components.at(0)},
                {11, *_components.at(1)},
                {12, *_components.at(2)},
                {13, *_components.at(3)},
                {14, *_components.at(3)}
    };

    _inputs = {
                {15, std::pair<std::size_t, nts::IComponent&>{1, *_components.at(3)}},
                {1,  std::pair<std::size_t, nts::IComponent&>{2, *_components.at(3)}},
                {2, std::pair<std::size_t, nts::IComponent&>{1, *_components.at(2)}},
                {3, std::pair<std::size_t, nts::IComponent&>{2, *_components.at(2)}},
                {4, std::pair<std::size_t, nts::IComponent&>{1, *_components.at(1)}},
                {5, std::pair<std::size_t, nts::IComponent&>{2, *_components.at(1)}},
                {6, std::pair<std::size_t, nts::IComponent&>{1, *_components.at(0)}},
                {7, std::pair<std::size_t, nts::IComponent&>{2, *_components.at(0)}},
                {9, std::pair<std::size_t, nts::IComponent&>{nts::SAdder::CARRY_IN, *_components.at(0)}}
    };

    _components.at(3)->setLink(nts::SAdder::CARRY_IN, _components.at(2), nts::SAdder::CARRY_OUT);
    _components.at(2)->setLink(nts::SAdder::CARRY_IN, _components.at(1), nts::SAdder::CARRY_OUT);
    _components.at(1)->setLink(nts::SAdder::CARRY_IN, _components.at(0), nts::SAdder::CARRY_OUT);
}

nts::Component4008::~Component4008()
{
}

nts::Tristate nts::Component4008::compute(std::size_t pin)
{
    if (pin >= 10 && pin <= 13) {
        return _outputs.at(pin).compute(nts::SAdder::SUM_OUT);
    } else if (pin == 14) {
        return _outputs.at(pin).compute(nts::SAdder::CARRY_OUT);
    } else {
        throw std::invalid_argument("Pin out of range");
    }
}

void nts::Component4008::setLink(std::size_t pin, std::shared_ptr<nts::IComponent> other, std::size_t otherPin)
{
    try {
        if ((pin >= 1 && pin < 10) || pin == 15) {
            _inputs.at(pin).second.setLink(_inputs.at(pin).first, other, otherPin);
        } else {
            throw std::invalid_argument("Pin out of range");
        }
    } catch (std::out_of_range &e) {
        throw std::invalid_argument("Pin out of range");
    }
}
