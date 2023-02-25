/*
** EPITECH PROJECT, 2023
** B-OOP-400-NAN-4-1-tekspice-timothee.lesellier-mirror
** File description:
** DLatchComponentTests
*/


#include <criterion/criterion.h>
#include <criterion/redirect.h>
#define private public
#define protected public
#include "NTS.hpp"
#undef private
#undef protected
#include <memory>
#include <map>

Test(DLatchComponent, InvalidSetLink)
{
    nts::DLatchComponent DLatchComponent;
    std::shared_ptr<nts::Input> input1 = std::make_shared<nts::Input>();
    try {
        DLatchComponent.setLink(5, input1, 1);
        cr_assert_fail("Should have thrown an exception");
    } catch (const std::invalid_argument &e) {
        cr_assert_str_eq(e.what(), "The pin wished is out of range");
    }
}

Test(DLatchComponent, invalid_pin)
{
    nts::DLatchComponent DLatchComponent;

    try {
        DLatchComponent.compute(1);
        cr_assert_fail("Should have thrown an exception");
    } catch (const std::invalid_argument &e) {
        cr_assert_str_eq(e.what(), "Pin out of range");
    }
    try {
        DLatchComponent.compute(2);
        cr_assert_fail("Should have thrown an exception");
    } catch (const std::invalid_argument &e) {
        cr_assert_str_eq(e.what(), "Pin out of range");
    }
    try {
        DLatchComponent.compute(5);
        cr_assert_fail("Should have thrown an exception");
    } catch (const std::invalid_argument &e) {
        cr_assert_str_eq(e.what(), "Pin out of range");
    }
}

Test(DLatchComponent, casual_undefined)
{
    nts::DLatchComponent DLatchComponent;
    std::shared_ptr<nts::Input> input1 = std::make_shared<nts::Input>();
    std::shared_ptr<nts::Input> input2 = std::make_shared<nts::Input>();

    input1->setNextState(nts::Undefined);
    input2->setNextState(nts::Undefined);
    input1->simulate(1);
    input2->simulate(1);
    DLatchComponent.setLink(1, input1, 1);
    DLatchComponent.setLink(2, input2, 1);
    cr_assert(DLatchComponent.compute(3) == nts::Undefined);
    cr_assert(DLatchComponent.compute(4) == nts::Undefined);
    input2->setNextState(nts::True);
    input2->simulate(1);
    cr_assert(DLatchComponent.compute(3) == nts::Undefined);
    cr_assert(DLatchComponent.compute(4) == nts::Undefined);
    input2->setNextState(nts::False);
    input2->simulate(1);
    cr_assert(DLatchComponent.compute(3) == nts::Undefined);
    cr_assert(DLatchComponent.compute(4) == nts::Undefined);
    input1->setNextState(nts::True);
    input2->setNextState(nts::Undefined);
    input1->simulate(1);
    input2->simulate(1);
    cr_assert(DLatchComponent.compute(3) == nts::Undefined);
    cr_assert(DLatchComponent.compute(4) == nts::Undefined);
    input1->setNextState(nts::Undefined);
    input2->setNextState(nts::True);
    DLatchComponent.simulate(1);
    DLatchComponent.resetUpdate();
    cr_assert(DLatchComponent.compute(3) == nts::Undefined);
    cr_assert(DLatchComponent.compute(4) == nts::Undefined);
    input1->setNextState(nts::False);
    DLatchComponent.simulate(1);
    DLatchComponent.resetUpdate();
    cr_assert(DLatchComponent.compute(3) == nts::Undefined);
    cr_assert(DLatchComponent.compute(4) == nts::Undefined);
}

Test(DLatchComponent, casualTrue)
{
    nts::DLatchComponent DLatchComponent;
    std::shared_ptr<nts::Input> input1 = std::make_shared<nts::Input>();
    std::shared_ptr<nts::Input> input2 = std::make_shared<nts::Input>();

    input1->setNextState(nts::True);
    input2->setNextState(nts::True);
    input1->simulate(1);
    input2->simulate(1);
    DLatchComponent.setLink(1, input1, 1);
    DLatchComponent.setLink(2, input2, 1);
    cr_assert(DLatchComponent.compute(3) == nts::True);
    cr_assert(DLatchComponent.compute(4) == nts::False);
}

Test(DLatchComponent, casualFalse)
{
    nts::DLatchComponent DLatchComponent;
    std::shared_ptr<nts::Input> input1 = std::make_shared<nts::Input>();
    std::shared_ptr<nts::Input> input2 = std::make_shared<nts::Input>();

    input1->setNextState(nts::True);
    input2->setNextState(nts::False);
    input1->simulate(1);
    input2->simulate(1);
    DLatchComponent.setLink(1, input1, 1);
    DLatchComponent.setLink(2, input2, 1);
    cr_assert(DLatchComponent.compute(3) == nts::False);
    cr_assert(DLatchComponent.compute(4) == nts::True);
}

Test(DLatchComponent, CasualState)
{
    nts::DLatchComponent DLatchComponent;
    std::shared_ptr<nts::Input> input1 = std::make_shared<nts::Input>();
    std::shared_ptr<nts::Input> input2 = std::make_shared<nts::Input>();

    DLatchComponent.setLink(1, input1, 1);
    DLatchComponent.setLink(2, input2, 1);
    input1->setNextState(nts::True);
    input2->setNextState(nts::False);
    DLatchComponent.simulate(1);
    DLatchComponent.resetUpdate();
    cr_assert(DLatchComponent.compute(3) == nts::False);
    cr_assert(DLatchComponent.compute(4) == nts::True);
    input1->setNextState(nts::False);
    input2->setNextState(nts::Undefined);
    DLatchComponent.simulate(1);
    DLatchComponent.resetUpdate();
    cr_assert(DLatchComponent.compute(3) == nts::False);
    cr_assert(DLatchComponent.compute(4) == nts::True);
    input1->setNextState(nts::False);
    input2->setNextState(nts::True);
    DLatchComponent.simulate(1);
    DLatchComponent.resetUpdate();
    cr_assert(DLatchComponent.compute(3) == nts::False);
    cr_assert(DLatchComponent.compute(4) == nts::True);
    input1->setNextState(nts::False);
    input2->setNextState(nts::False);
    DLatchComponent.simulate(1);
    DLatchComponent.resetUpdate();
    cr_assert(DLatchComponent.compute(3) == nts::False);
    cr_assert(DLatchComponent.compute(4) == nts::True);
    input1->setNextState(nts::True);
    input2->setNextState(nts::True);
    DLatchComponent.simulate(1);
    DLatchComponent.resetUpdate();
    input1->setNextState(nts::False);
    input2->setNextState(nts::False);
    DLatchComponent.simulate(1);
    DLatchComponent.resetUpdate();
    cr_assert(DLatchComponent.compute(3) == nts::True);
    cr_assert(DLatchComponent.compute(4) == nts::False);
}

Test(DLatchComponent, notLinks)
{
    nts::DLatchComponent DLatchComponent;

    try {
        DLatchComponent.compute(3);
        cr_assert_fail("Should have thrown an exception");
    } catch (const std::invalid_argument &e) {
        cr_assert_str_eq(e.what(), "Pin not linked");
    }
    try {
        DLatchComponent.simulate(4);
        DLatchComponent.resetUpdate();
        cr_assert_fail("Should have thrown an exception");
    } catch (const std::invalid_argument &e) {
        cr_assert_str_eq(e.what(), "Pin not linked");
    }
}

Test(DLatchComponent, doubleSimulate)
{
    nts::DLatchComponent DLatchComponent;
    std::shared_ptr<nts::Input> input1 = std::make_shared<nts::Input>();
    std::shared_ptr<nts::Input> input2 = std::make_shared<nts::Input>();

    DLatchComponent.setLink(1, input1, 1);
    DLatchComponent.setLink(2, input2, 1);
    input1->setNextState(nts::True);
    input2->setNextState(nts::False);
    DLatchComponent.simulate(1);
    cr_assert(DLatchComponent.compute(3) == nts::False);
    cr_assert(DLatchComponent.compute(4) == nts::True);
    input1->setNextState(nts::True);
    input2->setNextState(nts::True);
    DLatchComponent.simulate(1);
    cr_assert(DLatchComponent.compute(3) == nts::False);
    cr_assert(DLatchComponent.compute(4) == nts::True);
}