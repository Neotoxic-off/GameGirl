#include "CPU.hpp"

CPU::CPU(Logger *logger)
{
    this->logger = logger;

    this->registers = new Register();
}

CPU::~CPU()
{
    delete[] this->registers;
    delete[] this->logger;
}

void *CPU::NOP()
{
    this->logger->Log("CPU", "NOP");

    return (nullptr);
}

void *CPU::INC(uint8_t *r)
{
    this->logger->Log("CPU", "INC");

    *r += 1;

    return (nullptr);
}

void *CPU::DEC(uint8_t *r)
{
    this->logger->Log("CPU", "DEC");

    *r -= 1;

    return (nullptr);
}

void *CPU::ADD(uint8_t *a, uint8_t *b)
{
    this->logger->Log("CPU", "ADD");

    *a += *b;

    return (nullptr);
}

void *CPU::SUB(uint8_t *a, uint8_t *b)
{
    this->logger->Log("CPU", "SUB");

    *a -= *b;

    return (nullptr);
}

void *CPU::ADC(uint8_t *a, uint8_t *b)
{
    bool flag = true;
    uint16_t result = 0;

    this->logger->Log("CPU", "ADC");

    result = static_cast<uint16_t>(*a) + static_cast<uint16_t>(*a) + static_cast<uint16_t>(flag);
    flag = (result > 0xFF);
    *this->registers->a = static_cast<uint8_t>(result);

    return (nullptr);
}

void *CPU::SBC(uint8_t *a, uint8_t *b)
{
    bool flag = true;
    uint16_t result = 0;

    this->logger->Log("CPU", "SBC");

    result = static_cast<uint16_t>(*a) - static_cast<uint16_t>(*a) - static_cast<uint16_t>(flag);
    flag = (result > 0xFF);
    *this->registers->a = static_cast<uint8_t>(result);

    return (nullptr);
}

void *CPU::AND(uint8_t *r)
{
    this->logger->Log("CPU", "AND");

    *this->registers->a &= *r;

    return (nullptr);
}

void *CPU::XOR(uint8_t *r)
{
    this->logger->Log("CPU", "XOR");

    *this->registers->a ^= *r;

    return (nullptr);
}

void *CPU::OR(uint8_t *r)
{
    this->logger->Log("CPU", "OR");

    *this->registers->a |= *r;

    return (nullptr);
}

void *CPU::CP(uint8_t *r)
{
    this->logger->Log("CPU", "CP");

    *this->registers->a = *this->registers->a - *r;

    return (nullptr);
}

void *CPU::RET(uint8_t *r)
{
    this->logger->Log("CPU", "RET");

    return (nullptr);
}

void *CPU::POP(uint8_t *r)
{
    uint8_t *lsb = new uint8_t(0x34);
    uint8_t *msb = new uint8_t(0x12);
    uint16_t *de = nullptr;

    this->logger->Log("CPU", "POP");

    de = new uint16_t(static_cast<uint16_t>(*msb) << 8 | *lsb);
    *this->registers->sp += 2;

    return (de);
}

void *CPU::JP(uint8_t *r)
{
    this->logger->Log("CPU", "JP");

    return (nullptr);
}

void *CPU::CALL(uint8_t *r)
{
    this->logger->Log("CPU", "CALL");

    return (nullptr);
}

void *CPU::PUSH(uint8_t *r)
{
    this->logger->Log("CPU", "PUSH");

    return (nullptr);
}

void *CPU::RST(uint8_t *r)
{
    this->logger->Log("CPU", "RST");

    return (nullptr);
}

void *CPU::RETI(uint8_t *r)
{
    this->logger->Log("CPU", "RETI");

    return (nullptr);
}

void *CPU::LD(uint8_t *r)
{
    this->logger->Log("CPU", "LD");

    return (nullptr);
}

void *CPU::EI(uint8_t *r)
{
    this->logger->Log("CPU", "EI");

    return (nullptr);
}