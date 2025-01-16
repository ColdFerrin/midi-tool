//
// Created by ferri on 1/13/2025.
//

#include "HeaderChunk.h"

#include <iostream>
#include <ostream>

#include "../Utils.h"

HeaderChunk::HeaderChunk(uint32_t size, char data[6]) {
    setChunkType(HEADER_CHUNK);
    setChunkSize(size);

    char formatStr[2];
    char ntrksStr[2];
    char divisionStr[2];

    memcpy(formatStr, data, 2);
    memcpy(ntrksStr, data + 2, 2);
    memcpy(divisionStr, data + 4, 2);
    std::cout << formatStr << ntrksStr << divisionStr << std::endl;
    this->format = Utils::toUint16_t(formatStr, std::endian::big);
    this->ntrks = Utils::toUint16_t(ntrksStr, std::endian::big);

    uint16_t division = Utils::toUint16_t(divisionStr, std::endian::big);

    this->divisionType = Division::getDivisionType(division);;

    if (this->divisionType == Division::METRIC_TIME) {
        this->metricTimeDiv = new MetricTimeDivision(division);
    } else if (this->divisionType == Division::TIMECODE_TIME) {
        uint8_t timeCode = division >> 8;
        uint8_t ticksPerFrame = division & 0xff;
        this->timeDiv = new TimeCodeDivision(TimeCodeDivision::findTimeCodeFormat(timeCode), ticksPerFrame);
    }
}
