#ifndef _WEB_SERVER_PROCESS_
#define _WEB_SERVER_PROCESS_

#include <ProcessScheduler.h>
#include <ESP8266WebServer.h>
#include <ESP8266HTTPClient.h>
#include "../config.h"
#include "../web/index.h"
#include "../web/setSensorsData.h"
#include "../web/setParams.h"
#include "../web/click.h"
#include "../web/app.h"



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
         server.send(200, "text/javascript", appJS);
      });
      server.on("/setSensorsData.js", [this](){
         server.send(200, "text/javascript", setSensorsDataJS);
      });

      server.on("/setParams.js", [this](){
         server.send(200, "text/javascript", setParamsJS);
      });
      server.on("/click.js", [this](){
        server.send(200, "text/javascript", clickJS);
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
