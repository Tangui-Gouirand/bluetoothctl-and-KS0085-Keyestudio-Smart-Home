# TITLE: bluetoothctl

## Table of contents :

* [Installation](#installation)
* [Checking before started](#checking)
  - [Bluetooth Status](#checking-bluetooth-status)
* [Usage](#usage)
	- [Searchfor bluetooth devices](#use-bluetoothctl)
	- [Start a connection](#start-a-connection)

## Installation

### Install bluez

```bash
  sudo apt-get install bluez
```

## Checking

### Checking Bluetooth Status

```bash
  sudo systemctl status bluetooth
```

#### If the Bluetooth service status is not active you will have to enable it first :
```bash
  sudo systemctl enable bluetooth
```
Then start the service
```bash
  sudo systemctl start bluetooth
```

## Usage


### Use bluetoothctl

```bash
  sudo bluetoothctl
```

### search bluetooth devices

You can start a scan by using the scanning on/off command
```bash
[bluetooth]# scan on
```
If you can't find the Bluetooth device you are looking for, make sure that your system Bluetooth is discoverable.
```bash
[bluetooth]# discoverable on
```

You can disable the scanner when the operation of scanning is complete.
```bash
[bluetooth]# scan off
```

display bluetooth devices
```bash
[bluetooth]# devices
Device E6:C1:6C:23:27:A3 TEST1
Device E8:C1:8C:03:41:13 TEST2
Device 64:33:DB:92:B6:80 HMsoft
```

### Start a connection
```bash
[bluetooth]#connect 64:33:DB:92:B6:80
```

[HMsoft]#menu gatt</br>
[HMsoft]#list-atribute</br>
[HMsoft]#select-atribute /org/bluez/hci0/dev_64_33_DB_92_B6_80/service0010/char0011</br>
c’est l’atribute "characteristic" </br>

[HMsoft:/service0010/char0011]#read</br>
[HMsoft:/service0010/char0011]#notify on</br>

[HMsoft:/service0010/char0011]#notify off</br>

[HMsoft:/service0010/char0011]#write 0x72            = r </br>
[HMsoft:/service0010/char0011]#write 0x73 0xda        = s</br>


[HMsoft:/service0010/char0011]#write  0x2e     = .</br>
[HMsoft:/service0010/char0011]#write  0x5f          = _</br>
[HMsoft:/service0010/char0011]#write  0x5f         = _</br>
[HMsoft:/service0010/char0011]#write  0x2e     = .</br>
[HMsoft:/service0010/char0011]#write  0x5f         = _</br>
[HMsoft:/service0010/char0011]#write  0x2e     = .</br>
[HMsoft:/service0010/char0011]#write  0x76         = v</br>
