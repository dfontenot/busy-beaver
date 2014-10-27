#ifndef BUSY_BEAVER_HPP
#define BUSY_BEAVER_HPP

#include "TapeDeque.hpp"

#include <tuple>

using std::tuple;

struct state_t
{
    bool write; //true means write a 1, false write nothing
    bool direction; //true means right, false means left
    int nextState;
    
    state_t(bool w, bool d, int next) : write(w), direction(d), nextState(next) {}
};
typedef struct state_t state_t;

class BusyBeaver
{
protected:
    vector< tuple<state_t, state_t>* > states;
    int currentState;
    int steps;

    // emits: symbol to write, direction to write, new state
    tuple<bool, bool, int>* transition();

public:
    BusyBeaver(vector< tuple<state_t, state_t>* >& s) :
	states(s), currentState(0), steps(0) {}

    void run();
    int getSteps();
};

#endif
