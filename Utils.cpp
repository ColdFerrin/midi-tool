//
// Created by ferri on 1/14/2025.
//

#include "Utils.h"

#include <iostream>

uint32_t Utils::toUint32_t(char chars[4], std::endian endianness){

    int result = 0;
    if (endianness == std::endian::big) {
        result = ((chars[0] << 24) | (chars[1] << 16) | (chars[2] << 8) | chars[3]);
    } else if (endianness == std::endian::little) {
        result = ((chars[3] << 24) | (chars[2] << 16) | (chars[1] << 8) | chars[0]);
    }

    return result;
}

uint16_t Utils::toUint16_t(char chars[2], std::endian endianness){

    uint8_t firstByte = chars[0];
    uint8_t secondByte = chars[1];

    int result = 0;
    if (endianness == std::endian::big) {
        result = ((firstByte << 8) | secondByte);
    } else if (endianness == std::endian::little) {
        result = ((secondByte << 8) | firstByte);
    }

    return result;
}

Utils::Utils() {
}

