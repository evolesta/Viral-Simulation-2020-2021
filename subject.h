// Corona Simulation - basic simulation of a human transmissable virus
// Copyright (C) 2020  wbrinksma

// This program is free software: you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.

// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.

// You should have received a copy of the GNU General Public License
// along with this program.  If not, see <http://www.gnu.org/licenses/>.

#include "MovementStrategy.h"

namespace corsim
{
    
/**
 * A subject is an entity within the simulation. It is modeled as a
 * circle in 2D and can be infected.
 */
class Subject
{
    public:
        Subject(int x, int y, int radius, bool infected, bool immune);
        double x();
        double y();
        void set_x(double x);
        void set_y(double y);
        double dx(); //Speed on x axis
        double dy(); //Speed on y axis
        int radius(); //Radius needed for collisions
        void set_dx(double dx);
        void set_dy(double dy);
        bool infected();
        void infect(); // void to make the subject infected
        void cure(); // B3 assignment - void to make the subject better
        int infectTime(); // B3 assignment - int to count the number of ticks until subjects becomes cured
        void increaseInfectTime(); // B3 assignment - void to increase the infect time counter
        bool immune(); // B3 assignment - if immune, the subject can't get infected for a period of time
        void becomeImmune(); // B3 assignment - make the subject become immune
        void becomeVulnerable(); // B3 assignment - make the subject become vulnerable again
        int immuneTime(); // B3 assignment - int to count the number of ticks until the subject can be infected again
        double angle();
        double speed();

        // define the movement strategy for the subject
        void setMovement(MovementStrategy *strategy);
        void runStrategy(double dt);
    private:
        double _x = 0,_y = 0, _dx = 0, _dy = 0;
        bool _infected = false;
        bool _immune = false;
        int _radius = 0;

        MovementStrategy *_strategy;
};

};