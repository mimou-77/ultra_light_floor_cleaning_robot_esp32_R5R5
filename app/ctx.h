
#pragma once
#ifndef __CTX_H__
#define __CTX_H__


#ifdef __cplusplus
extern "C" {
#endif



#include <stdint.h>


#define GRID_SIZE 40 // 40 x 40 cells


/*-----------------------------------------------------------------------------------------------*/
/* types                                                                                         */
/*-----------------------------------------------------------------------------------------------*/

// position + angle of the servo
typedef struct
{
    float x;
    float y;
    float theta;
} Pose_t;


// robot state = pose + environment map
typedef struct
{
    Pose pose;
    uint8_t grid[GRID_SIZE][GRID_SIZE]; // 0: unkown, 1: free, 2: Obstacle
} ctx_t;





#ifdef __cplusplus
}
#endif


#endif // __CTX_H__