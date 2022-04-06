#include <Servo.h>
#include <Wire.h>
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C mylcd(0x27, 16, 2);
Servo servo_10;
Servo servo_9;

volatile int btn1_num;
volatile int btn2_num;
volatile int button1;
volatile int button2;
String fans_char;
volatile int fans_val;
volatile int flag;
volatile int flag2;
volatile int flag3;
volatile int gas;
volatile int infrar;
String led2;
volatile int light;
String pass;
String passwd;
String passblu ;
String servo1;
volatile int servo1_angle;
String servo2;
volatile int servo2_angle;
volatile int sol;
volatile int val;
volatile int value_led2;
volatile int water;
int COMPTEREBOUR;
int afficagecr;

int length;
int tonepin = 3;


void setup() {
  Serial.begin(9600);
  mylcd.init();
  mylcd.backlight();
  mylcd.setCursor(1 - 1, 1 - 1);
  mylcd.print("mot de passe:");
  servo_9.attach(9);
  servo_10.attach(10);
  pinMode(7, OUTPUT);
  pinMode(6, OUTPUT);
  servo_9.write(0);
  delay(300);
  servo_10.write(0);
  delay(300);
  digitalWrite(7, HIGH);
  digitalWrite(6, HIGH);
  pinMode(4, INPUT);
  pinMode(8, INPUT);
  pinMode(2, INPUT);
  pinMode(3, OUTPUT);
  pinMode(A0, INPUT);
  pinMode(A1, INPUT);
  pinMode(13, OUTPUT);
  pinMode(A3, INPUT);
  pinMode(A2, INPUT);
  pinMode(12, OUTPUT);
  pinMode(5, OUTPUT);
  pinMode(3, OUTPUT);
  val = 0;
  COMPTEREBOUR = 0;
  button1 = 0;
  afficagecr = "";
  button2 = 0;
  btn1_num = 0;
  btn2_num = 0;
  passwd = "";
  passblu = "";
  pass = "";
  gas = 0;
  flag = 0;
  light = 0;
  infrar = 0;
  water = 0;
  flag2 = 0;
  sol = 0;
  flag3 = 0;
  servo1 = "";
  servo1_angle = 0;
  servo2 = "";
  servo2_angle = 0;
  led2 = "";
  value_led2 = 0;
  fans_char = "";
  fans_val = 0;
}

void loop() {
  auto_sensor();
  if (Serial.available() > 0) {
    val = Serial.read();
    //Serial.println(val);
    pwm_control();
  }
  switch (val) {//for bluetooth remote control
    case 'a': //if i get the character "a"
      digitalWrite(13, HIGH);
      val = "0"; //so that it doesn't loop
      break;
    case 'b': //if i get the character "b"
      digitalWrite(13, LOW);
      val = "0";
      break;
    case 'c':
      digitalWrite(12, HIGH);
      val = "0"; //so that it doesn't loop
      break;
    case 'd':
      digitalWrite(12, LOW);
      val = "0";
      break;
    case 'e'://launch music 1
      music1();
      val = "0"; //so that it doesn't loop
      break;
    case 'f'://launch music 2
      music2();
      val = "0"; //so that it doesn't loop
      break;
    case 'g'://stop music
      noTone(3);
      val = "0"; //so that it doesn't loop
      break;
    case 'h'://return brightness value
      Serial.print("brightness sensor value = ");
      Serial.println(light);
      delay(100);
      val = "0"; //so that it doesn't loop
      break;
    case 'i'://return gas value
      Serial.print("gas sensor value = ");
      Serial.println(gas);
      delay(100);
      val = "0"; //so that it doesn't loop
      break;
    case 'j'://return soil moisture value
      Serial.print("soil moisture value = ");
      Serial.println(sol);
      delay(100);
      val = "0"; //so that it doesn't loop
      break;
    case 'k'://return water value
      Serial.print("valeur capteur d'eau = ");
      Serial.println(water);
      delay(100);
      val = "0"; //so that it doesn't loop
      break;
    case 'l'://open door
      servo_9.write(100);
      delay(500);
      val = "0"; //so that it doesn't loop
      break;
    case 'm'://closed door
      servo_9.write(10);
      delay(500);
      val = "0";
      break;
      val = "0";
    case 'n'://closed window
      servo_10.write(100);
      delay(500);
      val = "0";
      break;
    case 'o'://Open window
      servo_10.write(10);
      delay(500);
      val = "0";
      break;
    case 'p'://interior yellow led on
      digitalWrite(5, HIGH);
      val = "0";
      break;
    case 'q'://interior yellow led off
      digitalWrite(5, LOW);
      val = "0";
      break;
    case 'r'://if i get the character "r"  (fan on)
      Serial.println("fan on (remote control)");
      digitalWrite(7, LOW);
      digitalWrite(6, HIGH);
      val = "0";
      break;
    case 's'://if i get the character "s"  (fan off)
      Serial.println("fan off (remote control)");
      digitalWrite(7, LOW);
      digitalWrite(6, LOW);
      val = "0";
      break;
    case '_':
      passblu = String(passblu) + String("_");//password value
      Serial.print(passblu);
      val = "0";
      break;
    case '.':
      passblu = String(passblu) + String(".");//password value
      Serial.print(passblu);
      val = "0";
      break;
    case 'v':
      Serial.print("validation code (remote control) .....");
      Serial.println(passblu);
      doorblue();
      delay(500);
      val = "0";
      break;
  }
}
