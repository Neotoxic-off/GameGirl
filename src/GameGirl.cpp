#include "GameGirl.hpp"

GameGirl::GameGirl()
{
    this->romData = nullptr;
    this->logger = Logger();
}

GameGirl::~GameGirl()
{
    delete[] this->romData;
}

bool GameGirl::LoadRom(std::string path)
{
    std::ifstream romFile(path, std::ios::binary);
    std::streampos romSize = 0;

    if (romFile)
    {
        romFile.seekg(0, std::ios::end);
        romSize = romFile.tellg();
        romFile.seekg(0, std::ios::beg);
        romData = new char[romSize];
        romFile.read(romData, romSize);
        romFile.close();

        return (true);
    }

    return (false);
}


