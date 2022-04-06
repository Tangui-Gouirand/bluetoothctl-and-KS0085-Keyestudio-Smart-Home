void door() {
  button1 = digitalRead(4);
  button2 = digitalRead(8);
  if (button1 == 0) {
    delay(10);
    while (button1 == 0) {
      button1 = digitalRead(4);
      btn1_num = btn1_num + 1;
      delay(100);
    }
  }
  if (btn1_num >= 1 && btn1_num < 5) {//if short press on button 1
    Serial.print(".");//serial monitor display
    passwd = String(passwd) + String(".");//password value
    pass = String(pass) + String("."); //for screen display on LCD
    mylcd.setCursor(1 - 1, 2 - 1); //position on LCD screen
    mylcd.print(pass);//writing on LCD screen
  }
  if (btn1_num >= 5) {//if long press on button 1
    Serial.print("-");//serial monitor display
    passwd = String(passwd) + String("_"); //password value
    pass = String(pass) + String("_"); //for screen display on LCD
    mylcd.setCursor(1 - 1, 2 - 1);//position on LCD screen
    mylcd.print(pass);//writing on LCD screen
  }

  if (button2 == 0) { //if the validate button is pressed
    delay(10);
    if (passwd == ".__._.") { //if the password is :  .__._.
      Serial.println("  Code Bon");//serial monitor display
      tone(3, 100);
      delay(500);
      noTone(3);
      mylcd.clear(); //we clear the display
      mylcd.setCursor(1 - 1, 1 - 1);//position on LCD screen
      mylcd.print("ouvert!");//we display open on the screen
      servo_9.write(100);//activate the door motor

      afficagecr = 5;
      COMPTEREBOUR = 0; //a 5 sec countdown is displayed
      while (COMPTEREBOUR < 5) {
        mylcd.setCursor(1 - 1, 2 - 1);//position on LCD screen
        afficagecr = int(afficagecr) - 1;
        mylcd.print(afficagecr);
        delay(1000);
        COMPTEREBOUR += 1;
      }
      passwd = "";
      pass = "";
      mylcd.clear();
      mylcd.setCursor(1 - 1, 1 - 1);//position on LCD screen
      mylcd.print("mot de passe:");//LCD screen writing
    }
    else { //otherwise it is not the desired code so :
      Serial.println(" Code mauvais");//serial monitor display
      mylcd.clear(); //we clear the display
      mylcd.setCursor(1 - 1, 1 - 1);//position on LCD screen
      mylcd.print("erreur!");//LCD screen writing
      tone(3, 340);    //
      delay(500);      //
      tone(3, 100);    // sound, error
      delay(500);      //
      noTone(3);       //
      passwd = "";
      pass = "";
      delay(1000);
      mylcd.setCursor(1 - 1, 1 - 1);//position on LCD screen
      mylcd.print("refaire");//LCD screen writing
    }
  }
  btn1_num = 0;
  btn2_num = 0;

  infrar = digitalRead(2);
  if (infrar == 0 && (val != 'l' && val != 't')) {
    servo_9.write(0);
    delay(50);
  }
}
