// Copyright (c) 2023 Samuli Nyman
// SPDX-License-Identifier: MIT

#ifndef CANSAT_GNSS_H
#define CANSAT_GNSS_H

#include "Arduino.h"

#define DYNAMIC_MODEL_GROUND 0
#define DYNAMIC_MODEL_AIRBORNE 7
#define DYNAMIC_MODEL_ROCKET 8

uint8_t GNSS_init(uint8_t dynamic_model = DYNAMIC_MODEL_ROCKET);
uint8_t readPosition(float &latitude, float &longitude, float &altitude);
uint8_t getSIV();
uint32_t getTime();

#endif