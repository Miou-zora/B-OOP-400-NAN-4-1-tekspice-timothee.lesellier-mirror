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

Test(shell, loop)
{
    Shell shell;
    cr_assert_eq(shell.executeCommand("loop"), true);
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