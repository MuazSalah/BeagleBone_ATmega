# BeagleBone I2C ATmega

## Table of contents

1. What is this?
2. Contents
3. Supported devices
4. References

------------------------------------------------------------------------------------

### 1. What is this? 
A combination between an I2C master (a beagle bone) and an I2C slave (an AVR 
ATmega328 MCU). The I2C master is written in Python while the slave is in C and is 
compiled using WinAVR.

------------------------------------------------------------------------------------

### 2. Contents
	
There is two folders with the following contents:


#### BeagleBone
* Adafruit_I2C.py
* LEDs_Blink.py
* LEDs_OFF.py
* LEDs_ON.py

#### ATmega
* main.c
* I2C_slave.c
* I2C_slave.h
* Makefile


##### Adafruit_I2C.py
The I2C library written by Adafruit, this is driver code for the I2C interface
		
##### LEDs_Blink.py
This code will blink the LEDS on the slave ATmega328 PB0 and PB1
		
##### LEDs_OFF.py
This code will turn OFF the LEDS on the slave ATmega328 PB0 and PB1
		
##### LEDs_ON.py
This code will turn ON the LEDS on the slave ATmega328 PB0 and PB1
		

##### main.c
This is a piece of example code which reads and writes on the I2C interface
and is a proof of concept only
		
##### I2C_slave.c
This file contains all the function declarations to setup and work with the
TWI hardware peripheral inside the AVR.
It takes care of the interrupt handling and receiving the bytes.

*Make sure you add this source file to your Makefile!*
		
##### I2C_slave.h 
This file contains the function prototypes
		
*This file has to be included in your source file*

------------------------------------------------------------------------------------
	
### 3. Supported devices
Though I have only tested this library on an ATmega328P it should be running
on all major ATmega AVRs which has built-in I2C

Additionally, the I2C master code ||should|| work on Beagle Board and Raspberry Pi,
after changing the bus address (in BeagleBone it is 3, in R-Pi it is 0)

------------------------------------------------------------------------------------

### 4. References

##### BeagleBone
http://beagleboard.org/Products/BeagleBone

#### Installing Ubuntu (Raring 13.04) on the BeagleBone
http://elinux.org/BeagleBoardUbuntu#Raring_13.04_armhf

#### Enabling SSH Server on Ubuntu (OpenSSH)
https://help.ubuntu.com/12.04/serverguide/openssh-server.html

#### I2C Tutorial on the BeagleBone
http://www.gigamegablog.com/2012/11/04/beaglebone-coding-101-i2c/

#### My write-down of this test project
http://eshortcircuit.blogspot.ae/2013/06/atmega-has-got-new-friend-beaglebone.html
