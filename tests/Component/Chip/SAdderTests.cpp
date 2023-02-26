/*
** EPITECH PROJECT, 2023
** B-OOP-400-NAN-4-1-tekspice-timothee.lesellier-mirror
** File description:
** SAdderTests
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

Test(SAdder, InvalidSetlink)
{
    nts::SAdder SAdder;
    std::shared_ptr<nts::Input> input1 = std::make_shared<nts::Input>();
    std::shared_ptr<nts::Input> input2 = std::make_shared<nts::Input>();
    try {
        SAdder.setLink(7, input1, 1);
        cr_assert_fail("Should have thrown an exception");
    } catch (const std::invalid_argument &e) {
        cr_assert_str_eq(e.what(), "Pin out of range");
    }
}

Test(SAdder, casual_undefined)
{
    nts::SAdder SAdder;
    std::shared_ptr<nts::Input> input1 = std::make_shared<nts::Input>();
    std::shared_ptr<nts::Input> input2 = std::make_shared<nts::Input>();
    std::shared_ptr<nts::Input> input3 = std::make_shared<nts::Input>();
    std::vector<std::size_t> outputs = {5, 4};
    std::map<std::size_t, nts::Tristate> expected = {
        {5, nts::Tristate::Undefined},
        {4, nts::Tristate::Undefined}
    };

    SAdder.setLink(1, input1, 1);
    SAdder.setLink(2, input2, 1);
    SAdder.setLink(3, input3, 1);
    for (auto &output : outputs) {
        cr_assert_eq(SAdder.compute(output), expected[output]);
    }
}

Test(SAdder, illegalCompute)
{
    nts::SAdder SAdder;
    std::shared_ptr<nts::Input> input1 = std::make_shared<nts::Input>();
    std::shared_ptr<nts::Input> input2 = std::make_shared<nts::Input>();
    std::shared_ptr<nts::Input> input3 = std::make_shared<nts::Input>();
    SAdder.setLink(1, input1, 1);
    SAdder.setLink(2, input2, 1);
    SAdder.setLink(3, input3, 1);
    try {
        SAdder.compute(6);
        cr_assert_fail("Should have thrown an exception");
    } catch (const std::invalid_argument &e) {
        cr_assert_str_eq(e.what(), "Pin out of range");
    }
}

Test(SAdder, nolinks)
{
    nts::SAdder SAdder;
    std::vector<std::size_t> outputs = {5, 4};
    std::map<std::size_t, nts::Tristate> expected = {
        {5, nts::Tristate::Undefined},
        {4, nts::Tristate::Undefined}
    };

    for (auto &output : outputs) {
        cr_assert_eq(SAdder.compute(output), expected[output]);
    }
}

Test(SAdder, truthTable)
{
    nts::SAdder SAdder;
    std::shared_ptr<nts::Input> input1 = std::make_shared<nts::Input>();
    std::shared_ptr<nts::Input> input2 = std::make_shared<nts::Input>();
    std::shared_ptr<nts::Input> input3 = std::make_shared<nts::Input>();
    SAdder.setLink(1, input1, 1);
    SAdder.setLink(2, input2, 1);
    SAdder.setLink(3, input3, 1);
    input1->setCurrentState(nts::Tristate::False);
    input2->setCurrentState(nts::Tristate::False);
    input3->setCurrentState(nts::Tristate::False);

    cr_assert_eq(SAdder.compute(nts::SAdder::SUM_OUT), nts::Tristate::False);
    cr_assert_eq(SAdder.compute(nts::SAdder::CARRY_OUT), nts::Tristate::False);

    input3->setCurrentState(nts::Tristate::True);
    cr_assert_eq(SAdder.compute(nts::SAdder::SUM_OUT), nts::Tristate::True);
    cr_assert_eq(SAdder.compute(nts::SAdder::CARRY_OUT), nts::Tristate::False);

    input2->setCurrentState(nts::Tristate::True);
    input3->setCurrentState(nts::Tristate::False);

    cr_assert_eq(SAdder.compute(nts::SAdder::SUM_OUT), nts::Tristate::True);
    cr_assert_eq(SAdder.compute(nts::SAdder::CARRY_OUT), nts::Tristate::False);

    input3->setCurrentState(nts::Tristate::True);

    cr_assert_eq(SAdder.compute(nts::SAdder::SUM_OUT), nts::Tristate::False);
    cr_assert_eq(SAdder.compute(nts::SAdder::CARRY_OUT), nts::Tristate::True);

    input1->setCurrentState(nts::Tristate::True);
    input2->setCurrentState(nts::Tristate::False);
    input3->setCurrentState(nts::Tristate::False);

    cr_assert_eq(SAdder.compute(nts::SAdder::SUM_OUT), nts::Tristate::True);
    cr_assert_eq(SAdder.compute(nts::SAdder::CARRY_OUT), nts::Tristate::False);

    input3->setCurrentState(nts::Tristate::True);

    cr_assert_eq(SAdder.compute(nts::SAdder::SUM_OUT), nts::Tristate::False);
    cr_assert_eq(SAdder.compute(nts::SAdder::CARRY_OUT), nts::Tristate::True);

    input2->setCurrentState(nts::Tristate::True);
    input3->setCurrentState(nts::Tristate::False);

    cr_assert_eq(SAdder.compute(nts::SAdder::SUM_OUT), nts::Tristate::False);
    cr_assert_eq(SAdder.compute(nts::SAdder::CARRY_OUT), nts::Tristate::True);

    input3->setCurrentState(nts::Tristate::True);

    cr_assert_eq(SAdder.compute(nts::SAdder::SUM_OUT), nts::Tristate::True);
    cr_assert_eq(SAdder.compute(nts::SAdder::CARRY_OUT), nts::Tristate::True);
}
