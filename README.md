# lora-irrigation-network
IoT LoRa Network to monitor community garden plot moisture. Internet-free and scalable.
*REMOVE USB BUILD FLAG IN platform.ini*

# Setup
1) Download arduino-cli
2) Download PlatformIO (for build tools)[https://docs.platformio.org/en/latest/core/installation/index.html]

## Setup continued (Nvim)
1) create platformio.ini to set board and platform
2) clone https://github.com/ironlungx/nvim-pio.git
3) run: pio init --ide vim
4) cp -r /boards/ /nvim-pio/boards
5) cp -r /variants/ /nvim-pio/variants
6) cd nvim-pio && python3 conv.py

# Platform IO
pio run
pio run -t upload
pio device monitor -b 115200

# Resources
(Micro Reticulum C++)[https://github.com/Reticulum-Community/microReticulum]
(Heltec_V4 wiki for PlatformIO)[https://wiki.heltec.org/docs/devices/open-source-hardware/esp32-series/three-platform/PlatformIO/]
- Note the above does not enable LoRaWan
