#pragma once

#include <stdint.h>

typedef struct libusb_device libusb_device;

typedef struct libusb_device_descriptor {
	uint8_t bLength;
	uint8_t bDescriptorType;
	uint16_t bcdUSB;
	uint8_t bDeviceClass;
	uint8_t bDeviceSubClass;
	uint8_t bDeviceProtocol;
	uint8_t bMaxPacketSize0;
	uint16_t idVendor;
	uint16_t idProduct;
	uint16_t bcdDevice;
	uint8_t iManufacturer;
	uint8_t iProduct;
	uint8_t iSerialNumber;
	uint8_t bNumConfigurations;
} libusb_device_descriptor;

extern int (*sceUsbdInit)(void);
extern void (*sceUsbdExit)(void);
extern ssize_t (*sceUsbdGetDeviceList)(libusb_device ***list);
extern void (*sceUsbdFreeDeviceList)(libusb_device **list, int unrefDevices);
extern int (*sceUsbdGetDeviceDescriptor)(libusb_device *device, libusb_device_descriptor *desc);

void initUsb(void);