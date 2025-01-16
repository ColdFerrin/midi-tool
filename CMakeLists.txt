cmake_minimum_required(VERSION 3.22.1)
project(midi_tool)

set(CMAKE_CXX_STANDARD 20)

add_executable(midi_tool main.cpp
        Chunks/HeaderChunk.cpp
        Chunks/HeaderChunk.h
        Chunks/Chunk.cpp
        Chunks/Chunk.h
        MIDIFile.cpp
        MIDIFile.h
        Utils.cpp
        Utils.h
        Divisions/Division.cpp
        Divisions/Division.h
        Divisions/MetricTimeDivision.cpp
        Divisions/MetricTimeDivision.h
        Divisions/TimeCodeDivision.cpp
        Divisions/TimeCodeDivision.h
        Chunks/BodyChunk.cpp
        Chunks/BodyChunk.h)
