#!/usr/bin/env python3

import usb1 # pip install libusb1
import random
import sys

VENDOR_ID  = 0x1b3d
PRODUCT_ID = 0x000b
ENDPOINT_WR   = 0x01
ENDPOINT_RD   = 0x82

context = usb1.USBContext()

handle = context.openByVendorIDAndProductID(
    VENDOR_ID,
    PRODUCT_ID,
    skip_on_error=True,
)

if handle is None:
    # Device not present, or user is not allowed to access device.
    raise ValueError('Device not found. Please ensure it is connected.')
    sys.exit(1)

handle.claimInterface(0)

data = bytearray(1024)
for i in range(len(data)):
    data[i] = random.randint(0,255)

# Send the image
r = handle.bulkWrite(ENDPOINT_WR, data,timeout=5000)

# Zero length packet indicating the end of the transfer
data = bytearray(0)
r = handle.bulkWrite(ENDPOINT_WR, data,timeout=5000)

handle.releaseInterface(0)
