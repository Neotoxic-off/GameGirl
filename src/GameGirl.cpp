#include "GameGirl.hpp"

GameGirl::GameGirl()
{
    this->romData = nullptr;

    this->logger = new Logger();
    this->memory = new Memory();
}

GameGirl::~GameGirl()
{
    delete[] this->romData;

    delete[] this->logger;
    delete[] this->memory;
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


