esp-hello-world
========

This a simple "Hello World" application for the low cost WiFi SoC ESP8266.

The application and the instructions have been tested on [Olimex MOD-WIFI-ESP8266-DEV](https://www.olimex.com/Products/IoT/MOD-WIFI-ESP8266-DEV/ "Olimex MOD-WIFI-ESP8266-DEV").

How to build project and upload:

* Install ESP8266 toolchain
* Build the project
* Connect the board to a personal computer
* Upload the project to the board
* Run "Hello World"

### Install ESP8266 toolchain
Please follow these instructions to install and set up ESP8266 toolchain:
https://github.com/esp8266/esp8266-wiki/wiki

### Build the project
Clone this repository into Espressif install directory

```shell
cd /opt/Espressif
git clone https://github.com/leon-anavi/esp-hello-world.git
cd esp-hello-world
make
```

### Connect the board to a personal computer in a flash mode

You will need 3.3V cable like [USB-SERIAL-CABLE-F](https://www.olimex.com/Products/Components/Cables/USB-Serial-Cable/USB-Serial-Cable-F/ "USB-Serial-Cable-F").

Connect cable as follows:
* blue --> uext pin-2
* green --> uext pin-3
* red --> ext pin-4

Connect the cable to the USB port of the personal computer. You should see the new device in /dev/tty*, for example /dev/ttyUSB0 if you see other update makefile properly.

To go into bootloader (aka flash) mode, simply connect PIN 21 (GPIO0) to GND.

### Upload the project

If you have build the project without errors you can upload the code to ESP8266 with the following command:

```shell
sudo make flash
```
Now everything is complete and you are ready to test the application.

### Run the project

* Disconnect the power of the board
* Remove the wire from PIN 21 (GPIO0) to exit flash mode
* Launch a terminal on the personal computer to read data from the UART console: ```shell
sudo screen /dev/ttyUSB0 115200
```
* Power again the board and you will see "Hello World" in the terminal of the personal computer
