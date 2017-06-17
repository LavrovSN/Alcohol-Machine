#ifndef _WEB_SERVER_PROCESS_
#define _WEB_SERVER_PROCESS_

#include <ProcessScheduler.h>
#include <ESP8266WebServer.h>
#include <ESP8266HTTPClient.h>
#include "../config.h"
#include "../index.h"


typedef std::function<void(void)> THandlerFunction;
const char ContentOne[] PROGMEM = "......";
const char ContentTwo[] PROGMEM = "......";
// Create my custom Blink Process
class WebServerProcess : public Process
{
public:
    // Call the Process constructor
    WebServerProcess(Scheduler &manager, ProcPriority pr, unsigned int period, const int port = 80)
        :  Process(manager, pr, period)
        {
          // Port defaults to 80
          server = ESP8266WebServer(port);
        }
    ~WebServerProcess(){

    }


protected:
    virtual void setup()
    {
      server.on("/",[this](){ handleRoot();});
      server.on("/app.js", [this](){
         server.send(200, "text/javascript",   "\
         document.addEventListener('DOMContentLoaded', function (){\
        	console.log('Документ загрузился');\
        });\
        var sensorsData = {};\
        var ip = location.host;\
        console.log(ip);\
        var socket = new WebSocket('ws://' + ip +':81');\
        socket.onopen = function() {\
          console.log('Соединение установлено.');\
        };\
        socket.onclose = function(event) {\
          if (event.wasClean) {\
            console.log('Соединение закрыто чисто');\
          } else {\
            console.log('Обрыв соединения');\
          }\
          console.log('Код: ' + event.code + ' причина: ' + event.reason);\
        };\
        socket.onmessage = function(event) {\
        	sensorsData = JSON.parse(event.data);\
        	if ('temp1' in sensorsData) {\
        		setSensorsData(sensorsData);\
        	}; \
        	if('heatingStateTemp1Min' in sensorsData){\
            console.log(sensorsData);\
        		setParams(sensorsData);\
        	};\
        };\
        socket.onerror = function(error) {\
          console.log('Ошибка ' + error.message);\
        };\
        console.log('Connection started');\
        ");
      });
      server.on("/setSensorsData.js", [this](){
         server.send(200, "text/javascript",   "\
         function setSensorsData(data){\
           console.log('Temp sensor ' + data.temp1);\
 	         document.querySelector('#tSensor1').innerText = data.temp1;\
 	         document.querySelector('#tSensor2').innerText = data.temp2;\
 	         if (data.mainPower) {\
 		          document.querySelector('#mainPower').innerText = 'Вкл.';\
 	         } else {\
 		          document.querySelector('#mainPower').innerText = 'Выкл.';\
 	         };\
 	         if (data.addPower) {\
 		          document.querySelector('#addPower').innerText = 'Вкл.';\
 	         } else {\
 		          document.querySelector('#addPower').innerText = 'Выкл.';\
 	         };\
 	         if (data.valve1) {\
 		          document.querySelector('#valve1').innerText = 'Откр';\
 	         } else {\
 		          document.querySelector('#valve1').innerText = 'Закр';\
 	         };\
 	         if (data.valve2) {\
 		          document.querySelector('#valve2').innerText = 'Откр';\
 	         } else {\
 		          document.querySelector('#valve2').innerText = 'Закр';\
 	         };\
 	         if (data.valve3) {\
 		          document.querySelector('#valve3').innerText = 'Откр';\
 	         } else {\
 		          document.querySelector('#valve3').innerText = 'Закр';\
 	         };\
 	         if (data.valve4) {\
 		          document.querySelector('#valve4').innerText = 'Откр';\
 	         } else {\
 		          document.querySelector('#valve4').innerText = 'Закр';\
 	         };\
 	         if (data.inputLiquidLevel) {\
 		          document.querySelector('#inputLiquidLevel').innerText = 'Полный';\
 	         } else {\
 		          document.querySelector('#inputLiquidLevel').innerText = 'Пустой';\
 	         };\
 	         if (data.outputLiquidLevel1) {\
 		          document.querySelector('#outputLiquidLevel1').innerText = 'Полный';\
 	         } else {\
 		          document.querySelector('#outputLiquidLevel1').innerText = 'Пустой';\
 	         };\
 	         if (data.outputLiquidLevel2) {\
 		          document.querySelector('#outputLiquidLevel2').innerText = 'Полный';\
 	         } else {\
 		          document.querySelector('#outputLiquidLevel2').innerText = 'Пустой';\
 	         };\
 	         if (data.outputLiquidLevel3) {\
 		          document.querySelector('#outputLiquidLevel3').innerText = 'Полный';\
 	         } else {\
 		          document.querySelector('#outputLiquidLevel3').innerText = 'Пустой';\
 	         };\
 	         document.querySelector('#airHumidity').innerText = data.airHumidity;\
 	         if (!data.smokeLevel) {\
 		          document.querySelector('#smokeLevel').innerText = 'Норма';\
 	         } else {\
 		          document.querySelector('#smokeLevel').innerText = 'Задымление';\
 	         };\
 	         if(data.status == 30){\
 		          document.querySelector('#status').innerText = 'Авария. Пожар';\
 	         } else if(data.status == 31){\
 		          document.querySelector('#status').innerText = 'Авария. Утечка';\
 	         } else if(data.status == 32){\
 		          document.querySelector('#status').innerText = 'Авария. Открыто несколько клапанов.';\
 	         } else if(data.status == 33){\
 		          document.querySelector('#status').innerText = 'Авария. Работа при закрытом клапане.';\
 	         } else if(data.status == 3){\
 		          document.querySelector('#status').innerText = 'Авария';\
 	         } else if(data.status == 21){\
 		          document.querySelector('#status').innerText = 'Работа. Отбор первой фракции.';\
 	         } else if(data.status == 22){\
 		          document.querySelector('#status').innerText = 'Работа. Отбор второй фракции.';\
 	         } else if(data.status == 23){\
 		          document.querySelector('#status').innerText = 'Работа. Отбор третей фракции.';\
 	         } else if(data.status == 2){\
 		          document.querySelector('#status').innerText = 'Работа';\
 	         } else if(data.status == 1){\
 		          document.querySelector('#status').innerText = 'Простой';\
 	         } else {\
 		          document.querySelector('#status').innerText = 'Не определен';\
 	         };\
         };\
         ");
      });

      server.on("/setParams.js", [this](){
         server.send(200, "text/javascript",   "\
         function setParams(data){\
           console.log('Params: heating temp1: ' + data.heatingStateTemp1Min);\
 	         document.querySelector('#heatingTemp1Min').value = data.heatingStateTemp1Min;\
 	         document.querySelector('#heatingTemp1Max').value = data.heatingStateTemp1Max;\
 	         document.querySelector('#heatingTemp2Min').value = data.heatingStateTemp2Min;\
 	         document.querySelector('#heatingTemp2Max').value = data.heatingStateTemp2Max;\
 	         if (data.heatingStateMainPower = 1){\
 		          document.getElementById('heatingMainPowerOn').checked = true;\
 	         } else{\
 		          document.getElementById('heatingMainPowerOff').checked = true\
 	         };\
 	         if (data.heatingStateAddPower = 1){\
 		          document.getElementById('heatingAddPowerOn').checked = true;\
 	         } else{\
 		          document.getElementById('heatingAddPowerOff').checked = true\
 	         };\
 	         document.querySelector('#onFirstTemp1Min').value = data.onFirstStateTemp1Min;\
 	         document.querySelector('#onFirstTemp1Max').value = data.onFirstStateTemp1Max;\
 	         document.querySelector('#onFirstTemp2Min').value = data.onFirstStateTemp2Min;\
 	         document.querySelector('#onFirstTemp2Max').value = data.onFirstStateTemp2Max;\
 	         if (data.onFirstStateMainPower = 1){\
 		          document.getElementById('onFirstMainPowerOn').checked = true;\
 	         } else{\
 		          document.getElementById('onFirstMainPowerOff').checked = true\
 	         };\
 	         if (data.onFirstStateAddPower = 1){\
 		          document.getElementById('onFirstAddPowerOn').checked = true;\
 	         } else{\
 		          document.getElementById('onFirstAddPowerOff').checked = true\
 	         };\
 	         document.querySelector('#onSecondTemp1Min').value = data.onSecondStateTemp1Min;\
 	         document.querySelector('#onSecondTemp1Max').value = data.onSecondStateTemp1Max;\
 	         document.querySelector('#onSecondTemp2Min').value = data.onSecondStateTemp2Min;\
 	         document.querySelector('#onSecondTemp2Max').value = data.onSecondStateTemp2Max;\
 	         if (data.onSecondStateMainPower = 1){\
 		          document.getElementById('onSecondMainPowerOn').checked = true;\
 	         } else{\
 		          document.getElementById('onSecondMainPowerOff').checked = true\
 	         };\
 	         if (data.onSecondStateAddPower = 1){\
 		          document.getElementById('onSecondAddPowerOn').checked = true;\
 	         } else{\
 		          document.getElementById('onSecondAddPowerOff').checked = true\
 	         };\
 	         document.querySelector('#onThirdTemp1Min').value = data.onThirdStateTemp1Min;\
 	         document.querySelector('#onThirdTemp1Max').value = data.onThirdStateTemp1Max;\
 	         document.querySelector('#onThirdTemp2Min').value = data.onThirdStateTemp2Min;\
 	         document.querySelector('#onThirdTemp2Max').value = data.onThirdStateTemp2Max;\
 	         if (data.onThirdStateMainPower = 1){\
 		          document.getElementById('onThirdMainPowerOn').checked = true;\
 	         } else{\
 		          document.getElementById('onThirdMainPowerOff').checked = true\
 	         };\
 	         if (data.onThirdStateAddPower = 1){\
 	           document.getElementById('onThirdAddPowerOn').checked = true;\
 	        } else{\
 		         document.getElementById('onThirdAddPowerOff').checked = true\
 	        };\
 	        document.querySelector('#crashTemp1Min').value = data.crashStateTemp1Min;\
 	        document.querySelector('#crashTemp1Max').value = data.crashStateTemp1Max;\
 	        document.querySelector('#crashTemp2Min').value = data.crashStateTemp2Min;\
 	        document.querySelector('#crashTemp2Max').value = data.crashStateTemp2Max;\
        };\
        ");
      });
      server.on("/click.js", [this](){
        server.send(200, "text/javascript",   "\
        document.addEventListener('DOMContentLoaded', function (){\
           console.log('Документ click загрузился');\
         });\
         var formData = {};\
         function checkRadio(name) {\
           if (document.querySelector('input[name=' + name + ']:checked').value == 'on'){\
	            return true;\
            } else{\
	             return false;\
            };\
         };\
         ok.onclick = function(){\
           formData = {\
             'heatingStateTemp1Min':document.querySelector('#heatingTemp1Min').value,\
             'heatingStateTemp1Max':document.querySelector('#heatingTemp1Max').value,\
             'heatingStateTemp2Min':document.querySelector('#heatingTemp2Min').value,\
             'heatingStateTemp2Max':document.querySelector('#heatingTemp2Max').value,\
             'heatingStateMainPower':(checkRadio('heatingMainPower')),\
             'heatingStateAddPower':(checkRadio('heatingAddPower')),\
             'onFirstStateTemp1Min':document.querySelector('#onFirstTemp1Min').value,\
             'onFirstStateTemp1Max':document.querySelector('#onFirstTemp1Max').value,\
             'onFirstStateTemp2Min':document.querySelector('#onFirstTemp2Min').value,\
             'onFirstStateTemp2Max':document.querySelector('#onFirstTemp2Max').value,\
             'onFirstStateMainPower':(checkRadio('onFirstMainPower')),\
             'onFirstStateAddPower':(checkRadio('onFirstAddPower')),\
             'onSecondStateTemp1Min':document.querySelector('#onSecondTemp1Min').value,\
             'onSecondStateTemp1Max':document.querySelector('#onSecondTemp1Max').value,\
             'onSecondStateTemp2Min':document.querySelector('#onSecondTemp2Min').value,\
             'onSecondStateTemp2Max':document.querySelector('#onSecondTemp2Max').value,\
             'onSecondStateMainPower':(checkRadio('onSecondMainPower')),\
             'onSecondStateAddPower':(checkRadio('onSecondAddPower')),\
             'onThirdStateTemp1Min':document.querySelector('#onThirdTemp1Min').value,\
             'onThirdStateTemp1Max':document.querySelector('#onThirdTemp1Max').value,\
             'onThirdStateTemp2Min':document.querySelector('#onThirdTemp2Min').value,\
             'onThirdStateTemp2Max':document.querySelector('#onThirdTemp2Max').value,\
             'onThirdStateMainPower':(checkRadio('onThirdMainPower')),\
             'onThirdStateAddPower':(checkRadio('onThirdAddPower')),\
             'crashStateTemp1Min':document.querySelector('#crashTemp1Min').value,\
             'crashStateTemp1Max':document.querySelector('#crashTemp1Max').value,\
             'crashStateTemp2Min':document.querySelector('#crashTemp2Min').value,\
             'crashStateTemp2Max':document.querySelector('#crashTemp2Max').value\
           };\
           socket.send(JSON.stringify(formData));\
         };\
         start.onclick = function(){\
            console.log('Кнопка Start нажата');\
            socket.send('Start');\
         };\
         stahp.onclick = function(){\
            console.log('Кнопка Stop нажата');\
            socket.send('Stop');\
         };\
      ");
      });

      server.onNotFound( [this](){handleNotFound();} );

      server.begin();
      Serial.println("WebServerProcess started");
    }

    virtual void cleanup()
    {

    }

    // Create our service routine
    virtual void service()
    {
      server.handleClient();
    }
private:
  ESP8266WebServer server;
  void handleRoot() {
    // char* a;
    // itoa(head,a,10);
    // for(uint i=0; a[i] != '\0' && i < 10; i++)
    //   add_char_to_buffer(a[i]);response_buffer
    server.send(200,"text/html",indexHTML);
  }

  void handleNotFound(){
    String message = "File Not Found\n\n";
    message += "URI: ";
    message += server.uri();
    message += "\nMethod: ";
    message += (server.method() == HTTP_GET)?"GET":"POST";
    message += "\nArguments: ";
    message += server.args();
    message += "\n";
    for (uint8_t i=0; i<server.args(); i++){
      message += " " + server.argName(i) + ": " + server.arg(i) + "\n";
    }
    server.send(404, "text/plain", message);
  }
};

#endif
