/*
** EPITECH PROJECT, 2023
** B-OOP-400-NAN-4-1-tekspice-timothee.lesellier-mirror
** File description:
** FlipFlopComponent
*/

#pragma once

#include "../AComponent.hpp"
#include <vector>

namespace nts
{
    class FlipFlopComponent : public virtual nts::AComponent {
        public:
            FlipFlopComponent();
            ~FlipFlopComponent();


            nts::Tristate compute(std::size_t pin);
            void simulate(std::size_t tick);
            void setLink(std::size_t pin, std::shared_ptr<nts::IComponent> other, std::size_t otherPin);
            void resetUpdate(void);

        private:
            std::vector<std::shared_ptr<nts::IComponent>> _components;
            std::map<std::size_t, nts::IComponent&> _outputs;
            std::map<std::size_t, std::pair<std::size_t, nts::IComponent&>> _inputs;
    };
}