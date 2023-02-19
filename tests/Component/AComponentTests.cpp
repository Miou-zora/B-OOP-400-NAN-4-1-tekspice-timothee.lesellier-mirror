/*
** EPITECH PROJECT, 2023
** B-OOP-400-NAN-4-1-tekspice-timothee.lesellier-mirror
** File description:
** AComponent
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#define private public
#include "NTS.hpp"
#undef private

Test(AComponent, createComponent)
{
    nts::AndComponent andComponent;
    std::shared_ptr<nts::Input> input1;

    try {
        andComponent.setLink(4, input1, 4);
        cr_assert_fail("Should have thrown an exception");
    } catch (std::invalid_argument &e) {
        cr_assert_str_eq(e.what(), "The pin wished is out of range");
    }
}

Test(AComponent, link_itself)
{
    nts::AndComponent andComponent;
    std::shared_ptr<nts::AndComponent> andComponent2 = std::make_shared<nts::AndComponent>();
    std::shared_ptr<nts::Input> input1;

    try {
        andComponent2->setLink(1, andComponent2, 1);
        cr_assert_fail("Should have thrown an exception");
    } catch (std::invalid_argument &e) {
        cr_assert_str_eq(e.what(), "You can't link a component to itself");
    }
}

Test(AComponent, getPinMax)
{
    nts::AndComponent andComponent;

    cr_assert_eq(andComponent.getPinMax(), 3);
}