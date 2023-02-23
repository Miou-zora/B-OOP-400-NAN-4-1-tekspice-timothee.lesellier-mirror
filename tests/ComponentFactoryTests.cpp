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

Test(ComponentFactory, createUnknownComponent, .init = cr_redirect_stdout)
{
    nts::ComponentFactory factory;
    try {
        factory.create("4001");
    } catch (std::runtime_error &e) {
        cr_assert_str_eq(e.what(), "Component doesn't exist");
    }
}