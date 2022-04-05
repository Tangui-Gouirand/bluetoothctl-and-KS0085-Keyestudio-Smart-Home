void auto_sensor() {

  //----capteur gaz ---------
  gas = analogRead(A0);//on prend la valeur du capteur de gaz
  if (gas > 1000) {//si la valeur du capteur dde gaz et au dessus de 1000
    flag = 1;
    while (flag == 1) {
      Serial.println("GAZ");//pour le moniteur serie
      mylcd.clear();//on efface l'affichage
      mylcd.setCursor(1 - 1, 1 - 1);//position sur ecran LCD
      mylcd.print("DANGER GAZ");//ecriture ecran LCD
      Serial.println("DANGER GAZ");//affichage moniteur serie
      tone(3, 440);    //
      delay(125);      //
      delay(100);      //
      noTone(3);       //
      delay(100);      //
      tone(3, 440);    // son danger gaz
      delay(125);      //
      delay(100);      //
      noTone(3);       //
      delay(300);      //
      gas = analogRead(A0);//on prend une nouvelle valeur du capteur de gaz
      if (gas < 10) {//si le gaz et en dessous de 10
        flag = 0;
        mylcd.clear();//on efface l'affichage
        mylcd.setCursor(1 - 1, 1 - 1);//position sur ecran LCD
        mylcd.print("mot de passe:");//ecriture ecran LCD
        break;//on sort de la boucle while
      }
    }
  }
  else {
    noTone(3);
  }
  //------------------------------

  //----capteur mouvement de nuit----------
  light = analogRead(A1);//valeur de la luminositée
  if (light < 300) { //si la luminonosité et inferieur à 300 donc si il fait nuit
    Serial.println("Il fait nuit");//affichage moniteur serie
    infrar = digitalRead(2); //si =1 c'est qu'il y 'a un mouvement
    //Serial.println(infrar);//pour le moniteur serie
    if (infrar == 1) { //si il y a un mouvement
      digitalWrite(13, HIGH); //on allume la lumiere
      mylcd.clear();//on efface l'affichage
      mylcd.setCursor(1 - 1, 1 - 1);//position sur ecran LCD
      mylcd.print("BONSOIR");//ecriture ecran LCD
      delay(200);
      infrar = digitalRead(2);//on prend une nouvelle valeur du capteur de mouvement
    }
    else {//sinon c'est qu'il y a pas de mouvement
      digitalWrite(13, LOW);//on eteint la lumiere
      mylcd.clear();//on efface l'affichage
      infrar = digitalRead(2);//on prend une nouvelle valeur du capteur de mouvement
    }
  }
  else {//sinon c'est qu'il fait jour
    digitalWrite(13, LOW);//on eteint la lumiere
    mylcd.setCursor(1 - 1, 1 - 1);//position sur ecran LCD
    mylcd.print("mot de passe:");//ecriture ecran LCD
    infrar = digitalRead(2);//on prend une nouvelle valeur du capteur de mouvement
  }
  //------------------------------


  //----capteur de pluie ----------
  water = analogRead(A3);//valeur du capteur d'eau
  if (water > 800) {//si la valeur du capteur et au dessus de 800
    flag2 = 1;
    while (flag2 == 1) {
      Serial.println("il pleut");//pour le moniteur serie
      servo_10.write(10);//on ouvre la fenetre
      delay(500);//on attend 500ms
      water = analogRead(A3);//on prend un nouvelle valeur
      if (water < 30) {//si la valeur du capteur et en dessous de 30
        flag2 = 0;
        break;//on sort de la boucle while
      }
    }
  }
  else {
    if (val != 'u' && val != 'n') {
      servo_10.write(100);//on referme la fenetre
      delay(10);
    }
  }
  //------------------------------

  //----capteur humidité plante ----------
  sol = analogRead(A2);//valeur du capteur d'humidité
  if (sol > 50) { //si l'humidité du sol et au dessus de 50
    flag3 = 1;
    while (flag3 == 1) {
      Serial.println("sol trop humide ");//pour le moniteur serie
      mylcd.clear(); //on efface l'affichage
      mylcd.setCursor(1 - 1, 1 - 1);//position sur ecran LCD
      mylcd.print("sol trop humide");//ecriture ecran LCD
      tone(3, 440);     //
      delay(200);       //
      noTone(3);        //
      delay(100);       //
      tone(3, 440);     // son danger gaz
      delay(200);       //
      noTone(3);        //
      delay(300);       //
      sol = analogRead(A2);//nouvelle valeur du capteur d'humidite
      if (sol < 10) {//si l'humidité du sol et en dessous de 10
        flag3 = 0;
        mylcd.clear();//on efface l'affichage
        mylcd.setCursor(1 - 1, 1 - 1);//position sur ecran LCD
        mylcd.print("mot de passe:");//ecriture ecran LCD
        break;//on sort de la boucle while
      }
    }
  }
  else {
    noTone(3);
  }
  //------------------------------
  door();
}
