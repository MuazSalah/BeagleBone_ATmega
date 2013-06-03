#!/usr/bin/python
from Adafruit_I2C import Adafruit_I2C
import time



tester = Adafruit_I2C(0x05, 3, True)

print "----------------------------------------"

for i in range(10):
	tester.write8(1,0x01)
	time.sleep(0.1)
	tester.write8(2,0x01)
	time.sleep(0.1)
	tester.write8(1,0x00)
	time.sleep(0.1)
	tester.write8(2,0x00)
	time.sleep(0.1)


print "----------------------------------------"
