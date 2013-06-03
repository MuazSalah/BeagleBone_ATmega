#!/usr/bin/python
from Adafruit_I2C import Adafruit_I2C
import time



tester = Adafruit_I2C(0x05, 3, True)

print "----------------------------------------"

tester.write8(1,0x01)
tester.write8(2,0x01)

#print tester.readU8(5)

print "----------------------------------------"
