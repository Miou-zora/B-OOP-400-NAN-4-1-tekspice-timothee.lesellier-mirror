/*
** EPITECH PROJECT, 2023
** B-OOP-400-NAN-4-1-tekspice-timothee.lesellier-mirror
** File description:
** SAdder
*/

#ifndef SADDER_HPP_
    #define SADDER_HPP_

    #include "../AComponent.hpp"
    #include <vector>

namespace nts {
    class SAdder : public virtual nts::AComponent {

        public:

        enum PIN {
            CARRY_OUT = 5,
            SUM_OUT = 4
        };

            SAdder();
            ~SAdder();

            void setLink(std::size_t pin, std::shared_ptr<nts::IComponent> other, std::size_t otherPin);
            nts::Tristate compute(std::size_t pin);

        private:
            std::vector<std::shared_ptr<nts::IComponent>> _components;
            std::map<std::size_t, nts::IComponent&> _outputs;
            std::map<std::size_t, std::vector<std::pair<std::size_t, nts::IComponent&>>> _inputs;
    };
}
#endif /* !SADDER_HPP_ */