//defintions
#include <iostream>
#include <set>
#include <map>
#include <string>
using namespace std;

#include "dfa.h"

DFA::DFA(){     //default constructor, to add machine parameters later;
} 
void DFA::add_transition(int from, char c, int to){
    if(delta.find(make_pair(from,c))==delta.end()){
        delta[make_pair(from,c)].insert(to);
    }
    else{
        cout<<"\nTransition already exists"<<endl;
    }   
}


