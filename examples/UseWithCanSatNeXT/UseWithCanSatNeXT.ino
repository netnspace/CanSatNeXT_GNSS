/*
    This example shows how to use CanSatNeXT_GNSS library together with CanSat library to transmit the location over the radio.
*/

// Include both libraries
#include "CanSatNeXT_GNSS.h"
#include "CanSatNeXT.h"

// Declare variables to hold latitude, longitude and altitude.
float latitude = 0, longitude = 0, altitude = 0;
long GNSSTimer = 0;

void setup()
{
    // Initialize serial so we can print information
    Serial.begin(115200);

    // Let's initialize CanSat just like normally
    CanSatInit(72);

    // Initialize the GNSS module. This sets correct settings etc.
    if(!GNSS_init()){
        Serial.println("Module not found");
        return;
    }

    // Note on the GNSS initialization: By default the GNSS is told to assume a highly dynamic movement (like a rocket!)
    // This makes the 2D-position significantly less accurate, but allows maintaining fix during acceleration. 
    // If you would preferer more accuracy once landed, initialize the GNSS like this: GNSS_init(DYNAMIC_MODEL_GROUND);
}

void loop()
{
    // Check GPS every 1 seconds - Note: Trying to read the position more than 10 times per second will lead to timing issues
    if (millis() - GNSSTimer > 1000)
    {
        GNSSTimer = millis(); //Update the timer

        // Read new position to the variables
        readPosition(latitude, longitude, altitude);

        // Sprintf can be used to print a formatted string into a character array, which we can then transmit and print. 
        char msg[64];
        sprintf(msg, "Latitude: %.5f, Longitude: %.5f, Altitude: %.2f", latitude, longitude, altitude);
        sendData(msg);
        Serial.println(msg);
        
    }
}