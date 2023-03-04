/*
** EPITECH PROJECT, 2023
** B-OOP-400-NAN-4-1-tekspice-timothee.lesellier-mirror
** File description:
** Component4013
*/

#include "Component/Chip/Component4013.hpp"

nts::Component4013::Component4013()
{
    _components = {
                    std::make_shared<nts::FlipFlopComponent>(),
                    std::make_shared<nts::FlipFlopComponent>()
    };

    _outputs = {
                    {1, *_components[0]},
                    {2, *_components[0]},
                    {12, *_components[1]},
                    {13, *_components[1]}
    };

    _inputs = {
        {3, std::pair<std::size_t, nts::IComponent&>(2, *_components[0])}, //CLOCK
        {4, std::pair<std::size_t, nts::IComponent&>(4, *_components[0])}, //RESET
        {5, std::pair<std::size_t, nts::IComponent&>(1, *_components[0])}, //DATA
        {6, std::pair<std::size_t, nts::IComponent&>(3, *_components[0])}, //SET

        {8, std::pair<std::size_t, nts::IComponent&>(3, *_components[1])}, //SET
        {9, std::pair<std::size_t, nts::IComponent&>(1, *_components[1])}, //DATA
        {10, std::pair<std::size_t, nts::IComponent&>(4, *_components[1])}, //RESET
        {11, std::pair<std::size_t, nts::IComponent&>(2, *_components[1])}, //CLOCK
    };

}

nts::Component4013::~Component4013()
{

}

nts::Tristate nts::Component4013::compute(std::size_t pin)
{
    std::map<std::size_t, std::size_t>pinConvertor = {{1, 5}, {2, 6}, {12, 5}, {13, 6}};
    try {
        return _outputs.at(pin).compute(pinConvertor.at(pin));
    } catch (std::out_of_range &e) {
        std::cout << "PIN : " << pin << std::endl;
        throw std::invalid_argument("Pin out of range");
    }
}

void nts::Component4013::simulate(std::size_t tick)
{
    if (_updated == true)
        return;
    _updated = true;
    for (auto &component : _components) {
        component.get()->simulate(tick);
    }
}

void nts::Component4013::resetUpdate(void)
{
    if (_updated == false)
        return;
    _updated = false;
    for (auto &component : _components) {
        component.get()->resetUpdate();
    }
}

void nts::Component4013::setLink(std::size_t pin, std::shared_ptr<nts::IComponent> other, std::size_t otherPin)
{
    for (auto output: _outputs) {
        if (output.first == pin) {
            return;
        }
    }
    try {
        _inputs.at(pin).second.setLink(_inputs.at(pin).first, other, otherPin);
    } catch (std::out_of_range &e) {
        throw std::invalid_argument("Pin out of range");
    }
}
