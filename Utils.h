//
// Created by ferri on 1/14/2025.
//

#ifndef UTILS_H
#define UTILS_H
#include <bit>
#include <cstdint>


class Utils {
public:
    Utils();

    static uint32_t toUint32_t(char chars[4], std::endian endianness);
    static uint16_t toUint16_t(char chars[2], std::endian endianness);
};



#endif //UTILS_H
