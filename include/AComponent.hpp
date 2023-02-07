/*
** EPITECH PROJECT, 2023
** B-OOP-400-NAN-4-1-bootstrap-tekspice
** File description:
** AComponent
*/

#pragma once
    #include "IComponent.hpp"
    #include <map>

namespace nts
{
	class Link {
        public:
		    Link() {component = nullptr; otherPin = 0;};
            ~Link() {};
		    IComponent *component;
		    size_t pin;
            size_t otherPin;
	};

    class AComponent : virtual public nts::IComponent {
        public:
            AComponent() = default;
            virtual ~AComponent() = default;

            void setLink(std::size_t pin, nts::IComponent& other, std::size_t otherPin);

            nts::Tristate getLink(std::size_t pin);
            std::size_t getPinMax() const;
            nts::Tristate getState() const;

            virtual nts::Tristate compute(std::size_t pin) = 0;
            void simulate(std::size_t pin) {(void)pin;};

        protected:
            std::map<std::size_t, nts::Link> _links;
            std::size_t _pinMax;
            nts::Tristate _state;
    };

} // namespace nts

