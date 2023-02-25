/*
** EPITECH PROJECT, 2023
** B-OOP-400-NAN-4-1-tekspice-timothee.lesellier-mirror
** File description:
** Component4081
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#define private public
#define protected public
#include "NTS.hpp"
#undef private
#undef protected
#include <memory>
#include <map>


Test(Component4069, InvalidSetlink)
{
    nts::Component4069 Component4069;
    std::shared_ptr<nts::Input> input1 = std::make_shared<nts::Input>();
    std::shared_ptr<nts::Input> input2 = std::make_shared<nts::Input>();
    try {
        Component4069.setLink(7, input1, 1);
        cr_assert_fail("Should have thrown an exception");
    } catch (const std::invalid_argument &e) {
        cr_assert_str_eq(e.what(), "Pin out of range");
    }
}


Test(Component4069, invalid_pin)
{
    nts::Component4069 Component4069;

    try {
        Component4069.compute(1);
        cr_assert_fail("Should have thrown an exception");
    } catch (const std::invalid_argument &e) {
        cr_assert_str_eq(e.what(), "Pin out of range");
    }
    try {
        Component4069.compute(7);
        cr_assert_fail("Should have thrown an exception");
    } catch (const std::invalid_argument &e) {
        cr_assert_str_eq(e.what(), "Pin out of range");
    }
    try {
        Component4069.compute(14);
        cr_assert_fail("Should have thrown an exception");
    } catch (const std::invalid_argument &e) {
        cr_assert_str_eq(e.what(), "Pin out of range");
    }
}

Test(Component4069, casual_undefined)
{
    nts::Component4069 Component4069;
    std::shared_ptr<nts::Input> input = std::make_shared<nts::Input>();
    std::vector<std::size_t> outputs = {2, 4, 6, 8, 10, 12};
    std::map<std::size_t, std::size_t> inputs = {{2, 1}, {4, 3}, {6, 5}, {8, 9}, {10, 11}, {12, 13}};

    for (auto &pin: outputs) {
        cr_assert_eq(Component4069.compute(pin), nts::Tristate::Undefined);
        Component4069.setLink(inputs.at(pin), input, 1);
        input->setCurrentState(nts::Tristate::True);
        cr_assert_eq(Component4069.compute(pin), nts::Tristate::False);
        input->setCurrentState(nts::Tristate::False);
        cr_assert_eq(Component4069.compute(pin), nts::Tristate::True);
        input->setCurrentState(nts::Tristate::Undefined);
        cr_assert_eq(Component4069.compute(pin), nts::Tristate::Undefined);
    }
}
