/*
** EPITECH PROJECT, 2023
** B-OOP-400-NAN-4-1-tekspice-timothee.lesellier-mirror
** File description:
** BuilderTests
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#define private public
#include "NTS.hpp"
#undef private

Test(getFileContent, casual)
{
    nts::Builder builder("tests/BuilderTestsFolder/test1");
    std::list<std::string> fileContent = builder.getFileContent("tests/BuilderTestsFolder/test1");
    cr_assert_eq(fileContent.size(), 22);
}

Test(getFileContent, noFile)
{
    nts::Builder builder("No_file");
    try {
        std::list<std::string> fileContent = builder.getFileContent("No_file");
        cr_assert_fail();
    } catch (nts::FileError &e) {
        cr_assert_str_eq(e.what(), "File not found");
        cr_assert_str_eq(e.GetComponent().c_str(), "unknown");
    }
}

Test(clearComment, casual)
{
    nts::Builder builder("tests/BuilderTestsFolder/test1");
    std::string fileContentWithoutComment = builder.clearComment("Bonsoir a tous et a toutes #commentaire");
    cr_assert_eq(fileContentWithoutComment.size(), 27);
}

Test(clearComment, noComment)
{
    nts::Builder builder("tests/BuilderTestsFolder/test1");
    std::string fileContentWithoutComment = builder.clearComment("Bonsoir a tous et a toutes");
    cr_assert_eq(fileContentWithoutComment.size(), 26);
}

Test(isValidChipset, casual)
{
    nts::Builder builder("tests/BuilderTestsFolder/test1");
    cr_assert_eq(builder.isValidChipset("input     a   "), true);
}

Test(isValidChipset, noSpace)
{
    nts::Builder builder("tests/BuilderTestsFolder/test1");
    cr_assert_eq(builder.isValidChipset("inputa   "), false);
}

Test(isValidChipset, tooMuchSpace)
{
    nts::Builder builder("tests/BuilderTestsFolder/test1");
    cr_assert_eq(builder.isValidChipset("input  a   a  "), false);
}

Test(getComponentName, casual)
{
    nts::Builder builder("tests/BuilderTestsFolder/test1");
    cr_assert_str_eq(builder.getComponentName("input a").c_str(), "a");
}

Test(getComponentName, noSpace)
{
    nts::Builder builder("tests/BuilderTestsFolder/test1");
    try {
        std::string componentName = builder.getComponentName("inputa");
        cr_assert_fail();
    } catch (nts::FileError &e) {
        cr_assert_str_eq(e.what(), "Invalid line");
        cr_assert_str_eq(e.GetComponent().c_str(), "inputa");
    }
}

Test(getComponentName, tooMuchSpace)
{
    nts::Builder builder("tests/BuilderTestsFolder/test1");
    try {
        std::string componentName = builder.getComponentName("input  a   a  ");
        cr_assert_fail();
    } catch (nts::FileError &e) {
        cr_assert_str_eq(e.what(), "Invalid line");
        cr_assert_str_eq(e.GetComponent().c_str(), "input  a   a  ");
    }
}

Test(getComponentType, casual)
{
    nts::Builder builder("tests/BuilderTestsFolder/test1");
    cr_assert_str_eq(builder.getComponentType("input a").c_str(), "input");
}

Test(getComponentType, noSpace)
{
    nts::Builder builder("tests/BuilderTestsFolder/test1");
    try {
        std::string componentType = builder.getComponentType("inputa");
        cr_assert_fail();
    } catch (nts::FileError &e) {
        cr_assert_str_eq(e.what(), "Invalid line");
        cr_assert_str_eq(e.GetComponent().c_str(), "inputa");
    }
}

Test(buildComponent, casual)
{
    nts::Builder builder("tests/BuilderTestsFolder/test1");
    std::unique_ptr<nts::IComponent> component = builder.buildComponent("and");
}

Test(buildComponent, no_existing_component)
{
    nts::Builder builder("tests/BuilderTestsFolder/test1");
    try {
        std::unique_ptr<nts::IComponent> component = builder.buildComponent("no_existing_component");
        cr_assert_fail();
    } catch (std::runtime_error &e) {
        cr_assert_str_eq(e.what(), "Component doesn't exist");
    }
}