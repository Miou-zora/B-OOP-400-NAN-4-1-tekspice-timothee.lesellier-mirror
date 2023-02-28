/*
** EPITECH PROJECT, 2023
** B-OOP-400-NAN-4-1-tekspice-timothee.lesellier-mirror
** File description:
** TrueComponent
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#define private public
#define protected public
#include "NTS.hpp"
#undef private
#undef protected

Test(TrueComponent, casual)
{
    nts::TrueComponent trueComponent;

    cr_assert_eq(trueComponent.compute(1), nts::Tristate::True);
    trueComponent.simulate(1);
    cr_assert_eq(trueComponent.compute(1), nts::Tristate::True);
    trueComponent.simulate(1);
    cr_assert_eq(trueComponent.compute(1), nts::Tristate::True);

    try {
        trueComponent.compute(2);
        cr_assert_fail("Should have thrown an exception");
    } catch (const std::invalid_argument &e) {
        cr_assert_str_eq(e.what(), "Pin out of range");
    }
    try {
        trueComponent.setLink(1, NULL, 1);
    } catch (const std::invalid_argument &e) {
        cr_assert_str_eq(e.what(), "Pin out of range");
    }
}

Test(FalseComponent, casual)
{
    nts::FalseComponent falseComponent;

    cr_assert_eq(falseComponent.compute(1), nts::Tristate::False);
    falseComponent.simulate(1);
    cr_assert_eq(falseComponent.compute(1), nts::Tristate::False);
    falseComponent.simulate(1);
    cr_assert_eq(falseComponent.compute(1), nts::Tristate::False);

    try {
        falseComponent.compute(2);
        cr_assert_fail("Should have thrown an exception");
    } catch (const std::invalid_argument &e) {
        cr_assert_str_eq(e.what(), "Pin out of range");
    }
    try {
        falseComponent.setLink(1, NULL, 1);
    } catch (const std::invalid_argument &e) {
        cr_assert_str_eq(e.what(), "Pin out of range");
    }
}