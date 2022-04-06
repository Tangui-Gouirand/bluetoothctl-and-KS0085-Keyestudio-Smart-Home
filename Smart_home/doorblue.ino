void doorblue() {
  if (passblu.length() == 6) {
    if (passblu == ".__._.") { //if the code is :  .__._.
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
      passblu = "";
      mylcd.clear();//we clear the display
      mylcd.setCursor(1 - 1, 1 - 1);//position on LCD screen
      mylcd.print("mot de passe:");//LCD screen writing
    }
    else { //otherwise it's not the desired code so
      Serial.println(" Code mauvais");//serial monitor display
      mylcd.clear(); //we clear the display
      mylcd.setCursor(1 - 1, 1 - 1);//position on LCD screen
      mylcd.print("erreur!");//LCD screen writing
      tone(3, 340);    //
      delay(500);      //
      tone(3, 100);    // sound, error
      delay(500);      //
      noTone(3);       //
      passblu = "";
      delay(1000);
      mylcd.setCursor(1 - 1, 1 - 1);//position sur ecran LCD
      mylcd.print("refaire");//LCD screen writing
    }
  }
  else {
    Serial.println(" Code mauvais");//serial monitor display
    mylcd.clear(); //we clear the display
    mylcd.setCursor(1 - 1, 1 - 1);//position on LCD screen
    mylcd.print("erreur!");//LCD screen writing
    tone(3, 340);    //
    delay(500);      //
    tone(3, 100);    // sound, error
    delay(500);      //
    noTone(3);       //
    passblu = "";
    delay(1000);
    mylcd.setCursor(1 - 1, 1 - 1);//position on LCD screen
    mylcd.print("refaire");//LCD screen writing
    return;
  }
}
