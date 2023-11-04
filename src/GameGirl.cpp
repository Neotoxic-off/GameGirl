#include "GameGirl.hpp"

GameGirl::GameGirl(std::string path)
{
    this->logger = new Logger();
    this->cpu = new CPU();
    this->rom = new Rom(path);
}

GameGirl::~GameGirl()
{
    delete[] this->logger;
    delete[] this->cpu;
    delete[] this->rom;
}
