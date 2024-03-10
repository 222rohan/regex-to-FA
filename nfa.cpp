#include <stack>
#include <set>
#include <map>
#include <string>
#include <cstring>
#include "nfa.h"
#include <queue>
#include <iostream>

using namespace std;

NFA::NFA(){
    this->states = set<int>();
    this->alphabet = set<char>();
    this->delta = map<pair<int, char>, set<int>>();
    this->start_state = 0;
    this->final_states = set<int>();
}

NFA::NFA(set<int> states, set<char> alphabet, map<pair<int, char>, set<int>> delta, int start_state, set<int> final_states){
    this->states = states;
    this->alphabet = alphabet;
    this->delta = delta;
    this->start_state = start_state;
    this->final_states = final_states;
}

void NFA::add_alphabet(char c){
    this->alphabet.insert(c);
}

bool NFA::alphabetExists(char c){
    if(c == '-') 
        return true;

    return this->alphabet.find(c) != this->alphabet.end();
}

void NFA::add_state(int state){
    this->states.insert(state);
}

void NFA::add_final_state(int state){
    this->final_states.insert(state);
}

void NFA::add_transition(int from, char c, int to){
    this->delta[make_pair(from, c)].insert(to);
}

void NFA::set_start_state(int state){
    this->start_state = state;
}

set<int> NFA:: getFinalStates(){
    return final_states;
}

bool NFA::is_accept(string input){
    set<int> current_states = set<int>();
    current_states.insert(this->start_state);
    for(int i=0 ; i< input.length(); i++){
        set<int> next_states = set<int>();
        for(int state : current_states){
            if(delta.find(make_pair(state, input[i])) != delta.end()){
                for(int next_state : delta[make_pair(state, input[i])]){
                    next_states.insert(next_state);
                }
            }
        }
        current_states = next_states;
    }
    for(int state : current_states){
        if(final_states.find(state) != final_states.end()){
            return true;
        }
    }
    return false;
}


void NFA::printTransitionTable(){
    cout<<"Transition Table: "<<endl;
    for(auto transition : this->delta){
        cout<<"(q"<<transition.first.first<<", "<<transition.first.second<<") -> { ";
        for(auto state : transition.second){
            cout<<"q"<<state<<" ";
        }
        cout<<"}\n";
    }
}

set<int> NFA::getStates(){
    return states;
}


ENFA::ENFA(){ 
}
// overriding base NFA function to add epsilon tracking functionality
bool ENFA::is_accept(string input){
    set<int> current_states = epsilon_closure(this->start_state);
    for(int i=0 ; i< input.length(); i++){
        set<int> next_states;
        for(int state : current_states){
            if(delta.find(make_pair(state, input[i])) != delta.end()){
                for(int next_state : delta[make_pair(state, input[i])]){
                    set<int> closure = epsilon_closure(next_state);
                    next_states.insert(closure.begin(), closure.end());
                }
            }
        }
        current_states = next_states;
    }
    for(int state : current_states){
        if(final_states.find(state) != final_states.end()){
            return true;
        }
    }
    return false;
}

set<int> ENFA::epsilon_closure(int state){
    set<int> closure;
    queue<int> states_to_process;

    closure.insert(state);
    states_to_process.push(state);

    while (!states_to_process.empty()) {
        int curr_state = states_to_process.front();
        states_to_process.pop();

        if(delta.find(make_pair(curr_state,'-')) != delta.end()){
            for(int next_state : delta[make_pair(curr_state,'-')]){
                if (closure.find(next_state) == closure.end()) {
                    closure.insert(next_state);
                    states_to_process.push(next_state);
                }
            }
        }
    }

    return closure;
}

bool ENFA::isChar(char c){
    return c != '*' && c != '(' && c != ')' && c != '+' && c != '-';
}

ENFA ENFA::regex_to_nfa(string regex){

    regex = "(" + regex + ")"; //adding brackets to the regex to make it easier to parse    

    ENFA M = ENFA();
    M.add_state(0);

    int statecount = 0; //starting from zero keeps track of total states
    int subStartState = 0;  //starting state of sub-regex
    int currState = 0;//points to the current state
    int subFinalState = -1; //ending state of sub-regex
    int prevState = 0; //points to the previous state

    stack<int> stateStack = stack<int>(); //stack to keep track of start states of sub regex
    stateStack.push(0);

    for(int i=0;i<regex.length(); i++){
        
        if(regex[i] == '('){
            stateStack.push(currState);
            subStartState = currState;
        }
        if(isChar(regex[i])){
            M.add_alphabet(regex[i]);
            ++statecount;
            M.add_state(statecount);

            M.add_transition(currState, regex[i], statecount);
            prevState = currState;
            currState = statecount;
        }
        if(regex[i] == '+'){
            if(subFinalState != -1){
                M.add_transition(currState, '-', subFinalState);
                //M.add_transition(subFinalState, '-', currState);
                }
                if(stateStack.size() == 2){
                    M.add_final_state(currState);
                }
            
            subFinalState = currState;
            currState = subStartState;
        }
        if(regex[i] == ')'){    
            M.add_transition(currState, '-', subFinalState);
            //subFinalState=currState;

            if(regex[i+1] == '*'){
                M.add_transition(currState,'-',subStartState);
                M.add_transition(subStartState, '-', currState);
                i++;
            }
            
            stateStack.pop();
            subStartState = stateStack.top();
        }
        if(regex[i] == '*'){
            M.add_transition(currState,'-',subStartState);
            M.add_transition(subStartState, '-', currState);
            currState = prevState;
        }
    }
    //M.add_final_state(subFinalState);
    return M;

}
    