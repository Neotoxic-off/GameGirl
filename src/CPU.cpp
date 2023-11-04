#include "CPU.hpp"

CPU::CPU()
{
    this->registers = new Register();
}

CPU::~CPU()
{
    delete[] this->registers;
}

void *CPU::NOP()
{
    return (0);
}

void *CPU::INC(uint8_t *r)
{
    *r += 1;

    return (0);
}

void *CPU::DEC(uint8_t *r)
{
    *r -= 1;

    return (0);
}
