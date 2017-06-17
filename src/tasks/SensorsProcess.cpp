#ifndef _SENSORS_PROCESS_
#define _SENSORS_PROCESS_

#include <ProcessScheduler.h>
#include "WebSocketServerProcess.cpp"
//#include <ArduinoJson.h>
struct s_data
{
    int temp1;
    int temp2;
    bool mainPower;
    bool addPower;
    bool valve1;
    bool valve2;
    bool valve3;
    bool valve4;
    bool inputLiquidLevel;
    bool outputLiquidLevel1;
    bool outputLiquidLevel2;
    bool outputLiquidLevel3;
    int airHumidity;
    bool smokeLevel;
    int status;
};
// Create my custom Blink Process
class SensorsProcess : public Process
{
public:
  WebSocketServerProcess * ws;
  // Call the Process constructor
  SensorsProcess(Scheduler &manager, ProcPriority pr, unsigned int period, WebSocketServerProcess * _ws = NULL)
    :  Process(manager, pr, period)
    {
        ws = _ws;
    }
    config_t params;
    s_data sensorsData;
protected:
    virtual void setup()
    {

      Serial.println("SensorsProcess started");
    }

     // Undo setup()
    virtual void cleanup()
    {

    }

    // Create our service routine
    virtual void service()
    {
      sensorsData.temp1 = random(0,100);
      sensorsData.temp2 = random(0,100);
      sensorsData.mainPower = (random(2)==1);
      sensorsData.addPower = (random(2)==1);
      sensorsData.valve1 = (random(2)==1);
      sensorsData.valve2 = (random(2)==1);
      sensorsData.valve3 = (random(2)==1);
      sensorsData.valve4 = (random(2)==1);
      sensorsData.inputLiquidLevel = (random(2)==1);
      sensorsData.outputLiquidLevel1 = (random(2)==1);
      sensorsData.outputLiquidLevel2 = (random(2)==1);
      sensorsData.outputLiquidLevel3 = (random(2)==1);
      sensorsData.airHumidity = random(0,100);
      sensorsData.smokeLevel = (random(2)==1);
      sensorsData.status = getStatus();

      char JSON[512];
      sprintf(JSON,"{\"temp1\":%d,\"temp2\":%d,\"mainPower\":%d,\"addPower\":%d,\"valve1\":%d,\"valve2\":%d,\"valve3\":%d,\"valve4\":%d,\"inputLiquidLevel\":%d,\"outputLiquidLevel1\":%d,\"outputLiquidLevel2\":%d,\"outputLiquidLevel3\":%d,\"airHumidity\":%d,\"smokeLevel\":%d,\"status\":%d}",
      sensorsData.temp1, //temp1
      sensorsData.temp2, //temp2
      sensorsData.mainPower, //mainPower
      sensorsData.addPower, //addPower
      sensorsData.valve1, //valve1
      sensorsData.valve2, //valve2
      sensorsData.valve3, //valve3
      sensorsData.valve4, //valve4
      sensorsData.inputLiquidLevel, //inputLiquidLevel
      sensorsData.outputLiquidLevel1, //outputLiquidLevel1
      sensorsData.outputLiquidLevel2, //outputLiquidLevel2
      sensorsData.outputLiquidLevel3, //outputLiquidLevel3
      sensorsData.airHumidity, //airHumidity
      sensorsData.smokeLevel, //smokeLevel
      sensorsData.status); //Состояние
      ws->webSocket->broadcastTXT((char*)&JSON);
      delay(1000);
    }
  private:
    int getStatus(){
      params = ws->getParams();
      //Serial.println(params.crashStateTemp2Min);
      //sensorsData
      //params
      if (!sensorsData.mainPower && !sensorsData.addPower){
        return 0; //Состояние - "Простой", если оба нагревательных элемента не активны
      }
      int outputValveCount = 0; //Количество открытых выпускных клапанов
      if (sensorsData.valve1){
		      outputValveCount++;
	    }
	    if (sensorsData.valve2){
		      outputValveCount++;
	    }
	    if (sensorsData.valve3){
		      outputValveCount++;
	    }
      if (outputValveCount != 1) {
          return 5; //Авария если количество открытых выпускных клапанов не равно 1
      }
      if ((sensorsData.temp1 > params.crashStateTemp1Min) || (sensorsData.temp1 < params.crashStateTemp1Max)){
        return 5; //Авария по температуре в перегонном кубе
      }
      if ((sensorsData.temp2 > params.crashStateTemp2Min) || (sensorsData.temp2 < params.crashStateTemp2Max)){
        return 5; //Авария по температуре в блоке МСД
      }
      if((!sensorsData.inputLiquidLevel) && (sensorsData.mainPower)){
        return 5; //Авария - работа с пустым перегонным кубом
      }
      if((!sensorsData.inputLiquidLevel) && (sensorsData.addPower)){
        return 5; //Авария - работа с пустым перегонным кубом
      }
      if((sensorsData.outputLiquidLevel1) || (sensorsData.outputLiquidLevel2) || (sensorsData.outputLiquidLevel3)){
        return 5; //Авария - перелив в одной из приемных колб
      }
      if((sensorsData.temp1 >= params.heatingStateTemp1Min)&&(sensorsData.temp1 <= params.heatingStateTemp1Max)&&
      (sensorsData.temp2 >= params.heatingStateTemp2Min)&&(sensorsData.temp2 <= params.heatingStateTemp2Max)&&
      (params.heatingStateMainPower == sensorsData.mainPower)&&(params.heatingStateAddPower == sensorsData.addPower)){
        return 4; //Разогрев
      }
      if((sensorsData.temp1 >= params.onFirstStateTemp1Min)&&(sensorsData.temp1 <= params.onFirstStateTemp1Max)&&
      (sensorsData.temp2 >= params.onFirstStateTemp2Min)&&(sensorsData.temp2 <= params.onFirstStateTemp2Max)&&
      (params.onFirstStateMainPower == sensorsData.mainPower)&&(params.onFirstStateAddPower == sensorsData.addPower)){
        return 1; //Отбор первой фракции
      }
      if((sensorsData.temp1 >= params.onSecondStateTemp1Min)&&(sensorsData.temp1 <= params.onSecondStateTemp1Max)&&
      (sensorsData.temp2 >= params.onSecondStateTemp2Min)&&(sensorsData.temp2 <= params.onSecondStateTemp2Max)&&
      (params.onSecondStateMainPower == sensorsData.mainPower)&&(params.onSecondStateAddPower == sensorsData.addPower)){
        return 2; //Отбор второй фракции
      }
      if((sensorsData.temp1 >= params.onThirdStateTemp1Min)&&(sensorsData.temp1 <= params.onThirdStateTemp1Max)&&
      (sensorsData.temp2 >= params.onThirdStateTemp2Min)&&(sensorsData.temp2 <= params.onThirdStateTemp2Max)&&
      (params.onThirdStateMainPower == sensorsData.mainPower)&&(params.onThirdStateAddPower == sensorsData.addPower)){
        return 2; //Отбор третьей фракции
      }
    }
};
#endif
