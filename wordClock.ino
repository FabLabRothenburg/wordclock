#ifdef ESP8266
#  include <ESP8266WiFi.h>
#  include <ESP8266WiFiMulti.h>
#endif

#include <TimeLib.h>

#include "DisplayDriver10x11Clock.h"
#include "DisplayDriverFablabNeaClock.h"
#include "DisplayDriverFrickelClock.h"
#include "FallingStarAnimator.h"
#include "IncrementalAnimator.h"
#include "NtpClient.h"
#include "NullAnimator.h"
#include "MockWordClockScene.h"
#include "MqttController.h"
#include "WordingStrategyStesie.h"
#include "WordingStrategyEnglish.h"
#include "WordClockScene.h"

#ifdef ESP8266
ESP8266WiFiMulti wifiMulti;
WiFiClient wifiClient;
#endif


#if 0
DisplayDriver10x11Clock driver;
WordFactoryEnglish10x11Clock wordFactory;
WordingStrategyEnglish strategy = { &wordFactory };
#elif 1
DisplayDriverFablabNeaClock driver;
WordFactoryEnglish10x11Clock wordFactory;
WordingStrategyEnglish strategy = { &wordFactory };
#else
DisplayDriverFrickelClock driver;
WordFactoryFrickelClock wordFactory;
WordingStrategyStesie strategy = { &wordFactory };
#endif

//NullAnimator animator = { &driver };
//IncrementalAnimator animator = { &driver };
FallingStarAnimator animator = { &driver };

#if 0
WordClockScene wordClockScene = { &animator, &strategy };
#else
MockWordClockScene wordClockScene = { &animator, &strategy };
#endif

#ifdef ESP8266
MqttController *mqttController = new MqttController(&wordClockScene, wifiClient);
#endif

void setup() {
  driver.setup();

#ifdef ESP8266
  Serial.begin(9600);

  // TODO  Configure your WLAN networks here
  wifiMulti.addAP("wifiname", "wifiPassword");

  while (wifiMulti.run() != WL_CONNECTED) {
    delay(500);
  }

  syncTime();

  mqttController->setServer({ 176, 9, 118, 134 });
  mqttController->setId("mqtt_client_id");
  mqttController->setUser("mqtt_user_name");
  mqttController->setPassword("mqtt_password");
#endif
}

void loop() {
#ifdef ESP8266
  wifiMulti.run();
  mqttController->maintain();
#endif

  wordClockScene.loop();
  delay(1000);
}

