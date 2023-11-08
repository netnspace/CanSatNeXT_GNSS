/*
    This example shows how to use CanSatNeXT_GNSS library to read latitude, longitude, altitude and time
    from the GNSS module. Latitude and longitude are in degrees and the altitude is in meters. The timestamp
    is in unix time, i.e. seconds elapsed since 1st of January 1970 on midnight UTC.
*/

#include "CanSatNeXT_GNSS.h"

// Declare variables to hold latitude, longitude and altitude.
float latitude = 0, longitude = 0, altitude = 0;
long GNSSTimer = 0;

void setup()
{
    // Initialize serial so we can print information
    Serial.begin(115200);

    // Initialize the GNSS module. This sets correct settings etc.
    if(!GNSS_init()){
        Serial.println("Module not found");
        return;
    }

    // Note on the GNSS initialization: By default the GNSS is told to assume it is stationary on the height axis
    // You can change this behavior by initializing the GNSS like this: GNSS_init(DYNAMIC_MODEL_AIRBORNE);
}

void loop()
{
    // Check GPS every 1 seconds - Note: Trying to read the position more than 10 times per second will lead to timing issues
    if (millis() - GNSSTimer > 1000)
    {
        GNSSTimer = millis(); //Update the timer

        // We want to update the position only when we have good satellite fixes.
        // getSIV() returns the number of satellites we are receiving from. Let's only update the position
        // if we have fix to three or more satellites. Less than three can't create a unique position solution.
        if(getSIV()>=3)
        {
          // Read new position to the variables
          readPosition(latitude, longitude, altitude);
          // Read current unix timestamp
          uint32_t unixTime = getTime();

          // Print the readings
          Serial.print("Latitude: ");
          Serial.print(latitude, 5); // Print with five decimal places
          Serial.print(", Longitude: ");
          Serial.print(longitude, 5);
          Serial.print(", Altitude: ");
          Serial.print(altitude);
          Serial.print(", Unix timestamp:");
          Serial.print(unixTime);
          Serial.print(", Millis: ");
          Serial.println(millis());
        }else{
          Serial.println("No fix");
        }
    }
}