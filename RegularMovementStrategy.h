#pragma once

#include "MovementStrategy.h"

namespace corsim
{
    /**
     * Concrete strategy 
     * 'Regular Movement' 
     * 
     * Algorithm where all subjects move in the simulation and spreading of the virus takes less time
     * */

    class RegularMovementStrategy : public MovementStrategy
    {
        public:
            double executeMovementStrategy(double dx, double dy) override;
    };
}