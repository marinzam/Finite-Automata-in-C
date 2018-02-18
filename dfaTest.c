/*
 * File: dfaTest.c
 * Creator: Geraldine Marin-Zamora
 * Created: Sat Feb 4 16:18:43 2017
 * 
 * Test program for dfa library.
 */

#include <stdio.h>
#include <stdlib.h>
#include "dfa.h"

/*
 * Creates new dfa that accepts strings "ab".
 */

int
main(int argc, char **argv) {
    printf("test\n");
    DFA *dfa = DFA_new(3);
    char *input = {"ab"};
    //for(int i = 0; input[i] != '\0'; i++) {
    DFA_set_transition(dfa, 0, 'a', 1);
    DFA_set_transition(dfa, 0, 'b', DFA_NO_TRANSITION);
    DFA_set_transition(dfa, 1, 'a', DFA_NO_TRANSITION);
    DFA_set_transition(dfa, 1, 'b', 2);

    return DFA_execute(dfa, input);
}


    
