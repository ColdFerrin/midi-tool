//
// Created by ferri on 1/14/2025.
//

#include "MIDIFile.h"

#include <bit>
#include <iostream>

#include "Chunks/Chunk.h"
#include "Utils.h"
#include "Chunks/HeaderChunk.h"

MIDIFile::MIDIFile(std::string file) {
    this->file.open(file,std::ios_base::binary);

}

MIDIFile::~MIDIFile() {
    this->file.close();
}

void MIDIFile::read() {
    this->file.seekg(0, std::ios::beg);

    while (!file.eof()) {
        char header[4];
        this->file.read(header, sizeof(header));
        Chunk::CHUNK_TYPE chunkType = Chunk::readChunkType(header);

        if (chunkType == Chunk::ERROR_CHUNK) {
            std::cerr << "Error reading chunk" << std::endl;
            exit(1);
        }

        char lengthArr[4];
        this->file.read(lengthArr, sizeof(lengthArr));
        uint32_t length = Utils::toUint32_t(lengthArr, std::endian::big);

        if (chunkType == Chunk::HEADER_CHUNK) {
            char valueArr[6];
            this->file.read(valueArr, sizeof(valueArr));
            this->header = new HeaderChunk(length, valueArr);
        } else if (chunkType == Chunk::TRACK_CHUNK) {

        }


    }

    file.close();
}

uint32_t MIDIFile::readVariableLengthValue() {
    uint32_t value = 0;
    uint8_t continueMask = 0x80;
    uint8_t dataMask = 0x7F;

    char currentChar[1];
    do {
        file.read(currentChar, sizeof(currentChar));
        uint8_t dataChar = currentChar[0] & dataMask;
        value = value | (dataChar << 7);

    } while ((currentChar[0] & dataMask) == continueMask);

    return value;

}
