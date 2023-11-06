/*
    This example shows how to use CanSatNeXT_GNSS library to read latitude, longitude, altitude and time
    from the GNSS module. Latitude and longitude are in degrees and the altitude is in meters. The timestamp
    is in unix time, i.e. seconds elapsed since 1st of January 1970 on midnight UTC.
*/

#include "CanSatNeXT_GNSS.h"

// Declare variables to hold latitude, longitude and altitude.
float latitude = 0, longitude = 0, altitude = 0;

void setup()
{
    // Initialize serial so we can print information
    Serial.begin(115200);

    // Initialize the GNSS module. This sets correct settings etc.
    if(GNSS_init() == 0){
        Serial.println("Module not found");
        return;
    }

    // Note on the GNSS initialization: By default the GNSS is told to assume it is stationary on the height axis
    // You can change this behavior by initializing the GNSS like this: GNSS_init(DYNAMIC_MODEL_AIRBORNE);
}

void loop()
{
    // Check if we have fix.
    if(fixType()!=0)
    {
        // Read new position to the variables
        readPosition(latitude, longitude, altitude);

        // Read current unix timestamp
        uint32_t unixTime = getTime();

        // Print the readings
        Serial.print("Latitude: ");
        Serial.print(latitude);
        Serial.print(", Longitude: ");
        Serial.print(longitude);
        Serial.print(", Altitude: ");
        Serial.print(altitude);
        Serial.print(", Unix timestamp:");
        Serial.println(unixTime);
    }else{
        Serial.println("No fix");
    }

    // wait for a bit before checking the GNSS again 
    delay(1000);
}