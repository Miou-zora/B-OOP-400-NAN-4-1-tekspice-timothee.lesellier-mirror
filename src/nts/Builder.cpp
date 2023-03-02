/*
** EPITECH PROJECT, 2023
** B-OOP-400-NAN-4-1-tekspice-timothee.lesellier-mirror
** File description:
** Builder
*/

#include "Builder.hpp"
#include <fstream>
#include <algorithm>
#include <sstream>

nts::Builder::Builder(std::string filepath) : _filepath(filepath)
{
}

nts::Builder::~Builder(void)
{
}

std::unique_ptr<nts::Circuit> nts::Builder::BuildCircuit(void)
{
    this->checkExtension(_filepath);
    this->getFileContent();
    this->buildComponents(_fileContent);
    this->buildLinks(_fileContent);

    return (std::make_unique<nts::Circuit>(_circuit));
}

void nts::Builder::checkExtension(std::string filepath)
{
    std::string extension = filepath.substr(filepath.find_last_of(".") + 1);

    if (extension != "nts")
        throw nts::FileError("Invalid file extension");
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
    size_t nbrOfWord = 0;
    std::string buffer;

    for (char letter : lineWithOutComment) {
        if (!std::isspace(letter)) {
            buffer += letter;
        } else if (std::isspace(letter) && buffer != "") {
            nbrOfWord++;
            buffer.clear();
        }
    }
    if (buffer != "")
        nbrOfWord++;
    if (nbrOfWord == 2)
        return (true);
    return (false);
}

bool nts::Builder::isValidLink(std::string line)
{
    std::string lineWithOutComment(this->clearComment(line));
    size_t nbrOfWord = 0;
    std::string buffer;

    for (char letter : lineWithOutComment) {
        if (!std::isspace(letter)) {
            buffer += letter;
        } else if (std::isspace(letter) && buffer != "") {
            if (buffer.find(':') == std::string::npos)
                return (false);
            if (buffer.find(':') == 0 || buffer.find(':') == buffer.size() - 1)
                return (false);
            nbrOfWord++;
            buffer.clear();
        }
    }
    if (buffer != "") {
        if (buffer.find(':') == std::string::npos)
            return (false);
        if (buffer.find(':') == 0 || buffer.find(':') == buffer.size() - 1)
            return (false);
    }
    if (buffer != "")
        nbrOfWord++;
    if (nbrOfWord == 2)
        return (true);
    return (false);
}

std::unique_ptr<std::vector<std::string>> nts::Builder::splitString(std::string line)
{
    std::vector<std::string> list;
    std::string buffer;
    std::stringstream ss(line);

    while (ss >> buffer)
        list.push_back(buffer);
    return (std::make_unique<std::vector<std::string>>(list));
}

std::string nts::Builder::getStringFromString(std::string line, size_t pos)
{
    std::unique_ptr<std::vector<std::string>> list = this->splitString(line);

    return (list->at(pos));
}

std::string nts::Builder::getComponentType(std::string line)
{
    std::string lineWithOutComment;

    if (this->isValidChipset(line) == false)
        throw nts::FileError("Invalid line", line);
    lineWithOutComment = (this->clearComment(line));

    std::unique_ptr<std::vector<std::string>> list = this->splitString(lineWithOutComment);

    if (list->size() < 1)
        throw nts::FileError("Invalid line", line);

    return (list->at(0));
}

std::string nts::Builder::getComponentName(std::string line)
{
    std::string lineWithOutComment;

    if (this->isValidChipset(line) == false)
        throw nts::FileError("Invalid line", line);
    lineWithOutComment = (this->clearComment(line));

    std::unique_ptr<std::vector<std::string>> list = this->splitString(lineWithOutComment);

    if (list->size() < 2)
        throw nts::FileError("Invalid line", line);

    return (list->at(1));
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
    std::unique_ptr<std::vector<std::string>> list = this->splitString(lineWithOutComment);
    std::string secondPart = list->at(1);
    std::string name = secondPart.substr(0, secondPart.find(':'));

    return (name);
}

std::size_t nts::Builder::getLinkFirstPin(std::string line)
{
    std::string lineWithOutComment(this->clearComment(line));
    std::unique_ptr<std::vector<std::string>> list = this->splitString(lineWithOutComment);
    std::string firstPart = list->at(0);
    std::string pin = firstPart.substr(firstPart.find(':') + 1, firstPart.size());

    return (std::stoi(pin));
}

std::size_t nts::Builder::getLinkSecondPin(std::string line)
{
    std::string lineWithOutComment(this->clearComment(line));
    std::unique_ptr<std::vector<std::string>> list = this->splitString(lineWithOutComment);
    std::string firstPart = list->at(1);
    std::string pin = firstPart.substr(firstPart.find(':') + 1, firstPart.size());

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
        return (nts::ComponentFactory::create(chip));
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
                if (type.compare("input") == 0 || type.compare("clock") == 0) {
                    _circuit.addInput(std::shared_ptr<nts::IComponent>(nts::ComponentFactory::create(type)), name);
                } else if (type.compare("output") == 0) {
                    _circuit.addOutput(std::shared_ptr<nts::IComponent>(nts::ComponentFactory::create(type)), name);
                } else {
                    _circuit.addComponent(std::shared_ptr<nts::IComponent>(nts::ComponentFactory::create(type)), name);
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

std::string nts::Builder::clearComment(std::string line)
{
    std::string lineWithOutComment = "";
    if (line.find('#') == std::string::npos)
        return (line);
    lineWithOutComment = line.substr(0, line.find('#'));
    while (std::isspace(lineWithOutComment[lineWithOutComment.size() - 1]))
        lineWithOutComment = lineWithOutComment.substr(0, lineWithOutComment.size() - 1);
    return (lineWithOutComment);
}
