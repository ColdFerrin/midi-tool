//
// Created by ferri on 1/15/2025.
//

#ifndef BODYCHUNK_H
#define BODYCHUNK_H
#include "Chunk.h"


class BodyChunk : public Chunk {
    public:
    BodyChunk(std::ifstream& file, uint32_t length);
    ~BodyChunk();

private:
};



#endif //BODYCHUNK_H
