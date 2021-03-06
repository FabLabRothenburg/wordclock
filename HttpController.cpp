#include "DiyHueController.h"
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

#define readBoolParam(setting,param) { \
    setting = false; \
    if (server.hasArg(#param)) { \
      setting = server.arg(#param) != "0"; \
    } \
  }

#define readIntParam(setting,param)  \
  if (server.hasArg(#param)) { \
    setting = server.arg(#param).toInt(); \
  }

#define readColorParam(r,g,b,param) \
  if (server.hasArg(#param)) { \
    r = strtol(server.arg(#param).substring(1, 2+1).c_str(), NULL, 16); \
    g = strtol(server.arg(#param).substring(3, 4+1).c_str(), NULL, 16); \
    b = strtol(server.arg(#param).substring(5).c_str(), NULL, 16); \
  }

String form_small_header(const String& name) {
    String s = F("<hr><div><b>{n}</b></div>");
    s.replace("{n}", name);
    return s;
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

String getColorHex( uint8_t color ) {
  String str = String(color, HEX);
  if(str.length() < 2)
  {
    str = "0";
    str += String(color, HEX);
  }
  return str;
}

String form_color_input(const String& name, const String& info, uint8_t red, uint8_t green, uint8_t blue ) {
    String colorStr = F("#");
    colorStr += getColorHex( red );
    colorStr += getColorHex( green );
    colorStr += getColorHex( blue );
    String s = F("<div>{i}: <input type='color' id='{n}' name='{n}' placeholder='{i}' value='{c}'></div>");
    s.replace("{i}", info);
    s.replace("{n}", name);
    s.replace("{c}", colorStr);
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

#define USE_COLOR_PICKER 0

static void handleRoot() {
  String content = FPSTR(WEB_PAGE_HEADER);
  content.replace("{title}", F("WordClock Configuration"));

  if (server.method() == HTTP_GET) {
    content += F("<form method='POST'>");

    content += form_small_header("WiFi Settings");
    content += form_input("wifissid", F("SSID"), persistentStorage.wifi.ssid, 32);
    content += form_password("wifipassword", F("Password"), persistentStorage.wifi.password, 64);

    content += form_small_header("Primary Text Color");
    if(USE_COLOR_PICKER)
    {
      content += form_color_input("textcolor", F("Color"), persistentStorage.red, persistentStorage.green, persistentStorage.blue);
    }
    else
    {
      content += form_number("red", F("Red"), persistentStorage.red, 0, 255);
      content += form_number("green", F("Green"), persistentStorage.green, 0, 255);
      content += form_number("blue", F("Blue"), persistentStorage.blue, 0, 255);
    }

    content += form_small_header("NTP Settings");
    content += form_input("ntphost", F("Host"), persistentStorage.ntp.domain, sizeof(persistentStorage.ntp.domain));
    
    content += form_small_header("MQTT Settings");
    content += form_checkbox("mqttenabled", F("Enabled"), persistentStorage.flags.mqttEnabled);
    content += form_input("mqtthost", F("Host"), persistentStorage.mqtt.domain, 16);
    content += form_input("mqttclientid", F("Client-ID"), persistentStorage.mqtt.clientId, 16);
    content += form_input("mqttuser", F("User"), persistentStorage.mqtt.user, 16);
    content += form_password("mqttpassword", F("Password"), persistentStorage.mqtt.password, 64);

    content += F("<br/>");
    content += form_submit();
    content += F("</form>");
  }
  else {
    readCharParam(persistentStorage.wifi.ssid, wifissid);
    readCharParam(persistentStorage.wifi.password, wifipassword);
    if(USE_COLOR_PICKER)
    {
      readColorParam(persistentStorage.red, persistentStorage.green, persistentStorage.blue, textcolor);
    }
    else
    {
      readIntParam(persistentStorage.red, red);
      readIntParam(persistentStorage.green, green);
      readIntParam(persistentStorage.blue, blue);
    }
   
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

static void handleDiyHueSet() {
  float transitiontime = 4;

  for (uint8_t i = 0; i < server.args(); i++) {
    if (server.argName(i) == "on") {
      if (server.arg(i) == "True" || server.arg(i) == "true") {
        diyHueController.setLightState(true);
      }
      else {
        diyHueController.setLightState(false);
      }
    }
    else if (server.argName(i) == "r") {
      diyHueController.setRed(server.arg(i).toInt());
    }
    else if (server.argName(i) == "g") {
      diyHueController.setGreen(server.arg(i).toInt());
    }
    else if (server.argName(i) == "b") {
      diyHueController.setBlue(server.arg(i).toInt());
    }
    else if (server.argName(i) == "x") {
      diyHueController.setColorX(server.arg(i).toFloat());
    }
    else if (server.argName(i) == "y") {
      diyHueController.setColorY(server.arg(i).toFloat());
    }
    else if (server.argName(i) == "bri") {
      diyHueController.setBri(server.arg(i).toInt());
    }
    else if (server.argName(i) == "bri_inc") {
      diyHueController.incBri(server.arg(i).toInt());
    }
    else if (server.argName(i) == "ct") {
      diyHueController.setCt(server.arg(i).toInt());
    }
    else if (server.argName(i) == "sat") {
      diyHueController.setSat(server.arg(i).toInt());
    }
    else if (server.argName(i) == "hue") {
      diyHueController.setHue(server.arg(i).toInt());
    }
    else if (server.argName(i) == "alert" && server.arg(i) == "select") {
      diyHueController.alert();
    }
    else if (server.argName(i) == "transitiontime") {
      transitiontime = server.arg(i).toInt();
    }
  }

  server.send(200, "text/plain", "OK");
  //server.send(200, "text/plain", "OK, x: " + (String)x[light] + ", y:" + (String)y[light] + ", bri:" + (String)bri[light] + ", ct:" + ct[light] + ", colormode:" + color_mode[light] + ", state:" + light_state[light]);
  diyHueController.process_lightdata(transitiontime);
}

static void handleDiyHueGet() {
  String colormode;
  String power_status = diyHueController.getLightState() ? "true" : "false";
  
  if (diyHueController.getColorMode() == 1)
    colormode = "xy";
  else if (diyHueController.getColorMode() == 2)
    colormode = "ct";
  else if (diyHueController.getColorMode() == 3)
    colormode = "hs";

  server.send(200, "text/plain", "{\"on\": " + power_status
    + ", \"bri\": " + (String)diyHueController.getBri()
    + ", \"xy\": [" + (String)diyHueController.getColorX() + ", " + (String)diyHueController.getColorY()
    + "], \"ct\":" + (String)diyHueController.getCt()
    + ", \"sat\": " + (String)diyHueController.getSat()
    + ", \"hue\": " + (String)diyHueController.getHue()
    + ", \"colormode\": \"" + colormode + "\"}");
}

static void handleDiyHueDetect() {
  server.send(200, "text/plain", "{\"hue\": \"bulb\",\"lights\": 1,\"modelid\": \"LCT015\",\"name\": \"wordClock\",\"mac\": \"" + WiFi.macAddress() + "\"}");
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
  server.on("/set", handleDiyHueSet);
  server.on("/get", handleDiyHueGet);
  server.on("/detect", handleDiyHueDetect);

  server.onNotFound(handleNotFound);
  server.begin();
}

void HttpController::maintain() {
  server.handleClient();
}
