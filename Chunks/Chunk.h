//
// Created by ferri on 1/13/2025.
//

#ifndef CHUNK_H
#define CHUNK_H
#include <cstdint>
#include <string>


class Chunk {
public:
    enum CHUNK_TYPE {
        HEADER_CHUNK = 0x4D546864,
        TRACK_CHUNK = 0x4D54726B,
        ERROR_CHUNK = 0xFFFFFFFF,
    };

    Chunk();

    void setChunkType(CHUNK_TYPE chunkType);
    CHUNK_TYPE getChunkType();

    void setChunkSize(long chunkSize);
    long getChunkSize();

    static CHUNK_TYPE readChunkType(char ChunkTypeChars[4]);

private:
    CHUNK_TYPE chunkType;
    uint32_t chunkSize;
};


#endif //CHUNK_H
