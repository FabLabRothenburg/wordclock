#include "HttpController.h"
#include "HttpContent.h"
#include "PersistentStorage.h"

extern PersistentStorage persistentStorage;

static ESP8266WebServer server(80);
HttpController httpController;

#define readCharParam(setting,param) \
  if (server.hasArg(#param)) { \
    server.arg(#param).toCharArray(setting, sizeof(setting)); \
  }

#define readBoolParam(setting,param) \
  do { \
    setting = false; \
    if (server.hasArg(#param)) { \
      setting = server.arg(#param) == "1"; \
    } \
  } while(0)

#define readIntParam(setting,param)  \
  if (server.hasArg(#param)) { \
    setting = server.arg(#param).toInt(); \
  }


String form_input(const String& name, const String& info, const String& value, const int length) {
    String s = F("<div>{i}: <input type='text' name='{n}' id='{n}' placeholder='{i}' value='{v}' maxlength='{l}'/></div>");
    String t_value = value;
    t_value.replace("'", "&#39;");
    s.replace("{i}", info);
    s.replace("{n}", name);
    s.replace("{v}", t_value);
    s.replace("{l}", String(length));
    return s;
}

String form_password(const String& name, const String& info, const String& value, const int length) {
    String s = F("<div>{i}: <input type='password' name='{n}' id='{n}' placeholder='{i}' value='{v}' maxlength='{l}'/></div>");
    String t_value = value;
    t_value.replace("'", "&#39;");
    s.replace("{i}", info);
    s.replace("{n}", name);
    s.replace("{v}", t_value);
    s.replace("{l}", String(length));
    return s;
}

String form_number(const String& name, const String& info, const int value, const int min, const int max) {
    String s = F("<div>{i} ({min}..{max}): <input type='number' name='{n}' id='{n}' placeholder='{i} ({min}..{max})' value='{v}' min='{min}' max='{max}'/></div>");
    s.replace("{i}", info);
    s.replace("{n}", name);
    s.replace("{v}", String(value));
    s.replace("{min}", String(min));
    s.replace("{max}", String(max));
    return s;
}

String form_checkbox(const String& name, const String& info, const bool checked) {
    String s = F("<div><label for='{n}'><input type='checkbox' name='{n}' value='1' id='{n}' {c}/> {i}</label></div>");
    if (checked) {
        s.replace("{c}", F(" checked='checked'"));
    } else {
        s.replace("{c}", "");
    };
    s.replace("{i}", info);
    s.replace("{n}", name);
    return s;
}

String form_submit() {
    String s = F("<div><input type='submit' name='submit' value='Save &amp; Apply Changes' /></div>");
    return s;
}

static void handleRoot() {
  String content = FPSTR(WEB_PAGE_HEADER);
  content.replace("{title}", F("WordClock Configuration"));

  if (server.method() == HTTP_GET) {
    content += F("<form method='POST'>");

    content += F("<h4>Wifi Settings</h4>");
    content += form_input("wifissid", F("SSID"), persistentStorage.wifi.ssid, 16);
    content += form_password("wifipassword", F("Password"), persistentStorage.wifi.password, 64);

    content += F("<h4>Primary Text Color</h4>");
    content += form_number("red", F("Red"), persistentStorage.red, 0, 255);
    content += form_number("green", F("Green"), persistentStorage.green, 0, 255);
    content += form_number("blue", F("Blue"), persistentStorage.blue, 0, 255);

    content += F("<h4>NTP Settings</h4>");
    content += form_input("ntphost", F("Host"), persistentStorage.ntp.domain, sizeof(persistentStorage.ntp.domain));
    
    content += F("<h4>MQTT Settings</h4>");
    content += form_checkbox("mqttenabled", F("Enabled"), persistentStorage.flags.mqttEnabled);
    content += form_input("mqtthost", F("Host"), persistentStorage.mqtt.domain, 16);
    content += form_input("mqttclientid", F("Client-ID"), persistentStorage.mqtt.clientId, 16);
    content += form_input("mqttuser", F("User"), persistentStorage.mqtt.user, 16);
    content += form_password("mqttpassword", F("Password"), persistentStorage.mqtt.password, 64);

    content += form_submit();
    content += F("</form>");
  } else {
    readCharParam(persistentStorage.wifi.ssid, wifissid);
    readCharParam(persistentStorage.wifi.password, wifipassword);
    readIntParam(persistentStorage.red, red);
    readIntParam(persistentStorage.green, green);
    readIntParam(persistentStorage.blue, blue);
    readBoolParam(persistentStorage.flags.mqttEnabled, mqttenabled);
    readCharParam(persistentStorage.ntp.domain, ntphost);
    readCharParam(persistentStorage.mqtt.domain, mqtthost);
    readCharParam(persistentStorage.mqtt.clientId, mqttclientid);
    readCharParam(persistentStorage.mqtt.user, mqttuser);
    readCharParam(persistentStorage.mqtt.password, mqttpassword);
    Serial.println("updated mqtt domain to: " + String(persistentStorage.mqtt.domain));
    persistentStorage.commit();
    ESP.reset();
  }

  content += FPSTR(WEB_PAGE_FOOTER);
  server.send(200, "text/html", content);
}

static void handleNotFound(){
  String message = "File Not Found\n\n";
  message += "URI: ";
  message += server.uri();
  message += "\nMethod: ";
  message += (server.method() == HTTP_GET) ? "GET" : "POST";
  message += "\nArguments: ";
  message += server.args();
  message += "\n";

  for (uint8_t i = 0; i < server.args(); i ++) {
    message += " " + server.argName(i) + ": " + server.arg(i) + "\n";
  }

  server.send(404, "text/plain", message);
}

void HttpController::setup() {
  server.on("/", handleRoot);

  server.onNotFound(handleNotFound);
  server.begin();
}

void HttpController::maintain() {
  server.handleClient();
}
