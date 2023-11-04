#include "GameGirl.hpp"

GameGirl::GameGirl(std::string path)
{
    this->logger = new Logger();
    this->cpu = new CPU(this->logger);
    this->rom = new Rom(this->logger, path);
}

GameGirl::~GameGirl()
{
    delete[] this->logger;
    delete[] this->cpu;
    delete[] this->rom;
}
