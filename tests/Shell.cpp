/*
** EPITECH PROJECT, 2023
** B-OOP-400-NAN-4-1-tekspice-timothee.lesellier-mirror
** File description:
** Shell
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#define private public
#include "NTS.hpp"
#undef private
#include <iostream>
#include <sstream>

bool ctrlC = false;

Test(Shell, Shell)
{
    Shell shell;
    cr_assert_eq(shell._exit, false);
    cr_assert_eq(shell._command, "");
}

Test(shell, unvalidCommand)
{
    Shell shell;
    cr_assert_eq(shell.executeCommand("unvalidCommand"), false);
}

Test(shell, exit)
{
    Shell shell;
    cr_assert_eq(shell.executeCommand("exit"), true);
    cr_assert_eq(shell._exit, true);
}

Test(shell, display)
{
    Shell shell;
    cr_assert_eq(shell.executeCommand("display"), true);
}

Test(shell, simulate)
{
    Shell shell;
    cr_assert_eq(shell.executeCommand("simulate"), true);
}

Test(shell, getCommandName)
{
    Shell shell;
    cr_assert_eq(shell.getCommandName("simulate  "), "simulate");
    cr_assert_eq(shell.getCommandName("loop  "), "loop");
    cr_assert_eq(shell.getCommandName("display "), "display");
    cr_assert_eq(shell.getCommandName("exit  "), "exit");
    cr_assert_eq(shell.getCommandName("unvalidCommand  "), "unvalidCommand");
}

Test(shell, exit_command, .init = cr_redirect_stdout)
{
    Shell shell;

    std::stringstream input("exit\n");
    std::cin.rdbuf(input.rdbuf());

    cr_assert_eq(shell._exit, false);
    shell.run();
    cr_assert_eq(shell._exit, true);
    cr_assert_stdout_eq_str("> ");
}

Test(shell, invalid_command)
{
    Shell shell;

    std::stringstream input("unvalidCommand\nexit\n");
    std::cin.rdbuf(input.rdbuf());

    cr_redirect_stdout();
    cr_assert_eq(shell._exit, false);
    shell.run();
    cr_assert_eq(shell._exit, true);
    cr_assert_stdout_eq_str("> Invalid command\n"
                            "> ");
}

Test(shell, no_command)
{
    Shell shell;

    std::stringstream input("");
    std::cin.rdbuf(input.rdbuf());

    cr_redirect_stdout();
    cr_assert_eq(shell._exit, false);
    shell.run();
    cr_assert_eq(shell._exit, true);
    cr_assert_stdout_eq_str("> ");
}

Test(isValueAttriution, casual)
{
    Shell shell;

    cr_assert_eq(shell.isValueAttriution("a=1"), true);
    cr_assert_eq(shell.isValueAttriution("a0    &é ze"), false);
}

Test(split, casual)
{
    Shell shell;

    std::vector<std::string> result = shell.split("a=1", "=");
    cr_assert_eq(result.size(), 2);
    cr_assert_eq(result[0], "a");
    cr_assert_eq(result[1], "1");
}

Test(excecuteValueAttriution, casual)
{
    nts::Builder builder("tests/BuilderTestsFolder/test7");
    Shell shell;
    shell._circuit.reset(builder.BuildCircuit().get());

    cr_assert_eq(shell.excecuteValueAttriution("inputB=1"), true);
    std::cout << "yes" << std::endl;
}