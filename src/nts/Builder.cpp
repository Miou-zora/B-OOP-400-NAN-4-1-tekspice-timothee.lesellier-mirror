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

nts::Builder::Builder(std::string filepath)
{
    _filepath = filepath;
    this->initFactory();
}

nts::Builder::~Builder()
{
}

Circuit *nts::Builder::BuildCircuit()
{

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
    if (nbrOfWord == 2 | nbrOfWord == 0)
        return (true);
    return (false);
}

bool nts::Builder::isChipset(std::string line)
{

}

bool nts::Builder::isLink(std::string line)
{

}

bool nts::Builder::isComment(std::string line)
{

}

bool nts::Builder::isComponent(std::string line)
{

}

std::string nts::Builder::getComponentName(std::string line)
{
    if (this->isValidChipset(line) == false)
        throw nts::FileError("Invalid line", line);
    std::string lineWithOutComment(this->clearComment(line));
    std::reverse(lineWithOutComment.begin(), lineWithOutComment.end());
    return (lineWithOutComment.substr(0, lineWithOutComment.find(' ')));
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
