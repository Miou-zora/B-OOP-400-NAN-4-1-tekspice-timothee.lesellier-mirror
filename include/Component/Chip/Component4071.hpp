/*
** EPITECH PROJECT, 2023
** B-OOP-400-NAN-4-1-tekspice-timothee.lesellier-mirror
** File description:
** Component4071
*/

#ifndef COMPONENT4071_HPP_
#define COMPONENT4071_HPP_

#include "../AComponent.hpp"
#include "OrComponent.hpp"
#include <vector>

namespace nts
{
    class Component4071 : public virtual nts::AComponent {
        public:
            Component4071();
            ~Component4071();

            nts::Tristate compute(std::size_t pin);
            void setLink(std::size_t pin, std::shared_ptr<nts::IComponent> other, std::size_t otherPin);

        private:
            std::vector<std::shared_ptr<nts::IComponent>> _orComponents;
            std::map<std::size_t, nts::IComponent&> _outputs;
            std::map<std::size_t, std::pair<std::size_t, nts::IComponent&>> _inputs;
    };
}

#endif /* !COMPONENT4071_HPP_ */
