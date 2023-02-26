/*
** EPITECH PROJECT, 2023
** B-OOP-400-NAN-4-1-tekspice-timothee.lesellier-mirror
** File description:
** Component4008
*/

#pragma once

#include "../AComponent.hpp"
#include "SAdder.hpp"

namespace nts
{
    class Component4008 : public virtual nts::AComponent {
        public:
            Component4008();
            ~Component4008();

            void setLink(std::size_t pin, std::shared_ptr<nts::IComponent> other, std::size_t otherPin);
            nts::Tristate compute(std::size_t pin);

        private:
            std::vector<std::shared_ptr<nts::IComponent>> _components;
            std::map<std::size_t, nts::IComponent&> _outputs;
            std::map<std::size_t, std::pair<std::size_t, nts::IComponent&>> _inputs;
    };
}
