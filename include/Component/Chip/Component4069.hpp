/*
** EPITECH PROJECT, 2023
** B-OOP-400-NAN-4-1-tekspice-timothee.lesellier-mirror
** File description:
** Component4069
*/

#ifndef COMPONENT4069_HPP_
#define COMPONENT4069_HPP_

#include "../AComponent.hpp"
#include <vector>
#include "NotComponent.hpp"

namespace nts
{
    class Component4069 : public virtual nts::AComponent {
        public:
            Component4069();
            ~Component4069();

            nts::Tristate compute(std::size_t pin);
            void setLink(std::size_t pin, std::shared_ptr<nts::IComponent> other, std::size_t otherPin);

        private:
            std::vector<std::shared_ptr<nts::IComponent>> _notComponents;
            std::map<std::size_t, nts::IComponent&> _outputs;
            std::map<std::size_t, std::pair<std::size_t, nts::IComponent&>> _inputs;
    };
}

#endif /* !COMPONENT4069_HPP_ */
