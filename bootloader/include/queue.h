#ifndef __QUEUE_H__
#define __QUEUE_H__

/*******************************************************************************
 * Includes
 ******************************************************************************/
#include "srec.h"
#include "std_type.h"

/*******************************************************************************
 * Definitions
 ******************************************************************************/

#define MAX_QUEUE_SIZE 4u

/*******************************************************************************
 * Variables
 ******************************************************************************/
extern SREC_Record_Type queue[MAX_QUEUE_SIZE];

/*******************************************************************************
 * API
 ******************************************************************************/
/**
 * @brief Add element to the queue.
 *
 * @return 1 if successful, 0 otherwise. 
*/
__ramfunc uint8_t queue_enqueue(void);

/**
 * @brief Remove first element to the queue.
 *
 * @return 1 if successful, 0 otherwise. 
*/
uint8_t queue_dequeue(void);

/**
 * @brief Add element to the queue.
 *
 * @return index of the first element to the queue. 
 *         if queue empty return queue size + 1. 
*/
uint8_t queue_getFront(void);

/**
 * @brief Get back 
 *
 * @return index of the last element to the queue, 
*/
__ramfunc uint8_t queue_getBack(void);

#endif /* __QUEUE_H__ */
