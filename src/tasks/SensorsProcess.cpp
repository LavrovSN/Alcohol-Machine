#ifndef _SENSORS_PROCESS_
#define _SENSORS_PROCESS_

#include <ProcessScheduler.h>
#include "WebSocketServerProcess.cpp"

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
int counter = 0;
int cStatus = 98;

public:
  s_data sensorsData;
  WebSocketServerProcess * ws;
  // Call the Process constructor
  SensorsProcess(Scheduler &manager, ProcPriority pr, unsigned int period, WebSocketServerProcess * _ws = NULL)
    :  Process(manager, pr, period)
    {
        ws = _ws;
    }
    //config_t params = ;;///////////////
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
      delay(200);
      if (counter == 5){
        //Serial.println("Запрос статуса...");
        Serial.print("Status: "); Serial.println(cStatus);
        counter = 0;
      } else {
        counter++;
      };

      setSensorsData(random(1,5));
      cStatus = getStatus(ws->getParams());


      //Serial.print("Counter: ");
      //Serial.println(counter);
      //Serial.print("cStatus: ");
      //Serial.println(cStatus);


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
      Serial.println("Показания отправлены...");
    }

  private:
    void setSensorsData(int randomSD){
      if (randomSD == 1){
        Serial.print("RandomSD: "); Serial.println(randomSD);
        sensorsData.temp1 = random(0,50);
        sensorsData.temp2 = random(0,50); //random(0,100);
        sensorsData.mainPower = true; //(random(2)==1);
        sensorsData.addPower = false; //(random(2)==1);
        sensorsData.valve1 = true; //(random(2)==1);
        sensorsData.valve2 = false; //(random(2)==1);
        sensorsData.valve3 = false; //(random(2)==1);
        sensorsData.valve4 = false; //(random(2)==1);
        sensorsData.inputLiquidLevel = true; //(random(2)==1);
        sensorsData.outputLiquidLevel1 = false; //(random(2)==1);
        sensorsData.outputLiquidLevel2 = false; //(random(2)==1);
        sensorsData.outputLiquidLevel3 = false; //(random(2)==1);
        sensorsData.airHumidity = random(0,95);
        sensorsData.smokeLevel = false; //(random(2)==1);
        sensorsData.status = cStatus;
      };
      if (randomSD == 2){
        Serial.print("RandomSD: "); Serial.println(randomSD);
        sensorsData.temp1 = random(51,83);
        sensorsData.temp2 = random(50,80); //random(0,100);
        sensorsData.mainPower = true; //(random(2)==1);
        sensorsData.addPower = false; //(random(2)==1);
        sensorsData.valve1 = true; //(random(2)==1);
        sensorsData.valve2 = false; //(random(2)==1);
        sensorsData.valve3 = false; //(random(2)==1);
        sensorsData.valve4 = true; //(random(2)==1);
        sensorsData.inputLiquidLevel = true; //(random(2)==1);
        sensorsData.outputLiquidLevel1 = false; //(random(2)==1);
        sensorsData.outputLiquidLevel2 = false; //(random(2)==1);
        sensorsData.outputLiquidLevel3 = false; //(random(2)==1);
        sensorsData.airHumidity = random(0,95);
        sensorsData.smokeLevel = false; //(random(2)==1);
        sensorsData.status = cStatus;
      };
      if (randomSD == 3){
        Serial.print("RandomSD: "); Serial.println(randomSD);
        sensorsData.temp1 = random(60,110);
        sensorsData.temp2 = random(83,94); //random(0,100);
        sensorsData.mainPower = true; //(random(2)==1);
        sensorsData.addPower = true; //(random(2)==1);
        sensorsData.valve1 = false; //(random(2)==1);
        sensorsData.valve2 = true; //(random(2)==1);
        sensorsData.valve3 = false; //(random(2)==1);
        sensorsData.valve4 = false; //(random(2)==1);
        sensorsData.inputLiquidLevel = true; //(random(2)==1);
        sensorsData.outputLiquidLevel1 = false; //(random(2)==1);
        sensorsData.outputLiquidLevel2 = false; //(random(2)==1);
        sensorsData.outputLiquidLevel3 = false; //(random(2)==1);
        sensorsData.airHumidity = random(0,95);
        sensorsData.smokeLevel = false; //(random(2)==1);
        sensorsData.status = cStatus;
      };
      if (randomSD == 4){
        Serial.print("RandomSD: "); Serial.println(randomSD);
        sensorsData.temp1 = random(90,115);
        sensorsData.temp2 = random(95,99); //random(0,100);
        sensorsData.mainPower = true; //(random(2)==1);
        sensorsData.addPower = true; //(random(2)==1);
        sensorsData.valve1 = false; //(random(2)==1);
        sensorsData.valve2 = false; //(random(2)==1);
        sensorsData.valve3 = true; //(random(2)==1);
        sensorsData.valve4 = false; //(random(2)==1);
        sensorsData.inputLiquidLevel = true; //(random(2)==1);
        sensorsData.outputLiquidLevel1 = false; //(random(2)==1);
        sensorsData.outputLiquidLevel2 = false; //(random(2)==1);
        sensorsData.outputLiquidLevel3 = false; //(random(2)==1);
        sensorsData.airHumidity = random(0,95);
        sensorsData.smokeLevel = false; //(random(2)==1);
        sensorsData.status = cStatus;
      };
      if (randomSD == 5){
        Serial.print("RandomSD: "); Serial.println(randomSD);
        sensorsData.temp1 = random(110,120);
        sensorsData.temp2 = random(110,120); //random(0,100);
        sensorsData.mainPower = true; //(random(2)==1);
        sensorsData.addPower = true; //(random(2)==1);
        sensorsData.valve1 = false; //(random(2)==1);
        sensorsData.valve2 = false; //(random(2)==1);
        sensorsData.valve3 = true; //(random(2)==1);
        sensorsData.valve4 = false; //(random(2)==1);
        sensorsData.inputLiquidLevel = true; //(random(2)==1);
        sensorsData.outputLiquidLevel1 = false; //(random(2)==1);
        sensorsData.outputLiquidLevel2 = false; //(random(2)==1);
        sensorsData.outputLiquidLevel3 = false; //(random(2)==1);
        sensorsData.airHumidity = random(0,95);
        sensorsData.smokeLevel = false; //(random(2)==1);
        sensorsData.status = cStatus;
      };
    }

    int getStatus(config_t params){
      //params = ws -> scfg;
      /*Serial.println("Текущие ПАРАМЕТРЫ... ");
      Serial.print("heatingStateTemp1Max: "); Serial.println(params.heatingStateTemp1Max);
      Serial.print("heatingStateTemp2Max: "); Serial.println(params.heatingStateTemp2Max);

      Serial.print("temp1: "); Serial.println(sensorsData.temp1);
      Serial.print("temp2: "); Serial.println(sensorsData.temp2);*/

      /*Serial.print("\t temp1: "); Serial.println(sensorsData.temp1);
      Serial.print("\t temp2: "); Serial.println(sensorsData.temp2);
      Serial.print("\t mainPower: "); Serial.println(sensorsData.mainPower);
      Serial.print("\t addPower: "); Serial.println(sensorsData.addPower);
      Serial.print("\t valve1: "); Serial.println(sensorsData.valve1);
      Serial.print("\t valve2: "); Serial.println(sensorsData.valve2);
      Serial.print("\t valve3: "); Serial.println(sensorsData.valve3);
      Serial.print("\t valve4: "); Serial.println(sensorsData.valve4);
      Serial.print("\t inputLiquidLevel: "); Serial.println(sensorsData.inputLiquidLevel);
      Serial.print("\t outputLiquidLevel1: "); Serial.println(sensorsData.outputLiquidLevel1);
      Serial.print("\t outputLiquidLevel2: "); Serial.println(sensorsData.outputLiquidLevel2);
      Serial.print("\t outputLiquidLevel3: "); Serial.println(sensorsData.outputLiquidLevel3);
      Serial.print("\t airHumidity: "); Serial.println(sensorsData.airHumidity);
      Serial.print("\t smokeLevel: "); Serial.println(sensorsData.smokeLevel);
      Serial.println("------------------------------");
      Serial.print("\t heatingStateTemp1Min: "); Serial.println(params.heatingStateTemp1Min);
      Serial.print("\t heatingStateTemp1Max: "); Serial.println(params.heatingStateTemp1Max);
      Serial.print("\t heatingStateTemp2Min: "); Serial.println(params.heatingStateTemp2Min);
      Serial.print("\t heatingStateTemp2Max: "); Serial.println(params.heatingStateTemp2Max);
      Serial.print("\t heatingStateMainPower: "); Serial.println(params.heatingStateMainPower);
      Serial.print("\t heatingStateAddPower: "); Serial.println(params.heatingStateAddPower);
      Serial.print("\t onFirstStateTemp1Min: "); Serial.println(params.onFirstStateTemp1Min);
      Serial.print("\t onFirstStateTemp1Max: "); Serial.println(params.onFirstStateTemp1Max);
      Serial.print("\t onFirstStateTemp2Min: "); Serial.println(params.onFirstStateTemp2Min);
      Serial.print("\t onFirstStateTemp2Max: "); Serial.println(params.onFirstStateTemp2Max);
      Serial.print("\t onFirstStateMainPower: "); Serial.println(params.onFirstStateMainPower);
      Serial.print("\t onFirstStateAddPower: "); Serial.println(params.onFirstStateAddPower);
      Serial.print("\t onSecondStateTemp1Min: "); Serial.println(params.onSecondStateTemp1Min);
      Serial.print("\t onSecondStateTemp1Max: "); Serial.println(params.onSecondStateTemp1Max);
      Serial.print("\t onSecondStateTemp2Min: "); Serial.println(params.onSecondStateTemp2Min);
      Serial.print("\t onSecondStateTemp2Max: "); Serial.println(params.onSecondStateTemp2Max);
      Serial.print("\t onSecondStateMainPower: "); Serial.println(params.onSecondStateMainPower);
      Serial.print("\t onSecondStateAddPower: "); Serial.println(params.onSecondStateAddPower);
      Serial.print("\t onThirdStateTemp1Min: "); Serial.println(params.onThirdStateTemp1Min);
      Serial.print("\t onThirdStateTemp1Max: "); Serial.println(params.onThirdStateTemp1Max);
      Serial.print("\t onThirdStateTemp2Min: "); Serial.println(params.onThirdStateTemp2Min);
      Serial.print("\t onThirdStateTemp2Max: "); Serial.println(params.onThirdStateTemp2Max);
      Serial.print("\t onThirdStateMainPower: "); Serial.println(params.onThirdStateMainPower);
      Serial.print("\t onThirdStateAddPower: "); Serial.println(params.onThirdStateAddPower);
      Serial.print("\t crashStateTemp1Min: "); Serial.println(params.crashStateTemp1Min);
      Serial.print("\t crashStateTemp1Max: "); Serial.println(params.crashStateTemp1Max);
      Serial.print("\t crashStateTemp2Min: "); Serial.println(params.crashStateTemp2Min);
      Serial.print("\t crashStateTemp2Max: "); Serial.println(params.crashStateTemp2Max);
*/

      //Serial.println(params.crashStateTemp2Min);
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
          return 31; //Авария если количество открытых выпускных клапанов не равно 1
      }
      if ((sensorsData.temp1 > params.crashStateTemp1Min) && (sensorsData.temp1 < params.crashStateTemp1Max)){
        return 32; //Авария по температуре в перегонном кубе
      }
      if ((sensorsData.temp2 > params.crashStateTemp2Min) && (sensorsData.temp2 < params.crashStateTemp2Max)){
        return 33; //Авария по температуре в блоке МСД
      }
      if((!sensorsData.inputLiquidLevel) && (sensorsData.mainPower)){
        return 34; //Авария - работа с пустым перегонным кубом
      }
      if((!sensorsData.inputLiquidLevel) && (sensorsData.addPower)){
        return 34; //Авария - работа с пустым перегонным кубом
      }
      if((sensorsData.outputLiquidLevel1) || (sensorsData.outputLiquidLevel2) || (sensorsData.outputLiquidLevel3)){
        return 35; //Авария - перелив в одной из приемных колб
      }
      if(sensorsData.smokeLevel){
        return 36; //Авария - пожар
      }
      if(sensorsData.airHumidity > 95){
        return 37; //Авария - утечка
      }
      if((sensorsData.temp1 >= params.heatingStateTemp1Min)&&
        (sensorsData.temp1 <= params.heatingStateTemp1Max)&&
        (sensorsData.temp2 >= params.heatingStateTemp2Min)&&
        (sensorsData.temp2 <= params.heatingStateTemp2Max)&&
        (params.heatingStateMainPower == sensorsData.mainPower)&&
        (params.heatingStateAddPower == sensorsData.addPower)){
        return 1; //Разогрев
      }
      if((sensorsData.temp1 >= params.onFirstStateTemp1Min)&&
        (sensorsData.temp1 <= params.onFirstStateTemp1Max)&&
        (sensorsData.temp2 >= params.onFirstStateTemp2Min)&&
        (sensorsData.temp2 <= params.onFirstStateTemp2Max)&&
        (params.onFirstStateMainPower == sensorsData.mainPower)&&
        (params.onFirstStateAddPower == sensorsData.addPower)){
          return 21; //Отбор первой фракции
      }
      if((sensorsData.temp1 >= params.onSecondStateTemp1Min)&&(sensorsData.temp1 <= params.onSecondStateTemp1Max)&&
      (sensorsData.temp2 >= params.onSecondStateTemp2Min)&&(sensorsData.temp2 <= params.onSecondStateTemp2Max)&&
      (params.onSecondStateMainPower == sensorsData.mainPower)&&(params.onSecondStateAddPower == sensorsData.addPower)){
        return 22; //Отбор второй фракции
      }
      if((sensorsData.temp1 >= params.onThirdStateTemp1Min)&&(sensorsData.temp1 <= params.onThirdStateTemp1Max)&&
      (sensorsData.temp2 >= params.onThirdStateTemp2Min)&&(sensorsData.temp2 <= params.onThirdStateTemp2Max)&&
      (params.onThirdStateMainPower == sensorsData.mainPower)&&(params.onThirdStateAddPower == sensorsData.addPower)){
        return 23; //Отбор третьей фракции
      }
      if (!sensorsData.mainPower && !sensorsData.addPower){
        return 0; //Состояние - "Простой", если оба нагревательных элемента не активны
      }
      return 99;
    }
};
#endif
