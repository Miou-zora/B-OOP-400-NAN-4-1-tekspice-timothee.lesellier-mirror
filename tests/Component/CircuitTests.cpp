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

Test(getInput, nullptr)
{
    nts::Circuit circuit;

    try {
        circuit.getInput("test");
        cr_assert_fail("Should have thrown an exception");
    } catch (const std::runtime_error &e) {
        cr_assert_str_eq(e.what(), "Input not found");
    }
}

Test(getOutput, nullptr)
{
    nts::Circuit circuit;

    try {
        circuit.getOutput("test");
        cr_assert_fail("Should have thrown an exception");
    } catch (const std::runtime_error &e) {
        cr_assert_str_eq(e.what(), "Output not found");
    }
}

Test(getComponent, nullptr)
{
    nts::Circuit circuit;

    try {
        circuit.getComponent("test");
        cr_assert_fail("Should have thrown an exception");
    } catch (const std::runtime_error &e) {
        cr_assert_str_eq(e.what(), "Component not found");
    }
}

Test(getComponent, get)
{
    nts::Circuit circuit;
    std::shared_ptr<nts::IComponent> output = std::make_shared<nts::Output>();
    std::shared_ptr<nts::IComponent> input = std::make_shared<nts::Input>();
    std::shared_ptr<nts::IComponent> andComponent = std::make_shared<nts::AndComponent>();

    circuit.addOutput(output, "output");
    circuit.addInput(input, "input");
    circuit.addComponent(andComponent, "andComponent");

    circuit.getComponent("output");
    circuit.getComponent("input");
    circuit.getComponent("andComponent");
}

Test(addInput, two_same)
{
    nts::Circuit circuit;
    std::shared_ptr<nts::IComponent> input = std::make_shared<nts::Input>();

    circuit.addInput(input, "input");

    try {
        circuit.addInput(input, "input");
        cr_assert_fail("Should have thrown an exception");
    } catch (const std::runtime_error &e) {
        cr_assert_str_eq(e.what(), "Input already exists");
    }
}

Test(addOutput, two_same)
{
    nts::Circuit circuit;
    std::shared_ptr<nts::IComponent> output = std::make_shared<nts::Output>();

    circuit.addOutput(output, "output");

    try {
        circuit.addOutput(output, "output");
        cr_assert_fail("Should have thrown an exception");
    } catch (const std::runtime_error &e) {
        cr_assert_str_eq(e.what(), "Output already exists");
    }
}

Test(addComponent, two_same)
{
    nts::Circuit circuit;
    std::shared_ptr<nts::IComponent> output = std::make_shared<nts::Output>();

    circuit.addComponent(output, "output");

    try {
        circuit.addComponent(output, "output");
        cr_assert_fail("Should have thrown an exception");
    } catch (const std::runtime_error &e) {
        cr_assert_str_eq(e.what(), "Component already exists");
    }
}

Test(simulate, simulate)
{
    nts::Circuit circuit;
    std::shared_ptr<nts::Output> output = std::make_shared<nts::Output>();
    std::shared_ptr<nts::Input> input1 = std::make_shared<nts::Input>();
    std::shared_ptr<nts::Input> input2 = std::make_shared<nts::Input>();
    std::shared_ptr<nts::IComponent> andComponent = std::make_shared<nts::AndComponent>();

    input1->setNextState(nts::Tristate::True);
    input2->setNextState(nts::Tristate::True);

    circuit.addOutput(output, "output");
    circuit.addInput(input1, "input1");
    circuit.addInput(input2, "input2");
    circuit.addComponent(andComponent, "andComponent");

    circuit.setLink("input1", 1, "andComponent", 1);
    circuit.setLink("input2", 1, "andComponent", 2);
    circuit.setLink("andComponent", 3, "output", 1);

    cr_assert_eq(output->compute(1), nts::Tristate::Undefined);

    circuit.simulate(1);

    cr_assert_eq(output->compute(1), nts::Tristate::True);
}

Test(setLink, casual)
{
    nts::Circuit circuit;
    std::shared_ptr<nts::Output> output = std::make_shared<nts::Output>();

    circuit.setLink(1, output, 1);
}

Test(display, casual)
{
    nts::Circuit circuit;
    std::shared_ptr<nts::Output> output = std::make_shared<nts::Output>();
    std::shared_ptr<nts::Input> input1 = std::make_shared<nts::Input>();
    std::shared_ptr<nts::Input> input2 = std::make_shared<nts::Input>();
    std::shared_ptr<nts::IComponent> andComponent = std::make_shared<nts::AndComponent>();

    input1->setNextState(nts::Tristate::True);
    input2->setNextState(nts::Tristate::True);

    circuit.addOutput(output, "output");
    circuit.addInput(input1, "input1");
    circuit.addInput(input2, "input2");
    circuit.addComponent(andComponent, "andComponent");

    circuit.setLink("input1", 1, "andComponent", 1);
    circuit.setLink("input2", 1, "andComponent", 2);
    circuit.setLink("andComponent", 3, "output", 1);

    circuit.simulate(3);

    cr_redirect_stdout();

    circuit.display();

    cr_assert_stdout_eq_str("tick: 3\n"
                            "input(s):\n"
                            " input1: 1\n"
                            " input2: 1\n"
                            "output(s):\n"
                            " output: 1\n");
}

Test(setLink, name1_not_exist)
{
    nts::Circuit circuit;

    try {
        circuit.setLink("test", 1, "test", 1);
        cr_assert_fail("Should have thrown an exception");
    } catch (const std::runtime_error &e) {
        cr_assert_str_eq(e.what(), "Component not found");
    }
}

Test(setLink, name2_not_exist)
{
    nts::Circuit circuit;
    std::shared_ptr<nts::IComponent> input = std::make_shared<nts::Input>();

    circuit.addInput(input, "input");

    try {
        circuit.setLink("input", 1, "test", 1);
        cr_assert_fail("Should have thrown an exception");
    } catch (const std::runtime_error &e) {
        cr_assert_str_eq(e.what(), "Component not found");
    }
}

Test(compute, not_exist)
{
    nts::Circuit circuit;

    cr_assert_eq(circuit.compute(1), nts::Tristate::Undefined);
}