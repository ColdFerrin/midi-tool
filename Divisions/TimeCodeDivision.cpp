//
// Created by ferri on 1/14/2025.
//

#include "TimeCodeDivision.h"

TimeCodeDivision::TimeCodeDivision(TIME_CODE_FORMAT timeCodeFormat, uint8_t ticksPerFrame) {
    this->setDivisionType(DIVISION_TYPE::TIMECODE_TIME);
    this->timeCodeFormat = timeCodeFormat;
    this->ticksPerFrame = ticksPerFrame;
}

TimeCodeDivision::TIME_CODE_FORMAT TimeCodeDivision::getTimeCodeFormat() {
    return this->timeCodeFormat;
}

uint8_t TimeCodeDivision::getTicksPerFrame() {
    return this->ticksPerFrame;
}

TimeCodeDivision::TIME_CODE_FORMAT TimeCodeDivision::findTimeCodeFormat(uint8_t smpteFormat) {
    int8_t smpteFormatInt = ((smpteFormat & 0x40) << 1) | (smpteFormat & 0x3F);
    if (smpteFormatInt == -24) {
        return _24;
    }
    if (smpteFormatInt == -25) {
        return _25;
    }
    if (smpteFormatInt == -29) {
        return _29;
    }
    if (smpteFormatInt == -30) {
        return _30;
    }
    return ERR;
}
