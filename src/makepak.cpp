#include <fstream>
#include <vector>
#include <filesystem>
#include <cstring>
#include <algorithm>

// Use this file whenever you add new assets to "assets/" folder to create/update "assets.pak"
// However, after you compile once , you need to comment out the execute() call in main.cpp to avoid overwriting pak on each run.

namespace fs = std::filesystem;

struct PakHeader {
    char magic[4];
    uint32_t fileCount;
    uint32_t tableOffset;
};

struct PakEntry {
    char path[256];
    uint32_t offset;
    uint32_t size;
};


static void crypt(std::vector<char>& data) {
    for (char& b : data)
        b ^= 0xA7;
}

void execute() {
    
    if (std::filesystem::exists("assets.pak")) std::filesystem::remove("assets.pak");
 
    std::ofstream pak("assets.pak",std::ios::binary | std::ios::trunc);

    PakHeader header{};
    memcpy(header.magic, "PAK0", 4);
    pak.write((char*)&header, sizeof(header));

    std::vector<PakEntry> entries;

    for (auto& f : fs::recursive_directory_iterator("assets")) {
        if (!f.is_regular_file()) continue;

        PakEntry e{};
        std::string rel = fs::relative(f.path(), "assets").string();
        std::replace(rel.begin(), rel.end(), '\\', '/');
        strncpy(e.path, rel.c_str(), 255);

        e.offset = (uint32_t)pak.tellp();

        std::ifstream in(f.path(), std::ios::binary);
        std::vector<char> data((std::istreambuf_iterator<char>(in)), {});
        crypt(data);

        e.size = (uint32_t)data.size();
        pak.write(data.data(), data.size());
        entries.push_back(e);
    }

    header.fileCount = entries.size();
    header.tableOffset = (uint32_t)pak.tellp();

    if(!pak) return;

    for (auto& e : entries)
        pak.write((char*)&e, sizeof(e));

    pak.seekp(0);
    pak.write((char*)&header, sizeof(header));
}
