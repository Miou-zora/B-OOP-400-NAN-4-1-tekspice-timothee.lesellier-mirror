/*
** EPITECH PROJECT, 2023
** B-OOP-400-NAN-4-1-tekspice-timothee.lesellier-mirror
** File description:
** NotComponentTests
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#define private public
#define protected public
#include "NTS.hpp"
#undef private
#undef protected
#include <memory>

Test(NotComponent, invalid_pin)
{
    nts::NotComponent NotComponent;

    try {
        NotComponent.compute(1);
        cr_assert_fail("Should have thrown an exception");
    } catch (const std::invalid_argument &e) {
        cr_assert_str_eq(e.what(), "Pin out of range");
    }
}

Test(NotComponent, compute)
{
    nts::NotComponent NotComponent;
    nts::Tristate v = NotComponent.compute(2);

    cr_assert_eq(v, nts::Tristate::Undefined);
}

Test(NotComponent, notTrue)
{
    nts::NotComponent NotComponent;
    std::shared_ptr<nts::Input> input = std::make_shared<nts::Input>();
    input->setCurrentState(nts::Tristate::True);
    NotComponent.setLink(1, input, 1);
    cr_assert_eq(NotComponent.compute(2), nts::Tristate::False);
}

Test(NotComponent, notFalse)
{
    nts::NotComponent NotComponent;
    std::shared_ptr<nts::Input> input = std::make_shared<nts::Input>();
    input->setCurrentState(nts::Tristate::False);
    NotComponent.setLink(1, input, 1);
    cr_assert_eq(NotComponent.compute(2), nts::Tristate::True);
}

Test(NotComponent, Undefined)
{
    nts::NotComponent NotComponent;
    std::shared_ptr<nts::Input> input = std::make_shared<nts::Input>();
    input->setCurrentState(nts::Tristate::Undefined);
    NotComponent.setLink(1, input, 1);
    cr_assert_eq(NotComponent.compute(2), nts::Tristate::Undefined);
}