


#include "plc_core.h"


void hal_flash_erase(unsigned long start_sec, unsigned long end_sec)
{
#if (_PLATFROM_ == PLATFROM_STM32F20X)
    static FLASH_EraseInitTypeDef EraseInitStruct;
    uint32_t FirstSector = 0, NbOfSectors = 0;
    uint32_t SECTORError = 0;
    
    HAL_FLASH_Unlock();
    
    /* Get the 1st sector to erase */
    FirstSector = start_sec;
    /* Get the number of sector to erase from 1st sector*/
    NbOfSectors = end_sec - FirstSector + 1;
    /* Fill EraseInit structure*/
    EraseInitStruct.TypeErase     = TYPEERASE_SECTORS;
    EraseInitStruct.VoltageRange  = VOLTAGE_RANGE_3;
    EraseInitStruct.Sector        = FirstSector;
    EraseInitStruct.NbSectors     = NbOfSectors;

    /* Note: If an erase operation in Flash memory also concerns data in the data or instruction cache,
     you have to make sure that these data are rewritten before they are accessed during code
     execution. If this cannot be done safely, it is recommended to flush the caches by setting the
     DCRST and ICRST bits in the FLASH_CR register. */
    if (HAL_FLASHEx_Erase(&EraseInitStruct, &SECTORError) != HAL_OK)
    {
        ASSERT_ERROR();
    }

    HAL_FLASH_Lock();
#endif
}


void hal_flash_read(unsigned long addr, unsigned char *p, unsigned short len)
{
#if (_PLATFROM_ == PLATFROM_STM32F20X)
    unsigned long p_dat, dat;
    p_dat = addr;
    
    for(int i = 0; i < len; i++)
    {
        dat  = *(__IO uint32_t *)p_dat;
        p[i] = (unsigned char)(dat >> 24);
        p_dat++;
    }
#endif
}

int hal_flash_write(unsigned long addr, unsigned char *p, unsigned short len)
{

#if (_PLATFROM_ == PLATFROM_STM32F20X)
    HAL_FLASH_Lock();

    for(int i = 0; i < len; i++)
    {
        if(HAL_FLASH_Program(FLASH_TYPEPROGRAM_BYTE, addr, p[i]) != HAL_OK)
        {
            HAL_FLASH_Lock();
            return 0;
        }
    }
    
    HAL_FLASH_Lock();
#endif

    return 1;
}
















