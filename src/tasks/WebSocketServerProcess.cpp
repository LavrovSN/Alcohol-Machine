#ifndef _WEB_SOCKET_SERVER_PROCESS_
#define _WEB_SOCKET_SERVER_PROCESS_
#include <ProcessScheduler.h>
#include <WebSocketsServer.h>
#include <Hash.h>
#include <EEPROM.h>
#include <ArduinoJson.h>

struct config_t
{
    byte heatingStateTemp1Min;
    byte heatingStateTemp1Max;
    byte heatingStateTemp2Min;
    byte heatingStateTemp2Max;
    bool heatingStateMainPower;
    bool heatingStateAddPower;
    byte onFirstStateTemp1Min;
    byte onFirstStateTemp1Max;
    byte onFirstStateTemp2Min;
    byte onFirstStateTemp2Max;
    bool onFirstStateMainPower;
    bool onFirstStateAddPower;
    byte onSecondStateTemp1Min;
    byte onSecondStateTemp1Max;
    byte onSecondStateTemp2Min;
    byte onSecondStateTemp2Max;
    bool onSecondStateMainPower;
    bool onSecondStateAddPower;
    byte onThirdStateTemp1Min;
    byte onThirdStateTemp1Max;
    byte onThirdStateTemp2Min;
    byte onThirdStateTemp2Max;
    bool onThirdStateMainPower;
    bool onThirdStateAddPower;
    byte crashStateTemp1Min;
    byte crashStateTemp1Max;
    byte crashStateTemp2Min;
    byte crashStateTemp2Max;
};

class WebSocketServerProcess : public Process
{
  friend class SensorsProcess;
public:
    WebSocketsServer * webSocket;

    // Call the Process constructor
    WebSocketServerProcess(Scheduler &manager, ProcPriority pr, unsigned int period, const int port = 81)
        :  Process(manager, pr, period)
        {
          webSocket = new WebSocketsServer(port);
        }
    ~WebSocketServerProcess(){
        delete webSocket;
    }
    config_t cfg;
    //config_t cfg;

protected:
    config_t getParams(){
      return cfg;
    }
    virtual void setup()
    {
      webSocket->begin();
      webSocket->onEvent([this](uint8_t num, WStype_t type, uint8_t * payload, size_t lenght){webSocketEvent(num,type,payload,lenght);});

      //EEPROM.begin(4096);
      Serial.println("WebSocketServerProcess started");

    }

     // Undo setup()
    virtual void cleanup()
    {

    }

    // Create our service routine
    virtual void service()
    {
       webSocket->loop();
    }
private:
  void webSocketEvent(uint8_t num, WStype_t type, uint8_t * payload, size_t lenght) {
      String command = (char*)payload;
      switch(type) {
          case WStype_DISCONNECTED:
              Serial.printf("[%u] Disconnected!\n", num);
              break;
          case WStype_CONNECTED:
              {
                  IPAddress ip = webSocket->remoteIP(num);
                  Serial.printf("[%u] Connected from %d.%d.%d.%d url: %s\n", num, ip[0], ip[1], ip[2], ip[3], payload);

          				// send message to client
                  EEPROM.begin (512);
                  //config_t cfg;
                  EEPROM.get(0, cfg);
                  EEPROM.end();
                  char JSON[1024];
                  sprintf(JSON,"{\"heatingStateTemp1Min\":%d,\"heatingStateTemp1Max\":%d,\"heatingStateTemp2Min\":%d,\"heatingStateTemp2Max\":%d,\"heatingStateMainPower\":%d,\"heatingStateAddPower\":%d,\"onFirstStateTemp1Min\":%d,\"onFirstStateTemp1Max\":%d,\"onFirstStateTemp2Min\":%d,\"onFirstStateTemp2Max\":%d,\"onFirstStateMainPower\":%d,\"onFirstStateAddPower\":%d,\"onSecondStateTemp1Min\":%d,\"onSecondStateTemp1Max\":%d,\"onSecondStateTemp2Min\":%d,\"onSecondStateTemp2Max\":%d,\"onSecondStateMainPower\":%d,\"onSecondStateAddPower\":%d,\"onThirdStateTemp1Min\":%d,\"onThirdStateTemp1Max\":%d,\"onThirdStateTemp2Min\":%d,\"onThirdStateTemp2Max\":%d,\"onThirdStateMainPower\":%d,\"onThirdStateAddPower\":%d,\"crashStateTemp1Min\":%d,\"crashStateTemp1Max\":%d,\"crashStateTemp2Min\":%d,\"crashStateTemp2Max\":%d}",cfg.heatingStateTemp1Min,cfg.heatingStateTemp1Max,cfg.heatingStateTemp2Min,cfg.heatingStateTemp2Max,cfg.heatingStateMainPower,cfg.heatingStateAddPower,cfg.onFirstStateTemp1Min,cfg.onFirstStateTemp1Max,cfg.onFirstStateTemp2Min,cfg.onFirstStateTemp2Max,cfg.onFirstStateMainPower,cfg.onFirstStateAddPower,cfg.onSecondStateTemp1Min,cfg.onSecondStateTemp1Max,cfg.onSecondStateTemp2Min,cfg.onSecondStateTemp2Max,cfg.onSecondStateMainPower,cfg.onSecondStateAddPower,cfg.onThirdStateTemp1Min,cfg.onThirdStateTemp1Max,cfg.onThirdStateTemp2Min,cfg.onThirdStateTemp2Max,cfg.onThirdStateMainPower,cfg.onThirdStateAddPower,cfg.crashStateTemp1Min,cfg.crashStateTemp1Max,cfg.crashStateTemp2Min,cfg.crashStateTemp2Max);
                  webSocket->sendTXT(num, (char*)&JSON);
              }
              break;
          case WStype_TEXT:
            if (command == "Stop"){
              Serial.println("Чтение объекта...");
              EEPROM.begin (512);
              config_t tcfg;
              EEPROM.get(0, tcfg);
              EEPROM.end();
            } else if (command == "Start"){
              Serial.println("Starting...");
            } else{
              Serial.println("Прием параметров...");
              Serial.println(command);
              StaticJsonBuffer<2048> jsonBuffer;
              JsonObject& root = jsonBuffer.parseObject(command);
              cfg.heatingStateTemp1Min = root["heatingStateTemp1Min"];
              cfg.heatingStateTemp1Max = root["heatingStateTemp1Max"];
              cfg.heatingStateTemp2Min = root["heatingStateTemp2Min"];
              cfg.heatingStateTemp2Max = root["heatingStateTemp2Max"];
              cfg.heatingStateMainPower = root["heatingStateMainPower"];
              cfg.heatingStateAddPower = root["heatingStateAddPower"];
              cfg.onFirstStateTemp1Min = root["onFirstStateTemp1Min"];
              cfg.onFirstStateTemp1Max = root["onFirstStateTemp1Max"];
              cfg.onFirstStateTemp2Min = root["onFirstStateTemp2Min"];
              cfg.onFirstStateTemp2Max = root["onFirstStateTemp2Max"];
              cfg.onFirstStateMainPower = root["onFirstStateMainPower"];
              cfg.onFirstStateAddPower = root["onFirstStateAddPower"];
              cfg.onSecondStateTemp1Min = root["onSecondStateTemp1Min"];
              cfg.onSecondStateTemp1Max = root["onSecondStateTemp1Max"];
              cfg.onSecondStateTemp2Min = root["onSecondStateTemp2Min"];
              cfg.onSecondStateTemp2Max = root["onSecondStateTemp2Max"];
              cfg.onSecondStateMainPower = root["onSecondStateMainPower"];
              cfg.onSecondStateAddPower = root["onSecondStateAddPower"];
              cfg.onThirdStateTemp1Min = root["onThirdStateTemp1Min"];
              cfg.onThirdStateTemp1Max = root["onThirdStateTemp1Max"];
              cfg.onThirdStateTemp2Min = root["onThirdStateTemp2Min"];
              cfg.onThirdStateTemp2Max = root["onThirdStateTemp2Max"];
              cfg.onThirdStateMainPower = root["onThirdStateMainPower"];
              cfg.onThirdStateAddPower = root["onThirdStateAddPower"];
              cfg.crashStateTemp1Min = root["crashStateTemp1Min"];
              cfg.crashStateTemp1Max = root["crashStateTemp1Max"];
              cfg.crashStateTemp2Min = root["crashStateTemp2Min"];
              cfg.crashStateTemp2Max = root["crashStateTemp2Max"];
              root.printTo(Serial);
              Serial.println(cfg.crashStateTemp1Min);
              Serial.println("Запись объекта...");
              EEPROM.begin (512);
              EEPROM.put(0, cfg);
              EEPROM.end();
              //Serial.println("Отправка параметров...");
              //sendParams(num, cfg);
            }
            webSocket->broadcastTXT((char*)payload);
            break;

            // send message to client
            //webSocket->sendTXT(num, payload);

            // send data to all connected clients

          case WStype_BIN:
              Serial.printf("[%u] get binary lenght: %u\n", num, lenght);
              hexdump(payload, lenght);

              // send message to client
              // webSocket.sendBIN(num, payload, lenght);
              break;
      }

  }
};
#endif
