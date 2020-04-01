// libraries: https://bitbucket.org/xoseperez/fauxmoesp/src/master/
#include <WiFi.h>
#include <fauxmoESP.h>
fauxmoESP fauxmo;

const char* ssid       = "*****";
const char* password   = "*****";

void WIFI_connect() {
    Serial.printf("Connecting to %s ", ssid);
    WiFi.begin(ssid, password);
    while (WiFi.status() != WL_CONNECTED) {
        delay(500);
        Serial.print(".");
    }
    Serial.println(" CONNECTED");
}

void setup() {
  Serial.begin(115200);
  WIFI_connect();
  fauxmo.setPort(80);  
  fauxmo.enable(true);
  // ADD DEVICE: fauxmo.addDevice(devicename);  
  fauxmo.onSetState([](unsigned char device_id, const char * device_name, bool state, unsigned char value) {
   /* when alexa heard the name 
      if (strcmp(device_name, devicename) == 0) {
       
        ON   if (state) {
          
        OFF  } else {
          
        }
    }/**/
    
  }
}

void loop() {
  fauxmo.handle();

}
