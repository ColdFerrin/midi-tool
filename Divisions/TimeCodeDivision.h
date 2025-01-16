//
// Created by ferri on 1/14/2025.
//

#ifndef TIMECODEDIVISION_H
#define TIMECODEDIVISION_H
#include <cstdint>

#include "Division.h"


class TimeCodeDivision : public Division{
public:
    enum TIME_CODE_FORMAT {
        _24,
        _25,
        _29,
        _30,
        ERR
    };
    TimeCodeDivision(TIME_CODE_FORMAT timeCodeFormat, uint8_t ticksPerFrame);
    TIME_CODE_FORMAT getTimeCodeFormat();
    uint8_t getTicksPerFrame();

    static TIME_CODE_FORMAT findTimeCodeFormat(uint8_t smpteFormat);


private:
    TIME_CODE_FORMAT timeCodeFormat;
    uint8_t ticksPerFrame;
};


#endif //TIMECODEDIVISION_H
