

#include "state_machine.h" 
#include "hal/motor.h"



/*-----------------------------------------------------------------------------------------------*/
/* global variables                                                                             */
/*-----------------------------------------------------------------------------------------------*/

static state_t * current_state = NULL; // private var, current state (machine state) 

/*-----------------------------------------------------------------------------------------------*/
/* functions implementations                                                                             */
/*-----------------------------------------------------------------------------------------------*/

void state_machine_set(state_t *new_state, ctx_t *ctx)
{
    // if current_sate !=NULL AND fn ptr "exit" != NULL
    // (i.e: the ft ptr has been assigned a defined fn)
    if(current_state && current_state->exit)
    {
        // execute exit cb
        current_state->exit(ctx);
    }
    current_state = new_state;
    
}
