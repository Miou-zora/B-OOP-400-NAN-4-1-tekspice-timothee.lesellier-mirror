/*
** EPITECH PROJECT, 2023
** B-OOP-400-NAN-4-1-tekspice-timothee.lesellier-mirror
** File description:
** XorComponentTests
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#define private public
#define protected public
#include "NTS.hpp"
#undef private
#undef protected
#include <memory>

Test(XorComponent, invalid_pin)
{
    nts::XorComponent XorComponent;

    try {
        XorComponent.compute(1);
        cr_assert_fail("Should have thrown an exception");
    } catch (const std::invalid_argument &e) {
        cr_assert_str_eq(e.what(), "Pin out of range");
    }
}

Test(XorComponent, casual_undefined)
{
    nts::XorComponent XorComponent;
    std::shared_ptr<nts::Input> input1 = std::make_shared<nts::Input>();
    std::shared_ptr<nts::Input> input2 = std::make_shared<nts::Input>();

    cr_assert_eq(XorComponent.compute(3), nts::Tristate::Undefined);
    XorComponent.setLink(1, input1, 1);
    XorComponent.setLink(2, input2, 1);
    input1->setCurrentState(nts::Tristate::True);
    cr_assert_eq(XorComponent.compute(3), nts::Tristate::Undefined);
    input2->setCurrentState(nts::Tristate::True);
    input1->setCurrentState(nts::Tristate::Undefined);
    cr_assert_eq(XorComponent.compute(3), nts::Tristate::Undefined);
}

Test(XorComponent, casual_true)
{
    nts::XorComponent XorComponent;
    std::shared_ptr<nts::Input> input1 = std::make_shared<nts::Input>();
    std::shared_ptr<nts::Input> input2 = std::make_shared<nts::Input>();

    XorComponent.setLink(1, input1, 1);
    XorComponent.setLink(2, input2, 1);
    input1->setCurrentState(nts::Tristate::True);
    input2->setCurrentState(nts::Tristate::False);
    cr_assert_eq(XorComponent.compute(3), nts::Tristate::True);
}

Test(XorComponent, casual_false)
{
    nts::XorComponent XorComponent;
    std::shared_ptr<nts::Input> input1 = std::make_shared<nts::Input>();
    std::shared_ptr<nts::Input> input2 = std::make_shared<nts::Input>();

    XorComponent.setLink(1, input1, 1);
    XorComponent.setLink(2, input2, 1);
    input1->setCurrentState(nts::Tristate::True);
    input2->setCurrentState(nts::Tristate::False);
    cr_assert_eq(XorComponent.compute(3), nts::Tristate::True);
    input1->setCurrentState(nts::Tristate::False);
    input2->setCurrentState(nts::Tristate::True);
    cr_assert_eq(XorComponent.compute(3), nts::Tristate::True);
    input1->setCurrentState(nts::Tristate::False);
    input2->setCurrentState(nts::Tristate::False);
    cr_assert_eq(XorComponent.compute(3), nts::Tristate::False);
}

Test(XorComponent, pdf_bool_table)
{
    nts::XorComponent XorComponent;
    std::shared_ptr<nts::Input> input1 = std::make_shared<nts::Input>();
    std::shared_ptr<nts::Input> input2 = std::make_shared<nts::Input>();
    XorComponent.setLink(1, input1, 1);
    XorComponent.setLink(2, input2, 1);

    input1->setCurrentState(nts::Tristate::False);
    input2->setCurrentState(nts::Tristate::False);
    cr_assert_eq(XorComponent.compute(3), nts::Tristate::False);
    input2->setCurrentState(nts::Tristate::True);
    cr_assert_eq(XorComponent.compute(3), nts::Tristate::True);
    input2->setCurrentState(nts::Tristate::Undefined);
    cr_assert_eq(XorComponent.compute(3), nts::Tristate::Undefined);
    input1->setCurrentState(nts::Tristate::True);
    input2->setCurrentState(nts::Tristate::False);
    cr_assert_eq(XorComponent.compute(3), nts::Tristate::True);
    input2->setCurrentState(nts::Tristate::True);
    cr_assert_eq(XorComponent.compute(3), nts::Tristate::False);
    input2->setCurrentState(nts::Tristate::Undefined);
    cr_assert_eq(XorComponent.compute(3), nts::Tristate::Undefined);
    input1->setCurrentState(nts::Tristate::Undefined);
    input2->setCurrentState(nts::Tristate::False);
    cr_assert_eq(XorComponent.compute(3), nts::Tristate::Undefined);
    input2->setCurrentState(nts::Tristate::True);
    cr_assert_eq(XorComponent.compute(3), nts::Tristate::Undefined);
    input2->setCurrentState(nts::Tristate::Undefined);
    cr_assert_eq(XorComponent.compute(3), nts::Tristate::Undefined);
}