#ifdef ESP8266
#  include <ESP8266WiFi.h>
#  include <ESP8266WiFiMulti.h>
#endif

#include "DisplayDriver10x11Clock.h"
#include "DisplayDriverFablabNeaClock.h"
#include "DisplayDriverFrickelClock.h"
#include "FallingStarAnimator.h"
#include "IncrementalAnimator.h"
#include "NtpClient.h"
#include "NullAnimator.h"
#include "MockWordClockScene.h"
#include "MqttController.h"
#include "PersistentColors.h"
#include "WordingStrategyStesie.h"
#include "WordingStrategyEnglish.h"
#include "WordingStrategyFranken.h"
#include "WordClockScene.h"

#ifdef ESP8266
ESP8266WiFiMulti wifiMulti;
WiFiClient wifiClient;
#endif

PersistentStorage persistentStorage;

#if 0
DisplayDriver10x11Clock driver;
WordFactoryEnglish10x11Clock wordFactory;
WordingStrategyEnglish strategy = { &wordFactory };
#elif 0
DisplayDriverFablabNeaClock driver;
WordFactoryFrankenClock wordFactory;
WordingStrategyFranken strategy = { &wordFactory };
#else
DisplayDriverFrickelClock driver;
WordFactoryFrickelClock wordFactory;
WordingStrategyStesie strategy = { &wordFactory };
#endif

//NullAnimator animator = { &driver };
//IncrementalAnimator animator = { &driver };
FallingStarAnimator animator = { &driver };

#if 1
WordClockScene wordClockScene = { &animator, &strategy };
#else
MockWordClockScene wordClockScene = { &animator, &strategy };
#endif

PersistentColors persistentColors = { &persistentStorage, &wordClockScene };
MqttController *mqttController = new MqttController(&persistentColors, wifiClient);

void setup() {
  driver.setup();

#ifdef ESP8266
  Serial.begin(9600);
#endif

  persistentStorage.setup();

#ifdef ESP8266
  wifiMulti.addAP(persistentStorage.wifi.ssid, persistentStorage.wifi.password);

  while (wifiMulti.run() != WL_CONNECTED) {
    delay(500);
  }

  syncTime();
#endif

  persistentColors.setup();

  if (persistentStorage.flags.mqttEnabled) {
    mqttController->setServer(persistentStorage.mqtt.domain);
    mqttController->setId(persistentStorage.mqtt.clientId);
    mqttController->setUser(persistentStorage.mqtt.user);
    mqttController->setPassword(persistentStorage.mqtt.password);
  }
}

void loop() {
#ifdef ESP8266
  wifiMulti.run();
#endif

  if (persistentStorage.flags.mqttEnabled) {
    mqttController->maintain();
  }

  wordClockScene.loop();
  delay(1000);
}

