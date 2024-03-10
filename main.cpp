//c++ prog to simulate a dfa

//TODO: ADD EPSILON NFA TO NFA

//TODO: ADD A FUNCTION TO CONVERT NFA TO DFA
//TODO: ADD A FUNCTION TO CONVERT REGEX TO NFA
//TODO: ADD A FUNCTION TO CONVERT REGEX TO DFA
//regex to nfa to dfa to minimized dfa
//TODO COMPILER FROM DFA   


#include <bits/stdc++.h>
#include <set>
#include <map>
#include <string>

using namespace std;

#include "dfa.h"

int mainMenu();
int regexToFAMenu();


int main(){

    mainMenu();
    /*ENFA M = ENFA();
   
    cout<<"Alphabet Size: "; cin>>n;
    cout<<"Elements: "<<endl;
    for(int i = 0; i < n; i++){
        cout<<">";
        char c; cin>>c;
        M.add_alphabet(c);
    }

    cout<<"no of states: "; cin>>n; 
    for(int i = 0; i < n; i++){
        M.add_state(i);
    }

    cout<<"start state: "; cin>>n;
    M.set_start_state(n);

    cout<<"no of final states: "; cin>>n;
    cout<<"final states: ";
    cout<<endl;
    for(int i = 0; i < n; i++){
        int state; 
        cout<<">";
        cin>>state;
        M.add_final_state(state);
    }

    cout<<"no of transitions: "; cin>>n;    
    cout<<"transitions: ";
    for(int i = 0; i < n; i++){
        int from, to; char c;
        cin>>from>>c>>to;
        if(!M.alphabetExists(c)){
            cout<<"Invalid alphabet\n";
            i--;
            continue;}

        M.add_transition(from, c, to);
    }

    cout<<"no of strings to check: "; cin>>n;
    cout<<"strings: ";
    for(int i = 0; i < n; i++){
        string s; cin>>s;
        if(M.is_accept(s)){
            cout<<"accepted\n";
    }else{
        cout<<"rejected\n";
    }
    } 

    cout << "States: ";
for(int state : M.getStates()){
    cout << state << " ";
}
cout << "\n";

    cout << "final States: ";
for(int state : M.getFinalStates()){
    cout << state << " ";

    cout<<"transition table: \n";
    M.printTransitionTable();

    cout<<"epsilon closure of each state: \n";
    for(int state : M.getStates()){
        cout<<"E(q"<<state<<") = { ";
        set<int> closure = M.epsilon_closure(state);
        for(int eclosure_state : closure){
            cout<<"q"<<eclosure_state<<" ";
        }
        cout<<"}\n";
    }
    cout<<"\n";

    M.printTransitionTable(); 

    ENFA M = ENFA();
    string regex;
    cout<<"Enter regex: "; cin>>regex;
    M = M.regex_to_nfa(regex);

    cout<<"no of strings to check: "; cin>>n;
    cout<<"strings: ";
    for(int i = 0; i < n; i++){
        string s; cin>>s;
        if(M.is_accept(s)){
            cout<<"accepted\n";
    }else{
        cout<<"rejected\n";
        }
    }
        cout << "States: ";
for(int state : M.getStates()){
    cout << state << " ";
}
cout << "\n";

    cout << "final States: ";
for(int state : M.getFinalStates()){
    cout << state << " ";

    cout<<"transition table: \n";
    M.printTransitionTable();

    cout<<"epsilon closure of each state: \n";
    for(int state : M.getStates()){
        cout<<"E(q"<<state<<") = { ";
        set<int> closure = M.epsilon_closure(state);
        for(int eclosure_state : closure){
            cout<<"q"<<eclosure_state<<" ";
        }
        cout<<"}\n";
    }
    cout<<"\n";

    M.printTransitionTable();
}
*/

}

int mainMenu(){
    
    while(true){
        int choice;
        cout<<"1. DFA\n2. NFA\n3. ENFA\n4. Regex to FA\n5. Exit\n";
        cout<<"Enter choice: "; cin>>choice;
        switch(choice){
        case 1: //dfaMenu(); break;
        case 2: //nfaMenu(); break;
        case 3: //enfaMenu(); break;
        case 4: regexToFAMenu(); break;
        case 5: return 0;
        default: cout<<"Invalid choice\n"; 
    }
    
    }
}

int regexToFAMenu(){
    ENFA M = ENFA();
    string regex;
    cout<<"Enter regex: "; cin>>regex;
    M = M.regex_to_nfa(regex);
    int n;
    while(true){
        cout<<"1. Check string\n2. Print transition table\n3. Print epsilon closure\n4. Print Final States\n5. Exit\n";
        cout<<"Enter choice: "; cin>>n;
        switch(n){
            case 1: {
                    cout<<"enter string: ";
                    string s; cin>>s;
                    if(M.is_accept(s)){
                        cout<<"accepted\n";
                    }else{
                        cout<<"rejected\n";
                        }
                }
                break;
            case 2: M.printTransitionTable(); break;
            case 3: 
                cout<<"epsilon closure of each state: \n";
                for(int state : M.getStates()){
                    cout<<"E(q"<<state<<") = { ";
                    set<int> closure = M.epsilon_closure(state);
                    for(int eclosure_state : closure){
                        cout<<"q"<<eclosure_state<<" ";
                    }
                    cout<<"}\n";
                }
                cout<<"\n";
                break;
            case 4: cout<<"Final States: ";
                    for(int state : M.getFinalStates()){
                        cout<<"q"<<state<<" ";
                    }
                    cout<<"\n";
                    break;
            case 5: return 0;
            default: cout<<"Invalid choice\n";
        }
    }
}