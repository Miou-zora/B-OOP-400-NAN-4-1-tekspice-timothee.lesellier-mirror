/*
** EPITECH PROJECT, 2023
** B-OOP-400-NAN-4-1-tekspice-timothee.lesellier-mirror
** File description:
** Output
*/

#pragma once
#include "AIO.hpp"

class Output : public virtual nts::AIO {
    public:
        Output();
        ~Output();
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
