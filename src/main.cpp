#include <Arduino.h>
#include <ESP8266WiFi.h>
#include <ESP8266mDNS.h>
#include <WiFiUdp.h>
#include <ProcessScheduler.h>
#include "./tasks/WebServerProcess.cpp"
#include "./tasks/WebSocketServerProcess.cpp"
#include "./tasks/SensorsProcess.cpp"
#include "config.h"

Scheduler sched;

//////////////////////
// WiFi Definitions //
//////////////////////
const char WiFiAPPSK[] = "kalambur";

void setupWiFiAP(){
  WiFi.mode(WIFI_AP);

  // Do a little work to get a unique-ish name. Append the
  // last two bytes of the MAC (HEX'd) to "Thing-":
  uint8_t mac[WL_MAC_ADDR_LENGTH];
  WiFi.softAPmacAddress(mac);
  String macID = String(mac[WL_MAC_ADDR_LENGTH - 2], HEX) +
                 String(mac[WL_MAC_ADDR_LENGTH - 1], HEX);
  macID.toUpperCase();
  String AP_NameString = "ESP8266 WIFI" + macID;

  char AP_NameChar[AP_NameString.length() + 1];
  memset(AP_NameChar, 0, AP_NameString.length() + 1);

  for (int i=0; i<AP_NameString.length(); i++)
    AP_NameChar[i] = AP_NameString.charAt(i);

  WiFi.softAP(AP_NameChar, WiFiAPPSK);
}

void setupWifiClient(){
  const char* ssid = "MySpace";//"Andrewhous";
  const char* password = "Vfhnty1234";//"1234567891111";
//  const char* ssid = "MEIZU";//"Andrewhous";
//  const char* password = "1234567890asd";//"1234567891111";

  WiFi.mode(WIFI_STA);
  WiFi.begin(ssid, password);
  while (WiFi.waitForConnectResult() != WL_CONNECTED) {
    Serial.println("Connection Failed! Rebooting...");
    delay(5000);
    ESP.restart();
  }
}
WebServerProcess webServer(sched, HIGH_PRIORITY,250);
WebSocketServerProcess webSocketServer(sched, HIGH_PRIORITY,250);
SensorsProcess sensorsProcess(sched, HIGH_PRIORITY,3000, &webSocketServer);

void setup() {
  Serial.begin(115200);
  //setupWiFiAP();
  setupWifiClient();
  delay(1000);
  Serial.println(WiFi.localIP());
  webServer.add(true);
  webSocketServer.add(true);
  sensorsProcess.add(true);
}
void loop() {
  sched.run();
}
