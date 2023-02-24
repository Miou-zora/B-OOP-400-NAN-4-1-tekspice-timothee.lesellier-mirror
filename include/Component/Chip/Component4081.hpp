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
#include <vector>

namespace nts
{
    class Component4081 : public virtual nts::AComponent {
        public:
            Component4081();
            ~Component4081();

            nts::Tristate compute(std::size_t pin);
            void setLink(std::size_t pin, std::shared_ptr<nts::IComponent> other, std::size_t otherPin);

        private:
            std::vector<std::shared_ptr<nts::IComponent>> _andComponents;
            std::map<std::size_t, nts::IComponent&> _outputs;
            std::map<std::size_t, std::pair<std::size_t, nts::IComponent&>> _inputs;
    };
}

#endif /* !COMPONENT4081_HPP_ */
