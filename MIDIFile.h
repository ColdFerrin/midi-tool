//
// Created by ferri on 1/14/2025.
//

#ifndef MIDIFILE_H
#define MIDIFILE_H
#include <fstream>
#include <vector>

#include "Chunks/Chunk.h"
#include "Chunks/HeaderChunk.h"


class MIDIFile {
public:
    explicit MIDIFile(std::string file);
    ~MIDIFile();
    void read();

private:
    std::ifstream file;
    HeaderChunk *header;
    std::vector<Chunk> fileParts;


    uint32_t readVariableLengthValue();
};



#endif //MIDIFILE_H
