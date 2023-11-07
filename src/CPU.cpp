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

void *CPU::LD_16_16(uint8_t &a, uint8_t &b, uint16_t &value)
{
    this->logger->Log("CPU", "LD_16_16");

    a = static_cast<uint8_t>((value >> 8) & 0xFF);
    b = static_cast<uint8_t>(value & 0xFF);

    return (nullptr);
}

void *CPU::LD_8_8(uint8_t &a, uint8_t &value)
{
    this->logger->Log("CPU", "LD_8_8");

    a = value;

    return (nullptr);
}

void *CPU::LD_BC_A()
{
    // Load value from register A into memory location pointed by BC
    // Assuming memory write logic is implemented elsewhere

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

void *CPU::LD_B_d8(uint8_t &value)
{
    this->logger->Log("CPU", "LD_B_d8");

    return (CPU::LD_8_8(this->registers->b, value));
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


void *CPU::RLCA()
{
    uint8_t carry = (this->registers->a & 0x80) >> 7;

    this->registers->a = (this->registers->a << 1) | carry;
    this->registers->f = (carry << 4);

    return (nullptr);
}

void *CPU::ADD_HL_BC()
{
    uint32_t result = static_cast<uint32_t>(this->registers->hl) + static_cast<uint32_t>(this->registers->bc);
    
    this->registers->f = 0;
    if ((result & 0x10000) != 0) {
        // this->registers->f |= FLAG_CARRY;
    }
    if (((this->registers->hl ^ this->registers->bc ^ (result & 0xFFFF)) & 0x1000) != 0) {
        // this->registers->f |= FLAG_HALF_CARRY;
    }
    this->registers->hl = static_cast<uint16_t>(result & 0xFFFF);

    return (nullptr);
}

void *CPU::LD_C_d8(uint8_t &value)
{
    return (
        CPU::LD_8_8(this->registers->c, value)
    );
}

void *CPU::RRCA()
{
    uint8_t carry = this->registers->a & 1;

    this->registers->a = (this->registers->a >> 1) | (carry << 7);
    this->registers->f = (carry << 4);

    return (nullptr);
}