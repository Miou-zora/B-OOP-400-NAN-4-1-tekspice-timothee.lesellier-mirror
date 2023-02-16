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

Test(isValidLink, casual)
{
    nts::Builder builder("tests/BuilderTestsFolder/test1");
    cr_assert_eq(builder.isValidLink("a:1 b:2"), true);
}

Test(isValidLink, noSpace)
{
    nts::Builder builder("tests/BuilderTestsFolder/test1");
    cr_assert_eq(builder.isValidLink("a:1b:2"), false);
}

Test(isValidLink, tooMuchSpace)
{
    nts::Builder builder("tests/BuilderTestsFolder/test1");
    cr_assert_eq(builder.isValidLink("a:1  b:2  "), true);
}

Test(isValidLink, noColon)
{
    nts::Builder builder("tests/BuilderTestsFolder/test1");
    cr_assert_eq(builder.isValidLink("a1 b2"), false);
}

Test(isValidLink, noPin)
{
    nts::Builder builder("tests/BuilderTestsFolder/test1");
    cr_assert_eq(builder.isValidLink("a: b:2"), false);
}

Test(isValidLink, noName)
{
    nts::Builder builder("tests/BuilderTestsFolder/test1");
    cr_assert_eq(builder.isValidLink(":1 n:b"), false);
}

Test(isValidLink, noPin2)
{
    nts::Builder builder("tests/BuilderTestsFolder/test1");
    cr_assert_eq(builder.isValidLink("a:1 b:"), false);
}

Test(isValidLink, noName2)
{
    nts::Builder builder("tests/BuilderTestsFolder/test1");
    cr_assert_eq(builder.isValidLink("a:1 2"), false);
}

Test(buildComponents, casual)
{
    nts::Builder builder("tests/BuilderTestsFolder/test2");
    std::list<std::string> fileContent = builder.getFileContent("tests/BuilderTestsFolder/test2");
    std::unique_ptr<std::map<std::string, std::unique_ptr<nts::IComponent>>> components = builder.buildComponents(fileContent);

    cr_assert_eq(components->size(), 1);

    std::map<std::string, std::unique_ptr<nts::IComponent>>::iterator it = components->begin();
    cr_assert_str_eq(it->first.c_str(), "hello");
}

Test(buildComponents, invalidLine)
{
    nts::Builder builder("tests/BuilderTestsFolder/test3");
    std::list<std::string> fileContent = builder.getFileContent("tests/BuilderTestsFolder/test3");
    fileContent.push_back("invalid line");
    try {
        std::unique_ptr<std::map<std::string, std::unique_ptr<nts::IComponent>>> components = builder.buildComponents(fileContent);
        cr_assert_fail();
    } catch (std::runtime_error &e) {
        cr_assert_str_eq(e.what(), "Component doesn't exist");
    }
}

Test(buildComponents, invalidComponent)
{
    nts::Builder builder("tests/BuilderTestsFolder/test4");
    std::list<std::string> fileContent = builder.getFileContent("tests/BuilderTestsFolder/test4");
    fileContent.push_back("invalidComponent hello");
    try {
        std::unique_ptr<std::map<std::string, std::unique_ptr<nts::IComponent>>> components = builder.buildComponents(fileContent);
        cr_assert_fail();
    } catch (nts::FileError &e) {
        cr_assert_str_eq(e.what(), "Invalid line");
        cr_assert_str_eq(e.GetComponent().c_str(), "and this doesn't works");
    }
}

Test(buildComponents, noLinks)
{
    nts::Builder builder("tests/BuilderTestsFolder/test5");
    std::list<std::string> fileContent = builder.getFileContent("tests/BuilderTestsFolder/test5");
    try {
        std::unique_ptr<std::map<std::string, std::unique_ptr<nts::IComponent>>> components = builder.buildComponents(fileContent);
        cr_assert_fail();
    } catch (std::runtime_error &e) {
        cr_assert_str_eq(e.what(), "No links found");
    }
}