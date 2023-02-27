/*
** EPITECH PROJECT, 2023
** B-OOP-400-NAN-4-1-tekspice-timothee.lesellier-mirror
** File description:
** AComponent
*/

#pragma once

#include "IComponent.hpp"
#include "Link.hpp"
#include <map>

namespace nts
{
    class AComponent : virtual public nts::IComponent {
        public:
            AComponent() : _pinMax(0), _updated(false) {};
            virtual ~AComponent() = default;

            void setLink(std::size_t pin, std::shared_ptr<nts::IComponent> other, std::size_t otherPin);

            std::size_t getPinMax() const;

            virtual nts::Tristate compute(std::size_t pin) = 0;
            void simulate(std::size_t pin);
            void resetUpdate(void);

        protected:
            std::map<std::size_t, std::unique_ptr<nts::Link>> _links;
            std::size_t _pinMax;
            bool _updated;
    };

}