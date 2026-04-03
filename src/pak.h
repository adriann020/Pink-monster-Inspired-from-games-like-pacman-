#pragma once
#include <fstream>
#include <vector>
#include <string>
#include <cstdint>

struct PakEntry {
    char path[256];
    uint32_t offset;
    uint32_t size;
};

class Pak {
    std::ifstream file;
    std::vector<PakEntry> entries;

public:

    bool open(const char* name);
    std::vector<char> read(const std::string& path);
};
