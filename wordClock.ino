#ifdef ESP8266
#  include <ESP8266WiFi.h>
#  include <ESP8266WiFiMulti.h>
#endif

#include <TimeLib.h>

#include "NtpClient.h"
#include "DisplayDriverFrickelClock.h"
#include "DisplayDriver10x11Clock.h"
#include "WordingStrategyStesie.h"
#include "WordingStrategyEnglish.h"
#include "WordClockScene.h"

#ifdef ESP8266
ESP8266WiFiMulti wifiMulti;
#endif


#if 1
DisplayDriver10x11Clock driver;
WordFactoryEnglish10x11Clock wordFactory;
WordingStrategyEnglish strategy = { &wordFactory };
#else
DisplayDriverFrickelClock driver;
WordFactoryFrickelClock wordFactory;
WordingStrategyStesie strategy = { &wordFactory };
#endif

WordClockScene wordClockScene = { &driver, &driver, &strategy };

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
}

void loop() {
#ifdef ESP8266
  wifiMulti.run();
#endif
  
  wordClockScene.loop();
}





