






#ifndef HAL_FLASH_H
#define HAL_FLASH_H

#if (_PLATFROM_ == PLATFROM_STM32F20X)

/* Base address of the Flash sectors Bank 1 */
#define ADDR_FLASH_SECTOR_0     ((uint32_t)0x08000000) /* Base @ of Sector 0, 16 Kbytes */
#define ADDR_FLASH_SECTOR_1     ((uint32_t)0x08004000) /* Base @ of Sector 1, 16 Kbytes */
#define ADDR_FLASH_SECTOR_2     ((uint32_t)0x08008000) /* Base @ of Sector 2, 16 Kbytes */
#define ADDR_FLASH_SECTOR_3     ((uint32_t)0x0800C000) /* Base @ of Sector 3, 16 Kbytes */
#define ADDR_FLASH_SECTOR_4     ((uint32_t)0x08010000) /* Base @ of Sector 4, 64 Kbytes */
#define ADDR_FLASH_SECTOR_5     ((uint32_t)0x08020000) /* Base @ of Sector 5, 128 Kbytes */
#define ADDR_FLASH_SECTOR_6     ((uint32_t)0x08040000) /* Base @ of Sector 6, 128 Kbytes */
#define ADDR_FLASH_SECTOR_7     ((uint32_t)0x08060000) /* Base @ of Sector 7, 128 Kbytes */
#define ADDR_FLASH_SECTOR_8     ((uint32_t)0x08080000) /* Base @ of Sector 8, 128 Kbytes */
#define ADDR_FLASH_SECTOR_9     ((uint32_t)0x080A0000) /* Base @ of Sector 9, 128 Kbytes */
#define ADDR_FLASH_SECTOR_10    ((uint32_t)0x080C0000) /* Base @ of Sector 10, 128 Kbytes */
#define ADDR_FLASH_SECTOR_11    ((uint32_t)0x080E0000) /* Base @ of Sector 11, 128 Kbytes */





#define FLASH_SECTOR_0     0U  /*!< Sector Number 0   */
#define FLASH_SECTOR_1     1U  /*!< Sector Number 1   */
#define FLASH_SECTOR_2     2U  /*!< Sector Number 2   */
#define FLASH_SECTOR_3     3U  /*!< Sector Number 3   */
#define FLASH_SECTOR_4     4U  /*!< Sector Number 4   */
#define FLASH_SECTOR_5     5U  /*!< Sector Number 5   */
#define FLASH_SECTOR_6     6U  /*!< Sector Number 6   */
#define FLASH_SECTOR_7     7U  /*!< Sector Number 7   */
#define FLASH_SECTOR_8     8U  /*!< Sector Number 8   */
#define FLASH_SECTOR_9     9U  /*!< Sector Number 9   */
#define FLASH_SECTOR_10    10U /*!< Sector Number 10  */
#define FLASH_SECTOR_11    11U /*!< Sector Number 11  */


#define FIRMWARE_START_ADDR  ADDR_FLASH_SECTOR_2

#endif



void hal_flash_erase(unsigned long start_sec, unsigned long end_sec);

void hal_flash_read(unsigned long addr, unsigned char *p, unsigned short len);

int hal_flash_write(unsigned long addr, unsigned char *p, unsigned short len);

#endif

