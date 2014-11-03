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
    vector< tuple<state_t*, state_t*>* > states;

    //diagram of this state table
    /*    A    B    C
     * 0 1RB  0RC  1LC
     * 1 1RH  1RB  1LA
     */
    states.push_back(new tuple<state_t*, state_t*> (new state_t(true, true, 1), new state_t(true, true, 3)));
    states.push_back(new tuple<state_t*, state_t*> (new state_t(false, true, 2), new state_t(true, false, 0)));
    states.push_back(new tuple<state_t*, state_t*> (new state_t(true, false, 2), new state_t(true, false, 0)));

    BusyBeaver b(states);
    b.run();
    // int currentState = 0;
    // int steps = 0;

    // //the halt state is represented as 1 greater than the zero-indexed size of the states vector
    // while(currentState < states.size())
    // {
    // //while(currentState != states.size()) {
    // 	//true so pick the second part of the pair
    //     if(tape.currentValue()) 
    // 	{
    //         //true goes right, false goes left
    //         if(states[currentState]->second.direction) 
    //             tape.moveRight(states[currentState]->second.write);
    //         else
    //             tape.moveLeft(states[currentState]->second.write);
            
    //         currentState = states[currentState]->second.nextState;
    //     }
    // 	//false so pick the first part
    //     else
    // 	{    
    //         if(states[currentState]->first.direction)
    //             tape.moveRight(states[currentState]->first.write);
    //         else
    //             tape.moveLeft(states[currentState]->first.write);
            
    //         currentState = states[currentState]->first.nextState;
    //     }
        
    //     cout << "next state is " << currentState << endl;
        
    //     steps++;
    // }
    
    cout << "complete in " << b.getIterations() << " steps" << endl;
    cout << "the busy beaver's count is " << b.getScore() << endl;
    
    return 0;
}
