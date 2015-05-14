#include "BusyBeaver.hpp"
#include "TapeDeque.hpp"

#include <tuple>
#include <vector>

using std::tuple;
using std::vector;

// emits: symbol to write, direction to write, new state
state_t& BusyBeaver::transition()
{
    tuple<state_t, state_t>& s = states[currentState];
    if(t.currentValue())
	return std::get<1>(s);
    else
	return std::get<0>(s);
}

void BusyBeaver::run()
{
    // halt state defined as 1 greater than the 0-idx array size
    int haltState = states.size();

    while(currentState < haltState)
    {
	state_t& trans = transition();

	if(trans.direction)
	    t.moveRight(trans.write);
	else
	    t.moveLeft(trans.write);

	// update the state
	currentState = trans.nextState;
	++iterations;
    }

    score = t.score();
}

int BusyBeaver::getIterations()
{
    return iterations;
}

int BusyBeaver::getScore()
{
    return score;
}

