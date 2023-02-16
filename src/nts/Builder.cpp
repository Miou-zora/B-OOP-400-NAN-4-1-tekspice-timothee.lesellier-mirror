/*
** EPITECH PROJECT, 2023
** B-OOP-400-NAN-4-1-tekspice-timothee.lesellier-mirror
** File description:
** Builder
*/

#include "Builder.hpp"
#include "Circuit.hpp"
#include <cstring>
#include <algorithm>
#include "Component/Component.hpp"

nts::Builder::Builder(std::string filepath)
{
    _filepath = filepath;
    this->initFactory();
}

nts::Builder::~Builder(void)
{
}

std::unique_ptr<Circuit> nts::Builder::BuildCircuit(void)
{
    Circuit circuit();
    std::list<std::string> fileContent = this->getFileContent(_filepath);
}

void nts::Builder::initFactory(void)
{
    _factory.addConstructor("and", []() { return std::make_unique<nts::AndComponent>(); });
}

std::list<std::string> nts::Builder::getFileContent(std::string filepath)
{
    std::ifstream myfile(filepath);
    std::string myText;

    if (!myfile.is_open())
        throw nts::FileError("File not found");
    while (getline (myfile, myText)) {
        _fileContent.push_back(myText);
    }
    myfile.close();
    return (_fileContent);
}

bool nts::Builder::isValidChipset(std::string line)
{
    std::string lineWithOutComment(this->clearComment(line));
    char separator = ' ';
    size_t nbrOfWord = 0;
    std::string s;
    for (char letter : lineWithOutComment) {
        if (letter != separator) {
            s += letter;
        } else if (letter == separator && s != "") {
            nbrOfWord++;
            s.clear();
        }
    }
    if (s != "")
        nbrOfWord++;
    if (nbrOfWord == 2)
        return (true);
    return (false);
}

bool nts::Builder::isValidLink(std::string line)
{
    std::string lineWithOutComment(this->clearComment(line));
    char separator = ' ';
    size_t nbrOfWord = 0;
    std::string s;
    for (char letter : lineWithOutComment) {
        if (letter != separator) {
            s += letter;
        } else if (letter == separator && s != "") {
            if (s.find(':') == std::string::npos)
                return (false);
            if (s.find(':') == 0 || s.find(':') == s.size() - 1)
                return (false);
            nbrOfWord++;
            s.clear();
        }
    }
    if (s != "") {
        if (s.find(':') == std::string::npos)
            return (false);
        if (s.find(':') == 0 || s.find(':') == s.size() - 1)
            return (false);
    }
    if (s != "")
        nbrOfWord++;
    if (nbrOfWord == 2)
        return (true);
    return (false);
}

std::string nts::Builder::getComponentName(std::string line)
{
    if (this->isValidChipset(line) == false)
        throw nts::FileError("Invalid line", line);
    std::string lineWithOutComment(this->clearComment(line));
    std::reverse(lineWithOutComment.begin(), lineWithOutComment.end());
    lineWithOutComment = lineWithOutComment.substr(0, lineWithOutComment.find(' '));
    std::reverse(lineWithOutComment.begin(), lineWithOutComment.end());
    return (lineWithOutComment);
}

bool nts::Builder::setComponentsLinks(std::string line)
{

}

std::unique_ptr<nts::IComponent> nts::Builder::buildComponent(std::string chip)
{
    try {
        return (this->_factory.create(chip));
    } catch (std::runtime_error &e) {
        throw e;
    }
}

std::unique_ptr<std::map<std::string, std::unique_ptr<nts::IComponent>>> nts::Builder::buildComponents(std::list<std::string> fileContent)
{
    std::unique_ptr<std::map<std::string, std::unique_ptr<nts::IComponent>>> components = std::make_unique<std::map<std::string, std::unique_ptr<nts::IComponent>>>();
    for (std::string line : fileContent) {
        line = this->clearComment(line);
        if (this->isValidChipset(line) == true) {
            std::string name = this->getComponentName(line);
            std::string type = this->getComponentType(line);
            try {
                std::unique_ptr<nts::IComponent> component = this->buildComponent(type);
                (*components)[name] = std::move(component);
            } catch (std::runtime_error &e) {
                throw e;
            }
        } else if (line.compare(".links:") == 0) {
            return (components);
        } else if (line.compare(".chipsets:") != 0 && line.compare("") != 0)
            throw nts::FileError("Invalid line", line);
    }
    throw std::runtime_error("No links found");
}

std::string nts::Builder::getComponentType(std::string line)
{
    if (this->isValidChipset(line) == false)
        throw nts::FileError("Invalid line", line);
    std::string lineWithOutComment(this->clearComment(line));
    return (lineWithOutComment.substr(0, lineWithOutComment.find(' ')));
}

std::string nts::Builder::clearComment(std::string line)
{
    return (line.substr(0, line.find('#')));
}
