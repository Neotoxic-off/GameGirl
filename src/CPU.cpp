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
        this->registers->f |= this->flags->c;
    }
    if (((this->registers->hl ^ this->registers->bc ^ (result & 0xFFFF)) & 0x1000) != 0) {
        this->registers->f |= this->flags->h;
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

void *CPU::STOP()
{
    this->logger->Log("CPU", "STOP");
    // Implement the logic for STOP instruction if needed
    return (nullptr);
}

void *CPU::LD_DE_d16(uint16_t &value)
{
    this->logger->Log("CPU", "LD_DE_d16");

    return (
        CPU::LD_16_16(this->registers->d, this->registers->e, value)
    );
}

void *CPU::LD_DE_A()
{
    // Load value from register A into memory location pointed by DE
    // Assuming memory write logic is implemented elsewhere
    return nullptr;
}

void *CPU::INC_DE()
{
    this->logger->Log("CPU", "INC_DE");
    this->registers->de += 1;
    return (nullptr);
}

void *CPU::INC_D()
{
    this->logger->Log("CPU", "INC_D");
    CPU::INC(this->registers->d);
    return (nullptr);
}

void *CPU::DEC_D()
{
    this->logger->Log("CPU", "DEC_D");
    
    CPU::DEC(this->registers->d);

    return (nullptr);
}

void *CPU::LD_D_d8(uint8_t &value)
{
    return (
        CPU::LD_8_8(this->registers->d, value)
    );
}

void *CPU::RLA()
{
    this->logger->Log("CPU", "RLA");

    uint8_t carry = (this->registers->f & this->flags->c) >> 4;

    this->registers->f = (this->registers->a & 0x80) >> 3;
    this->registers->a = (this->registers->a << 1) | carry;

    return (nullptr);
}

void *CPU::JR_r8(int8_t &offset)
{
    this->logger->Log("CPU", "JR_r8");

    this->registers->pc += offset;

    return (nullptr);
}

void *CPU::ADD_HL_DE()
{
    uint32_t result = static_cast<uint32_t>(this->registers->hl) + static_cast<uint32_t>(this->registers->de);

    this->registers->f = 0;
    if ((result & 0x10000) != 0) {
        this->registers->f |= this->flags->c;
    }
    if (((this->registers->hl ^ this->registers->de ^ (result & 0xFFFF)) & 0x1000) != 0) {
        this->registers->f |= this->flags->h;
    }
    this->registers->hl = static_cast<uint16_t>(result & 0xFFFF);

    return (nullptr);
}

void *CPU::LD_E_d8(uint8_t &value)
{
    return CPU::LD_8_8(this->registers->e, value);
}

void *CPU::RRA()
{
    this->logger->Log("CPU", "RRA");

    uint8_t carry = this->registers->f & this->flags->c;

    this->registers->f = (this->registers->a & 1) << 4;
    this->registers->a = (this->registers->a >> 1) | (carry << 7);

    return (nullptr);
}

void *CPU::JR_NZ_r8(int8_t &offset)
{
    this->logger->Log("CPU", "JR_NZ_r8");
    if ((this->registers->f & this->flags->z) == 0) {
        this->registers->pc += offset;
    }
    return nullptr;
}

void *CPU::LD_HL_d16(uint16_t &value)
{
    this->logger->Log("CPU", "LD_HL_d16");
    return CPU::LD_16_16(this->registers->h, this->registers->l, value);
}

void *CPU::LD_HL_A()
{
    // Load value from register A into memory location pointed by HL
    // Assuming memory write logic is implemented elsewhere
    return nullptr;
}

void *CPU::INC_HL()
{
    this->logger->Log("CPU", "INC_HL");
    this->registers->hl += 1;
    return nullptr;
}

void *CPU::INC_H()
{
    this->logger->Log("CPU", "INC_H");
    CPU::INC(this->registers->h);
    return nullptr;
}

void *CPU::DEC_H()
{
    this->logger->Log("CPU", "DEC_H");
    CPU::DEC(this->registers->h);
    return nullptr;
}

void *CPU::LD_H_d8(uint8_t &value)
{
    return CPU::LD_8_8(this->registers->h, value);
}

void *CPU::DAA()
{
    this->logger->Log("CPU", "DAA");

    uint8_t correction = 0;
    if ((this->registers->f & this->flags->h) || ((this->registers->a & 0x0F) > 9)) {
        correction |= 0x06;
    }
    if ((this->registers->f & this->flags->c) || (this->registers->a > 0x99)) {
        correction |= 0x60;
        this->registers->f |= this->flags->c;
    }

    this->registers->a += (this->registers->f & this->flags->n) ? -correction : correction;
    this->registers->f &= ~this->flags->h;
    if (this->registers->a == 0) {
        this->registers->f |= this->flags->z;
    }

    return nullptr;
}

void *CPU::JR_Z_r8(int8_t &offset)
{
    this->logger->Log("CPU", "JR_Z_r8");
    if (this->registers->f & this->flags->z) {
        this->registers->pc += offset;
    }
    return nullptr;
}

void *CPU::ADD_HL_HL()
{
    uint32_t result = static_cast<uint32_t>(this->registers->hl) + static_cast<uint32_t>(this->registers->hl);

    this->registers->f = 0;
    if ((result & 0x10000) != 0) {
        this->registers->f |= this->flags->c;
    }
    if (((this->registers->hl ^ this->registers->hl ^ (result & 0xFFFF)) & 0x1000) != 0) {
        this->registers->f |= this->flags->h;
    }
    this->registers->hl = static_cast<uint16_t>(result & 0xFFFF);

    return nullptr;
}

void *CPU::LD_A_HL()
{
    this->logger->Log("CPU", "LD_A_HL");
    // Load value from memory location pointed by HL into register A
    // Assuming memory read logic is implemented elsewhere
    return nullptr;
}

void *CPU::DEC_HL()
{
    this->logger->Log("CPU", "DEC_HL");
    this->registers->hl -= 1;
    return nullptr;
}

void *CPU::INC_L()
{
    this->logger->Log("CPU", "INC_L");
    CPU::INC(this->registers->l);
    return nullptr;
}

void *CPU::DEC_L()
{
    this->logger->Log("CPU", "DEC_L");
    CPU::DEC(this->registers->l);
    return nullptr;
}

void *CPU::LD_L_d8(uint8_t &value)
{
    return CPU::LD_8_8(this->registers->l, value);
}

void *CPU::CPL()
{
    this->logger->Log("CPU", "CPL");
    this->registers->a = ~this->registers->a;
    this->registers->f |= (this->flags->n | this->flags->h);
    return nullptr;
}

void *CPU::JR_NC_r8(int8_t &offset)
{
    this->logger->Log("CPU", "JR_NC_r8");
    if ((this->registers->f & this->flags->c) == 0) {
        this->registers->pc += offset;
    }
    return nullptr;
}

void *CPU::LD_SP_d16(uint16_t &value)
{
    this->logger->Log("CPU", "LD_SP_d16");
    this->registers->sp = value;
    return nullptr;
}

void *CPU::LD_HL_A_d8()
{
    this->logger->Log("CPU", "LD_HL_A_d8");
    // Load value from register A into memory location pointed by HL
    // Assuming memory write logic is implemented elsewhere
    return nullptr;
}

void *CPU::INC_SP()
{
    this->logger->Log("CPU", "INC_SP");
    this->registers->sp += 1;
    return nullptr;
}
