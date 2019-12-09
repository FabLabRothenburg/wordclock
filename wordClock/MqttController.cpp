#ifdef ESP8266
#include "MqttController.h"

/* ugly */
extern MqttController *mqttController;
static void mqtt_message_handler(char* topic, byte* payload, unsigned int length) {
  mqttController->handle(topic, payload, length);
}

MqttController::MqttController(IColorControllable *colorControllable, Client& client)
  : colorControllable(colorControllable) {
  mqttClient.setCallback(mqtt_message_handler);
  mqttClient.setClient(client);
}

void MqttController::maintain() {
  if (!mqttClient.connected())
    reconnect();
  mqttClient.loop();
}

void MqttController::reconnect() {
  Serial.println("Attempting MQTT connection...");
  
  if (!mqttClient.connect(id, user, password)) {
    Serial.println("MQTT connect failed.");
    return;  /* failed to connect */
  }

  publish("status", "hello world");

  subscribe("color/red");
  subscribe("color/green");
  subscribe("color/blue");
}

void MqttController::publish(const char *topic, const char *payload) {
  uint8_t i = strlen(id);
  char buffer[i + strlen(topic) + 2];
  strcpy(buffer, id);
  buffer[i++] = '/';
  strcpy(&buffer[i], topic);

  Serial.print("publishing to topic: ");
  Serial.println(buffer);
  
  mqttClient.publish(buffer, payload);
}

void MqttController::subscribe(const char *topic) {
  uint8_t i = strlen(id);
  char buffer[i + strlen(topic) + 2];
  strcpy(buffer, id);
  buffer[i++] = '/';
  strcpy(&buffer[i], topic);

  Serial.print("subscribing to: ");
  Serial.println(buffer);
  
  mqttClient.subscribe(buffer);
}

void MqttController::handle(char* topic, byte* payload, unsigned int length) {
  Serial.print("Message arrived [");
  Serial.print(topic);
  Serial.print("] ");

  for (unsigned int i = 0; i < length; i ++)
    Serial.print((char) payload[i]);

  if (length > 10) {
    Serial.println("ignoring loooong message");
    return;
  }

  Serial.println();
  Serial.println(topic);
  Serial.println(id);
  Serial.println(String(strlen(id)));

  char *ptr = topic + strlen(id) + 1;

  Serial.print("subcommand: ");
  Serial.println(ptr);

  char buf[length + 1];
  memmove (buf, payload, length);
  buf[length] = 0;

  int value = atoi(buf);
  Serial.print("converted value: ");
  Serial.println(String(value));

  if (strncmp(ptr, "color/red", 9) == 0) {
    Serial.println("color change for RED");
    colorControllable->setRed(value);
  }
  else if (strncmp(ptr, "color/green", 11) == 0) {
    Serial.println("color change for GREEN");
    colorControllable->setGreen(value);
  }
  else if (strncmp(ptr, "color/blue", 10) == 0) {
    Serial.println("color change for BLUE");
    colorControllable->setBlue(value);
  }
}

#endif  /* ESP8266 */
