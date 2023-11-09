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
    delete[] this->memory;

    delete[] this->logger;
}

uint8_t CPU::Execute(uint8_t disassembly)
{
    Instruction *instruction = new Instruction(nullptr, nullptr, 0);

    if (disassembly < 256) {
        *instruction = this->instructions[disassembly];
        instruction->execute();
        return (instruction->length);
    }

    return (0);
}

void *CPU::NIY()
{
    this->logger->Log("CPU", "NOT IMPLEMENTED YET ;w;");

    return (nullptr);
}

void *CPU::LD_A_A()
{
    this->logger->Log("CPU", "LD A, A");
    
    return nullptr;
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
    this->logger->Log("CPU", "LD_BC_A");

    return (nullptr);
}

void *CPU::INC(uint8_t &r)
{
    this->logger->Log("CPU", "INC");

    r += 1;

    return (nullptr);
}

void *CPU::INC_B()
{
    this->logger->Log("CPU", "INC_B");

    this->registers->b += 1;

    return (nullptr);
}

void *CPU::INC_C()
{
    this->logger->Log("CPU", "INC_C");

    this->registers->c += 1;

    return (nullptr);
}

void *CPU::DEC(uint8_t &r)
{
    this->logger->Log("CPU", "DEC");

    r -= 1;

    return (nullptr);
}

void *CPU::DEC_C()
{
    this->logger->Log("CPU", "DEC_C");

    this->registers->c -= 1;

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
    this->logger->Log("CPU", "RLCA");

    uint8_t carry = (this->registers->a & 0x80) >> 7;

    this->registers->a = (this->registers->a << 1) | carry;
    this->registers->f = (carry << 4);

    return (nullptr);
}

void *CPU::ADD_HL_BC()
{
    this->logger->Log("CPU", "ADD_HL_BC");

    uint16_t hl = this->registers->GetRegister16(this->registers->h, this->registers->l);
    uint16_t bc = this->registers->GetRegister16(this->registers->b, this->registers->c);
    uint32_t result = (static_cast<uint32_t>(hl) + static_cast<uint32_t>(bc));
    
    this->registers->f = 0;
    if ((result & 0x10000) != 0) {
        this->registers->f |= this->flags->c;
    }
    if (((hl ^ bc ^ (result & 0xFFFF)) & 0x1000) != 0) {
        this->registers->f |= this->flags->h;
    }
    this->registers->SetRegister16(
        this->registers->h,
        this->registers->l,
        static_cast<uint16_t>(result & 0xFFFF)
    );

    return (nullptr);
}

void *CPU::LD_C_d8(uint8_t &value)
{
    this->logger->Log("CPU", "LD_C_d8");

    return (
        CPU::LD_8_8(this->registers->c, value)
    );
}

void *CPU::RRCA()
{
    this->logger->Log("CPU", "RRCA");

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
    return (nullptr);
}

void *CPU::INC_DE()
{
    this->logger->Log("CPU", "INC_DE");

    this->registers->SetRegister16(
        this->registers->d,
        this->registers->e,
        this->registers->GetRegister16(this->registers->d, this->registers->e) + 1
    );

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
    uint16_t hl = this->registers->GetRegister16(this->registers->h, this->registers->l);
    uint16_t de = this->registers->GetRegister16(this->registers->d, this->registers->e);
    uint32_t result = static_cast<uint32_t>(hl) + static_cast<uint32_t>(de);

    this->registers->f = 0;
    if ((result & 0x10000) != 0) {
        this->registers->f |= this->flags->c;
    }
    if (((hl ^ de ^ (result & 0xFFFF)) & 0x1000) != 0) {
        this->registers->f |= this->flags->h;
    }
    this->registers->SetRegister16(
        this->registers->h,
        this->registers->l,
        static_cast<uint16_t>(result & 0xFFFF)
    );

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
    return (nullptr);
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
    return (nullptr);
}

void *CPU::INC_HL()
{
    this->logger->Log("CPU", "INC_HL");

    this->registers->SetRegister16(
        this->registers->h,
        this->registers->l,
        this->registers->GetRegister16(this->registers->h, this->registers->l) + 1
    );

    return (nullptr);
}

void *CPU::INC_H()
{
    this->logger->Log("CPU", "INC_H");
    CPU::INC(this->registers->h);
    return (nullptr);
}

void *CPU::DEC_H()
{
    this->logger->Log("CPU", "DEC_H");
    CPU::DEC(this->registers->h);
    return (nullptr);
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

    return (nullptr);
}

void *CPU::JR_Z_r8(int8_t &offset)
{
    this->logger->Log("CPU", "JR_Z_r8");
    if (this->registers->f & this->flags->z) {
        this->registers->pc += offset;
    }
    return (nullptr);
}

void *CPU::ADD_HL_HL()
{
    uint16_t hl = this->registers->GetRegister16(this->registers->h, this->registers->l);
    uint32_t result = static_cast<uint32_t>(hl) + static_cast<uint32_t>(hl);

    this->registers->f = 0;
    if ((result & 0x10000) != 0) {
        this->registers->f |= this->flags->c;
    }
    if (((hl ^ hl ^ (result & 0xFFFF)) & 0x1000) != 0) {
        this->registers->f |= this->flags->h;
    }
    this->registers->SetRegister16(
        this->registers->h,
        this->registers->l,
        static_cast<uint16_t>(result & 0xFFFF)
    );

    return (nullptr);
}

void *CPU::LD_A_HL()
{
    this->logger->Log("CPU", "LD_A_HL");
    // Load value from memory location pointed by HL into register A
    // Assuming memory read logic is implemented elsewhere
    return (nullptr);
}

void *CPU::DEC_HL()
{
    this->logger->Log("CPU", "DEC_HL");

    this->registers->SetRegister16(
        this->registers->h,
        this->registers->l,
        this->registers->GetRegister16(this->registers->h, this->registers->l) - 1
    );

    return (nullptr);
}

void *CPU::INC_L()
{
    this->logger->Log("CPU", "INC_L");
    CPU::INC(this->registers->l);
    return (nullptr);
}

void *CPU::DEC_L()
{
    this->logger->Log("CPU", "DEC_L");
    CPU::DEC(this->registers->l);
    return (nullptr);
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
    return (nullptr);
}

void *CPU::JR_NC_r8(int8_t &offset)
{
    this->logger->Log("CPU", "JR_NC_r8");

    if ((this->registers->f & this->flags->c) == 0) {
        this->registers->pc += offset;
    }

    return (nullptr);
}

void *CPU::LD_SP_d16(uint16_t &value)
{
    this->logger->Log("CPU", "LD_SP_d16");

    this->registers->sp = value;

    return (nullptr);
}

void *CPU::LD_HL_A_d8()
{
    this->logger->Log("CPU", "LD_HL_A_d8");
    // Load value from register A into memory location pointed by HL
    // Assuming memory write logic is implemented elsewhere
    return (nullptr);
}

void *CPU::INC_SP()
{
    this->logger->Log("CPU", "INC_SP");
    this->registers->sp += 1;
    return (nullptr);
}

void *CPU::DEC_SP()
{
    this->logger->Log("CPU", "DEC_SP");
    this->registers->sp -= 1;
    return nullptr;
}

void *CPU::SPHL()
{
    this->logger->Log("CPU", "SPHL");

    this->registers->sp = this->registers->GetRegister16(this->registers->h, this->registers->l);

    return nullptr;
}

void *CPU::JR_C_r8(int8_t &offset)
{
    this->logger->Log("CPU", "JR_C_r8");
    if (this->registers->f & this->flags->c) {
        this->registers->pc += offset;
    }
    return nullptr;
}

void *CPU::LD_d16_A(uint16_t &address)
{
    this->logger->Log("CPU", "LD_d16_A");
    // Load value from register A into memory location specified by d16
    // Assuming memory write logic is implemented elsewhere
    return nullptr;
}

void *CPU::A16_SP()
{
    this->logger->Log("CPU", "A16_SP");
    // Store SP at the memory location specified by the 16-bit address
    // Assuming memory write logic is implemented elsewhere
    return nullptr;
}

void *CPU::LD_A_d16(uint16_t &address)
{
    this->logger->Log("CPU", "LD_A_d16");
    // Load value from memory location specified by d16 into register A
    // Assuming memory read logic is implemented elsewhere
    return nullptr;
}

void *CPU::EI()
{
    this->logger->Log("CPU", "EI");
    // Enable interrupts
    // Implement interrupt handling logic if necessary
    return nullptr;
}

void *CPU::DI()
{
    this->logger->Log("CPU", "DI");
    // Disable interrupts
    // Implement interrupt handling logic if necessary
    return nullptr;
}

void *CPU::CALL(uint16_t &address)
{
    this->logger->Log("CPU", "CALL");
    // Call subroutine at the specified address
    // Implement call logic if necessary
    return nullptr;
}

void *CPU::PUSH_AF()
{
    this->logger->Log("CPU", "PUSH_AF");
    // Push register AF onto the stack
    // Assuming stack operations are implemented elsewhere
    return nullptr;
}

void *CPU::RST(uint8_t &offset)
{
    this->logger->Log("CPU", "RST");
    // Restart the CPU and jump to the specified address
    // Implement restart logic if necessary
    return nullptr;
}

void *CPU::RET()
{
    this->logger->Log("CPU", "RET");
    // Return from subroutine
    // Implement return logic if necessary
    return nullptr;
}

void *CPU::POP_AF()
{
    this->logger->Log("CPU", "POP_AF");
    // Pop value from the stack into register AF
    // Assuming stack operations are implemented elsewhere
    return nullptr;
}

void *CPU::JP(uint16_t &address)
{
    this->logger->Log("CPU", "JP");
    // Jump to the specified address
    // Implement jump logic if necessary
    return nullptr;
}

void *CPU::JP_NZ(uint16_t &address)
{
    this->logger->Log("CPU", "JP_NZ");
    if ((this->registers->f & this->flags->z) == 0) {
        // Jump to the specified address if Z flag is not set
        // Implement jump logic if necessary
    }
    return nullptr;
}

void *CPU::JP_Z(uint16_t &address)
{
    this->logger->Log("CPU", "JP_Z");
    if (this->registers->f & this->flags->z) {
        // Jump to the specified address if Z flag is set
        // Implement jump logic if necessary
    }
    return nullptr;
}

void *CPU::JP_NC(uint16_t &address)
{
    this->logger->Log("CPU", "JP_NC");
    if ((this->registers->f & this->flags->c) == 0) {
        // Jump to the specified address if C flag is not set
        // Implement jump logic if necessary
    }
    return nullptr;
}

void *CPU::JP_C(uint16_t &address)
{
    this->logger->Log("CPU", "JP_C");
    if (this->registers->f & this->flags->c) {
        // Jump to the specified address if C flag is set
        // Implement jump logic if necessary
    }
    return nullptr;
}

void *CPU::CALL_NZ(uint16_t &address)
{
    this->logger->Log("CPU", "CALL_NZ");
    if ((this->registers->f & this->flags->z) == 0) {
        // Call subroutine at the specified address if Z flag is not set
        // Implement call logic if necessary
    }
    return nullptr;
}

void *CPU::CALL_Z(uint16_t &address)
{
    this->logger->Log("CPU", "CALL_Z");
    if (this->registers->f & this->flags->z) {
        // Call subroutine at the specified address if Z flag is set
        // Implement call logic if necessary
    }
    return nullptr;
}

void *CPU::CALL_NC(uint16_t &address)
{
    this->logger->Log("CPU", "CALL_NC");
    if ((this->registers->f & this->flags->c) == 0) {
        // Call subroutine at the specified address if C flag is not set
        // Implement call logic if necessary
    }
    return nullptr;
}

void *CPU::CALL_C(uint16_t &address)
{
    this->logger->Log("CPU", "CALL_C");
    if (this->registers->f & this->flags->c) {
        // Call subroutine at the specified address if C flag is set
        // Implement call logic if necessary
    }
    return nullptr;
}

void *CPU::RET_NZ()
{
    this->logger->Log("CPU", "RET_NZ");
    if ((this->registers->f & this->flags->z) == 0) {
        // Return from subroutine if Z flag is not set
        // Implement return logic if necessary
    }
    return nullptr;
}

void *CPU::RET_Z()
{
    this->logger->Log("CPU", "RET_Z");
    if (this->registers->f & this->flags->z) {
        // Return from subroutine if Z flag is set
        // Implement return logic if necessary
    }
    return nullptr;
}

void *CPU::RET_NC()
{
    this->logger->Log("CPU", "RET_NC");
    if ((this->registers->f & this->flags->c) == 0) {
        // Return from subroutine if C flag is not set
        // Implement return logic if necessary
    }
    return nullptr;
}

void *CPU::RET_C()
{
    this->logger->Log("CPU", "RET_C");

    if (this->registers->f & this->flags->c) {
        // Return from subroutine if C flag is set
        // Implement return logic if necessary
    }
    return nullptr;
}

void *CPU::RETI()
{
    this->logger->Log("CPU", "RETI");
    // Return from interrupt
    // Implement return logic if necessary
    return nullptr;
}

void *CPU::RST_00()
{
    this->logger->Log("CPU", "RST_00");
    // Restart at address 0x00
    // Implement restart logic if necessary
    return nullptr;
}

void *CPU::RST_08()
{
    this->logger->Log("CPU", "RST_08");
    // Restart at address 0x08
    // Implement restart logic if necessary
    return nullptr;
}

void *CPU::RST_10()
{
    this->logger->Log("CPU", "RST_10");
    // Restart at address 0x10
    // Implement restart logic if necessary
    return nullptr;
}

void *CPU::RST_18()
{
    this->logger->Log("CPU", "RST_18");
    // Restart at address 0x18
    // Implement restart logic if necessary
    return nullptr;
}

void *CPU::RST_20()
{
    this->logger->Log("CPU", "RST_20");
    // Restart at address 0x20
    // Implement restart logic if necessary
    return nullptr;
}

void *CPU::RST_28()
{
    this->logger->Log("CPU", "RST_28");
    // Restart at address 0x28
    // Implement restart logic if necessary
    return nullptr;
}

void *CPU::RST_30()
{
    this->logger->Log("CPU", "RST_30");
    // Restart at address 0x30
    // Implement restart logic if necessary
    return nullptr;
}

void *CPU::RST_38()
{
    this->logger->Log("CPU", "RST_38");
    // Restart at address 0x38
    // Implement restart logic if necessary
    return nullptr;
}

void *CPU::HALT()
{
    this->logger->Log("CPU", "HALT");
    // Halt the CPU
    // Implement halt logic if necessary
    return nullptr;
}
