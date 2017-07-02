





#ifndef HAL_USB_BULK_H
#define HAL_USB_BULK_H



typedef enum
{
    EP_BULK_OUT_0 = 0x01,   // USB Bulk
    EP_BULK_IN_0  = 0x81,   // USB Bulk
}usb_ep_t;


typedef enum
{
    USB_EVT_DATA_REV = 0,
    USB_EVT_DATA_CONFIRM,
    USB_EVT_PLUG_IN,
    USB_EVT_PLUG_OUT,
}usb_evt_t;


typedef enum{
    USB_ST_PLUG_OUT      = 0x01,
    USB_ST_PLUG_IN       = 0x02,
    USB_ST_BULK_OUT_BUSY = 0x04,
}usb_st_t;


typedef struct
{
    usb_ep_t ep;
    usb_evt_t evt;
    unsigned char *p_buf;
    unsigned short len;
}usb_pkt_t;




typedef void (*usb_bulk_cb)(usb_pkt_t *p_pkt);



void hal_usb_bulk_init(usb_bulk_cb usb_bulk_evt);



int hal_usb_bulk_tx(usb_pkt_t *p_pkt);


void irq_usb(usb_pkt_t *p_pkt);

int hal_usb_st(void);

#endif

