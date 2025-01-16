//
// Created by ferri on 1/13/2025.
//

#ifndef HEADERCHUNK_H
#define HEADERCHUNK_H
#include "Chunk.h"
#include "../Divisions/Division.h"
#include "../Divisions/TimeCodeDivision.h"
#include "../Divisions/MetricTimeDivision.h"


class HeaderChunk : public Chunk {
public:
    explicit HeaderChunk(uint32_t size, char data[6]);

private:
    uint16_t format;
    uint16_t ntrks;
    Division::DIVISION_TYPE divisionType;
    union {
        TimeCodeDivision* timeDiv;
        MetricTimeDivision* metricTimeDiv;
    };
};


#endif //HEADERCHUNK_H
