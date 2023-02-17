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
    std::list<std::string> fileContent = builder.getFileContent();
    cr_assert_eq(fileContent.size(), 22);
}

Test(getFileContent, noFile)
{
    nts::Builder builder("No_file");
    try {
        std::list<std::string> fileContent = builder.getFileContent();
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
    cr_assert_eq(fileContentWithoutComment.size(), 26);
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
    std::list<std::string> fileContent = builder.getFileContent();
    builder.buildComponents(fileContent);

    cr_assert_eq(builder._circuit._components.size(), 2);
    builder._circuit.getComponent("hello");
    builder._circuit.getComponent("helloo");
    cr_assert_eq(builder._circuit._input.size(), 0);
    cr_assert_eq(builder._circuit._output.size(), 0);
    try {
        builder._circuit.getComponent("hellooo");
        cr_assert_fail();
    } catch (std::runtime_error &e) {
        cr_assert_str_eq(e.what(), "Component not found");
    }
}

Test(buildComponents, invalidLine)
{
    nts::Builder builder("tests/BuilderTestsFolder/test3");
    std::list<std::string> fileContent = builder.getFileContent();
    fileContent.push_back("invalid line");
    try {
        builder.buildComponents(fileContent);
        cr_assert_fail();
    } catch (std::runtime_error &e) {
        cr_assert_str_eq(e.what(), "Component doesn't exist");
    }
}

Test(buildComponents, invalidComponent)
{
    nts::Builder builder("tests/BuilderTestsFolder/test4");
    std::list<std::string> fileContent = builder.getFileContent();
    fileContent.push_back("invalidComponent hello");
    try {
        builder.buildComponents(fileContent);
        cr_assert_fail();
    } catch (nts::FileError &e) {
        cr_assert_str_eq(e.what(), "Invalid line");
        cr_assert_str_eq(e.GetComponent().c_str(), "and this doesn't works");
    }
}

Test(buildComponents, noLinks)
{
    nts::Builder builder("tests/BuilderTestsFolder/test5");
    std::list<std::string> fileContent = builder.getFileContent();
    try {
        builder.buildComponents(fileContent);
        cr_assert_fail();
    } catch (std::runtime_error &e) {
        cr_assert_str_eq(e.what(), "No links found");
    }
}

Test(buildComponents, input)
{
    nts::Builder builder("tests/BuilderTestsFolder/test6");
    std::list<std::string> fileContent = builder.getFileContent();

    builder.buildComponents(fileContent);

    cr_assert_eq(builder._circuit._components.size(), 3);
    cr_assert_eq(builder._circuit._input.size(), 1);
    cr_assert_eq(builder._circuit._output.size(), 1);

    builder._circuit.getComponent("a");
    builder._circuit.getInput("a");
    try {
        builder._circuit.getInput("b");
        cr_assert_fail();
    } catch (std::runtime_error &e) {
        cr_assert_str_eq(e.what(), "Input not found");
    }
    try {
        builder._circuit.getComponent("d");
        cr_assert_fail();
    } catch (std::runtime_error &e) {
        cr_assert_str_eq(e.what(), "Component not found");
    }
}

Test(buildComponents, output)
{
    nts::Builder builder("tests/BuilderTestsFolder/test6");
    std::list<std::string> fileContent = builder.getFileContent();

    builder.buildComponents(fileContent);

    cr_assert_eq(builder._circuit._components.size(), 3);
    cr_assert_eq(builder._circuit._input.size(), 1);
    cr_assert_eq(builder._circuit._output.size(), 1);

    builder._circuit.getComponent("b");
    builder._circuit.getOutput("b");
    try {
        builder._circuit.getOutput("c");
        cr_assert_fail();
    } catch (std::runtime_error &e) {
        cr_assert_str_eq(e.what(), "Output not found");
    }
    try {
        builder._circuit.getComponent("d");
        cr_assert_fail();
    } catch (std::runtime_error &e) {
        cr_assert_str_eq(e.what(), "Component not found");
    }
}

Test(buildLinks, no_links)
{
    nts::Builder builder("tests/BuilderTestsFolder/test6");
    std::list<std::string> fileContent = builder.getFileContent();
    try {
        builder.buildLinks(fileContent);
        cr_assert_fail();
    } catch (nts::FileError &e) {
        cr_assert_str_eq(e.what(), "No links found");
    }
}

Test(getLinkFirstName, casual)
{
    nts::Builder builder("tests/BuilderTestsFolder/test6");
    std::string link = "ab:12 ba:21";
    cr_assert_str_eq(builder.getLinkFirstName(link).c_str(), "ab");
}

Test(getLinkSecondName, casual)
{
    nts::Builder builder("tests/BuilderTestsFolder/test6");
    std::string link = "ab:12 ba:21";
    cr_assert_str_eq(builder.getLinkSecondName(link).c_str(), "ba");
}

Test(getLinkFirstPin, casual)
{
    nts::Builder builder("tests/BuilderTestsFolder/test6");
    std::string link = "ab:12 ba:21";
    cr_assert_eq(builder.getLinkFirstPin(link), 12);
}

Test(getLinkSecondPin, casual)
{
    nts::Builder builder("tests/BuilderTestsFolder/test6");
    std::string link = "ab:12 ba:21";
    cr_assert_eq(builder.getLinkSecondPin(link), 21);
}

Test(buildLinks, casual)
{
    nts::Builder builder("tests/BuilderTestsFolder/test7");
    std::list<std::string> fileContent = builder.getFileContent();
    builder.buildComponents(fileContent);
    builder.buildLinks(fileContent);
}

Test(buildLinks, invalidLink)
{
    nts::Builder builder("tests/BuilderTestsFolder/test4");
    std::list<std::string> fileContent = builder.getFileContent();
    try {
        builder.buildLinks(fileContent);
        cr_assert_fail();
    } catch (nts::FileError &e) {
        cr_assert_str_eq(e.what(), "Invalid link");
    }
}