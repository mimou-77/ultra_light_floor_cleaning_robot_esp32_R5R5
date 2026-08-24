
#pragma once
#ifndef __STATE_MACHINE_H__
#define __STATE_MACHINE_H__


#ifdef __cplusplus
extern "C" {
#endif




#include "ctx.h"


/*-----------------------------------------------------------------------------------------------*/
/* types                                                                                         */
/*-----------------------------------------------------------------------------------------------*/

// state is a set of cbs
typedef struct state_s state_t;


// cbs that execute when we transition from 1 state to another
struct state_s
{
    void (*init)(ctx_t* ctx);
    void (*update)(ctx_t* ctx);
    void (*exit)(ctx_t* ctx);
};


/*-----------------------------------------------------------------------------------------------*/
/* global variables                                                                             */
/*-----------------------------------------------------------------------------------------------*/

extern state_t cleaning_state; // position ok, i clean
extern state_t avoidance_state; // position nok, i avoid




/*-----------------------------------------------------------------------------------------------*/
/* headers                                                                                       */
/*-----------------------------------------------------------------------------------------------*/

// transition ctx from current_state to new_state ;
// exists current state, updates current_state=new_state, initializes new_state
void state_machine_set(state_t * new_state, ctx_t * ctx);

// 
void state_machine_update(ctx_t * ctx);





#ifdef __cplusplus
}
#endif


#endif // __STATE_MACHINE_H__