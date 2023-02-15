/*
** EPITECH PROJECT, 2023
** B-OOP-400-NAN-4-1-tekspice-timothee.lesellier-mirror
** File description:
** LinkTests
*/

#include "Component/Link.hpp"
#include <criterion/criterion.h>

Test(Link, createLink)
{
    nts::Link link;
}

Test(Link, setter_getter)
{
    nts::Link link;

    link.setComponent(nullptr);
    link.setPin(0);
    link.setOtherPin(0);

    cr_assert_eq(link.getComponent(), nullptr);
    cr_assert_eq(link.getPin(), 0);
    cr_assert_eq(link.getOtherPin(), 0);
}

