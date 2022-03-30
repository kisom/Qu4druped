#!/usr/bin/env python3

import time
import serial

def execute(port, args):
    for arg in args:
        s = f'{arg[0]} {arg[1]} {arg[2]} {arg[3]}\r\n'
        port.write(s.encode('ascii'))
        time.sleep(0.256)

LEG3_WALK = [
        (3, -1, -1, 145),
        (3, -1, 15, -1),
        (3, 15, -1, -1),
        (3, 15, -1, 90),
        (3, 15, 90, 90),
        (3, 90, 90, 90),
]

def get_port(port='/dev/ttyUSB0', rate=9600):
    return serial.Serial(port=port, baudrate=rate)
