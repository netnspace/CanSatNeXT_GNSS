// Copyright (c) 2023 Samuli Nyman
// SPDX-License-Identifier: MIT

#include "CanSatNeXT_GNSS.h"
#include <SparkFun_u-blox_GNSS_Arduino_Library.h> // Include the library for the U-blox GNSS module
SFE_UBLOX_GNSS myGNSS;



uint8_t GNSS_init(uint8_t dynamic_model){
  Serial2.begin(38400, SERIAL_8N1, 16, 17);  // Initialize Serial2 with parameters

  // Try to connect with current baud rate
  if (!myGNSS.begin(Serial2))
  {
    // not successful, let's try the default baud rate
    Serial2.begin(9600, SERIAL_8N1, 16, 17);  // Switch to 38400 baud
    delay(100);
    if (myGNSS.begin(Serial2) == true) {
        myGNSS.setSerialRate(38400);
        Serial2.begin(38400, SERIAL_8N1, 16, 17);  // Switch to 38400 baud
        delay(100);
    } else {
        return 1; // failed to connect
    }
  }

  myGNSS.setDynamicModel((dynModel) dynamic_model);
  myGNSS.setUART1Output(COM_TYPE_UBX); // Set the UART port to output UBX only
  myGNSS.setI2COutput(COM_TYPE_UBX); // Set the I2C port to output UBX only (turn off NMEA noise)
  myGNSS.saveConfiguration(); // Save the current settings to flash and BBR

  return 0;
}

uint8_t fixType(){
  return myGNSS.getFixType();
}

uint32_t getTime(){
  return myGNSS.getUnixEpoch();
}

uint8_t readPosition(float &latitude, float &longitude, float &altitude){
    latitude = myGNSS.getLatitude()/10000000;

    longitude = myGNSS.getLongitude()/10000000;

    altitude = myGNSS.getAltitude()/1000;

    return 0;
}


