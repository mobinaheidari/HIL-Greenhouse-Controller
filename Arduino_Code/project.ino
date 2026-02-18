#include <DHT.h>
#include <WiFi.h>

#define DHTPIN 4
#define DHTTYPE DHT22
DHT dht(DHTPIN, DHTTYPE);

#define RED_LED 5    
#define BLUE_LED 18  

const char* ssid = "HIL_Project_WiFi";   
const char* password = "12345678";       

WiFiServer server(80); 


unsigned long previousMillis = 0;
const long interval = 2000; 

void setup() {

  Serial.begin(115200);
  
  dht.begin();
  pinMode(RED_LED, OUTPUT);
  pinMode(BLUE_LED, OUTPUT);

  WiFi.softAP(ssid, password);
  
  IPAddress myIP = WiFi.softAPIP();
  
  Serial.print("AP IP address: ");
  Serial.println(myIP); 
  
  server.begin();
}

void loop() {
  WiFiClient client = server.available();

  if (client) {

    while (client.connected()) {
      

      unsigned long currentMillis = millis();
      
      if (currentMillis - previousMillis >= interval) {
        previousMillis = currentMillis; 


        float temp = dht.readTemperature();
        if (isnan(temp)) temp = 0.0; 
        

        client.write('A'); 
        client.write((uint8_t*)&temp, 4); 
        client.write('Z');
        
      
        Serial.write('A'); 
        Serial.write((uint8_t*)&temp, 4); 
        Serial.write('Z');
      }

    
      if (client.available()) {
        char command = client.read();
        if (command == 'H' || command == 'C' || command == 'O') {
             controlActuators(command);
        }
      }
      

      delay(5); 
    }
    
    client.stop();
  }
}

void controlActuators(char cmd) {
  if (cmd == 'H') {         
    digitalWrite(RED_LED, HIGH);
    digitalWrite(BLUE_LED, LOW);
  } else if (cmd == 'C') {  
    digitalWrite(RED_LED, LOW);
    digitalWrite(BLUE_LED, HIGH);
  } else if (cmd == 'O') {  
    digitalWrite(RED_LED, LOW);
    digitalWrite(BLUE_LED, LOW);
  }
}