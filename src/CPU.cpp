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

void *CPU::ADD(uint8_t *r)
{
    this->logger->Log("CPU", "ADD");

    return (nullptr);
}

void *CPU::SUB(uint8_t *r)
{
    this->logger->Log("CPU", "SUB");

    return (nullptr);
}

void *CPU::ADC(uint8_t *r)
{
    this->logger->Log("CPU", "ADC");

    return (nullptr);
}

void *CPU::SBC(uint8_t *r)
{
    this->logger->Log("CPU", "SBC");

    return (nullptr);
}

void *CPU::AND(uint8_t *r)
{
    this->logger->Log("CPU", "AND");

    return (nullptr);
}

void *CPU::XOR(uint8_t *r)
{
    this->logger->Log("CPU", "XOR");

    return (nullptr);
}

void *CPU::OR(uint8_t *r)
{
    this->logger->Log("CPU", "OR");

    return (nullptr);
}

void *CPU::CP(uint8_t *r)
{
    this->logger->Log("CPU", "CP");

    return (nullptr);
}

void *CPU::RET(uint8_t *r)
{
    this->logger->Log("CPU", "RET");

    return (nullptr);
}

void *CPU::POP(uint8_t *r)
{
    this->logger->Log("CPU", "POP");

    return (nullptr);
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