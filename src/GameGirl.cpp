#include "GameGirl.hpp"

GameGirl::GameGirl()
{
    this->tests = new Tests();
}

GameGirl::GameGirl(std::string path)
{
    this->logger = new Logger();
    this->rom = new Rom(this->logger, path);
    this->cpu = new CPU(this->logger, new uint8_t(this->rom->size));
}

GameGirl::~GameGirl()
{
    // delete this->logger;
    delete[] this->cpu;
    delete[] this->rom;
}
