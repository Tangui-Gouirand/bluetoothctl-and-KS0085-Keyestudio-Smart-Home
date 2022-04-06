## Table of contents :

* [Keyestudio Arduino CODE](#keyestudio-arduino-code)
  - [Installation](#installation-keyestudio-arduino)
  	- [Keyestudio wiring](#keyestudio-wiring)
  	- [Arduino Installation](#arduino-installation)
  - [Arduino Code](#arduino-code)
    	- [prerequisite](#prerequisite)
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

Download my arduino code 
[here](../../tree/main/Smart_home)

> the arduino code is complete but in this example we will just see the bluetooth part



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
[HMsoft:/service0010/char0011]#write 0x73 0xda
```
> 0x72 corresponds to character "r" </br>
> 0x73 0xda corresponds to character "s"

[Linux]: https://www.arduino.cc/en/Guide/Linux
[macOS]: https://www.arduino.cc/en/Guide/macOS
[Windows]: https://www.arduino.cc/en/Guide/Windows
[arduino]: https://www.arduino.cc/en/Main/Software
[gatt_menu]: https://www.bluetooth.com/specifications/specs/gatt-specification-supplement-6/
