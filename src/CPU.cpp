#include "CPU.hpp"

CPU::CPU(Logger *logger, uint8_t *size)
{
    this->logger = logger;

    this->registers = new Register();
    this->flags = new Flags();
    this->memory = new uint8_t(*size);
}

CPU::~CPU()
{
    delete[] this->registers;
    delete[] this->flags;
    delete[] this->logger;
    delete[] this->memory;
}

void *CPU::NOP()
{
    this->logger->Log("CPU", "NOP");

    return (nullptr);
}

void *CPU::INC(uint8_t &r)
{
    this->logger->Log("CPU", "INC");

    r += 1;

    return (nullptr);
}

void *CPU::DEC(uint8_t &r)
{
    this->logger->Log("CPU", "DEC");

    r -= 1;

    return (nullptr);
}

void *CPU::ADD(uint8_t &a, uint8_t &b)
{
    this->logger->Log("CPU", "ADD");

    a += b;

    return (nullptr);
}

void *CPU::SUB(uint8_t &a, uint8_t &b)
{
    this->logger->Log("CPU", "SUB");

    a -= b;

    return (nullptr);
}
