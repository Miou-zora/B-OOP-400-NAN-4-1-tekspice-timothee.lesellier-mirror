/*
** EPITECH PROJECT, 2023
** B-OOP-400-NAN-4-1-tekspice-timothee.lesellier-mirror
** File description:
** CircuitTests
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#define private public
#include "NTS.hpp"
#undef private

Test(Circuit, createCircuit)
{
    nts::Circuit circuit;
}

Test(Circuit, setter_getter)
{
    nts::Circuit circuit;
}

Test(Circuit, addComponent)
{
    nts::Circuit circuit;

    circuit.addComponent(component);
    cr_assert_eq(circuit.getComponents().size(), 1);
}

Test(Circuit, addComponentTwice)
{
    nts::Circuit circuit;
    nts::ComponentFactory factory;
    nts::IComponent *component = factory.createComponent("input", "input");

    circuit.addComponent(component);
    circuit.addComponent(component);
    cr_assert_eq(circuit.getComponents().size(), 1);
}