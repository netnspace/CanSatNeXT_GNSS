# CanSatNeXT_GNSS library

This library extends CanSat NeXT to add support for the GNSS board. This library prioritizes ease-of-use, and only has basic functionalities such as getting location and time from the GNSS. For users looking for more advanced GNSS features, the excellent SparkFun_u-blox_GNSS_Arduino_Library might be a better choice. This library is actually just a wrapper for that library, just making all configurations with CanSat operations in mind.

While this library is intended to be used with CanSat NeXT, other use is permitted as well. For more information, refer to the license found in this repository.

# Getting started

This is an Arduino library, designed to be primarily used through the Arduino IDE. Here are the basic steps to get started with the library:

1. Install the Arduino IDE: Download and install the Arduino IDE from the official website if you haven't already.

2. Install ESP32 Support: 
   - Open the Arduino IDE.
   - Navigate to Tools -> Board -> Boards Manager.
   - In the search bar, type "ESP32" and find the option provided by Espressif.
   - Click on the "Install" button to add ESP32 support to your Arduino IDE.

3. Install the CanSatNeXT_GNSS Library:
   - In the Arduino IDE, go to Sketch -> Include Library -> Manage Libraries.
   - In the search bar, type "CanSatNeXT_GNSS" and find the corresponding library.
   - Click on the "Install" button to install the library. If the Arduino IDE asks if you want to install with dependencies - click yes.
   - Alternatively, you can manually add the library by downloading this repository and saving it into the Arduino libraries folder on your computer.

4. Connect the CanSatNeXT_GNSS
   - Turn power off from CanSat NeXT
   - Plug in the GNSS board, making sure all the pins are attached
   - Turn power on. The GNSS module will immediately start looking for a location fix.

5. Get Started with the CanSatNeXT:
   - Check examples for how to read the location, go to File -> Examples -> CanSatNeXT_GPS in the Arduino IDE.

# Pinout

Below is the pinout of the CanSat NeXT extension header. The pins are also shared with the GNSS module. This module and library use the pins 16 and 17 (UART2 TX/RX) for connecting the GNSS radio.

The picture below shows the pins for using the extension header for adding external electronics to the board.

![image description](https://lh3.googleusercontent.com/drive-viewer/AK7aPaDrKPQzTgqN-vACXaDWKlyC1ZMQ5sLF344OpBNhWeb7bTWGEP2YD6sUS9N-EKQ_dZ4yIQjQIWknBSTpaJIGGBf7yUxEAg=s1600)

# License

This library and the CanSat NeXT board are developed by Samuli Nyman, in collaboration with ESERO Finland and Arctic Astronautics Oy. The development is also supported by the Finnish Physical Society. This software library is licensed under the MIT license.

# Contribution

If you wish to contribute to the library or if you have feedback, please contact me through samuli@kitsat.fi or start a GitHub issue. You are also welcome to create a pull request.

