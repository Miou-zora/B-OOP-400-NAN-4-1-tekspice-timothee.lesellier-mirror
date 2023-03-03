/*
** EPITECH PROJECT, 2023
** B-OOP-400-NAN-4-1-tekspice-timothee.lesellier-mirror
** File description:
** Component4514
*/

#include "Component/Chip/Component4514.hpp"

// 4-bits Decoder (4514)
//
//                              +-11- out_00
//                              |   +-09- out_01
//                              |   |   +-10- out_02
//                              |   |   |   +-08- out_03
//                              |   |   |   |   +-07- out_04
//              inhibit -23-+   |   |   |   |   |   +-06- out_05
//                          |   |   |   |   |   |   |
//          +---4514--------v---^---^---^---^---^---^-------+
//          |               |   |   |   |   |   |   |       |
// in_0  -2->---+---+---+---+---+---+---+---+---+---+---+--->-05- out_06
//          |   | L |   |                               |   |
// in_1  -3->---| A |---|                               +--->-04- out_07
//          |   | T |   |        4-to-16 DECODER        |   |
// in_2 -21->---| C |---|                               +--->-18- out_08
//          |   | H |   |                               |   |
// in_3 -22->---+---+---+-------+---+---+---+---+---+---+--->-17- out_09
//          |     |  ign ign    |   |   |   |   |   |       |
//          +-----^---+---+-----v---v---v---v---v---v-------+
//                |   |   |     |   |   |   |   |   |
//      strobe -1-+   |   |     |   |   |   |   |   +-20- out_10
//                -12-+   |     |   |   |   |   +-19- out_11
//                    -24-+     |   |   |   +-14- out_12
//                              |   |   +-13- out_13
//                              |   +-16- out_14
//                              +-15- out_15

nts::Component4514::Component4514()
{
    _components = {
                // 4 InvSRNLatchComponents
                std::make_shared<nts::InvSRNLatchComponent>(),
                std::make_shared<nts::InvSRNLatchComponent>(),
                std::make_shared<nts::InvSRNLatchComponent>(),
                std::make_shared<nts::InvSRNLatchComponent>(),
                // idx 3

                // 15 TNandGates
                std::make_shared<nts::TNandGate>(),
                std::make_shared<nts::TNandGate>(),
                std::make_shared<nts::TNandGate>(),
                std::make_shared<nts::TNandGate>(),
                std::make_shared<nts::TNandGate>(),
                std::make_shared<nts::TNandGate>(),
                std::make_shared<nts::TNandGate>(),
                std::make_shared<nts::TNandGate>(),
                std::make_shared<nts::TNandGate>(),
                std::make_shared<nts::TNandGate>(),
                std::make_shared<nts::TNandGate>(),
                std::make_shared<nts::TNandGate>(),
                std::make_shared<nts::TNandGate>(),
                std::make_shared<nts::TNandGate>(),
                std::make_shared<nts::TNandGate>(),
                // idx 18

                std::make_shared
    };

        /*
            Outputs are made only of TNandGates
            pins : 4 5 6 7 8 9 10 11 13 14 15 16 17 18 19 20
        */
    _outputs = {
            {4, *_components[3]},
            {5, *_components[4]},
            {6, *_components[5]},
            {7, *_components[6]},
            {8, *_components[7]},
            {9, *_components[8]},
            {10, *_components[9]},
            {11, *_components[10]},
            {13, *_components[11]},
            {14, *_components[12]},
            {15, *_components[13]},
            {16, *_components[14]},
            {17, *_components[15]},
            {18, *_components[16]},
            {19, *_components[17]},
            {20, *_components[18]}
        };

        /*
            Inputs are made only of InvSRNLatchComponents
            1 2 3 21 22 23
        */
    _inputs = {
            {1, {
                {std::pair<std::size_t, nts::IComponent &>(1, *_components[0])},
            }

        /*
            Links between components
        */
}


nts::Component4514::~Component4514()
{
}

nts::Tristate nts::Component4514::compute(std::size_t pin)
{
    pin++;
    return (nts::Tristate::Undefined);
}

void nts::Component4514::setLink(std::size_t pin, std::shared_ptr<nts::IComponent> other, std::size_t otherPin)
{
    pin++;
    otherPin++;
    (void) other;
}