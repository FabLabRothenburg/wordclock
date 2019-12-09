# WordClock
## Hardware
Take a look inside the [hardware](hardware/) directory.

## Software
you have two options to build this software:
1. Using Arduino IDE
2. Using platformio

## Arduino IDE

### Adding ESP8266 Board
If you want to use ESP8266 hardware you first need to do add it to Arduino.
* Install the current upstream Arduino IDE at the 1.8.7 level or later. The current version is on the [Arduino website](https://www.arduino.cc/en/main/software).
* Start Arduino and open the Preferences window.
* Enter ```https://arduino.esp8266.com/stable/package_esp8266com_index.json``` into the *Additional Board Manager URLs* field. You can add multiple URLs, separating them with commas.
* Open Boards Manager from Tools > Board menu and install *esp8266* platform (and don't forget to select your ESP8266 board from Tools > Board menu after installation).

### Installing the required libraries
Please refer to the [platformio configuration](platformio.ini) for a list of required libraries.

## platformio
* [Install platformio](https://docs.platformio.org/en/latest/installation.html)
* To build this project for your target, such as D1 Mini run:

```
pio run -e d1_mini
```

* To upload the firmware to your Word Clock, run:

```
pio run -e d1_mini -t upload
```
