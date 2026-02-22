#include <OneWire.h>
#include <DallasTemperature.h>
#include <WiFi.h>
#include <PubSubClient.h>
//------------oled display --------------
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

//---- on board GPIO ---------
#define oneWireBus 15
#define relay1 26
#define relay2 27
#define relay3 33
#define relay4 32

//------ oled display -----------------------
#define SCREEN_WIDTH 128 // OLED display width, in pixels
#define SCREEN_HEIGHT 64 // OLED display height, in pixels
// Declaration for an SSD1306 display connected to I2C (SDA, SCL pins)
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, -1);

//----ISTIHAR SENSOR SUHU DS18B20 ---------------------------------------------------------------------
OneWire oneWire(oneWireBus);
DallasTemperature sensors(&oneWire);
//----------------------------------- end -------------------------------------------------------------

//----------- wifi and Broker -------------------------
//------perlu ubah nama wifi dan password --------------
//const char* ssid = "Kimz";
//const char* password = "hakim123";

//const char* ssid = "COT Hotspot";
//const char* password = "cotjkm#ptsb";

const char* ssid = "JKM M.LOJI";
const char* password = "loji@ptsb";

//------------------------------------------------------

const char* mqtt_server = "broker.hivemq.com";

WiFiClient espClient;
PubSubClient client(espClient);

//-------- Data variable
long lastMsg = 0;
char msg[50];
int value = 0;
String AzaText;
char dataPotString[8];
float temperatureC;

//---- pembolehubah memori data tersimpan dari bacaan sensor ------

float tempC;


void setup() {
pinMode(relay1,OUTPUT); 
pinMode(relay2,OUTPUT); 
pinMode(relay3,OUTPUT); 
pinMode(relay4,OUTPUT); 


Serial.begin(115200);
 
if(!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) { // Address 0x3D for 128x64
    Serial.println(F("SSD1306 allocation failed"));
    for(;;);
  }

  setup_wifi();
  client.setServer(mqtt_server, 1883);
  client.setCallback(callback);

  sensors.begin();
    
}

void loop() {

  if (!client.connected()) {
    reconnect();
  }
  client.loop();

 long now = millis();
  
  if (now - lastMsg > 2000) {  
      lastMsg = now;

//----sensor 1-----------------------------------
sensorTemp();


//----coding for OLED screen-----------------------------------
    display.clearDisplay();
    display.setCursor(0,0);
    display.println("MUSHROOM MONITORING");
    display.setTextSize(1);
    display.setTextColor(WHITE,BLACK);

      display.setCursor(0,20);
    display.print("TEMPERATURE:");
    display.print(tempC,1);
    display.print(" C");
  display.display();

      
  }
}