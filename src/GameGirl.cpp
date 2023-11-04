#include "GameGirl.hpp"

GameGirl::GameGirl(std::string path)
{
    this->logger = new Logger();
    this->memory = new Memory();
    this->rom = new Rom(path);
}

GameGirl::~GameGirl()
{
    delete[] this->logger;
    delete[] this->memory;
    delete[] this->rom;
}
