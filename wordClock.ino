#include <ESP8266WiFi.h>
#include <ESP8266WiFiMulti.h>
#include <TimeLib.h>

#include "NtpClient.h"
#include "DisplayDriverFrickelClock.h"
#include "WordingStrategyStesie.h"
#include "WordClockScene.h"

ESP8266WiFiMulti wifiMulti;

DisplayDriverFrickelClock driver;
WordFactoryFrickelClock wordFactory;
WordClockScene *wordClockScene;

void setup() {
  driver.setup();

  // TODO  Configure your WLAN networks here
  wifiMulti.addAP("wifiname", "wifiPassword");

  while (wifiMulti.run() != WL_CONNECTED) {
    delay(500);
  }

  syncTime();

  wordClockScene = new WordClockScene(&driver, &driver, new WordingStrategyStesie(&wordFactory));
}

void loop() {
  wifiMulti.run();
  wordClockScene->loop();
}




