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
  if (btn1_num >= 1 && btn1_num < 5) {//si appui court sur bouton 1
    Serial.print(".");//affichage moniteur serie
    passwd = String(passwd) + String(".");//valeur du mdp
    pass = String(pass) + String("."); //pour affichage ecran LCD
    mylcd.setCursor(1 - 1, 2 - 1); //position sur ecran LCD
    mylcd.print(pass);//ecriture ecran LCD
  }
  if (btn1_num >= 5) {//si appui long sur bouton 1
    Serial.print("-");//affichage moniteur serie
    passwd = String(passwd) + String("_"); //valeur du mdp
    pass = String(pass) + String("_"); //pour affichage ecran LCD
    mylcd.setCursor(1 - 1, 2 - 1);//position sur ecran LCD
    mylcd.print(pass);//ecriture ecran LCD
  }

  if (button2 == 0) { //si le bouton valider est appuyé
    delay(10);
    if (passwd == ".__._.") { //si le code est :  .__._.
      Serial.println("  Code Bon");//affichage moniteur serie
      tone(3, 100);
      delay(500);
      noTone(3);
      mylcd.clear(); //on efface l'affichage
      mylcd.setCursor(1 - 1, 1 - 1);//position sur ecran LCD
      mylcd.print("ouvert!");//on affiche ouvert sur l'ecran
      servo_9.write(100);//on active le moteur de la porte

      afficagecr = 5;
      COMPTEREBOUR = 0; //on affiche un compte à rebours de 5sec
      while (COMPTEREBOUR < 5) {
        mylcd.setCursor(1 - 1, 2 - 1);//position sur ecran LCD
        afficagecr = int(afficagecr) - 1;
        mylcd.print(afficagecr);
        delay(1000);
        COMPTEREBOUR += 1;
      }
      passwd = "";
      pass = "";
      mylcd.clear();
      mylcd.setCursor(1 - 1, 1 - 1);//position sur ecran LCD
      mylcd.print("mot de passe:");//ecriture ecran LCD
    }
    else { //sinon c'est pas le code voulu donc
      Serial.println(" Code mauvais");//affichage moniteur seri
      mylcd.clear(); //on efface l'affichage
      mylcd.setCursor(1 - 1, 1 - 1);//position sur ecran LCD
      mylcd.print("erreur!");//ecriture ecran LCD
      tone(3, 340);    //
      delay(500);      //
      tone(3, 100);    // son erreur
      delay(500);      //
      noTone(3);       //
      passwd = "";
      pass = "";
      delay(1000);
      mylcd.setCursor(1 - 1, 1 - 1);//position sur ecran LCD
      mylcd.print("refaire");//ecriture ecran LCD
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
