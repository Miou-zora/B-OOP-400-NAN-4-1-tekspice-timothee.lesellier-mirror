/*
** EPITECH PROJECT, 2023
** B-OOP-400-NAN-4-1-tekspice-timothee.lesellier-mirror
** File description:
** Builder
*/

#ifndef BUILDER_HPP_
    #define BUILDER_HPP_

    #define CHIPSET "chipsets"
    #define LINK "links"

    #include <iostream>
    #include <string>
    #include <fstream>
    #include <list>

    #include "Component/Component.hpp"
    #include "Circuit.hpp"


class FileError : public std::exception {
    public:
        FileError(std::string const &message, std::string const &component="Unknown");
        ~FileError() = default;

        std::string const &getComponent() const;
        const char *what();

    protected:
    private:
        std::string _message;
        std::string _component;
};

class Builder {
    public:
        Builder(std::string filepath);
        ~Builder();

        Circuit *BuildCircuit();

    protected:
    private:
        std::string _filepath;
        std::list<std::string> _fileContent;
        Circuit *_circuit;

        std::string getFileContent(std::string filepath);
        bool isChipset(std::string line);
        bool isLink(std::string line);
        bool isComment(std::string line);
        bool isComponent(std::string line);
        bool componentExist(std::string name);

        std::string getComponentName(std::string line);
        bool setComponentsLinks(std::string line);
        nts::IComponent buildComponent(std::string name);
        std::string getComponentType(std::string name);
        std::string clearComment(std::string line);
};

#endif /* !BUILDER_HPP_ */
