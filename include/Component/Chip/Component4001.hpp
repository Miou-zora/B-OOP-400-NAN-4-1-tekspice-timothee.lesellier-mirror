/*
** EPITECH PROJECT, 2023
** B-OOP-400-NAN-4-1-tekspice-timothee.lesellier-mirror
** File description:
** Component4001
*/

#ifndef COMPONENT4001_HPP_
#define COMPONENT4001_HPP_

#include "../AComponent.hpp"
#include <vector>
#include "Component/Chip/NorComponent.hpp"

namespace nts
{
    class Component4001 : public virtual nts::AComponent {
        public:
            Component4001();
            ~Component4001();

            nts::Tristate compute(std::size_t pin);
            void setLink(std::size_t pin, std::shared_ptr<nts::IComponent> other, std::size_t otherPin);

        private:
            std::vector<std::shared_ptr<nts::IComponent>> _norComponent;
            std::map<std::size_t, nts::IComponent&> _outputs;
            std::map<std::size_t, std::pair<std::size_t, nts::IComponent&>> _inputs;
    };
}

#endif /* !COMPONENT4001_HPP_ */
