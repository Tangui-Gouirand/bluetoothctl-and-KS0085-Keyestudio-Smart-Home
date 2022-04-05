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
  switch (val) {//pour la telecommande bluetooth
    case 'a':
      digitalWrite(13, HIGH);
      val = "0";
      break;
    case 'b':
      digitalWrite(13, LOW);
      val = "0";
      break;
    case 'c':
      digitalWrite(12, HIGH);
      val = "0";
      break;
    case 'd':
      digitalWrite(12, LOW);
      val = "0";
      break;
    case 'e'://lancer musique 1
      music1();
      val = "0";
      break;
    case 'f'://lancer musique 2
      music2();
      val = "0";
      break;
    case 'g'://arreter musique
      noTone(3);
      val = "0";
      break;
    case 'h'://retourner valeur luminosité
      Serial.print("valeur capteur de luminosité = ");
      Serial.println(light);
      delay(100);
      val = "0";
      break;
    case 'i'://retourner valeur gaz
      Serial.print("valeur capteur de gaz = ");
      Serial.println(gas);
      delay(100);
      val = "0";
      break;
    case 'j'://retourner valeur humidite sol
      Serial.print("valeur humidite sol = ");
      Serial.println(sol);
      delay(100);
      val = "0";
      break;
    case 'k'://retourner valeur eau
      Serial.print("valeur capteur d'eau = ");
      Serial.println(water);
      delay(100);
      val = "0";
      break;
    case 'l'://porte ouverte
      servo_9.write(100);
      delay(500);
      val = "0";
      break;
    case 'm'://porte fermé
      servo_9.write(10);
      delay(500);
      val = "0";
      break;
      val = "0";
    case 'n'://fenetre fermé
      servo_10.write(100);
      delay(500);
      val = "0";
      break;
    case 'o'://fenetre ouverte
      servo_10.write(10);
      delay(500);
      val = "0";
      break;
    case 'p'://led jaune interieur allumé
      digitalWrite(5, HIGH);
      val = "0";
      break;
    case 'q'://led jaune interieur éteint
      digitalWrite(5, LOW);
      val = "0";
      break;
    case 'r'://ventilateur allumé
      Serial.println("ventilateur allumé (télécommande)");
      digitalWrite(7, LOW);
      digitalWrite(6, HIGH);
      val = "0";
      break;
    case 's'://ventilateur éteint
      Serial.println("ventilateur éteint (télécommande)");
      digitalWrite(7, LOW);
      digitalWrite(6, LOW);
      val = "0";
      break;


    case '_':
      passblu = String(passblu) + String("_");//valeur du mdp
      Serial.print(passblu);
      val = "0";
      break;
    case '.':
      passblu = String(passblu) + String(".");//valeur du mdp
      Serial.print(passblu);
      val = "0";
      break;
    case 'v':
      Serial.print("validation code (télécommande) .....");
      Serial.println(passblu);
      doorblue();
      delay(500);
      val = "0";
      break;

  }
}
