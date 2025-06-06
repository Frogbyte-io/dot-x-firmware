# Firmware for Dot X devices

## Overview

This repository contains the firmware for Dot X devices, to make it work with Dot X by DotMatrixLabs. The firmware is responsible for handling the slider inputs, and sending them to Dot X.

## Dot X

Dot X is a GUI mainly for controlling Decker, the volume controller made by DotMatrixLabs.
The software allows for easy selection of apps and system features to control, as well as beeing able to see the input live. 

We also plan to expand it further with more features! Check out our [Roadmap/feedback site](https://dotmatrixlabs.sleekplan.app/). Here you can also add your own suggestions!

You can find more info about [Dot X here](https://docs.dotmatrixlabs.com/dot-x/)


## Compatible devices

At this moment, Dot X only supports 5 sliders.

These 5 sliders are connected to pin A0 to A4 in this firmware, but can be changed to match your setup.

### Pin Configuration

The firmware is configured to read from the following analog pins:

| Slider | Arduino Pin |
|--------|-------------|
| Slider 1 | A0 |
| Slider 2 | A1 |
| Slider 3 | A2 |
| Slider 4 | A3 |
| Slider 5 | A4 |

**Note**: You can use any potentiometer value between 1kΩ to 100kΩ. Common values like 10kΩ work well for this application.

## Getting Started

The simplest way to flash an Arduino Nano with the Dot X compatible firmware is by using the [Web Flasher](https://flasher.dotmatrixlabs.com/)

This will flash the Arduino with the firmware without needing to install Arduino IDE. [More info on how this works](https://docs.dotmatrixlabs.com/dot-x/#setting-up-deej-for-dot-x)

You might need to manually install the drivers for Arduino Nano if the device is not recognized by Dot X. [You can follow these instructions to install the correct driver](https://learn.sparkfun.com/tutorials/how-to-install-ch340-drivers/all)

If you want to compile and flash it yourselves, please follow the instructions below.

### Prerequisites

Before you begin, ensure you have the following:

- Compatible hardware
- USB cable
- A computer running Windows
- Arduino IDE (for firmware uploads)

### Installation

1. **Clone the Repository**:
    ```bash
    git clone https://github.com/Frogbyte-io/dot-x-firmware.git
    cd dot-x-firmware
    ```

2. **Install Required Libraries**:
    - Launch Arduino IDE.
    - Go to `Tools > Manage Libraries...` or press `Ctrl+Shift+I`.
    - In the Library Manager, search for "ArduinoJson".
    - Find "ArduinoJson" by Benoit Blanchon and click "Install".
    - Wait for the installation to complete.

3. **Open the Firmware in Arduino IDE**:
    - Open the `device-firmware.ino` file from the `device-firmware` folder in the cloned repository.

4. **Select Your Board and Port**:
    - Go to `Tools > Board` and select the appropriate board.
    - Go to `Tools > Port` and select the correct port for your Dot X hardware.

5. **Upload the Firmware**:
    - Click the upload button in the Arduino IDE to upload the firmware to your Dot X hardware.

## Usage

Once the firmware is uploaded, your Dot X hardware is ready to use. Connect it to your computer, open Dot X, and add the programs or system features you want to control.

For information on how to install and set up Dot X, please visit [the docs](https://docs.dotmatrixlabs.com/dot-x/)

## Issues? 

Open a new issue here in the repository, and we will take a look at it.


## License

This project is licensed under the GPL-3.0 License. See the [LICENSE](LICENSE) file for details.

## Contact

For any questions or support, please open an issue in this repository or contact us at post@frogbyte.io
