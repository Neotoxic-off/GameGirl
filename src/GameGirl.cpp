#include "GameGirl.hpp"

GameGirl::GameGirl(std::string path)
{
    this->logger = new Logger();
    this->cpu = new CPU(this->logger);
    this->rom = new Rom(this->logger, path);

    this->memory = new uint8_t(this->rom->size);
}

GameGirl::~GameGirl()
{
    delete[] this->logger;
    delete[] this->cpu;
    delete[] this->rom;

    delete[] this->memory;
}
