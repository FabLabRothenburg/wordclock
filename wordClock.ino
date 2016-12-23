#ifdef ESP8266
#  include <ESP8266WiFi.h>
#  include <ESP8266WiFiMulti.h>
#endif

#include <TimeLib.h>

#include "NtpClient.h"
#include "DisplayDriverFrickelClock.h"
#include "WordingStrategyStesie.h"
#include "WordClockScene.h"

#ifdef ESP8266
ESP8266WiFiMulti wifiMulti;
#endif

DisplayDriverFrickelClock driver;
WordFactoryFrickelClock wordFactory;
WordClockScene *wordClockScene;

void setup() {
  driver.setup();

#ifdef ESP8266
  // TODO  Configure your WLAN networks here
  wifiMulti.addAP("wifiname", "wifiPassword");

  while (wifiMulti.run() != WL_CONNECTED) {
    delay(500);
  }

  syncTime();
#endif

  wordClockScene = new WordClockScene(&driver, &driver, new WordingStrategyStesie(&wordFactory));
}

void loop() {
#ifdef ESP8266
  wifiMulti.run();
#endif
  
  wordClockScene->loop();
}




