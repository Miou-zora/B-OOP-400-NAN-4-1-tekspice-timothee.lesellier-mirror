/*
** EPITECH PROJECT, 2023
** B-OOP-400-NAN-4-1-tekspice-timothee.lesellier-mirror
** File description:
** Builder
*/

#pragma once

#include <string>
#include <list>
#include <memory>

#include "Component/Component.hpp"
#include "Component/Circuit.hpp"
#include "ComponentFactory.hpp"

namespace nts
{
    class FileError : public std::exception {
        public:
            FileError(std::string const &message, const std::string &component="unknown") : _message(message), _component(component) {};
            ~FileError() = default;

            std::string const &GetComponent() const { return _component; };
            virtual const char* what() const throw() { return _message.c_str(); };

        private:
            std::string _message;
            std::string _component;
    };
}

namespace nts {
    class Builder {
        public:
            Builder(std::string filepath);
            ~Builder(void);

            std::unique_ptr<Circuit> BuildCircuit(void);

        private:
            std::string _filepath;
            std::list<std::string> _fileContent;
            nts::Circuit _circuit;

            std::list<std::string> getFileContent(void);
            bool isValidChipset(std::string line);
            bool isValidLink(std::string line);

            std::string getLinkFirstName(std::string line);
            std::string getLinkSecondName(std::string line);
            std::size_t getLinkFirstPin(std::string line);
            std::size_t getLinkSecondPin(std::string line);

            std::string getComponentName(std::string line);
            void buildLink(std::string line);
            void buildLinks(std::list<std::string> fileContent);
            std::unique_ptr<nts::IComponent> buildComponent(std::string chip);
            void buildComponents(std::list<std::string> fileContent);
            std::string getComponentType(std::string name);
            std::string clearComment(std::string line);
    };
}
