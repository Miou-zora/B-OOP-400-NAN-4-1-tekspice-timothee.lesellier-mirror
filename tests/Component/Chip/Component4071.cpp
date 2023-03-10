/*
** EPITECH PROJECT, 2023
** B-OOP-400-NAN-4-1-tekspice-timothee.lesellier-mirror
** File description:
** Component4071
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


Test(Component4071, InvalidSetlink)
{
    nts::Component4071 Component4071;
    std::shared_ptr<nts::Input> input1 = std::make_shared<nts::Input>();
    std::shared_ptr<nts::Input> input2 = std::make_shared<nts::Input>();
    try {
        Component4071.setLink(7, input1, 1);
        cr_assert_fail("Should have thrown an exception");
    } catch (const std::invalid_argument &e) {
        cr_assert_str_eq(e.what(), "Pin out of range");
    }
}


Test(Component4071, invalid_pin)
{
    nts::Component4071 Component4071;

    try {
        Component4071.compute(1);
        cr_assert_fail("Should have thrown an exception");
    } catch (const std::invalid_argument &e) {
        cr_assert_str_eq(e.what(), "Pin out of range");
    }
    try {
        Component4071.compute(7);
        cr_assert_fail("Should have thrown an exception");
    } catch (const std::invalid_argument &e) {
        cr_assert_str_eq(e.what(), "Pin out of range");
    }
    try {
        Component4071.compute(14);
        cr_assert_fail("Should have thrown an exception");
    } catch (const std::invalid_argument &e) {
        cr_assert_str_eq(e.what(), "Pin out of range");
    }
}

Test(Component4071, casual_undefined)
{
    nts::Component4071 Component4071;
    std::shared_ptr<nts::Input> input1 = std::make_shared<nts::Input>();
    std::shared_ptr<nts::Input> input2 = std::make_shared<nts::Input>();
    std::vector<std::size_t> outputs = {3, 4, 10, 11};
    std::map<std::size_t, std::vector<size_t>> inputs = {{3, {1, 2}}, {4, {5, 6}}, {11, {12, 13}}, {10, {8, 9}}};

    for (auto &pin: outputs) {
        input1->setCurrentState(nts::Tristate::Undefined);
        input2->setCurrentState(nts::Tristate::Undefined);
        cr_assert_eq(Component4071.compute(pin), nts::Tristate::Undefined);
        Component4071.setLink(inputs.at(pin).at(0), input1, 1);
        Component4071.setLink(inputs.at(pin).at(1), input2, 1);
        input1->setCurrentState(nts::Tristate::True);
        cr_assert_eq(Component4071.compute(pin), nts::Tristate::True);
        input2->setCurrentState(nts::Tristate::Undefined);
        input1->setCurrentState(nts::Tristate::Undefined);
        cr_assert_eq(Component4071.compute(pin), nts::Tristate::Undefined);
    }
}

Test(Component4071, casual_true)
{
    nts::Component4071 Component4071;
    std::shared_ptr<nts::Input> input1 = std::make_shared<nts::Input>();
    std::shared_ptr<nts::Input> input2 = std::make_shared<nts::Input>();
    std::vector<std::size_t> outputs = {3, 4, 10, 11};
    std::map<std::size_t, std::vector<size_t>> inputs = {{3, {1, 2}}, {4, {5, 6}}, {11, {12, 13}}, {10, {8, 9}}};

    for (auto &pin: outputs) {
        input1->setCurrentState(nts::Tristate::Undefined);
        input2->setCurrentState(nts::Tristate::Undefined);
        cr_assert_eq(Component4071.compute(pin), nts::Tristate::Undefined);
        Component4071.setLink(inputs.at(pin).at(0), input1, 1);
        Component4071.setLink(inputs.at(pin).at(1), input2, 1);
        input1->setCurrentState(nts::Tristate::True);
        cr_assert_eq(Component4071.compute(pin), nts::Tristate::True);
        input2->setCurrentState(nts::Tristate::True);
        input1->setCurrentState(nts::Tristate::True);
        cr_assert_eq(Component4071.compute(pin), nts::Tristate::True);
    }
}

Test(Component4071, no_links)
{
    nts::Component4071 Component4071;
    std::vector<std::size_t> outputs = {3, 4, 10, 11};

    for (auto &pin: outputs) {
        cr_assert_eq(Component4071.compute(pin), nts::Tristate::Undefined);
    }
}

Test(Component4071, casual_false)
{
    nts::Component4071 Component4071;
    std::shared_ptr<nts::Input> input1 = std::make_shared<nts::Input>();
    std::shared_ptr<nts::Input> input2 = std::make_shared<nts::Input>();
    std::vector<std::size_t> outputs = {3, 4, 10, 11};
    std::map<std::size_t, std::vector<size_t>> inputs = {{3, {1, 2}}, {4, {5, 6}}, {11, {12, 13}}, {10, {8, 9}}};

    for (auto &pin: outputs) {
        input1->setCurrentState(nts::Tristate::Undefined);
        input2->setCurrentState(nts::Tristate::Undefined);
        cr_assert_eq(Component4071.compute(pin), nts::Tristate::Undefined);
        Component4071.setLink(inputs.at(pin).at(0), input1, 1);
        Component4071.setLink(inputs.at(pin).at(1), input2, 1);
        input1->setCurrentState(nts::Tristate::False);
        input2->setCurrentState(nts::Tristate::False);
        cr_assert_eq(Component4071.compute(pin), nts::Tristate::False);
        input2->setCurrentState(nts::Tristate::False);
        input1->setCurrentState(nts::Tristate::Undefined);
        cr_assert_eq(Component4071.compute(pin), nts::Tristate::Undefined);
    }
}
