







#ifndef HAL_DEBUG_H
#define HAL_DEBUG_H

#include "plc_core_cfg.h"



#if (_DEBUG_ENABLE_ == 1)

void hal_debug_init(void);

#define DEBUG_INIT() hal_debug_init()

#define DEBUG(...)  printf(__VA_ARGS__)
#define ERR(...)  do{printf("[ERR]:"); printf(__VA_ARGS__);}while(0)
#define WARN(...) do{printf("[WARN]:"); printf(__VA_ARGS__);}while(0)

#else

#define DEBUG_INIT()
#define DEBUG(...)
#define ERR(...)
#define WARN(...)

#endif



#endif

