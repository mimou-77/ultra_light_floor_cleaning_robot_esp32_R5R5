

#include "state_machine.h" 
#include "hal/motor.h"



/*-----------------------------------------------------------------------------------------------*/
/* global variables                                                                             */
/*-----------------------------------------------------------------------------------------------*/

static state_t * current_state = NULL; // private var, current state (machine state) 

state_t cleaning_state =
{   .init = cleaning_init,
    .update = cleaning_update,
    .exit = cleaning_exit
};

state_t avoidance_state =
{   .init = avoidance_init,
    .update = avoidance_update,
    .exit = avoidance_exit
};



/*-----------------------------------------------------------------------------------------------*/
/* functions implementations                                                                             */
/*-----------------------------------------------------------------------------------------------*/

void state_machine_set(state_t *new_state, ctx_t *ctx)
{
    // if current_sate !=NULL AND fn ptr "exit" != NULL
    // (i.e: the ft ptr has been assigned a defined fn)
    // : 
    // - exit current sate of ctx
    // - init new state of ctx 
    if(current_state && current_state->exit)
    {
        // execute exit cb
        current_state->exit(ctx);
    }
    current_state = new_state;
    if (current_state && current_state->init)
    {
        current_state->init(ctx);
    }
}


// XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX
void state_machine_update(ctx_t *ctx)
{
    if (current_state && current_state->update)
    {
        current_state->update(ctx);
    }
}


// cleaning init = move robot forward with speed = 80
static void cleaning_init(ctx_t* ctx)
{
    motor_set_speeds(80, 80);
}
static void cleaning_update(ctx_t* ctx)
{   
}
static void cleaning_exit(ctx_t* ctx)
{
}


// avoidance init = move robot right with speed = 60
static void avoidance_init(ctx_t* ctx) 
{
    motor_set_speeds(60, -60);
}
static void avoidance_update(ctx_t* ctx) 
{ 
}
static void avoidance_exit(ctx_t* ctx) 
{
}