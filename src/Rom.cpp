#include "Rom.hpp"

Rom::Rom(std::string path)
{
    this->path = path;
    this->status = false;
    this->title = nullptr;
    this->data = nullptr;
    this->size = 0;

    this->status = Rom::Load();
}

Rom::~Rom()
{
    delete[] this->title;
    delete[] this->data;
}

bool Rom::Load()
{
    std::ifstream romFile(this->path, std::ios::binary);

    if (romFile)
    {
        romFile.seekg(0, std::ios::end);
        this->size = romFile.tellg();
        romFile.seekg(0, std::ios::beg);
        this->data = new char[this->size];
        romFile.read(this->data, this->size);
        this->title = new char[16];
        romFile.seekg(0x134, std::ios::beg);
        romFile.read(this->title, 16);
        romFile.close();

        return (true);
    }

    return (false);
}