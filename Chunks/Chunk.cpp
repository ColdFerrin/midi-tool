//
// Created by ferri on 1/13/2025.
//

#include "Chunk.h"

#include <iostream>

#include "HeaderChunk.h"

Chunk::Chunk() {
    chunkType = ERROR_CHUNK;
    chunkSize = 0;
}

void Chunk::setChunkType(CHUNK_TYPE chunkType) {
    this->chunkType = chunkType;
}

Chunk::CHUNK_TYPE Chunk::getChunkType() {
    return chunkType;
}

void Chunk::setChunkSize(long chunkSize) {
    this->chunkSize = chunkSize;
}

long Chunk::getChunkSize() {
    return chunkSize;
}

Chunk::CHUNK_TYPE Chunk::readChunkType(char ChunkTypeChars[4]) {
    std::cout << ChunkTypeChars << "\n";

    int chunkTypeNum = ChunkTypeChars[0] << 24 | ChunkTypeChars[1] << 16 | ChunkTypeChars[2] << 8 | ChunkTypeChars[3];

    if (chunkTypeNum == static_cast<int>(HEADER_CHUNK)) {
        return HEADER_CHUNK;
    }
    if (chunkTypeNum == static_cast<int>(TRACK_CHUNK)) {
        return TRACK_CHUNK;
    }
    return ERROR_CHUNK;
}
