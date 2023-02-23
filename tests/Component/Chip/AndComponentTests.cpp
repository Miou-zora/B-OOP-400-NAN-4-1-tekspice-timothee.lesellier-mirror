/*
** EPITECH PROJECT, 2023
** B-OOP-400-NAN-4-1-tekspice-timothee.lesellier-mirror
** File description:
** AndComponentTests
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#define private public
#define protected public
#include "NTS.hpp"
#undef private
#undef protected
#include <memory>

Test(AndComponent, invalid_pin)
{
    nts::AndComponent andComponent;

    try {
        andComponent.compute(1);
        cr_assert_fail("Should have thrown an exception");
    } catch (const std::invalid_argument &e) {
        cr_assert_str_eq(e.what(), "Pin out of range");
    }
}

Test(AndComponent, casual_undefined)
{
    nts::AndComponent andComponent;
    std::shared_ptr<nts::Input> input1 = std::make_shared<nts::Input>();
    std::shared_ptr<nts::Input> input2 = std::make_shared<nts::Input>();

    cr_assert_eq(andComponent.compute(3), nts::Tristate::Undefined);
    andComponent.setLink(1, input1, 1);
    andComponent.setLink(2, input2, 1);
    input1->setCurrentState(nts::Tristate::True);
    cr_assert_eq(andComponent.compute(3), nts::Tristate::Undefined);
    input2->setCurrentState(nts::Tristate::True);
    input1->setCurrentState(nts::Tristate::Undefined);
    cr_assert_eq(andComponent.compute(3), nts::Tristate::Undefined);
}

Test(AndComponent, casual_true)
{
    nts::AndComponent andComponent;
    std::shared_ptr<nts::Input> input1 = std::make_shared<nts::Input>();
    std::shared_ptr<nts::Input> input2 = std::make_shared<nts::Input>();

    andComponent.setLink(1, input1, 1);
    andComponent.setLink(2, input2, 1);
    input1->setCurrentState(nts::Tristate::True);
    input2->setCurrentState(nts::Tristate::True);
    cr_assert_eq(andComponent.compute(3), nts::Tristate::True);
}

Test(AndComponent, casual_false)
{
    nts::AndComponent andComponent;
    std::shared_ptr<nts::Input> input1 = std::make_shared<nts::Input>();
    std::shared_ptr<nts::Input> input2 = std::make_shared<nts::Input>();

    andComponent.setLink(1, input1, 1);
    andComponent.setLink(2, input2, 1);
    input1->setCurrentState(nts::Tristate::True);
    input2->setCurrentState(nts::Tristate::False);
    cr_assert_eq(andComponent.compute(3), nts::Tristate::False);
    input1->setCurrentState(nts::Tristate::False);
    input2->setCurrentState(nts::Tristate::True);
    cr_assert_eq(andComponent.compute(3), nts::Tristate::False);
    input1->setCurrentState(nts::Tristate::False);
    input2->setCurrentState(nts::Tristate::False);
    cr_assert_eq(andComponent.compute(3), nts::Tristate::False);
}

Test(AndComponent, pdf_bool_table)
{
    nts::AndComponent andComponent;
    std::shared_ptr<nts::Input> input1 = std::make_shared<nts::Input>();
    std::shared_ptr<nts::Input> input2 = std::make_shared<nts::Input>();

    andComponent.setLink(1, input1, 1);
    andComponent.setLink(2, input2, 1);
    input1->setCurrentState(nts::Tristate::False);
    input2->setCurrentState(nts::Tristate::False);
    cr_assert_eq(andComponent.compute(3), nts::Tristate::False);
    input2->setCurrentState(nts::Tristate::True);
    cr_assert_eq(andComponent.compute(3), nts::Tristate::False);
    input2->setCurrentState(nts::Tristate::Undefined);
    cr_assert_eq(andComponent.compute(3), nts::Tristate::False);
    input1->setCurrentState(nts::Tristate::True);
    input2->setCurrentState(nts::Tristate::False);
    cr_assert_eq(andComponent.compute(3), nts::Tristate::False);
    input2->setCurrentState(nts::Tristate::True);
    cr_assert_eq(andComponent.compute(3), nts::Tristate::True);
    input2->setCurrentState(nts::Tristate::Undefined);
    cr_assert_eq(andComponent.compute(3), nts::Tristate::Undefined);
    input1->setCurrentState(nts::Tristate::Undefined);
    input2->setCurrentState(nts::Tristate::False);
    cr_assert_eq(andComponent.compute(3), nts::Tristate::False);
    input2->setCurrentState(nts::Tristate::True);
    cr_assert_eq(andComponent.compute(3), nts::Tristate::Undefined);
    input2->setCurrentState(nts::Tristate::Undefined);
    cr_assert_eq(andComponent.compute(3), nts::Tristate::Undefined);
}
