#include <iostream>
#include <vector>
#include <utility>
#include <tuple>

#include "TapeDeque.hpp"
#include "BusyBeaver.hpp"

using std::cout;
using std::endl;
using std::vector;
using std::tuple;

int main(int argc, char** argv)
{    
    /* first: execution on zero
     * second: execution on one */
    vector< tuple<state_t, state_t> > states;

    //diagram of this state table
    /*    A    B    C
     * 0 1RB  0RC  1LC
     * 1 1RH  1RB  1LA
     */
    states.push_back(tuple<state_t, state_t>(state_t(true, true, 1), state_t(true, true, 3)));
    states.push_back(tuple<state_t, state_t> (state_t(false, true, 2), state_t(true, false, 0)));
    states.push_back(tuple<state_t, state_t> (state_t(true, false, 2), state_t(true, false, 0)));

    BusyBeaver b(states);
    b.run();
    
    cout << "complete in " << b.getIterations() << " steps" << endl;
    cout << "the busy beaver's score is " << b.getScore() << endl;
    
    return 0;
}
