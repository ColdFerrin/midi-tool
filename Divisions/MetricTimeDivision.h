//
// Created by ferri on 1/14/2025.
//

#ifndef METRICTIMEDIVISION_H
#define METRICTIMEDIVISION_H
#include <cstdint>

#include "Division.h"


class MetricTimeDivision : Division {
public:
    explicit MetricTimeDivision(uint16_t ticksPerQuarterNote);

    uint16_t getTicksPerQuarterNote();
private:
    uint16_t ticksPerQuarterNote;
};


#endif //METRICTIMEDIVISION_H
