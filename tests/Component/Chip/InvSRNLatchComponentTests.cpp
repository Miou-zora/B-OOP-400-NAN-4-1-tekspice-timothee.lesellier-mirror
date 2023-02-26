/*
** EPITECH PROJECT, 2023
** B-OOP-400-NAN-4-1-tekspice-timothee.lesellier-mirror
** File description:
** InvSRNLatchComponentTests
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

Test(InvSRNLatchComponent, notLinks)
{
    nts::InvSRNLatchComponent InvSRNLatchComponent;

    try {
        InvSRNLatchComponent.compute(3);
        cr_assert_fail("Should have thrown an exception");
    } catch (const std::invalid_argument &e) {
        cr_assert_str_eq(e.what(), "Pin out of range");
    }
    try {
        InvSRNLatchComponent.simulate(4);
        InvSRNLatchComponent.resetUpdate();
        cr_assert_fail("Should have thrown an exception");
    } catch (const std::invalid_argument &e) {
        cr_assert_str_eq(e.what(), "Pin out of range");
    }
}

Test(InvSRNLatchComponent, InvalidSetLink)
{
    nts::InvSRNLatchComponent InvSRNLatchComponent;
    std::shared_ptr<nts::Input> input1 = std::make_shared<nts::Input>();
    try {
        InvSRNLatchComponent.setLink(5, input1, 1);
        cr_assert_fail("Should have thrown an exception");
    } catch (const std::invalid_argument &e) {
        cr_assert_str_eq(e.what(), "Pin out of range");
    }
}

Test(InvSRNLatchComponent, invalid_pin)
{
    nts::InvSRNLatchComponent InvSRNLatchComponent;

    try {
        InvSRNLatchComponent.compute(1);
        cr_assert_fail("Should have thrown an exception");
    } catch (const std::invalid_argument &e) {
        cr_assert_str_eq(e.what(), "Pin out of range");
    }
    try {
        InvSRNLatchComponent.compute(2);
        cr_assert_fail("Should have thrown an exception");
    } catch (const std::invalid_argument &e) {
        cr_assert_str_eq(e.what(), "Pin out of range");
    }
    try {
        InvSRNLatchComponent.compute(5);
        cr_assert_fail("Should have thrown an exception");
    } catch (const std::invalid_argument &e) {
        cr_assert_str_eq(e.what(), "Pin out of range");
    }
}

Test(InvSRNLatchComponent, casualUndefined)
{
    nts::InvSRNLatchComponent InvSRNLatchComponent;
    std::shared_ptr<nts::Input> input1 = std::make_shared<nts::Input>();
    std::shared_ptr<nts::Input> input2 = std::make_shared<nts::Input>();

    InvSRNLatchComponent.setLink(1, input1, 1);
    InvSRNLatchComponent.setLink(2, input2, 1);

    input1->setNextState(nts::Undefined);

    input2->setNextState(nts::Undefined);
    InvSRNLatchComponent.simulate(1);
    InvSRNLatchComponent.resetUpdate();
    cr_assert(InvSRNLatchComponent.compute(3) == nts::Undefined);
    cr_assert(InvSRNLatchComponent.compute(4) == nts::Undefined);

    input2->setNextState(nts::False);
    InvSRNLatchComponent.simulate(1);
    InvSRNLatchComponent.resetUpdate();
    cr_assert(InvSRNLatchComponent.compute(3) == nts::Undefined);
    cr_assert(InvSRNLatchComponent.compute(4) == nts::Undefined);

    input2->setNextState(nts::True);
    InvSRNLatchComponent.simulate(1);
    InvSRNLatchComponent.resetUpdate();
    cr_assert(InvSRNLatchComponent.compute(3) == nts::Undefined);
    cr_assert(InvSRNLatchComponent.compute(4) == nts::False);
}

Test(InvSRNLatchComponent, casualTrue)
{
    nts::InvSRNLatchComponent InvSRNLatchComponent;
    std::shared_ptr<nts::Input> input1 = std::make_shared<nts::Input>();
    std::shared_ptr<nts::Input> input2 = std::make_shared<nts::Input>();

    InvSRNLatchComponent.setLink(1, input1, 1);
    InvSRNLatchComponent.setLink(2, input2, 1);

    input1->setNextState(nts::True);

    input2->setNextState(nts::Undefined);
    InvSRNLatchComponent.simulate(1);
    InvSRNLatchComponent.resetUpdate();
    cr_assert(InvSRNLatchComponent.compute(3) == nts::False);
    cr_assert(InvSRNLatchComponent.compute(4) == nts::Undefined);

    input2->setNextState(nts::False);
    InvSRNLatchComponent.simulate(1);
    InvSRNLatchComponent.resetUpdate();
    cr_assert(InvSRNLatchComponent.compute(3) == nts::False);
    cr_assert(InvSRNLatchComponent.compute(4) == nts::True);

    input2->setNextState(nts::True);
    InvSRNLatchComponent.simulate(1);
    InvSRNLatchComponent.resetUpdate();
    cr_assert(InvSRNLatchComponent.compute(3) == nts::False);
    cr_assert(InvSRNLatchComponent.compute(4) == nts::False);
}

Test(InvSRNLatchComponent, casualFalse)
{
    nts::InvSRNLatchComponent InvSRNLatchComponent;
    std::shared_ptr<nts::Input> input1 = std::make_shared<nts::Input>();
    std::shared_ptr<nts::Input> input2 = std::make_shared<nts::Input>();

    InvSRNLatchComponent.setLink(1, input1, 1);
    InvSRNLatchComponent.setLink(2, input2, 1);

    input1->setNextState(nts::False);

    input2->setNextState(nts::Undefined);
    InvSRNLatchComponent.simulate(1);
    InvSRNLatchComponent.resetUpdate();
    cr_assert(InvSRNLatchComponent.compute(3) == nts::Undefined);
    cr_assert(InvSRNLatchComponent.compute(4) == nts::Undefined);

    input2->setNextState(nts::True);
    InvSRNLatchComponent.simulate(1);
    InvSRNLatchComponent.resetUpdate();
    cr_assert(InvSRNLatchComponent.compute(3) == nts::True);
    cr_assert(InvSRNLatchComponent.compute(4) == nts::False);

    input2->setNextState(nts::False);
    InvSRNLatchComponent.simulate(1);
    InvSRNLatchComponent.resetUpdate();
    cr_assert(InvSRNLatchComponent.compute(3) == nts::True);
    cr_assert(InvSRNLatchComponent.compute(4) == nts::False);
}

Test(InvSRNLatchComponent, doubleSimulate)
{
    nts::InvSRNLatchComponent InvSRNLatchComponent;
    std::shared_ptr<nts::Input> input1 = std::make_shared<nts::Input>();
    std::shared_ptr<nts::Input> input2 = std::make_shared<nts::Input>();

    InvSRNLatchComponent.setLink(1, input1, 1);
    InvSRNLatchComponent.setLink(2, input2, 1);

    input1->setNextState(nts::False);

    input2->setNextState(nts::Undefined);
    InvSRNLatchComponent.simulate(1);
    input1->setNextState(nts::True);
    input2->setNextState(nts::True);
    InvSRNLatchComponent.simulate(1);
    InvSRNLatchComponent.resetUpdate();
    input1->setNextState(nts::False);
    input2->setNextState(nts::False);
    InvSRNLatchComponent.resetUpdate();
    cr_assert(InvSRNLatchComponent.compute(3) == nts::Undefined);
    cr_assert(InvSRNLatchComponent.compute(4) == nts::Undefined);
}