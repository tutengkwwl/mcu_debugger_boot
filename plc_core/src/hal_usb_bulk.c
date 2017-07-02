

#include "plc_core.h"

#if (_PLATFROM_ == PLATFROM_STM32F20X)

USBD_HandleTypeDef  USBD_Device;

#endif

static usb_bulk_cb usb_evt = NULL;

static int usb_st;


void irq_usb(usb_pkt_t *ptr)
{
    if(usb_evt)
    {
        usb_evt(ptr);
    }
}





void hal_usb_bulk_init(usb_bulk_cb usb_bulk_evt)
{
#if (_PLATFROM_ == PLATFROM_STM32F20X)
    usb_evt = usb_bulk_evt;

    /* Init Device Library */
		USBD_Init(&USBD_Device, &HID_Desc, 0);
		
		/* Add Supported Class */
		USBD_RegisterClass(&USBD_Device, USBD_HID_CLASS);
		
		/* Start Device Process */
		USBD_Start(&USBD_Device);
#endif
}





int hal_usb_bulk_tx(usb_pkt_t *p_pkt)
{
#if (_PLATFROM_ == PLATFROM_STM32F20X)
    return stm32_usb_bulk_tx((unsigned char)(p_pkt->ep), p_pkt->p_buf, p_pkt->len);
#endif
}



int hal_usb_st()
{
    usb_st &= ~USB_ST_BULK_OUT_BUSY;
    usb_st |= (((USBD_HID_HandleTypeDef *)USBD_Device.pClassData)->state == HID_IDLE) ? 0 : USB_ST_BULK_OUT_BUSY;
    
    return usb_st;
}





