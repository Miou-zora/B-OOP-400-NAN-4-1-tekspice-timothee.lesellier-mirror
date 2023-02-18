/*
** EPITECH PROJECT, 2023
** B-OOP-400-NAN-4-1-tekspice-timothee.lesellier-mirror
** File description:
** AComponent
*/

#ifndef ACOMPONENT_HPP_
    #define ACOMPONENT_HPP_

#include "IComponent.hpp"
#include "Link.hpp"
#include <map>

namespace nts
{
    class AComponent : virtual public nts::IComponent {
        public:
            AComponent() = default;
            virtual ~AComponent() = default;

            void setLink(std::size_t pin, std::shared_ptr<nts::IComponent> other, std::size_t otherPin);

            nts::Tristate getLink(std::size_t pin);
            std::size_t getPinMax() const;

            virtual nts::Tristate compute(std::size_t pin) = 0;
            void simulate(std::size_t pin) {(void)pin;};

        protected:
            std::map<std::size_t, nts::Link> _links;
            std::size_t _pinMax;
    };

} // namespace nts

#endif /* !ACOMPONENT_HPP_ */