/*
 * File: nfa.c
 * Creator: Geraldine Marin-Zamora
 * Created: Sat Feb 4 20:06:55 2017
 */

#include <stdio.h>
#include <stdlib.h>
#include "nfa.h"

/**
 * Allocate, initialize and return a new (empty) nfa.
 */
NFA 
*NFA_new(int nstates){
    NFA *nfa = (NFA*)malloc(sizeof(NFA));
    nfa->current_states = NFA_START_STATE;
    nfa->nstates = nstates;
    nfa->states = (NFA_State*)malloc(sizeof(NFA_State));
    printf("success - NFA created");
    return nfa;
}

/**
 * Frees nfa from memory.
 */
void 
NFA_free(NFA *nfa){
    
}

/**
 * Returns int number of states.
 */
int 
NFA_get_size(NFA *nfa){
    return nfa->nstates;
}
/**
 * Returns (int) destination state after transition.
 */
int 
NFA_get_transition(NFA *nfa, int statenum, char symbol){
    return nfa->states[statenum].transitions[(int) symbol];
}

/**
 * Sets (int) destination state after transition.
 */
void 
NFA_set_transition(NFA *nfa, int src, char symbol, int dst){
    nfa->states[src].transitions[(int) symbol] = dst;
}

/**
 * Iterates through chars and sets the same transition and destination state on each.???
 */
void 
NFA_set_transition_str(NFA *nfa, int src, char *str, int dst){
    for(int i = 0; str[i] != '\0'; i++) {
        NFA_set_transition(nfa, src, str[i], dst);
    }
}

/**
 * Idk what this method does???
 */
void 
NFA_set_transition_all(NFA *nfa, int src, int dst){
     for(int i = 0; i < (nfa->nstates); i++) {
        //NFA_set_transition(nfa, src, i, dst);
    }
}

/**
 * Returns (int) current state.
 */
int 
NFA_get_current_state(NFA *nfa){
    return nfa->current_state;
}

/**
 * Sets (int) current state.
 */
void 
NFA_set_current_state(NFA *nfa, int statenum){
    nfa->current_state = statenum;
}

/**
 * Returns nonzero (int) for specific state if accepting.
 */
int 
NFA_get_accepting(NFA *nfa, int statenum){
    return nfa->states[statenum].is_accepting;
}

/**
 * Sets nonzero (int) if state is accepting, zero if not.
 */
void 
NFA_set_accepting(NFA *nfa, int statenum, int value){
    nfa->states[statenum].is_accepting = value;
}

/**
 * Returns nonzero (int) for current state if accepting.
 */
int 
NFA_is_accepting(NFA *nfa){
    return nfa->states[nfa->current_state].is_accepting;
}

/**
 * Executes nfa with char input.
 * Retrieves transition for given char, checks to see if valid, and sets current_state.
 * Checks to see if reached accepting state, returns 1 if true, continues if false.
 * Prints out whether nfa reached an invalid input or the end of string.
 */
int 
NFA_execute(NFA *nfa, char *input){
     for(int i = 0; input[i] != '\0'; i++) {
        int dest = NFA_get_transition(nfa, nfa->current_state, input[i]);
        
        if(dest == NFA_NO_TRANSITION) {
            printf("No transition, nfa failed.");
            return 0;
        }else{
            NFA_set_current_state(nfa, dest);
    
            if(NFA_get_accepting(nfa, dest)) {
                printf("Reached accepting state.\n");
                //NFA_print(nfa);
                return 1; 
            }//else, continue processing input
        }
     }
     printf("End of string reached, nfa failed.");
     return 0;
}

/**
 * Iterates through states and prints out transition and destination states.
 */
void 
NFA_print(NFA *nfa) {
    printf("Printing nfa.\n");
    for(int i = 0; i < (nfa->nstates); i++) {
        printf("State %d: ", i);
        
        for(int j = 0; (nfa->states[i].transitions[j]) != NFA_NO_TRANSITION; j++) {
            printf("%c to %d, ",'a',j);
        }        
    printf("\n");
    }
}
