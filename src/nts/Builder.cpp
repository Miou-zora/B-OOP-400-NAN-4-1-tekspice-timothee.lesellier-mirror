/*
** EPITECH PROJECT, 2023
** B-OOP-400-NAN-4-1-tekspice-timothee.lesellier-mirror
** File description:
** Builder
*/

#include "Builder.hpp"
#include <cstring>
#include <algorithm>
#include "Component/Component.hpp"

nts::Builder::Builder(std::string filepath) : _filepath(filepath)
{
}

nts::Builder::~Builder(void)
{
}

std::unique_ptr<nts::Circuit> nts::Builder::BuildCircuit(void)
{
    this->getFileContent();
    this->buildComponents(_fileContent);
    this->buildLinks(_fileContent);
    return (std::make_unique<nts::Circuit>(_circuit));
}

std::list<std::string> nts::Builder::getFileContent(void)
{
    std::ifstream myfile(_filepath);
    std::string myText;

    if (!myfile.is_open())
        throw nts::FileError("File not found");
    while (getline (myfile, myText)) {
        _fileContent.push_back(this->clearComment(myText));
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

std::string nts::Builder::getLinkFirstName(std::string line)
{
    std::string lineWithOutComment(this->clearComment(line));
    std::string name = lineWithOutComment.substr(0, lineWithOutComment.find(':'));
    return (name);
}

std::string nts::Builder::getLinkSecondName(std::string line)
{
    std::string lineWithOutComment(this->clearComment(line));
    reverse(lineWithOutComment.begin(), lineWithOutComment.end());
    std::string name = lineWithOutComment.substr(0, lineWithOutComment.find(' '));
    reverse(name.begin(), name.end());
    name = name.substr(0, name.find(':'));
    return (name);
}

std::size_t nts::Builder::getLinkFirstPin(std::string line)
{
    std::string lineWithOutComment(this->clearComment(line));
    std::string pin = lineWithOutComment.substr(lineWithOutComment.find(':') + 1, lineWithOutComment.find(' '));
    return (std::stoi(pin));
}

std::size_t nts::Builder::getLinkSecondPin(std::string line)
{
    std::string lineWithOutComment(this->clearComment(line));
    reverse(lineWithOutComment.begin(), lineWithOutComment.end());
    std::string pin = lineWithOutComment.substr(0, lineWithOutComment.find(':'));
    reverse(pin.begin(), pin.end());
    return (std::stoi(pin));
}


void nts::Builder::buildLink(std::string line)
{
    std::string firstName = this->getLinkFirstName(line);
    std::string secondName = this->getLinkSecondName(line);
    std::size_t firstPin = this->getLinkFirstPin(line);
    std::size_t secondPin = this->getLinkSecondPin(line);

    _circuit.setLink(firstName, firstPin, secondName, secondPin);
}

void nts::Builder::buildLinks(std::list<std::string> fileContent)
{
    std::list<std::string>::iterator it = fileContent.begin();

    while (it != fileContent.end()) {
        if ((*it).compare(".links:") == 0) {
            it++;
            break;
        }
        it++;
    }
    if (it == fileContent.end())
        throw nts::FileError("No links found");
    while (it != fileContent.end()) {
        if (this->isValidLink(*it) == true) {
            this->buildLink(*it);
        } else if (it->compare("") != 0) {
            throw nts::FileError("Invalid link", *it);
        }
        it++;
    }
}

std::unique_ptr<nts::IComponent> nts::Builder::buildComponent(std::string chip)
{
    try {
        return (this->_factory.create(chip));
    } catch (std::runtime_error &e) {
        throw e;
    }
}

void nts::Builder::buildComponents(std::list<std::string> fileContent)
{
    std::string name;
    std::string type;

    for (std::string line : fileContent) {
        line = this->clearComment(line);
        if (this->isValidChipset(line) == true) {
            name = this->getComponentName(line);
            type = this->getComponentType(line);
            try {
                if (type.compare("input") == 0 || type.compare("clock") == 0 || type.compare("false") == 0 || type.compare("true") == 0) {
                    _circuit.addInput(std::shared_ptr<nts::IComponent>(_factory.create(type)), name);
                } else if (type.compare("output") == 0) {
                    _circuit.addOutput(std::shared_ptr<nts::IComponent>(_factory.create(type)), name);
                } else {
                    _circuit.addComponent(std::shared_ptr<nts::IComponent>(_factory.create(type)), name);
                }
            } catch (std::runtime_error &e) {
                throw e;
            }
        } else if (line.compare(".links:") == 0) {
            return;
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
    if (line.find('#') == std::string::npos)
        return (line);
    line = line.substr(0, line.find('#'));
    while (line[line.size() - 1] == ' ')
        line = line.substr(0, line.size() - 1);
    return (line);
}
