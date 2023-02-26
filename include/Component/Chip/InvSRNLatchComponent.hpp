/*
** EPITECH PROJECT, 2023
** B-OOP-400-NAN-4-1-tekspice-timothee.lesellier-mirror
** File description:
** InvSRNLatchComponent
*/

#pragma once

#include "../AComponent.hpp"
#include <vector>

namespace nts {
    class InvSRNLatchComponent : public virtual nts::AComponent {
        public:
            InvSRNLatchComponent();
            ~InvSRNLatchComponent();

            nts::Tristate compute(std::size_t pin);
            void simulate(std::size_t tick);
            void setLink(std::size_t pin, std::shared_ptr<nts::IComponent> other, std::size_t otherPin);

        private:
            std::vector<std::shared_ptr<nts::IComponent>> _components;
            std::map<std::size_t, nts::IComponent&> _outputs;
            std::map<std::size_t, std::pair<std::size_t, nts::IComponent&>> _inputs;
    };
}
