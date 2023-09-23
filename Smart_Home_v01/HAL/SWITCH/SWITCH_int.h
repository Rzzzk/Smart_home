/*
 * SWITCH_int.h
 *
 *  Created on: Feb 12, 2023
 *      Author: esraa
 */

#ifndef HAL_SWITCH_SWITCH_INT_H_
#define HAL_SWITCH_SWITCH_INT_H_

#include"../../LIB/stdtypes.h"
#include"../../LIB/errorstate.h"

ES_t SWITCH_init(void);
ES_t SWITCH_read(u8 copy_SWITCH_port,u8 copy_SWITCH_pin,u8 *value);

#endif /* HAL_SWITCH_SWITCH_INT_H_ */
