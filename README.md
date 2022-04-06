## Table of contents :

* [Keyestudio Arduino CODE](#keyestudio-arduino-code)
  - [Installation](#installation-keyestudio-arduino)
  	- [Keyestudio wiring](#keyestudio-wiring)
  	- [Arduino Installation](#arduino-installation)
  - [Arduino Code](#arduino-code)
  	- [prerequisite](#prerequisite)
 		- [Download Arduino code](#download-arduino-code )
 		- [Download Arduino Libraries](#download-arduino-libraries )
 	 		- [Add Libraries to Arduino](#add-libraries-to-arduino)
 	 - [Arduino code for bluetooth control](#arduino-code-for-bluetooth-control)
* [Bluetoothctl](#bluetoothctl)
  - [Installation](#installation)
  - [Checking before started](#checking)
  	- [Bluetooth Status](#checking-bluetooth-status)
  - [Usage](#usage)
  	- [Search for bluetooth devices](#use-bluetoothctl)
  	- [Start a connection](#start-a-connection)
  	- [READ and WRITE](#read-and-write)
		- [READ](#show-bluetooth-updates)
		- [WRITE](#write-on-bluetooth-device)


# Keyestudio Arduino CODE

Official documentation for the assembly and wiring of the keyestudio connected house </br>
[here](/smart-home-doc.pdf)

## Installation Keyestudio Arduino

### Keyestudio wiring

### Arduino Installation
Download [arduino][arduino] open source software

![Github](https://img.shields.io/github/v/release/arduino/Arduino)

Detailed instructions for installation :

-  [Linux][Linux]
-  [macOS][macOS]
-  [Windows][Windows]


## Arduino Code

### prerequisite

#### Download Arduino code 
Download my arduino code 
[here](../../tree/main/Smart_home)

> the arduino code is complete but in this example we will just see the bluetooth part

#### Download Arduino Libraries 

Download liquidcrystal-i2c libraries directly on the arduino website :</br>
[here](https://www.arduino.cc/reference/en/libraries/liquidcrystal-i2c/)</br>
or directly on my github :</br>
[here](../../blob/main/Smart_home/libraries/LiquidCrystal_I2C-1.1.2.zip)

##### Add Libraries to Arduino

To install a new library into your Arduino.</br>
Open the Arduino and click to the "Sketch" menu and then Include Library > ADD Libraries zip.</br>
Then select the library in your files</br>

## Arduino code for bluetooth control

```console
void loop() {
	if (Serial.available() > 0) {
    		val = Serial.read(); //the value that the remote sends to us
  	}
  	switch (val) {  //for bluetooth remote control / depending on what i get
    		case 'r'://if i get the character "r"  (fan on)
      			Serial.println("fan on (remote control)"); //print on remote screen
      			digitalWrite(7, LOW);
      			digitalWrite(6, HIGH);
      			val = "0"; //so that it doesn't loop
      			break;
    		case 's'://if i get the character "s"  (fan off)
      			Serial.println("fan off (remote control)"); //print on remote screen
      			digitalWrite(7, LOW);
      			digitalWrite(6, LOW);
      			val = "0"; //so that it doesn't loop
      			break;
 	}
}
```


# Bluetoothctl

## Installation

### Install bluez

```bash
  sudo apt-get install bluez
```

## Checking

### Checking Bluetooth Status

```console
YOURCOMPUTER:~$ sudo systemctl status bluetooth
```

#### If the Bluetooth service status is not active you will have to enable it first :
```console
YOURCOMPUTER:~$ sudo systemctl enable bluetooth
```
Then start the service
```console
YOURCOMPUTER:~$ sudo systemctl start bluetooth
```

## Usage


### Use bluetoothctl

```console
YOURCOMPUTER:~$ sudo bluetoothctl
```

### Search bluetooth devices

You can start a scan by using the scanning on/off command :
```bash 
[bluetooth]:# scan on
```
If you can't find the Bluetooth device you are looking for, make sure that your system Bluetooth is discoverable :
```bash
[bluetooth]# discoverable on
```

You can disable the scanner when the operation of scanning is complete :
```bash
[bluetooth]# scan off
```

Display bluetooth devices
```bash
[bluetooth]# devices
Device E6:C1:6C:23:27:A3 TEST1
Device E8:C1:8C:03:41:13 TEST2
Device 64:33:DB:92:B6:80 HMsoft
```

### Start a connection

Now is the time to log in using the mac address of the desired device :

```bash
[bluetooth]#connect 64:33:DB:92:B6:80
```
> Note that once you are connected, the target is not bluetooth anymore but your localname tag.

### Read and Write

Now you can enter the [gatt menu][gatt_menu] :

```bash
[HMsoft]#menu gatt
```

show the different services and characteristics :

```bash
[HMsoft]#list-attributes 64:33:DB:92:B6:80
```

Enable the right properties for  to acquire notification and writing :

```bash
[HMsoft]#select-atribute /org/bluez/hci0/dev_64_33_DB_92_B6_80/service0010/char0011
```

#### show bluetooth updates

```bash
[HMsoft:/service0010/char0011]#read
[HMsoft:/service0010/char0011]#notify on
```
You can disable the notify with the following command :

```bash
[HMsoft:/service0010/char0011]#notify off
```


#### Write on bluetooth device

```bash
[HMsoft:/service0010/char0011]#write 0x72
[HMsoft:/service0010/char0011]#write 0x73 0x0a
```
> 0x72 corresponds to character "r" </br>
> 0x73 0xda corresponds to character "s"



| character        | hexadecimal      | function |
| ------|-----|-----|
| a  	| 0x61	| sends a high value to a digital output pin 13	|
| b 	| 0x62	| sends a low value to a digital output pin 13	|
| c 	| 0x63	| sends a high value to a digital output pin 12	|
| d 	| 0x64	| sends a low value to a digital output pin 12	|
| e 	| 0x65	| launch music 1	|
| f 	| 0x66	| launch music 2	|
| g 	| 0x67	| stop music	|
| h 	| 0x69	| return brightness value	|
| i 	| 0x69	| return gas value	|
| j 	| 0x6A	| return soil moisture value	|
| k 	| 0x6B	| return water value	|
| l 	| 0x6C	| open door	|
| m 	| 0x6D	| closed door	|
| n 	| 0x6E	| closed window	|
| o 	| 0x6F	| Open window	|
| p 	| 0x70	| interior yellow led on	|
| q 	| 0x71	| interior yellow led off	|
| r 	| 0x72	| fan on	|
| s 	| 0x73 0x0A	| fan off	|
| . 	| 0x2E	| Send "_" to password for door	|
| _ 	| 0x5F	| Send "." to password for door	|
| v 	| 0x76	| validate the door code	|

	
<br></br>



[Linux]: https://www.arduino.cc/en/Guide/Linux
[macOS]: https://www.arduino.cc/en/Guide/macOS
[Windows]: https://www.arduino.cc/en/Guide/Windows
[arduino]: https://www.arduino.cc/en/Main/Software
[gatt_menu]: https://www.bluetooth.com/specifications/specs/gatt-specification-supplement-6/
