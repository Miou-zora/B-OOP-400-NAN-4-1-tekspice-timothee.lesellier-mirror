/*
** EPITECH PROJECT, 2023
** B-OOP-400-NAN-4-1-tekspice-timothee.lesellier-mirror
** File description:
** Component4013
*/

#ifndef COMPONENT4013_HPP_
#define COMPONENT4013_HPP_

#include "../AComponent.hpp"
#include <vector>
#include "FlipFlopComponent.hpp"

namespace nts
{
    class Component4013 : public virtual nts::AComponent {
        public:
            Component4013();
            ~Component4013();

            nts::Tristate compute(std::size_t pin);
            void setLink(std::size_t pin, std::shared_ptr<nts::IComponent> other, std::size_t otherPin);
            void simulate(std::size_t tick);
            void resetUpdate(void);
        private:
            std::vector<std::shared_ptr<nts::IComponent>> _components;
            std::map<std::size_t, nts::IComponent&> _outputs;
            std::map<std::size_t, std::pair<std::size_t, nts::IComponent&>> _inputs;
    };
}

#endif /* !COMPONENT4013_HPP_ */
