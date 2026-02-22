void sensorTemp(void)
{ 

  sensors.requestTemperatures(); 
  tempC = sensors.getTempCByIndex(0);
   Serial.println(tempC);
   //delay(1000);

   dtostrf(tempC,1,2,dataPotString);
   Serial.print("bacaan suhu : ");
   Serial.println("tempC");
   client.publish("Hakimz/DS18B20",dataPotString);

  }
