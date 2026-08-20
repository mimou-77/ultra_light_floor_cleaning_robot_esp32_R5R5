
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

typedef struct State State;


// cbs that execute when we move from 1 state to another
struct State
{
    void (*init)(ctx_t* ctx);
    void (*update)(ctx_t* ctx);
    void (*exit)(ctx_t* ctx);
};


/*-----------------------------------------------------------------------------------------------*/
/* headers                                                                                       */
/*-----------------------------------------------------------------------------------------------*/








#ifdef __cplusplus
}
#endif


#endif // __STATE_MACHINE_H__