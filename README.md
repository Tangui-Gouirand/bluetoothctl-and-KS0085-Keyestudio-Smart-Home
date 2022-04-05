# bluetoothctl

ARDUINO :</br>




On your Raspberry/PC :</br>

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
