





#ifndef PLC_CORE_H
#define PLC_CORE_H

/* Global configration */
#include "plc_core_cfg.h"

#include "stdio.h"

#if (_PLATFROM_ == PLATFROM_STM32F20X)
#include "stm32f2xx_hal.h"
#include "usbd_def.h"
#include "usbd_core.h"
#include "usbd_desc.h"
#include "usbd_hid.h"
#endif

#include "hal_debug.h"

#include "hal_time.h"

#include "hal_led.h"

#include "hal_flash.h"

#include "hal_usb_bulk.h"

#endif

