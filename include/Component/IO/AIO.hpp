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

            virtual void display(void) = 0;

        protected:
        private:
    };
}

#endif /* !AIO_HPP_ */
