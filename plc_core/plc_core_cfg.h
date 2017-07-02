












#ifndef PLC_CORE_CFG_H
#define PLC_CORE_CFG_H


enum{
    PLATFROM_STM32F20X,         
};




/* Using STM32F20X MCU */
#define _PLATFROM_ PLATFROM_STM32F20X




/* Debug function enable or disable macro, set to '1' means enable otherwize '0' */
#define _DEBUG_ENABLE_      1





/* Assert error function */
void error_handler(char *file, unsigned long line);
#define ASSERT_ERROR()  error_handler(__FILE__, __LINE__);








#define SOFT_TIMER_SIZE   5









#endif

