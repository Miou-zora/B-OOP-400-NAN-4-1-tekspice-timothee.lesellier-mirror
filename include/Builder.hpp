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
    #include <memory>

    #include "Component/Component.hpp"
    #include "Component/Circuit.hpp"
    #include "ComponentFactory.hpp"
    #include <memory>

namespace nts {
    class FileError : public std::exception {
        public:
            FileError(std::string const &message, const std::string &component="unknown") : _message(message), _component(component) {};
            ~FileError() = default;

            std::string const &GetComponent() const { return _component; };
            virtual const char* what() const throw() { return _message.c_str(); };

        protected:
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

        protected:
        private:
            std::string _filepath;
            std::list<std::string> _fileContent;
            nts::ComponentFactory _factory;

            void initFactory(void);
            std::list<std::string> getFileContent(std::string filepath);
            bool isValidChipset(std::string line);
            bool isValidLink(std::string line);

            std::string getComponentName(std::string line);
            bool setComponentsLinks(std::string line);
            std::unique_ptr<nts::IComponent> buildComponent(std::string chip);
            std::unique_ptr<std::map<std::string, std::unique_ptr<nts::IComponent>>> buildComponents(std::list<std::string> fileContent);
            std::string getComponentType(std::string name);
            std::string clearComment(std::string line);
    };
}

#endif /* !BUILDER_HPP_ */
