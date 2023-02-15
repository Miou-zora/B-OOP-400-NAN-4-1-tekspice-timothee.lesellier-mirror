/*
** EPITECH PROJECT, 2023
** B-OOP-400-NAN-4-1-tekspice-timothee.lesellier-mirror
** File description:
** ComponentFactory
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "NTS.hpp"
#include <iostream>

struct TESTCONSTRUCTOR : virtual public nts::AComponent
{
    TESTCONSTRUCTOR()
    {
        std::cout << "TESTCONSTRUCTOR" << std::endl;
    }

    nts::Tristate compute(std::size_t pin = 1) override
    {
        if (pin == 1)
            return nts::Tristate::True;
        else if (pin == 2)
            return nts::Tristate::False;
        else
            return nts::Tristate::Undefined;
    }

    ~TESTCONSTRUCTOR() override = default;
};

Test(ComponentFactory, createComponent, .init = cr_redirect_stdout)
{
    nts::ComponentFactory factory;
    factory.addConstructor("4001", []() { return std::make_unique<TESTCONSTRUCTOR>(); });

    auto component = factory.create("4001");
    cr_assert_stdout_eq_str("TESTCONSTRUCTOR\n");
}

Test(ComponentFactory, createComponentTwice, .init = cr_redirect_stdout)
{
    nts::ComponentFactory factory;
    factory.addConstructor("4001", []() { return std::make_unique<TESTCONSTRUCTOR>(); });

    auto component = factory.create("4001");
    auto component2 = factory.create("4001");
    cr_assert_stdout_eq_str("TESTCONSTRUCTOR\nTESTCONSTRUCTOR\n");
    cr_assert_neq(component, component2);
}

Test(ComponentFactory, addTwiceComponent, .init = cr_redirect_stdout)
{
    nts::ComponentFactory factory;
    try {
        factory.addConstructor("4001", []() { return std::make_unique<TESTCONSTRUCTOR>(); });
        factory.addConstructor("4001", []() { return std::make_unique<TESTCONSTRUCTOR>(); });
    } catch (std::runtime_error &e) {
        cr_assert_str_eq(e.what(), "Component already exists");
    }
}

Test(ComponentFactory, addNullComponent, .init = cr_redirect_stdout)
{
    nts::ComponentFactory factory;
    try {
        factory.addConstructor("4001", nullptr);
    } catch (std::runtime_error &e) {
        cr_assert_str_eq(e.what(), "Creator is null");
    }
}

Test(ComponentFactory, createUnknownComponent, .init = cr_redirect_stdout)
{
    nts::ComponentFactory factory;
    try {
        factory.create("4001");
    } catch (std::runtime_error &e) {
        cr_assert_str_eq(e.what(), "Component doesn't exist");
    }
}