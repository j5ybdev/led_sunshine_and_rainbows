# Sunshine ☀️ and Rainbows 🌈 LED strips controller

Arduino code to control a 7 RGB LED ring light (sun) and a 30 LED half circle RGB LED ring light (Rainbow) to make a 'Sunshine and Rainbows' scene.

## Hardware
### Controller: ESP32 Dev Board
 - link: https://www.amazon.com/gp/product/B08BYJR9Y4
 - menu: ESP 32 Arduino -> ESP 32 Dev Module
### Sun: 7 LED WS2812 5050 RGB LED Ring Lamp w/ integrated drivers
 - link: https://www.amazon.com/dp/B089PWMQ59
### Rainbow: Half of 60 LED WS2812B 5050 RGB LED Ring Lamp w/ integrated drivers
 - link: https://www.amazon.com/dp/B09N3KHG1W


## Dev Environment Setup on Ubuntu
Install Arduino IDE
 - Add user to dialout group
```sh
sudo usermod -aG dialout myusername
```
- reboot
- Add additional board URL https://dl.espressif.com/dl/package_esp32_index.json
- Install esp32 boards in Board Manager
- Install Adafruit NeoPixel Library in Library Manager
- Install esptool
```sh
sudo apt install python3 python-is-python3 python3-pip
pip install pyserial
pip install esptool
```
- If on Ubuntu 22.04, remove brltty to prevent devices from disconnecting
```sh
sudo apt remove brltty
```
