//
// Created by ferri on 1/14/2025.
//

#include "MetricTimeDivision.h"

MetricTimeDivision::MetricTimeDivision(uint16_t ticksPerQuarterNote) {
    this->ticksPerQuarterNote = ticksPerQuarterNote;
    this->setDivisionType(METRIC_TIME);
}

uint16_t MetricTimeDivision::getTicksPerQuarterNote() {
    return this->ticksPerQuarterNote;
}


