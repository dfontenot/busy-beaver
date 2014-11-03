#include "BusyBeaver.hpp"
#include "TapeDeque.hpp"

#include <tuple>
#include <vector>

using std::tuple;
using std::vector;

// emits: symbol to write, direction to write, new state
state_t* BusyBeaver::transition()
{
    tuple<state_t*, state_t*>* s = states[currentState];
    if(t.currentValue())
	return std::get<0>(*s);
    else
	return std::get<1>(*s);
}

void BusyBeaver::run()
{
    // halt state defined as 1 greater than the 0-idx array size
    int haltState = states.size();

    state_t* trans;
    while(currentState < haltState)
    {
	trans = transition();

	if(trans->direction)
	    t.moveRight(trans->write);
	else
	    t.moveLeft(trans->write);

	// update the state
	currentState = trans->nextState;
	++iterations;
    }

    score = t.score();
}

// don't delete the container, not dynamically allocated
BusyBeaver::~BusyBeaver()
{
    for(auto stateTuple : states)
    {
	delete std::get<0>(*stateTuple);
	delete std::get<1>(*stateTuple);
	delete stateTuple;
    }
}

int BusyBeaver::getIterations()
{
    return iterations;
}

int BusyBeaver::getScore()
{
    return score;
}
