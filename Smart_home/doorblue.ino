void doorblue() {
  if (passblu.length() == 6) {
    if (passblu == ".__._.") { //si le code est :  .__._.
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
      passblu = "";
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
      passblu = "";
      delay(1000);
      mylcd.setCursor(1 - 1, 1 - 1);//position sur ecran LCD
      mylcd.print("refaire");//ecriture ecran LCD
    }
  }
  else {
    Serial.println(" Code mauvais");//affichage moniteur seri
    mylcd.clear(); //on efface l'affichage
    mylcd.setCursor(1 - 1, 1 - 1);//position sur ecran LCD
    mylcd.print("erreur!");//ecriture ecran LCD
    tone(3, 340);    //
    delay(500);      //
    tone(3, 100);    // son erreur
    delay(500);      //
    noTone(3);       //
    passblu = "";
    delay(1000);
    mylcd.setCursor(1 - 1, 1 - 1);//position sur ecran LCD
    mylcd.print("refaire");//ecriture ecran LCD
    return;
  }
}
