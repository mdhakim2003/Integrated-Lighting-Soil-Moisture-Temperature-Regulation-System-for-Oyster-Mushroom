
  void sensorSoil() {

    dataSoil = analogRead(35);
    dataSoil_percentage = map(dataSoil, 3500, 2623, 0, 100);
    Serial.println(dataSoil_percentage);


   dtostrf(dataSoil_percentage,1,2,dataPotString);
   Serial.print("bacaan soil : ");
   Serial.println("data :");
   client.publish("Kimz/soil",dataPotString);
  }

  void sensorSoil_2() {

    dataSoil2 = analogRead(34);
    dataSoil_percentage2 = map(dataSoil2, 4000, 2623, 0, 100);
    Serial.println(dataSoil_percentage2);

   dtostrf(dataSoil_percentage2,1,2,dataPotString);
   Serial.print("bacaan soil 2 : ");
   Serial.println("data :");
   client.publish("Kimz/soil2",dataPotString);
  }