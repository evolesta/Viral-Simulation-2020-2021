#pragma once

namespace corsim
{

    /**
     * Interface klasse
     * The Movement Strategy class let the user decide which strategy can be executed
     **/

    class MovementStrategy
    {
        public:
            MovementStrategy() {}
            virtual ~ MovementStrategy() {}
            virtual double executeMovementStrategy(double dy, double dx) = 0;
    };
}