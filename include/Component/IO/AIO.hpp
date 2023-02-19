/*
** EPITECH PROJECT, 2023
** B-OOP-400-NAN-4-1-tekspice-timothee.lesellier-mirror
** File description:
** AIO
*/

#ifndef AIO_HPP_
#define AIO_HPP_

#include "../AComponent.hpp"

namespace nts {
    class AIO : public nts::AComponent {
        public:
            AIO() = default;
            virtual ~AIO() = default;

            virtual nts::Tristate getNextState(void) {return (_nextState);};
            virtual nts::Tristate getCurrentState(void) {return (_state);};

            virtual void setNextState(nts::Tristate nextState) {_nextState = nextState;};
            virtual void setCurrentState(nts::Tristate currentState) {_state = currentState;};

        protected:
                nts::Tristate _state;
                nts::Tristate _nextState;
        private:
    };
}

#endif /* !AIO_HPP_ */
