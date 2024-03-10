#include <vector>
#include <set>
#include <map>
#include <string>

using namespace std;

class NFA {
    protected:
        set<int> states; // Q, no duplicates
        set<char> alphabet; // Sigma, no duplicates
        map<pair<int, char>, set<int>> delta; // NFA, delta : Q x Sigma -> 2^Q
        int start_state; // q0
        set<int> final_states;  // F, no duplicates

    public:
        NFA();
        //yet to add this feature
        NFA(set<int> states, set<char> alphabet, map<pair<int, char>, set<int>> delta, int start_state, set<int> final_states);
        bool alphabetExists(char c);
        bool is_accept(string input);
        
        void add_alphabet(char c);
        void add_state(int state);
        void add_final_state(int state);
        void add_transition(int from, char c, int to);
        void set_start_state(int state);

        void printTransitionTable();
        set<int> getStates();

        set<int> getFinalStates();

        
        
};

class ENFA : public NFA{
    
    public:
        ENFA();
        //void add_transition(int from, char c, int to);
        bool is_accept(string input);
        set<int> epsilon_closure(int state);
        ENFA regex_to_nfa(string regex);

        bool isChar(char c);

        
};
