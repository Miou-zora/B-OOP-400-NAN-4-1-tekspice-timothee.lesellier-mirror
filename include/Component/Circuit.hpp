/*
** EPITECH PROJECT, 2023
** B-OOP-400-NAN-4-1-tekspice-timothee.lesellier-mirror
** File description:
** Circuit
*/

#ifndef CIRCUIT_HPP_
    #define CIRCUIT_HPP_

    #include <iostream>
    #include <string>
    #include <map>
    #include <list>
    #include "Component/IComponent.hpp"

class Circuit : virtual public nts::IComponent {
    public:
        Circuit(std::map<std::string, nts::IComponent> &components);
        ~Circuit();

        std::map<std::string, nts::IComponent> getComponents() const;

        void simulate(std::size_t tick);
        nts::Tristate compute(std::size_t pin);
        void setLink(std::string name, std::size_t pin, std::string other, std::size_t otherPin);
        void setLink(std::pair<std::string, size_t> aComponent, std::pair<std::string, size_t> bComponent);

    protected:
    private:
        std::map<std::string, nts::IComponent> _components;

};

#endif /* !CIRCUIT_HPP_ */