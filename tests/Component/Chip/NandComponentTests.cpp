/*
** EPITECH PROJECT, 2023
** B-OOP-400-NAN-4-1-tekspice-timothee.lesellier-mirror
** File description:
** NandComponentTests
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#define private public
#define protected public
#include "NTS.hpp"
#undef private
#undef protected
#include <memory>

Test(NandComponent, invalid_pin)
{
    nts::NandComponent nandcomponent;

    try {
        nandcomponent.compute(1);
        cr_assert_fail("Should have thrown an exception");
    } catch (const std::invalid_argument &e) {
        cr_assert_str_eq(e.what(), "Pin out of range");
    }
}

Test(NandComponent, casual_undefined)
{
    nts::NandComponent NandComponent;
    std::shared_ptr<nts::Input> input1 = std::make_shared<nts::Input>();
    std::shared_ptr<nts::Input> input2 = std::make_shared<nts::Input>();

    cr_assert_eq(NandComponent.compute(3), nts::Tristate::Undefined);
    NandComponent.setLink(1, input1, 1);
    NandComponent.setLink(2, input2, 1);
    input1->setCurrentState(nts::Tristate::True);
    cr_assert_eq(NandComponent.compute(3), nts::Tristate::Undefined);
    input2->setCurrentState(nts::Tristate::True);
    input1->setCurrentState(nts::Tristate::Undefined);
    cr_assert_eq(NandComponent.compute(3), nts::Tristate::Undefined);
}

Test(NandComponent, casual_true)
{
    nts::NandComponent NandComponent;
    std::shared_ptr<nts::Input> input1 = std::make_shared<nts::Input>();
    std::shared_ptr<nts::Input> input2 = std::make_shared<nts::Input>();

    NandComponent.setLink(1, input1, 1);
    NandComponent.setLink(2, input2, 1);
    input1->setCurrentState(nts::Tristate::True);
    input2->setCurrentState(nts::Tristate::True);
    cr_assert_eq(NandComponent.compute(3), nts::Tristate::False);
}

Test(NandComponent, casual_false)
{
    nts::NandComponent NandComponent;
    std::shared_ptr<nts::Input> input1 = std::make_shared<nts::Input>();
    std::shared_ptr<nts::Input> input2 = std::make_shared<nts::Input>();

    NandComponent.setLink(1, input1, 1);
    NandComponent.setLink(2, input2, 1);
    input1->setCurrentState(nts::Tristate::True);
    input2->setCurrentState(nts::Tristate::False);
    cr_assert_eq(NandComponent.compute(3), nts::Tristate::True);
    input1->setCurrentState(nts::Tristate::False);
    input2->setCurrentState(nts::Tristate::True);
    cr_assert_eq(NandComponent.compute(3), nts::Tristate::True);
    input1->setCurrentState(nts::Tristate::False);
    input2->setCurrentState(nts::Tristate::False);
    cr_assert_eq(NandComponent.compute(3), nts::Tristate::True);
}