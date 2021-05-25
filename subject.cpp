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

#include "subject.h"
#include <math.h>

namespace corsim
{

Subject::Subject(int x, int y, int radius, bool infected, bool immune)
{
    this->_x = x;
    this->_y = y;
    this->_radius = radius;
    this->_infected = infected;
    this->_immune = immune;
}

double Subject::x()
{
    return this->_x;
}

double Subject::y()
{
    return this->_y;
}

void Subject::set_x(double x)
{
    this->_x = x;
}

void Subject::set_y(double y)
{
    this->_y = y;
}

double Subject::dx()
{
    return this->_dx;
}

double Subject::dy()
{
    return this->_dy;
}

void Subject::set_dx(double dx)
{
    this->_dx = dx;
}

void Subject::set_dy(double dy)
{
    this->_dy = dy;
}

int Subject::radius()
{
    return this->_radius;
}

bool Subject::infected()
{
    return this->_infected;
}

// B3 assignment - return if the subject is immune to the virus
bool Subject::immune()
{
    return this->_immune;
}

// b3 assignment - return the count of ticks which passed on the subject immune time
int Subject::immuneTime()
{
    return this->_immuneTime;
}

void Subject::infect()
{
    this->_infected = true;
}

// B3 assignment - return the count of ticks which passed on the subject infect time
int Subject::infectTime()
{
    return this->_infectTime;
}

// B3 assignment - increase the counter for infection time +1
void Subject::increaseInfectTime()
{
    this->_infectTime++;
}

// B3 assignment - increase the counter for infection time +1
void Subject::increaseImmuneTime()
{
    this->_immuneTime++;
}

// B3 assignment - added void to cure the subject
void Subject::cure()
{
    this->_infected = false;
    this->_infectTime = 0;
    this->_immune = true;
}

// B3 assignment - added void to make the subject vulnerable again
void Subject::becomeVulnerable()
{
    this->_immune = false;
    this->_immuneTime = 0;
}

double Subject::angle()
{
    return atan2(_dy,_dx);
}

double Subject::speed()
{
    return sqrt(_dx * _dx + _dy * _dy);
}

// define the strategy to run
void Subject::setMovement(MovementStrategy *strategy)
{
    this->_strategy = strategy;
}

void Subject::runStrategy(double dt)
{
    this->set_x(this->_strategy->run(this->x(), this->dx(), dt));
    this->set_y(this->_strategy->run(this->y(), this->dy(), dt));
}

}