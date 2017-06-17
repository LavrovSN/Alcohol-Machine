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
    config_t getParams(){
      return cfg;
    }

protected:
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
                  config_t scfg;
                  EEPROM.get(0, scfg);
                  EEPROM.end();
                  char JSON[1024];
                  Serial.println("Отправка объекта...");
                  sprintf(JSON,"{\"heatingStateTemp1Min\":%d,\"heatingStateTemp1Max\":%d,\"heatingStateTemp2Min\":%d,\"heatingStateTemp2Max\":%d,\"heatingStateMainPower\":%d,\"heatingStateAddPower\":%d,\"onFirstStateTemp1Min\":%d,\"onFirstStateTemp1Max\":%d,\"onFirstStateTemp2Min\":%d,\"onFirstStateTemp2Max\":%d,\"onFirstStateMainPower\":%d,\"onFirstStateAddPower\":%d,\"onSecondStateTemp1Min\":%d,\"onSecondStateTemp1Max\":%d,\"onSecondStateTemp2Min\":%d,\"onSecondStateTemp2Max\":%d,\"onSecondStateMainPower\":%d,\"onSecondStateAddPower\":%d,\"onThirdStateTemp1Min\":%d,\"onThirdStateTemp1Max\":%d,\"onThirdStateTemp2Min\":%d,\"onThirdStateTemp2Max\":%d,\"onThirdStateMainPower\":%d,\"onThirdStateAddPower\":%d,\"crashStateTemp1Min\":%d,\"crashStateTemp1Max\":%d,\"crashStateTemp2Min\":%d,\"crashStateTemp2Max\":%d}",scfg.heatingStateTemp1Min,scfg.heatingStateTemp1Max,scfg.heatingStateTemp2Min,scfg.heatingStateTemp2Max,scfg.heatingStateMainPower,scfg.heatingStateAddPower,scfg.onFirstStateTemp1Min,scfg.onFirstStateTemp1Max,scfg.onFirstStateTemp2Min,scfg.onFirstStateTemp2Max,scfg.onFirstStateMainPower,scfg.onFirstStateAddPower,scfg.onSecondStateTemp1Min,scfg.onSecondStateTemp1Max,scfg.onSecondStateTemp2Min,scfg.onSecondStateTemp2Max,scfg.onSecondStateMainPower,scfg.onSecondStateAddPower,scfg.onThirdStateTemp1Min,scfg.onThirdStateTemp1Max,scfg.onThirdStateTemp2Min,scfg.onThirdStateTemp2Max,scfg.onThirdStateMainPower,scfg.onThirdStateAddPower,scfg.crashStateTemp1Min,scfg.crashStateTemp1Max,scfg.crashStateTemp2Min,scfg.crashStateTemp2Max);
                  webSocket->sendTXT(num, (char*)&JSON);
                  Serial.println(JSON);
              }
              break;
          case WStype_TEXT:


            if (command == "Stop"){
              Serial.println("Чтение объекта...");
              EEPROM.begin (512);
              config_t tcfg;
              EEPROM.get(0, tcfg);
              EEPROM.end();
              Serial.print("heatingStateTemp1Min : ");
              Serial.println(tcfg.heatingStateTemp1Min);
              Serial.print("heatingStateTemp1Max : ");
              Serial.println(tcfg.heatingStateTemp1Max);
              Serial.print("heatingStateTemp2Min : ");
              Serial.println(tcfg.heatingStateTemp2Min);
              Serial.print("heatingStateTemp2Max : ");
              Serial.println(tcfg.heatingStateTemp2Max);
              Serial.print("heatingStateMainPower : ");
              Serial.println(tcfg.heatingStateMainPower);
              Serial.print("heatingStateAddPower : ");
              Serial.println(tcfg.heatingStateAddPower);
              Serial.print("onFirstStateTemp1Min : ");
              Serial.println(tcfg.onFirstStateTemp1Min);
              Serial.print("onFirstStateTemp1Max : ");
              Serial.println(tcfg.onFirstStateTemp1Max);
              Serial.print("onFirstStateTemp2Min : ");
              Serial.println(tcfg.onFirstStateTemp2Min);
              Serial.print("onFirstStateTemp2Max : ");
              Serial.println(tcfg.onFirstStateTemp2Max);
              Serial.print("onFirstStateMainPower : ");
              Serial.println(tcfg.onFirstStateMainPower);
              Serial.print("onFirstStateAddPower : ");
              Serial.println(tcfg.onFirstStateAddPower);
              Serial.print("onSecondStateTemp1Min : ");
              Serial.println(tcfg.onSecondStateTemp1Min);
              Serial.print("onSecondStateTemp1Max : ");
              Serial.println(tcfg.onSecondStateTemp1Max);
              Serial.print("onSecondStateTemp2Min : ");
              Serial.println(tcfg.onSecondStateTemp2Min);
              Serial.print("onSecondStateTemp2Min : ");
              Serial.println(tcfg.onSecondStateTemp2Max);
              Serial.print("onSecondStateMainPower : ");
              Serial.println(tcfg.onSecondStateMainPower);
              Serial.print("onSecondStateAddPower : ");
              Serial.println(tcfg.onSecondStateAddPower);
              Serial.print("onThirdStateTemp1Min : ");
              Serial.println(tcfg.onThirdStateTemp1Min);
              Serial.print("onThirdStateTemp1Max : ");
              Serial.println(tcfg.onThirdStateTemp1Max);
              Serial.print("onThirdStateTemp2Min : ");
              Serial.println(tcfg.onThirdStateTemp2Min);
              Serial.print("onThirdStateTemp2Max : ");
              Serial.println(tcfg.onThirdStateTemp2Max);
              Serial.print("onThirdStateMainPower : ");
              Serial.println(tcfg.onThirdStateMainPower);
              Serial.print("onThirdStateAddPower : ");
              Serial.println(tcfg.onThirdStateAddPower);
              Serial.print("crashStateTemp1Min : ");
              Serial.println(tcfg.crashStateTemp1Min);
              Serial.print("crashStateTemp1Max : ");
              Serial.println(tcfg.crashStateTemp1Max);
              Serial.print("crashStateTemp2Min : ");
              Serial.println(tcfg.crashStateTemp2Min);
              Serial.print("crashStateTemp2Max : ");
              Serial.println(tcfg.crashStateTemp2Max);
            } else if (command == "Start"){
              Serial.println("Starting...");
            } else{
              Serial.println("Тест параметров...");
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
              Serial.println();
              Serial.println("Тест объекта...");
              Serial.println(cfg.crashStateTemp1Min);
              Serial.println("Запись объекта...");
              EEPROM.begin (512);
              EEPROM.put(0, cfg);
              EEPROM.end();
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
