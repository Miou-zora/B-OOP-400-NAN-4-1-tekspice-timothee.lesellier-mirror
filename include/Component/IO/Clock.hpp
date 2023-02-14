/*
** EPITECH PROJECT, 2023
** B-OOP-400-NAN-4-1-tekspice-timothee.lesellier-mirror
** File description:
** Clock
*/

#ifndef CLOCK_HPP_
#define CLOCK_HPP_

#include "AIO.hpp"

class Clock : public nts::AIO {
    public:
        Clock();
        ~Clock();
        nts::Tristate compute(std::size_t pin);

        nts::Tristate getNextState(void);
        nts::Tristate getCurrentState(void);

        void setNextState(nts::Tristate nextState);
        void setCurrentState(nts::Tristate currentState);

    protected:
    private:
        nts::Tristate _currentState;
        nts::Tristate _nextState;
};

#endif /* !CLOCK_HPP_ */
