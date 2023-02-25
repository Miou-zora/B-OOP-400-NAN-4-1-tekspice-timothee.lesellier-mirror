/*
** EPITECH PROJECT, 2023
** B-OOP-400-NAN-4-1-tekspice-timothee.lesellier-mirror
** File description:
** Component4030
*/

#ifndef COMPONENT4030_HPP_
#define COMPONENT4030_HPP_

#include "../AComponent.hpp"
#include "XorComponent.hpp"
#include <vector>

namespace nts
{
    class Component4030 : public virtual nts::AComponent {
        public:
            Component4030();
            ~Component4030();

            nts::Tristate compute(std::size_t pin);
            void setLink(std::size_t pin, std::shared_ptr<nts::IComponent> other, std::size_t otherPin);

        private:
            std::vector<std::shared_ptr<nts::IComponent>> _xorComponents;
            std::map<std::size_t, nts::IComponent&> _outputs;
            std::map<std::size_t, std::pair<std::size_t, nts::IComponent&>> _inputs;
    };
}

#endif /* !COMPONENT4030_HPP_ */
