/*
** EPITECH PROJECT, 2023
** B-OOP-400-NAN-4-1-tekspice-timothee.lesellier-mirror
** File description:
** TNandGateTests
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#define private public
#define protected public
#include "NTS.hpp"
#undef private
#undef protected
#include <memory>

Test(TNandGate, invalid_pin)
{
    nts::TNandGate TNandGate;

    try {
        TNandGate.compute(1);
        cr_assert_fail("Should have thrown an exception");
    } catch (const std::invalid_argument &e) {
        cr_assert_str_eq(e.what(), "Pin out of range");
    }
}

Test(TNandGate, Invalid_pins_operation)
{
    nts::TNandGate TNandGate;
    std::shared_ptr<nts::Input> input = std::make_shared<nts::Input>();

    TNandGate.setLink(4, input, 1);
    cr_assert_eq(TNandGate.compute(4), nts::Tristate::Undefined);
}

Test(TNandGate, true_case)
{
    nts::TNandGate TNandGate;
    std::shared_ptr<nts::Input> input1 = std::make_shared<nts::Input>();
    std::shared_ptr<nts::Input> input2 = std::make_shared<nts::Input>();
    std::shared_ptr<nts::Input> input3 = std::make_shared<nts::Input>();

    input1->setCurrentState(nts::Tristate::True);
    input2->setCurrentState(nts::Tristate::True);
    input3->setCurrentState(nts::Tristate::True);

    TNandGate.setLink(1, input1, 1);
    TNandGate.setLink(2, input2, 1);
    TNandGate.setLink(3, input3, 1);

    cr_assert_eq(TNandGate.compute(4), nts::Tristate::False);
}