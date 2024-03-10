#include <vector>
#include <set>
#include <map>

#include "nfa.h"

using namespace std;

class DFA : public NFA{
    
    public:
        DFA();
        //DFA(set<int> states, set<char> alphabet, map<pair<int, char>, int> delta, int start_state, set<int> final_states);  
        void add_transition(int from, char c, int to); 
    
};