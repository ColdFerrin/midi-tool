//
// Created by ferri on 1/14/2025.
//

#ifndef DIVISION_H
#define DIVISION_H
#include <cstdint>

class Division {
public:
    enum DIVISION_TYPE {
        METRIC_TIME = 0,
        TIMECODE_TIME = 1,
        ERROR_TIME = 2,
    };

    Division();

    [[nodiscard]] DIVISION_TYPE getDivisionType() const;

    void setDivisionType(DIVISION_TYPE division_type);

    static DIVISION_TYPE getDivisionType(uint16_t divisionId);

private:
    DIVISION_TYPE divisionType;
};


#endif //DIVISION_H
