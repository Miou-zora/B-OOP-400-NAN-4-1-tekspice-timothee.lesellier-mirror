/*
** EPITECH PROJECT, 2023
** B-OOP-400-NAN-4-1-tekspice-timothee.lesellier-mirror
** File description:
** ClockTests
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#define private public
#define protected public
#include "NTS.hpp"
#undef private
#undef protected

Test(Clock, casual)
{
    nts::Clock Clock;

    cr_assert_eq(Clock.compute(1), nts::Tristate::Undefined);
    Clock.simulate(1);
    Clock.resetUpdate();
    cr_assert_eq(Clock.compute(1), nts::Tristate::Undefined);
    Clock.setNextState(nts::Tristate::True);
    cr_assert_eq(Clock.compute(1), nts::Tristate::Undefined);
    Clock.simulate(1);
    Clock.resetUpdate();
    cr_assert_eq(Clock.compute(1), nts::Tristate::True);
    Clock.simulate(1);
    cr_assert_eq(Clock.compute(1), nts::Tristate::False);
    Clock.simulate(1);
    Clock.resetUpdate();
    cr_assert_eq(Clock.compute(1), nts::Tristate::False);
    Clock.setNextState(nts::Undefined);
    cr_assert_eq(Clock.compute(1), nts::Tristate::False);
    Clock.simulate(1);
    Clock.resetUpdate();
    cr_assert_eq(Clock.compute(1), nts::Tristate::Undefined);

    try {
        Clock.compute(2);
        cr_assert_fail("Should have thrown an exception");
    } catch (const std::invalid_argument &e) {
        cr_assert_str_eq(e.what(), "Pin out of range");
    }
}