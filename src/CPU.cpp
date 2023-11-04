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

void *CPU::ADD(uint8_t *r)
{
    return (0);
}

void *CPU::SUB(uint8_t *r)
{
    return (0);
}

void *CPU::ADC(uint8_t *r)
{
    return (0);
}

void *CPU::SBC(uint8_t *r)
{
    return (0);
}

void *CPU::AND(uint8_t *r)
{
    return (0);
}

void *CPU::XOR(uint8_t *r)
{
    return (0);
}

void *CPU::OR(uint8_t *r)
{
    return (0);
}

void *CPU::CP(uint8_t *r)
{
    return (0);
}

void *CPU::RET(uint8_t *r)
{
    return (0);
}

void *CPU::POP(uint8_t *r)
{
    return (0);
}

void *CPU::JP(uint8_t *r)
{
    return (0);
}

void *CPU::CALL(uint8_t *r)
{
    return (0);
}

void *CPU::PUSH(uint8_t *r)
{
    return (0);
}

void *CPU::RST(uint8_t *r)
{
    return (0);
}

void *CPU::RETI(uint8_t *r)
{
    return (0);
}

void *CPU::LD(uint8_t *r)
{
    return (0);
}

void *CPU::EI(uint8_t *r)
{
    return (0);
}
