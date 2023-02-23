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
#include <memory>

Test(AndComponent, invalid_pin)
{
    nts::AndComponent andComponent;

    try {
        andComponent.compute(1);
        cr_assert_fail("Should have thrown an exception");
    } catch (const std::invalid_argument &e) {
        cr_assert_str_eq(e.what(), "Pin out of range");
    }
}

Test(AndComponent, casual_undefined)
{
    nts::AndComponent andComponent;
    std::shared_ptr<nts::Input> input1 = std::make_shared<nts::Input>();
    std::shared_ptr<nts::Input> input2 = std::make_shared<nts::Input>();

    cr_assert_eq(andComponent.compute(3), nts::Tristate::Undefined);
    andComponent.setLink(1, input1, 1);
    andComponent.setLink(2, input2, 1);
    input1->setCurrentState(nts::Tristate::True);
    cr_assert_eq(andComponent.compute(3), nts::Tristate::Undefined);
    input2->setCurrentState(nts::Tristate::True);
    input1->setCurrentState(nts::Tristate::Undefined);
    std::cout << input1->getCurrentState() << std::endl;
    std::cout << input2->getCurrentState() << std::endl;
    std::cout << input1->compute(1) << std::endl;
    std::cout << input2->compute(1) << std::endl;
    std::cout << input1.get() << std::endl;
    std::cout << input2.get() << std::endl;
    std::cout << andComponent._links[1]->getComponent().get() << std::endl;
    std::cout << andComponent._links[2]->getComponent().get() << std::endl;
    cr_assert_eq(andComponent.compute(3), nts::Tristate::Undefined);
}

Test(AndComponent, casual_true)
{
    nts::AndComponent andComponent;
    std::shared_ptr<nts::Input> input1 = std::make_shared<nts::Input>();
    std::shared_ptr<nts::Input> input2 = std::make_shared<nts::Input>();

    andComponent.setLink(1, input1, 1);
    andComponent.setLink(2, input2, 1);
    input1->setCurrentState(nts::Tristate::True);
    input2->setCurrentState(nts::Tristate::True);
    cr_assert_eq(andComponent.compute(3), nts::Tristate::True);
}

Test(AndComponent, casual_false)
{
    nts::AndComponent andComponent;
    std::shared_ptr<nts::Input> input1 = std::make_shared<nts::Input>();
    std::shared_ptr<nts::Input> input2 = std::make_shared<nts::Input>();

    andComponent.setLink(1, input1, 1);
    andComponent.setLink(2, input2, 1);
    printf("|%p|", andComponent._links[1].get());
    fflush(stdout);
    input1->setCurrentState(nts::Tristate::True);
    input2->setCurrentState(nts::Tristate::False);
    cr_assert_eq(andComponent.compute(3), nts::Tristate::False);
    input1->setCurrentState(nts::Tristate::False);
    input2->setCurrentState(nts::Tristate::True);
    cr_assert_eq(andComponent.compute(3), nts::Tristate::False);
    input1->setCurrentState(nts::Tristate::False);
    input2->setCurrentState(nts::Tristate::False);
    cr_assert_eq(andComponent.compute(3), nts::Tristate::False);
}