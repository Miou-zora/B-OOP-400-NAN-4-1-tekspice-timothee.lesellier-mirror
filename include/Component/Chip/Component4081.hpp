/*
** EPITECH PROJECT, 2023
** B-OOP-400-NAN-4-1-tekspice-timothee.lesellier-mirror
** File description:
** Component4081
*/

#ifndef COMPONENT4081_HPP_
#define COMPONENT4081_HPP_

#include "../AComponent.hpp"
#include "Component/IO/Input.hpp"
#include <map>

namespace nts
{
    class Component4081 : public virtual nts::AComponent {
        public:
            Component4081();
            ~Component4081();

            nts::Tristate compute(std::size_t pin);

        private:
            std::shared_ptr<IComponent> _andComponent;
            std::shared_ptr<nts::AIO> _inputPin1;
            std::shared_ptr<nts::AIO> _inputPin2;
            std::vector<std::size_t> _outputs;
            std::map<std::size_t, std::vector<std::size_t>> _inputs;

            nts::Tristate safeCompute(std::size_t pin);
    };
}

#endif /* !COMPONENT4081_HPP_ */
