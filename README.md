# bluetoothctl

ARDUINO :</br>




On your Raspberry/PC :</br>





## Install bluez

```bash
  sudo apt-get install bluez
```




## Checking Bluetooth Status
```bash
  sudo systemctl status bluetooth
```

If the Bluetooth service status is not active you will have to enable it first.</br>
```bash
  sudo systemctl enable bluetooth
```
Then start the service
```bash
  sudo systemctl start bluetooth
```




## Use bluetoothctl
```bash
  sudo bluetoothctl
```

You can start a scan by using the scanning on/off command
```bash
[bluetooth]# scan on
```
You can disable the scanner when the operation of scanning is complete.
```bash
[bluetooth]# scan off
```



```bash
[bluetooth]# devices
Device E6:C1:6C:23:27:A3 TEST1
Device E8:C1:8C:03:41:13 TEST2
Device 64:33:DB:92:B6:80 HMsoft
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
