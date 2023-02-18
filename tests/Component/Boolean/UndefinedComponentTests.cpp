/*
** EPITECH PROJECT, 2023
** B-OOP-400-NAN-4-1-tekspice-timothee.lesellier-mirror
** File description:
** UndefinedComponentTests
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#define private public
#define protected public
#include "NTS.hpp"
#undef private
#undef protected

Test(UndefinedComponent, casual)
{
    nts::UndefinedComponent undefinedComponent;

    cr_assert_eq(undefinedComponent.compute(1), nts::Tristate::Undefined);
    undefinedComponent.simulate(1);
    cr_assert_eq(undefinedComponent.compute(1), nts::Tristate::Undefined);

    try {
        undefinedComponent.compute(2);
        cr_assert_fail("Should have thrown an exception");
    } catch (const std::invalid_argument &e) {
        cr_assert_str_eq(e.what(), "Pin out of range");
    }
}