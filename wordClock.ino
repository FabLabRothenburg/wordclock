#ifdef ESP8266
#  include <ESP8266WiFi.h>
#  include <ArduinoOTA.h>
#  include <ESP8266mDNS.h>
#endif

#include "DisplayDriver10x11Clock.h"
#include "DisplayDriverFablabNeaClock.h"
#include "DisplayDriverFrickelClock.h"
#include "FallingStarAnimator.h"
#include "IncrementalAnimator.h"
#include "HttpController.h"
#include "NtpClient.h"
#include "NullAnimator.h"
#include "MockWordClockScene.h"
#include "MqttController.h"
#include "PersistentColors.h"
#include "PersistentStorage.h"
#include "WordFactoryGermanV2Clock.h"
#include "WordingStrategyStesie.h"
#include "WordingStrategyEnglish.h"
#include "WordingStrategyFranken.h"
#include "WordClockScene.h"

#ifdef ESP8266
WiFiClient wifiClient;
#endif

#if 0
DisplayDriver10x11Clock driver;
WordFactoryEnglish10x11Clock wordFactory;
WordingStrategyEnglish strategy = { &wordFactory };
#elif 1
DisplayDriverFablabNeaClock driver;
WordFactoryGermanV2Clock wordFactory;
WordingStrategyFranken strategy = { &wordFactory };
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

PersistentColors persistentColors = { &animator };
MqttController *mqttController = new MqttController(&persistentColors, wifiClient);

static void setupWifiAP() {
  IPAddress apIP(192, 168, 4, 1);
  IPAddress netMsk(255, 255, 255, 0);

  char ssid[32];
  sprintf(ssid, "wordclock-%06x", ESP.getChipId());

  WiFi.softAPConfig(apIP, apIP, netMsk);
  WiFi.softAP(ssid);
}

static void setupWifi() {
  if (persistentStorage.wifi.ssid[0] != 0) {
    WiFi.mode(WIFI_STA);
    WiFi.begin(persistentStorage.wifi.ssid, persistentStorage.wifi.password);

    int retry_count = 0;
    while (WiFi.status() != WL_CONNECTED && retry_count < 20) {
      delay(500);
      Serial.print(".");
      retry_count ++;
    }
  }

  if (WiFi.status() == WL_CONNECTED) {
    syncTime();
  } else {
    setupWifiAP();
  }
}

void setup() {
  driver.setup();

#ifdef ESP8266
  Serial.begin(115200);
#endif

  persistentStorage.setup();

#ifdef ESP8266
  setupWifi();

  char tmp[32];
  sprintf(tmp, "wordclock-%06x", ESP.getChipId());
  ArduinoOTA.setHostname(tmp);
  ArduinoOTA.begin();

  MDNS.addService("http", "tcp", 80);
#endif

  persistentColors.setup();
  httpController.setup();

  if (persistentStorage.flags.mqttEnabled) {
    mqttController->setServer(persistentStorage.mqtt.domain);
    mqttController->setId(persistentStorage.mqtt.clientId);
    mqttController->setUser(persistentStorage.mqtt.user);
    mqttController->setPassword(persistentStorage.mqtt.password);
  }
}

void loop() {
#ifdef ESP8266
  if (persistentStorage.wifi.ssid[0] != 0 && WiFi.status() != WL_CONNECTED) {
    Serial.println("Connection lost, reconnecting");
    WiFi.reconnect();

    int retry_count = 0;
    while (WiFi.status() != WL_CONNECTED && retry_count < 20) {
      delay(500);
      Serial.print(".");
      retry_count ++;
    }
  }

  if (persistentStorage.flags.mqttEnabled) {
    mqttController->maintain();
  }

  MDNS.update();
  ArduinoOTA.handle();

  httpController.maintain();
#endif

  wordClockScene.loop();
  delay(1000);
}

