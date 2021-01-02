#ifdef ESP8266
#  include <ESP8266WiFi.h>
#  include <ArduinoOTA.h>
#  include <ESP8266mDNS.h>
#endif

#include "DiyHueController.h"
#include "HttpController.h"
#include "NtpClient.h"
#include "MqttController.h"
#include "PersistentColors.h"
#include "PersistentStorage.h"

#include "WordClockScene.h"
#include "MockWordClockScene.h"

#include "AnimatorNull.h"
#include "AnimatorIncremental.h"
#include "AnimatorFallingStar.h"

#include "DisplayDriver10x11Clock.h"
#include "DisplayDriverFablabNeaClock.h"
#include "DisplayDriverFrickelClock.h"

#include "WordFactoryGermanV2Clock.h"
#include "WordFactorySchwabenClock.h"
#include "WordFactoryFrankenClock.h"
#include "WordFactorySwedishClock.h"

#include "WordingStrategyStesie.h"
#include "WordingStrategyEnglish.h"
#include "WordingStrategyFranken.h"
#include "WordingStrategyWest.h"
#include "WordingStrategySchwaben.h"
#include "WordingStrategySwedish.h"

#ifdef ESP8266
WiFiClient wifiClient;
#endif

#if 0
DisplayDriver10x11Clock driver;
WordFactoryEnglish10x11Clock wordFactory;
WordingStrategyEnglish strategy( &wordFactory );
#elif 0
DisplayDriverFablabNeaClock driver;
WordFactoryGermanV2Clock wordFactory;
WordingStrategyWest strategy( &wordFactory );
#elif 0
DisplayDriverFablabNeaClock driver;
WordFactorySchwabenClock wordFactory;
WordingStrategySchwaben strategy( &wordFactory );
#elif 1
DisplayDriverFablabNeaClock driver;
WordFactoryGermanV2Clock wordFactory;
WordingStrategyFranken strategy( &wordFactory );
#elif 0
DisplayDriverFablabNeaClock driver;
WordFactoryFrankenClock wordFactory;
WordingStrategyFranken strategy( &wordFactory );
#elif 0
DisplayDriverFrickelClock driver;
WordFactoryFrickelClock wordFactory;
WordingStrategyStesie strategy( &wordFactory );
#else
DisplayDriverFablabNeaClock driver;
WordFactorySwedishClock wordFactory;
WordingStrategySwedish strategy( &wordFactory );
#endif

//#define TEST_MODE  /* Zum Testen */

#ifdef TEST_MODE
NullAnimator animator( &driver );
#else
//NullAnimator animator( &driver );
//IncrementalAnimator animator( &driver );
FallingStarAnimator animator( &driver );
#endif

DiyHueController diyHueController( &animator );

#if TEST_MODE
MockWordClockScene wordClockScene( &animator, &strategy );
#else
WordClockScene wordClockScene( &animator, &strategy );
#endif

const char strWifiID[] = "Wordclock-%06x";

PersistentColors persistentColors( &diyHueController );

// MQTT Controller can be "configured" to either update persistent colors, i.e. store each
// changed value to EEPROM immediately.  Use this if you want the clock to reset with colors
// updated via EEPROM.
//MqttController *mqttController = new MqttController(&persistentColors, wifiClient);
// Influence animator directly (use this if you intend to update colors often)
MqttController *mqttController = new MqttController(&diyHueController, wifiClient);

static void setupWifiAP() {
  IPAddress apIP(192, 168, 4, 1);
  IPAddress netMsk(255, 255, 255, 0);

  char ssid[32];
  sprintf(ssid, strWifiID, ESP.getChipId());

  WiFi.softAPConfig(apIP, apIP, netMsk);
  WiFi.softAP(ssid);
}

static void setupWifi() {
  if (persistentStorage.wifi.ssid[0] != 0) {
    WiFi.mode(WIFI_STA);
    WiFi.begin(persistentStorage.wifi.ssid, strlen(persistentStorage.wifi.password) > 0 ? persistentStorage.wifi.password : NULL);

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
  Serial.println("wordClock reset, setting up ...");
#endif

  persistentStorage.setup();

#ifdef ESP8266
  setupWifi();

  char tmp[32];
  sprintf(tmp, strWifiID, ESP.getChipId());
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

#ifdef TEST_MODE
  delay(300);
#endif

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
  diyHueController.maintain();
}
