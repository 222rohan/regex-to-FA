# Regex to Finite Automata (FA)

- This project is a C++ implementation of a Non-deterministic Finite Automata (NFA & e-NFA) and Deterministic Finite Automata (DFA). It converts regular expressions to finite automata.
- Converts Regex to FA in a single scan (without converting expression to postfix).

## Files

- `nfa.cpp`: This file contains the implementation of the NFA & e-NFA and conversion of a regex to e-NFA.
- `dfa.cpp`: This file contains the implementation of the DFA.
- `main.cpp`: This is the main driver of the program that uses the NFA and DFA.

## Features
- Convert any regex to e-NFA.
- created types for DFA, NFA and e-NFA 
- membership check for these FAs, printing transition tables, and other info
- used C++ for sets, maps, and object oriented approach.

## How to Run

1. Clone the repository.
2. Compile the code using a C++ compiler.
    ```bash
    g++ main.cpp nfa.cpp dfa.cpp -o main
    ```
3. Run the compiled executable
    ```bash
    ./main
    ```
## TODO
- NFA-DFA conversions
- DFA minimizations
- compiler(?)
