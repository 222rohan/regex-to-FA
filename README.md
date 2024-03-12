# Regex to Finite Automata (FA)

This project is a C++ implementation of a Non-deterministic Finite Automata (NFA & e-NFA) and Deterministic Finite Automata (DFA). It converts regular expressions to finite automata.

## Files

- `nfa.cpp`: This file contains the implementation of the NFA & e-NFA and conversion of a regex to e-NFA.
- `dfa.cpp`: This file contains the implementation of the DFA.
- `main.cpp`: This is the main driver of the program that uses the NFA and DFA.

## Features
- created types for DFA, NFA and e-NFA 
- membership check for these FAs, printing transition tables, and other info
- used C++ for sets, maps, and object oriented approach.

## Regex to FA conversion

Linearly scans the given regex in string format and converts it into the given e-NFA in a SINGLE scan
- This can be then used to check for regular-language membership, printing info about FA, etc

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
