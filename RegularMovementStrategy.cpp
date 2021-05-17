#include "RegularMovementStrategy.h"

namespace corsim
{
    double RegularMovementStrategy::run(double i, double di, double dt)
    {
        return i + di * dt;
    }
}