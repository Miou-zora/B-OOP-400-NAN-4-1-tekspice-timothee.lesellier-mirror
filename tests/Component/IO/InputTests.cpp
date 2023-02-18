/*
** EPITECH PROJECT, 2023
** B-OOP-400-NAN-4-1-tekspice-timothee.lesellier-mirror
** File description:
** InputTests
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#define private public
#define protected public
#include "NTS.hpp"
#undef private
#undef protected

Test(Input, casual)
{
    nts::Input input;

    cr_assert_eq(input.compute(1), nts::Tristate::Undefined);
    input.simulate(1);
    cr_assert_eq(input.compute(1), nts::Tristate::Undefined);
    input.setNextState(nts::Tristate::True);
    cr_assert_eq(input.compute(1), nts::Tristate::Undefined);
    input.simulate(1);
    cr_assert_eq(input.compute(1), nts::Tristate::True);

    try {
        input.compute(2);
        cr_assert_fail("Should have thrown an exception");
    } catch (const std::invalid_argument &e) {
        cr_assert_str_eq(e.what(), "Pin out of range");
    }
}

Test(Input, getter_setter)
{
    nts::Input input;

    input.setCurrentState(nts::Tristate::True);
    cr_assert_eq(input.compute(1), nts::Tristate::True);
    cr_assert_eq(input.getCurrentState(), nts::Tristate::True);


    input.setCurrentState(nts::Tristate::False);
    cr_assert_eq(input.compute(1), nts::Tristate::False);
    cr_assert_eq(input.getCurrentState(), nts::Tristate::False);

    input.setCurrentState(nts::Tristate::Undefined);
    cr_assert_eq(input.compute(1), nts::Tristate::Undefined);
    cr_assert_eq(input.getCurrentState(), nts::Tristate::Undefined);

    input.setNextState(nts::Tristate::True);
    cr_assert_eq(input.compute(1), nts::Tristate::Undefined);
    cr_assert_eq(input.getNextState(), nts::Tristate::True);
    input.simulate(1);
    cr_assert_eq(input.compute(1), nts::Tristate::True);
    cr_assert_eq(input.getNextState(), nts::Tristate::True);

    input.setNextState(nts::Tristate::False);
    cr_assert_eq(input.compute(1), nts::Tristate::True);
    cr_assert_eq(input.getNextState(), nts::Tristate::False);
    input.simulate(1);
    cr_assert_eq(input.compute(1), nts::Tristate::False);
    cr_assert_eq(input.getNextState(), nts::Tristate::False);

    input.setNextState(nts::Tristate::Undefined);
    cr_assert_eq(input.compute(1), nts::Tristate::False);
    cr_assert_eq(input.getNextState(), nts::Tristate::Undefined);
    input.simulate(1);
    cr_assert_eq(input.compute(1), nts::Tristate::Undefined);
    cr_assert_eq(input.getNextState(), nts::Tristate::Undefined);
}