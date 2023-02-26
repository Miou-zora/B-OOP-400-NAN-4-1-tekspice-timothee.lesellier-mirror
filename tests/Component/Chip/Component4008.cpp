/*
** EPITECH PROJECT, 2023
** B-OOP-400-NAN-4-1-tekspice-timothee.lesellier-mirror
** File description:
** Component4008
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

Test(Component4008, InvalidSetlink)
{
    nts::Component4008 Component4008;
    std::shared_ptr<nts::Input> input1 = std::make_shared<nts::Input>();
    std::shared_ptr<nts::Input> input2 = std::make_shared<nts::Input>();
    try {
        Component4008.setLink(8, input1, 1);
        cr_assert_fail("Should have thrown an exception");
    } catch (const std::invalid_argument &e) {
        cr_assert_str_eq(e.what(), "Pin out of range");
    }
}


Test(Component4008, invalid_pin)
{
    nts::Component4008 Component4008;

    try {
        Component4008.compute(1);
        cr_assert_fail("Should have thrown an exception");
    } catch (const std::invalid_argument &e) {
        cr_assert_str_eq(e.what(), "Pin out of range");
    }
    try {
        Component4008.compute(7);
        cr_assert_fail("Should have thrown an exception");
    } catch (const std::invalid_argument &e) {
        cr_assert_str_eq(e.what(), "Pin out of range");
    }
    try {
        Component4008.compute(15);
        cr_assert_fail("Should have thrown an exception");
    } catch (const std::invalid_argument &e) {
        cr_assert_str_eq(e.what(), "Pin out of range");
    }
}

Test(Component4008, no_links)
{
    nts::Component4008 Component4008;
    std::vector<std::size_t> pins = {10, 11, 12, 13, 14};

    for (auto pin : pins) {
        cr_assert_eq(Component4008.compute(pin), nts::Tristate::Undefined);
    }
}

Test(Component4008, casual_undefined)
{
    nts::Component4008 Component4008;
    std::shared_ptr input1 = std::make_shared<nts::Input>();
    std::shared_ptr input2 = std::make_shared<nts::Input>();
    std::shared_ptr input3 = std::make_shared<nts::Input>();
    std::shared_ptr input4 = std::make_shared<nts::Input>();
    std::shared_ptr input5 = std::make_shared<nts::Input>();
    std::shared_ptr input6 = std::make_shared<nts::Input>();
    std::shared_ptr input7 = std::make_shared<nts::Input>();
    std::shared_ptr input9 = std::make_shared<nts::Input>();
    std::shared_ptr input15 = std::make_shared<nts::Input>();
    std::vector<std::size_t> pins = {10, 11, 12, 13, 14};

    Component4008.setLink(1, input1, 1);
    Component4008.setLink(2, input2, 1);
    Component4008.setLink(3, input3, 1);
    Component4008.setLink(4, input4, 1);
    Component4008.setLink(5, input5, 1);
    Component4008.setLink(6, input6, 1);
    Component4008.setLink(7, input7, 1);
    Component4008.setLink(9, input9, 1);
    Component4008.setLink(15, input15, 1);

    for (auto pin : pins) {
        cr_assert_eq(Component4008.compute(pin), nts::Tristate::Undefined);
    }
}

Test(Component4008, casual_true)
{
    nts::Component4008 Component4008;
    std::shared_ptr input1 = std::make_shared<nts::Input>();
    std::shared_ptr input2 = std::make_shared<nts::Input>();
    std::shared_ptr input3 = std::make_shared<nts::Input>();
    std::shared_ptr input4 = std::make_shared<nts::Input>();
    std::shared_ptr input5 = std::make_shared<nts::Input>();
    std::shared_ptr input6 = std::make_shared<nts::Input>();
    std::shared_ptr input7 = std::make_shared<nts::Input>();
    std::shared_ptr carry_in = std::make_shared<nts::Input>();
    std::shared_ptr input15 = std::make_shared<nts::Input>();

    std::vector<std::size_t> pins = {10, 11, 12, 13, 14};

    input1->setCurrentState(nts::Tristate::True);
    input15->setCurrentState(nts::Tristate::True);
    input2->setCurrentState(nts::Tristate::True);
    input3->setCurrentState(nts::Tristate::True);

    input4->setCurrentState(nts::Tristate::True);
    input5->setCurrentState(nts::Tristate::True);
    input6->setCurrentState(nts::Tristate::True);
    input7->setCurrentState(nts::Tristate::True);

    carry_in->setCurrentState(nts::Tristate::False);

    Component4008.setLink(15, input15, 1);
    Component4008.setLink(1, input1, 1);
    Component4008.setLink(2, input2, 1);
    Component4008.setLink(3, input3, 1);

    Component4008.setLink(4, input4, 1);
    Component4008.setLink(5, input5, 1);
    Component4008.setLink(6, input6, 1);
    Component4008.setLink(7, input7, 1);

    Component4008.setLink(9, carry_in, 1);

    for (size_t i = 0; i < 4; i++) {
        std::cout << Component4008._components[i]->compute(5) << Component4008._components[i]->compute(4) <<std::endl;
    }

    cr_assert_eq(Component4008.compute(10), nts::Tristate::False);
    cr_assert_eq(Component4008.compute(11), nts::Tristate::True);
    cr_assert_eq(Component4008.compute(12), nts::Tristate::True);

    cr_assert_eq(Component4008.compute(13), nts::Tristate::True);
    cr_assert_eq(Component4008.compute(14), nts::Tristate::True);
}