# bluetoothctl

ARDUINO :</br>




On your Raspberry/PC :</br>

## Install bluez


## Use bluetoothctl for connection
First of all, you need to launch bluetoothctl in a terminal. Open a terminal and then start bluetoothctl.
```bash
  sudo bluetoothctl
```

Then you are ready to use all command available from bluetooth to handle connection with you tag. If you need more information, you can use the help command to get all the primary commands available. But now, we try to connect to a specific tag called "P T EN 800633" to send command via bluetooth connected mode (Nordic UART). At this point, it's important to see the tag and show it in the device list. You can try to use the command **devices** to see if the target tag is present or not.
```bash
[bluetooth]# devices
Device F8:B6:7C:03:76:13 Cherchez moi
Device F0:68:B4:96:8B:05 BE_BLUE_T
```

If not, you can start a scan by using the scanning on/off command. Please do it!
```bash
[bluetooth]# scan on
```
You can disable the scanner when the operation of scanning is complete by using the following command.
```bash
[bluetooth]# scan off
```


#bluetoothctl</br>
[bluetoothctl]#scann on </br>
[bluetoothctl]#connect 64:33:DB:92:B6:80</br>
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
