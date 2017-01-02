#ifdef ESP8266
#include <Arduino.h>
#include <PubSubClient.h>

#include "IColorControllable.h"

class MqttController {
  private:
    PubSubClient mqttClient;

    const char *id;
    const char *user;
    const char *password;

    IColorControllable *colorControllable;

  public:
    MqttController(IColorControllable *colorControllable, Client& client);
    
    void setServer(IPAddress ip, uint16_t port = 1883) { mqttClient.setServer(ip, port); }
    void maintain();

    void setId(const char *id) { this->id = id; }
    void setUser(const char *user) { this->user = user; }
    void setPassword(const char *password) { this->password = password; }

    void handle(char* topic, byte* payload, unsigned int length);

  private:
    void reconnect();

    void publish(const char *topic, const char *payload);
    void subscribe(const char *topic);
};

#endif  /* ESP8266 */
