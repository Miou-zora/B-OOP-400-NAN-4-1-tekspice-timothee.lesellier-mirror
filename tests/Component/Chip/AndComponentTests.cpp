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

Test(simulate, casual)
{
    nts::AndComponent andComponent;

    andComponent.simulate(1);
    cr_assert_eq(andComponent._state, nts::Tristate::Undefined);
}