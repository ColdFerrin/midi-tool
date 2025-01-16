#include <iostream>

#include "MIDIFile.h"

int main() {
    std::string filePath;
    std::cout << "Enter the path of the midi file: ";
    std::cin >> filePath;

    MIDIFile midiFile(filePath);
    midiFile.read();


    return 0;
}
