#include "pak.h"
#include <cstring>

// (static void crypt si in makepak.cpp)
static void crypt(std::vector<char>& data) {
    for (char& b : data)
        b ^= 0xA7;
}

bool Pak::open(const char* name) {
    file.open(name, std::ios::binary);
    if (!file) return false;

    char magic[4];
    file.read(magic, 4);
    if (memcmp(magic, "PAK0", 4) != 0) return false;

    uint32_t count, table;
    file.read((char*)&count, 4);
    file.read((char*)&table, 4);

    entries.resize(count);
    file.seekg(table);
    file.read((char*)entries.data(), count * sizeof(PakEntry));
    return true;
}

std::vector<char> Pak::read(const std::string& path) {
    for (auto& e : entries) {
        if (path == e.path) {
            std::vector<char> data(e.size);
            file.seekg(e.offset);
            file.read(data.data(), e.size);
            crypt(data);
            return data;
        }
    }
    return {};
}
