#ifndef HTTP_CONTROLLER_H
#define HTTP_CONTROLLER_H

#include <ESP8266WebServer.h>

class HttpController {
  public:
    void setup();
    void maintain();
};

extern HttpController httpController;

#endif  /* HTTP_CONTROLLER_H */

