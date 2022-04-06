void auto_sensor() {

  //----gas sensor ---------
  gas = analogRead(A0);//we take the value of the gas sensor
  if (gas > 1000) {//if the gas sensor value and above 1000
    flag = 1;
    while (flag == 1) {
      Serial.println("GAZ");//for serial monitor
      mylcd.clear();//we clear the display
      mylcd.setCursor(1 - 1, 1 - 1);//position on LCD screen
      mylcd.print("DANGER GAZ");//LCD screen writing
      Serial.println("DANGER GAZ");//serial monitor display
      tone(3, 440);    //
      delay(125);      //
      delay(100);      //
      noTone(3);       //
      delay(100);      //
      tone(3, 440);    // sound, gas hazard
      delay(125);      //
      delay(100);      //
      noTone(3);       //
      delay(300);      //
      gas = analogRead(A0);//we take a new value from the gas sensor
      if (gas < 10) {//if the gas value is below 10
        flag = 0;
        mylcd.clear();//we clear the display
        mylcd.setCursor(1 - 1, 1 - 1);//position on LCD screen
        mylcd.print("mot de passe:");//LCD screen writing
        break;//exit the while loop
      }
    }
  }
  else {
    noTone(3);
  }
  //------------------------------

  //----night motion sensor----------
  light = analogRead(A1);//brightness value
  if (light < 300) { //if the luminosity is lower than 300 so if it is dark
    Serial.println("Il fait nuit");//serial monitor display
    infrar = digitalRead(2); //if =1 it is that there is a movement
    //Serial.println(infrar);//for serial monitor
    if (infrar == 1) { //if there is a movement
      digitalWrite(13, HIGH); //we turn on the light
      mylcd.clear();//we clear the display
      mylcd.setCursor(1 - 1, 1 - 1);//position on LCD screen
      mylcd.print("BONSOIR");//LCD screen writing
      delay(200);
      infrar = digitalRead(2);//we take a new value from the motion sensor
    }
    else {//otherwise there is no movement
      digitalWrite(13, LOW);//we turn off the light
      mylcd.clear();//we clear the display
      infrar = digitalRead(2);//we take a new value from the motion sensor
    }
  }
  else {//otherwise it's daytime
    digitalWrite(13, LOW);//we turn off the light
    mylcd.setCursor(1 - 1, 1 - 1);//position on LCD screen
    mylcd.print("mot de passe:");//LCD screen writing
    infrar = digitalRead(2);//we take a new value from the motion sensor
  }
  //------------------------------


  //----rain sensor ----------
  water = analogRead(A3);//water sensor value
  if (water > 800) {//if the sensor value is above 800
    flag2 = 1;
    while (flag2 == 1) {
      Serial.println("il pleut");//for serial monitor
      servo_10.write(10);//we open the window
      delay(500);//we wait 500ms
      water = analogRead(A3);//we take a new value
      if (water < 30) {//if the sensor value and below 30
        flag2 = 0;
        break;//exit the while loop
      }
    }
  }
  else {
    if (val != 'u' && val != 'n') {
      servo_10.write(100);//we close the window
      delay(10);
    }
  }
  //------------------------------

  //----plant humidity sensor----------
  sol = analogRead(A2);//humidity sensor value
  if (sol > 50) { //if soil moisture and above 50
    flag3 = 1;
    while (flag3 == 1) {
      Serial.println("sol trop humide ");//for serial monitor
      mylcd.clear(); //we clear the display
      mylcd.setCursor(1 - 1, 1 - 1);//position on LCD screen
      mylcd.print("sol trop humide");//LCD screen writing
      tone(3, 440);     //
      delay(200);       //
      noTone(3);        //
      delay(100);       //
      tone(3, 440);     // sound, gas hazard
      delay(200);       //
      noTone(3);        //
      delay(300);       //
      sol = analogRead(A2);//new humidity sensor value
      if (sol < 10) {//if soil moisture and below 10
        flag3 = 0;
        mylcd.clear();//we clear the display
        mylcd.setCursor(1 - 1, 1 - 1);//position on LCD screen
        mylcd.print("mot de passe:");//LCD screen writing
        break;//exit the while loop
      }
    }
  }
  else {
    noTone(3);
  }
  //------------------------------
  door();
}
