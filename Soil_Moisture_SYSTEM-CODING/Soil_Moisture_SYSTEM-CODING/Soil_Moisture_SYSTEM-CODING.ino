#include <WiFi.h>
#include <PubSubClient.h>
//------------oled display --------------
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

//---- on board GPIO ---------
#define oneWireBus 15


//------ oled display -----------------------
#define SCREEN_WIDTH 128 // OLED display width, in pixels
#define SCREEN_HEIGHT 64 // OLED display height, in pixels
// Declaration for an SSD1306 display connected to I2C (SDA, SCL pins)
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, -1);


//----------------------------------- end -------------------------------------------------------------

//----------- wifi and Broker -------------------------
//------perlu ubah nama wifi dan password --------------
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
int dataSoil;
float dataSoil_percentage;
int dataSoil2;
float dataSoil_percentage2;

void setup() {


Serial.begin(115200);
 
if(!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) { // Address 0x3D for 128x64
    Serial.println(F("SSD1306 allocation failed"));
    for(;;);
  }

  setup_wifi();
  client.setServer(mqtt_server, 1883);
  client.setCallback(callback);
    
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

sensorSoil();
sensorSoil_2();

//----coding for OLED screen-----------------------------------
    display.clearDisplay();
    display.setCursor(0,0);
    display.println("MUSHROOM MONITORING");
    display.setTextSize(1);
    display.setTextColor(WHITE,BLACK);

      display.setCursor(0,20);
    display.print("MOISTURE 1:");
    display.print(dataSoil_percentage);
    display.print("%");
    display.display();

     display.setCursor(0,30);
    display.print("MOISTURE 2:");
    display.print(dataSoil_percentage2);
    display.print("%");
    display.display();
      
  }
}
