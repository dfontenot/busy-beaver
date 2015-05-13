#ifndef BUSY_BEAVER_HPP
#define BUSY_BEAVER_HPP

#include "TapeDeque.hpp"

#include <vector>
#include <tuple>

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
    TapeDeque t;
    std::vector< std::tuple<state_t, state_t> > states;
    
    int currentState;
    int iterations;
    int score;

    // emits: symbol to write, direction to write, new state
    state_t& transition();

public:
    BusyBeaver(std::vector< std::tuple<state_t, state_t> > const& s) :
	states(s), currentState(0), iterations(0), score(0) {}

    void run();
    int getIterations();
    int getScore();
};

#endif
