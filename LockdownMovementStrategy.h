#pragma once
#include "MovementStrategy.h"

namespace corsim
{
    /* Concrete strategy
    'Lockdown Movement strategy' 
    Whithin this strategy 75% of the subjects stand still in the simulation
    Infection takes more time because spreading the virus takes longer
    **/

   class LockdownMovementStrategy : public MovementStrategy
   {
       public:
        double run(double i, double di, double dt) override;
   };
}