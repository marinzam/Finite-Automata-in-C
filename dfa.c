/*
 * File: dfa.c
 * Creator: Geraldine Marin-Zamora
 * Created: Sat Feb 4 13:09:57 2017
 */

#include <stdio.h>
#include <stdlib.h>
#include "dfa.h"

/**
 * Allocate, initialize and return a new (empty) dfa.
 */
DFA 
*DFA_new(int nstates){
    DFA *dfa = (DFA*)malloc(sizeof(DFA));
    dfa->current_state = DFA_START_STATE;
    dfa->nstates = nstates;
    dfa->states = (DFA_State*)malloc(sizeof(DFA_State));
    printf("success - DFA created");
    return dfa;
}

/**
 * Frees dfa from memory.
 */
void 
DFA_free(DFA *dfa){
    
}

/**
 * Returns int number of states.
 */
int 
DFA_get_size(DFA *dfa){
    return dfa->nstates;
}
/**
 * Returns (int) destination state after transition.
 */
int 
DFA_get_transition(DFA *dfa, int statenum, char symbol){
    return dfa->states[statenum].transitions[(int) symbol];
}

/**
 * Sets (int) destination state after transition.
 */
void 
DFA_set_transition(DFA *dfa, int src, char symbol, int dst){
    dfa->states[src].transitions[(int) symbol] = dst;
}

/**
 * Iterates through chars and sets the same transition and destination state on each.???
 */
void 
DFA_set_transition_str(DFA *dfa, int src, char *str, int dst){
    for(int i = 0; str[i] != '\0'; i++) {
        DFA_set_transition(dfa, src, str[i], dst);
    }
}

/**
 * Idk what this method does???
 */
void 
DFA_set_transition_all(DFA *dfa, int src, int dst){
     for(int i = 0; i < (dfa->nstates); i++) {
        //DFA_set_transition(dfa, src, i, dst);
    }
}

/**
 * Returns (int) current state.
 */
int 
DFA_get_current_state(DFA *dfa){
    return dfa->current_state;
}

/**
 * Sets (int) current state.
 */
void 
DFA_set_current_state(DFA *dfa, int statenum){
    dfa->current_state = statenum;
}

/**
 * Returns nonzero (int) for specific state if accepting.
 */
int 
DFA_get_accepting(DFA *dfa, int statenum){
    return dfa->states[statenum].is_accepting;
}

/**
 * Sets nonzero (int) if state is accepting, zero if not.
 */
void 
DFA_set_accepting(DFA *dfa, int statenum, int value){
    dfa->states[statenum].is_accepting = value;
}

/**
 * Returns nonzero (int) for current state if accepting.
 */
int 
DFA_is_accepting(DFA *dfa){
    return dfa->states[dfa->current_state].is_accepting;
}

/**
 * Executes dfa with char input.
 * Retrieves transition for given char, checks to see if valid, and sets current_state.
 * Checks to see if reached accepting state, returns 1 if true, continues if false.
 * Prints out whether dfa reached an invalid input or the end of string.
 */
int 
DFA_execute(DFA *dfa, char *input){
     for(int i = 0; input[i] != '\0'; i++) {
        int dest = DFA_get_transition(dfa, dfa->current_state, input[i]);
        
        if(dest == DFA_NO_TRANSITION) {
            printf("No transition, dfa failed.");
            return 0;
        }else{
            DFA_set_current_state(dfa, dest);
    
            if(DFA_get_accepting(dfa, dest)) {
                printf("Reached accepting state.\n");
                //DFA_print(dfa);
                return 1; 
            }//else, continue processing input
        }
     }
     printf("End of string reached, dfa failed.");
     return 0;
}

/**
 * Iterates through states and prints out transition and destination states.
 */
void 
DFA_print(DFA *dfa) {
    printf("Printing dfa.\n");
    for(int i = 0; i < (dfa->nstates); i++) {
        printf("State %d: ", i);
        
        for(int j = 0; (dfa->states[i].transitions[j]) != DFA_NO_TRANSITION; j++) {
            printf("%c to %d, ",'a',j);
        }        
    printf("\n");
    }
}
