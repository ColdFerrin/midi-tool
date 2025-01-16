//
// Created by ferri on 1/14/2025.
//

#include "Division.h"

#include "MetricTimeDivision.h"


Division::Division() {
    this->setDivisionType(ERROR_TIME);
}

Division::DIVISION_TYPE Division::getDivisionType() const {
    return divisionType;
}

void Division::setDivisionType(DIVISION_TYPE division_type) {
    divisionType = division_type;
}

Division::DIVISION_TYPE Division::getDivisionType(uint16_t divisionData) {
    uint16_t divisionType = divisionData  >> 15;

    if (divisionType == 0) {
        return METRIC_TIME;
    }
    if (divisionType == 1) {
        return TIMECODE_TIME;
    }
    return ERROR_TIME;
}
