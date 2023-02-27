/*
** EPITECH PROJECT, 2023
** B-OOP-400-NAN-4-1-tekspice-timothee.lesellier-mirror
** File description:
** SRLatchComponentTests
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

Test(SRLatchComponent, notLinks)
{
    nts::SRLatchComponent SRLatchComponent;

    try {
        SRLatchComponent.compute(3);
        cr_assert_fail("Should have thrown an exception");
    } catch (const std::invalid_argument &e) {
        cr_assert_str_eq(e.what(), "Pin not linked");
    }
    try {
        SRLatchComponent.simulate(4);
        SRLatchComponent.resetUpdate();
        cr_assert_fail("Should have thrown an exception");
    } catch (const std::invalid_argument &e) {
        cr_assert_str_eq(e.what(), "Pin not linked");
    }
}

Test(SRLatchComponent, InvalidSetLink)
{
    nts::SRLatchComponent SRLatchComponent;
    std::shared_ptr<nts::Input> input1 = std::make_shared<nts::Input>();
    try {
        SRLatchComponent.setLink(5, input1, 1);
        cr_assert_fail("Should have thrown an exception");
    } catch (const std::invalid_argument &e) {
        cr_assert_str_eq(e.what(), "The pin wished is out of range");
    }
}

Test(SRLatchComponent, invalid_pin)
{
    nts::SRLatchComponent SRLatchComponent;

    try {
        SRLatchComponent.compute(1);
        cr_assert_fail("Should have thrown an exception");
    } catch (const std::invalid_argument &e) {
        cr_assert_str_eq(e.what(), "Pin out of range");
    }
    try {
        SRLatchComponent.compute(2);
        cr_assert_fail("Should have thrown an exception");
    } catch (const std::invalid_argument &e) {
        cr_assert_str_eq(e.what(), "Pin out of range");
    }
    try {
        SRLatchComponent.compute(5);
        cr_assert_fail("Should have thrown an exception");
    } catch (const std::invalid_argument &e) {
        cr_assert_str_eq(e.what(), "Pin out of range");
    }
}

Test(SRLatchComponent, casualUndefined)
{
    nts::SRLatchComponent SRLatchComponent;
    std::shared_ptr<nts::Input> input1 = std::make_shared<nts::Input>();
    std::shared_ptr<nts::Input> input2 = std::make_shared<nts::Input>();

    SRLatchComponent.setLink(1, input1, 1);
    SRLatchComponent.setLink(2, input2, 1);

    input1->setNextState(nts::Undefined);

    input2->setNextState(nts::Undefined);
    SRLatchComponent.simulate(1);
    SRLatchComponent.resetUpdate();
    cr_assert(SRLatchComponent.compute(3) == nts::Undefined);
    cr_assert(SRLatchComponent.compute(4) == nts::Undefined);

    input2->setNextState(nts::False);
    SRLatchComponent.simulate(1);
    SRLatchComponent.resetUpdate();
    cr_assert(SRLatchComponent.compute(3) == nts::Undefined);
    cr_assert(SRLatchComponent.compute(4) == nts::Undefined);

    input2->setNextState(nts::True);
    SRLatchComponent.simulate(1);
    SRLatchComponent.resetUpdate();
    cr_assert(SRLatchComponent.compute(3) == nts::Undefined);
    cr_assert(SRLatchComponent.compute(4) == nts::False);
}

Test(SRLatchComponent, casualTrue)
{
    nts::SRLatchComponent SRLatchComponent;
    std::shared_ptr<nts::Input> input1 = std::make_shared<nts::Input>();
    std::shared_ptr<nts::Input> input2 = std::make_shared<nts::Input>();

    SRLatchComponent.setLink(1, input1, 1);
    SRLatchComponent.setLink(2, input2, 1);

    input1->setNextState(nts::True);

    input2->setNextState(nts::Undefined);
    SRLatchComponent.simulate(1);
    SRLatchComponent.resetUpdate();
    cr_assert(SRLatchComponent.compute(3) == nts::False);
    cr_assert(SRLatchComponent.compute(4) == nts::Undefined);

    input2->setNextState(nts::False);
    SRLatchComponent.simulate(1);
    SRLatchComponent.resetUpdate();
    cr_assert(SRLatchComponent.compute(3) == nts::False);
    cr_assert(SRLatchComponent.compute(4) == nts::True);

    input2->setNextState(nts::True);
    SRLatchComponent.simulate(1);
    SRLatchComponent.resetUpdate();
    cr_assert(SRLatchComponent.compute(3) == nts::False);
    cr_assert(SRLatchComponent.compute(4) == nts::False);
}

Test(SRLatchComponent, casualFalse)
{
    nts::SRLatchComponent SRLatchComponent;
    std::shared_ptr<nts::Input> input1 = std::make_shared<nts::Input>();
    std::shared_ptr<nts::Input> input2 = std::make_shared<nts::Input>();

    SRLatchComponent.setLink(1, input1, 1);
    SRLatchComponent.setLink(2, input2, 1);

    input1->setNextState(nts::False);

    input2->setNextState(nts::Undefined);
    SRLatchComponent.simulate(1);
    SRLatchComponent.resetUpdate();
    std::cout << 3 << std::endl;
    cr_assert(SRLatchComponent.compute(3) == nts::Undefined);
    std::cout << 4 << std::endl;
    cr_assert(SRLatchComponent.compute(4) == nts::Undefined);

    input2->setNextState(nts::True);
    SRLatchComponent.simulate(1);
    SRLatchComponent.resetUpdate();
    cr_assert(SRLatchComponent.compute(3) == nts::True);
    cr_assert(SRLatchComponent.compute(4) == nts::False);

    input2->setNextState(nts::False);
    SRLatchComponent.simulate(1);
    SRLatchComponent.resetUpdate();
    cr_assert(SRLatchComponent.compute(3) == nts::True);
    cr_assert(SRLatchComponent.compute(4) == nts::False);
}

Test(SRLatchComponent, doubleSimulate)
{
    nts::SRLatchComponent SRLatchComponent;
    std::shared_ptr<nts::Input> input1 = std::make_shared<nts::Input>();
    std::shared_ptr<nts::Input> input2 = std::make_shared<nts::Input>();

    SRLatchComponent.setLink(1, input1, 1);
    SRLatchComponent.setLink(2, input2, 1);

    input1->setNextState(nts::False);

    input2->setNextState(nts::Undefined);
    SRLatchComponent.simulate(1);
    input1->setNextState(nts::True);
    input2->setNextState(nts::True);
    SRLatchComponent.simulate(1);
    SRLatchComponent.resetUpdate();
    input1->setNextState(nts::False);
    input2->setNextState(nts::False);
    SRLatchComponent.resetUpdate();
    cr_assert(SRLatchComponent.compute(3) == nts::Undefined);
    cr_assert(SRLatchComponent.compute(4) == nts::Undefined);
}