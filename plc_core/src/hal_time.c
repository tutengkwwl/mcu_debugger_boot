




#include "plc_core.h"

typedef struct{
    unsigned long cnt;
    unsigned long reload;
}s_time_t;



static inline void irq_time_base(void);







#if (_PLATFROM_ == PLATFROM_STM32F20X)
extern __IO uint32_t uwTick;

void HAL_IncTick()
{
    uwTick++;
    irq_time_base();
}


#endif



void hal_time_init()
{

#if (_PLATFROM_ == PLATFROM_STM32F20X)
    /* Set time base to 10ms interrupt */
    
#endif

}


static inline void irq_time_base()
{
    //DEBUG("Time RUN\n");
}







