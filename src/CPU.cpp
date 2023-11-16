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

void *CPU::NOP()
{
    this->logger->Log("CPU", "NOP");
    // No operation
    
    return (nullptr);
}

void *CPU::INC_B()
{
    this->logger->Log("CPU", "INC_B");
    this->registers->b++;
    updateFlags(this->registers->b);
    
    return (nullptr);
}

void *CPU::DEC_B()
{
    this->logger->Log("CPU", "DEC_B");
    this->registers->b--;
    updateFlags(this->registers->b);
    
    return (nullptr);
}

void *CPU::INC_C()
{
    this->logger->Log("CPU", "INC_C");
    this->registers->c++;
    updateFlags(this->registers->c);
    
    return (nullptr);
}

void *CPU::DEC_C()
{
    this->logger->Log("CPU", "DEC_C");
    this->registers->c--;
    updateFlags(this->registers->c);
    
    return (nullptr);
}

void *CPU::INC_D()
{
    this->logger->Log("CPU", "INC_D");
    this->registers->d++;
    updateFlags(this->registers->d);
    
    return (nullptr);
}

void *CPU::DEC_D()
{
    this->logger->Log("CPU", "DEC_D");
    this->registers->d--;
    updateFlags(this->registers->d);
    
    return (nullptr);
}

void *CPU::INC_E()
{
    this->logger->Log("CPU", "INC_E");
    this->registers->e++;
    updateFlags(this->registers->e);
    
    return (nullptr);
}

void *CPU::DEC_E()
{
    this->logger->Log("CPU", "DEC_E");
    this->registers->e--;
    updateFlags(this->registers->e);
    
    return (nullptr);
}

void *CPU::INC_H()
{
    this->logger->Log("CPU", "INC_H");
    this->registers->h++;
    updateFlags(this->registers->h);
    
    return (nullptr);
}

void *CPU::DEC_H()
{
    this->logger->Log("CPU", "DEC_H");
    this->registers->h--;
    updateFlags(this->registers->h);
    
    return (nullptr);
}

void *CPU::INC_L()
{
    this->logger->Log("CPU", "INC_L");
    this->registers->l++;
    updateFlags(this->registers->l);
    
    return (nullptr);
}

void *CPU::DEC_L()
{
    this->logger->Log("CPU", "DEC_L");
    this->registers->l--;
    updateFlags(this->registers->l);
    
    return (nullptr);
}

void *CPU::INC_BC()
{
    this->logger->Log("CPU", "INC_BC");
    this->registers->SetRegister16(
        this->registers->b,
        this->registers->c,
        this->registers->GetRegister16(this->registers->b, this->registers->c) + 1
    );
    
    return (nullptr);
}

void *CPU::DEC_BC()
{
    this->logger->Log("CPU", "DEC_BC");
    this->registers->SetRegister16(
        this->registers->b,
        this->registers->c,
        this->registers->GetRegister16(this->registers->b, this->registers->c) - 1
    );
    
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

void *CPU::DEC_DE()
{
    this->logger->Log("CPU", "DEC_DE");
    this->registers->SetRegister16(
        this->registers->d,
        this->registers->e,
        this->registers->GetRegister16(this->registers->d, this->registers->e) - 1
    );
    
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

void *CPU::INC_SP()
{
    this->logger->Log("CPU", "INC_SP");
    this->registers->sp++;
    
    return (nullptr);
}

void *CPU::DEC_SP()
{
    this->logger->Log("CPU", "DEC_SP");
    this->registers->sp--;
    
    return (nullptr);
}

void *CPU::LD_A_A()
{
    this->logger->Log("CPU", "LD_A_A");
    // Load A into A (no operation)
    
    return (nullptr);
}

void *CPU::LD_DE_A()
{
    this->logger->Log("CPU", "LD_DE_A");
    this->registers->SetRegister16(
        this->registers->d,
        this->registers->e,
        this->registers->a
    );
    
    return (nullptr);
}

void *CPU::RLA()
{
    this->logger->Log("CPU", "RLA");
    // Rotate A left through Carry flag
    uint8_t carry = (this->registers->a & 0x80) >> 7;
    this->registers->a = (this->registers->a << 1) | carry;
    
    return (nullptr);
}

void *CPU::RRCA()
{
    this->logger->Log("CPU", "RRCA");
    // Rotate A right through Carry flag
    uint8_t carry = this->registers->a & 0x01;
    this->registers->a = (this->registers->a >> 1) | (carry << 7);
    
    return (nullptr);
}

void *CPU::RLCA()
{
    this->logger->Log("CPU", "RLCA");
    this->registers->a = (this->registers->a << 1) | (this->registers->a >> 7);
    
    return (nullptr);
}

void *CPU::RRA()
{
    this->logger->Log("CPU", "RRA");
    this->registers->a = (this->registers->a >> 1) | (this->registers->a << 7);
    
    return (nullptr);
}

void *CPU::DAA()
{
    this->logger->Log("CPU", "DAA");
    // Decimal adjust register A
    if (this->registers->a > 0x99) {
        this->registers->a += 0x60;
    }
    if ((this->registers->a & 0x0f) > 0x09) {
        this->registers->a += 0x06;
    }
    
    return (nullptr);
}

void *CPU::CPL()
{
    this->logger->Log("CPU", "CPL");
    // Complement A register (flip all bits)
    this->registers->a = ~this->registers->a;
    
    return (nullptr);
}

void *CPU::AND_B()
{
    this->logger->Log("CPU", "AND_B");
    this->registers->a &= this->registers->b;
    updateFlags(this->registers->a);
    
    return (nullptr);
}

void *CPU::AND_C()
{
    this->logger->Log("CPU", "AND_C");
    this->registers->a &= this->registers->c;
    updateFlags(this->registers->a);
    
    return (nullptr);
}

void *CPU::AND_D()
{
    this->logger->Log("CPU", "AND_D");
    this->registers->a &= this->registers->d;
    updateFlags(this->registers->a);
    
    return (nullptr);
}

void *CPU::AND_E()
{
    this->logger->Log("CPU", "AND_E");
    this->registers->a &= this->registers->e;
    updateFlags(this->registers->a);
    
    return (nullptr);
}

void *CPU::AND_H()
{
    this->logger->Log("CPU", "AND_H");
    this->registers->a &= this->registers->h;
    updateFlags(this->registers->a);
    
    return (nullptr);
}

void *CPU::AND_L()
{
    this->logger->Log("CPU", "AND_L");
    this->registers->a &= this->registers->l;
    updateFlags(this->registers->a);
    
    return (nullptr);
}

void *CPU::AND_HL()
{
    this->logger->Log("CPU", "AND_HL");
    this->registers->a &= readByte(this->registers->GetRegister16(this->registers->h, this->registers->l));
    updateFlags(this->registers->a);
    
    return (nullptr);
}

void *CPU::AND_A()
{
    this->logger->Log("CPU", "AND_A");
    // AND A with A (no operation)
    updateFlags(this->registers->a);
    
    return (nullptr);
}

void *CPU::OR_B()
{
    this->logger->Log("CPU", "OR_B");
    this->registers->a |= this->registers->b;
    updateFlags(this->registers->a);
    
    return (nullptr);
}

void *CPU::OR_C()
{
    this->logger->Log("CPU", "OR_C");
    this->registers->a |= this->registers->c;
    updateFlags(this->registers->a);
    
    return (nullptr);
}

void *CPU::OR_D()
{
    this->logger->Log("CPU", "OR_D");
    this->registers->a |= this->registers->d;
    updateFlags(this->registers->a);
    
    return (nullptr);
}

void *CPU::OR_E()
{
    this->logger->Log("CPU", "OR_E");
    this->registers->a |= this->registers->e;
    updateFlags(this->registers->a);

    return (nullptr);
}

void *CPU::OR_H()
{
    this->logger->Log("CPU", "OR_H");
    this->registers->a |= this->registers->h;
    updateFlags(this->registers->a);
    
    return (nullptr);
}

void *CPU::OR_L()
{
    this->logger->Log("CPU", "OR_L");
    this->registers->a |= this->registers->l;
    updateFlags(this->registers->a);
    
    return (nullptr);
}

void *CPU::OR_HL()
{
    this->logger->Log("CPU", "OR_HL");
    this->registers->a |= readByte(this->registers->GetRegister16(this->registers->h, this->registers->l));
    updateFlags(this->registers->a);
    
    return (nullptr);
}

void *CPU::OR_A()
{
    this->logger->Log("CPU", "OR_A");
    // OR A with A (no operation)
    updateFlags(this->registers->a);
    
    return (nullptr);
}

void *CPU::CP_B()
{
    this->logger->Log("CPU", "CP_B");
    compare(this->registers->b);
}

void *CPU::CP_C()
{
    this->logger->Log("CPU", "CP_C");
    compare(this->registers->c);
    
    return (nullptr);
}

void *CPU::CP_D()
{
    this->logger->Log("CPU", "CP_D");
    compare(this->registers->d);
    
    return (nullptr);
}

void *CPU::CP_E()
{
    this->logger->Log("CPU", "CP_E");
    compare(this->registers->e);
    
    return (nullptr);
}

void *CPU::CP_H()
{
    this->logger->Log("CPU", "CP_H");
    compare(this->registers->h);
    
    return (nullptr);
}

void *CPU::CP_L()
{
    this->logger->Log("CPU", "CP_L");
    compare(this->registers->l);
    
    return (nullptr);
}

void *CPU::CP_HL()
{
    this->logger->Log("CPU", "CP_HL");
    compare(readByte(this->registers->GetRegister16(this->registers->h, this->registers->l)));
    
    return (nullptr);
}

void *CPU::CP_A()
{
    this->logger->Log("CPU", "CP_A");
    compare(this->registers->a);
    
    return (nullptr);
}

void *CPU::updateFlags(uint8_t value)
{
    this->logger->Log("CPU", "updateFlags");
    return (nullptr);
}

void *CPU::compare(uint8_t value)
{
    this->logger->Log("CPU", "compare");
    return (nullptr);
}

void *CPU::add(uint8_t value)
{
    this->logger->Log("CPU", "add");
    return (nullptr);
}

uint8_t CPU::readByte(uint16_t addr)
{
    this->logger->Log("CPU", "readByte");
    // Implement memory read operation
    return 0;
}

void *CPU::writeByte(uint16_t addr, uint8_t value)
{
    this->logger->Log("CPU", "writeByte");
    // Implement memory write operation
}

void *CPU::push16(uint16_t value)
{
    this->logger->Log("CPU", "push16");
    return (nullptr);
}

uint16_t CPU::pop16()
{
    this->logger->Log("CPU", "pop16");
    // Implement pop operation
    return 0;
}

void *CPU::LD_BC_d16()
{
    this->logger->Log("CPU", "LD_BC_d16");
    uint16_t immediateValue = fetch16();

    this->registers->SetRegister16(this->registers->b, this->registers->c, immediateValue);
    
    return nullptr;
}

void *CPU::LD_BC_A()
{
    this->logger->Log("CPU", "LD_BC_A");
    writeByte(this->registers->GetRegister16(this->registers->b, this->registers->c), this->registers->a);
    return nullptr;
}

uint16_t CPU::fetch16()
{
    this->logger->Log("CPU", "fetch16");
    uint8_t lowByte = readByte(this->registers->pc++);
    uint8_t highByte = readByte(this->registers->pc++);

    return static_cast<uint16_t>((highByte << 8) | lowByte);
}

void *CPU::LD_B_d8()
{
    this->logger->Log("CPU", "LD_B_d8");
    registers->b = fetch8();

    return nullptr;
}

void *CPU::LD_a16_SP()
{
    this->logger->Log("CPU", "LD_a16_SP");
    uint16_t address = fetch16();
    write16(address, registers->sp);

    return nullptr;
}

void *CPU::ADD_HL_BC()
{
    this->logger->Log("CPU", "ADD_HL_BC");
    this->registers->SetRegister16(
        this->registers->h,
        this->registers->l,
        this->registers->GetRegister16(
            this->registers->b,
            this->registers->c
        ) +
        this->registers->GetRegister16(
            this->registers->h,
            this->registers->l
        )
    );

    return nullptr;
}

void *CPU::LD_A_BC()
{
    this->logger->Log("CPU", "LD_A_BC");
    this->registers->a = this->registers->GetRegister16(
        this->registers->b,
        this->registers->c
    );

    return nullptr;
}

void *CPU::LD_C_d8()
{
    this->logger->Log("CPU", "LD_C_d8");
    registers->c = fetch8();

    return nullptr;
}

uint8_t CPU::fetch8()
{
    this->logger->Log("CPU", "fetch8");
    uint8_t value = memory[this->registers->pc];
    this->registers->pc++;

    return value;
}

void CPU::write16(uint16_t address, uint16_t value)
{
    this->logger->Log("CPU", "write16");
    write8(address, value & 0xFF);
    write8(address + 1, (value >> 8) & 0xFF);
}

void CPU::write8(uint16_t address, uint8_t value)
{
    this->logger->Log("CPU", "write8");
    memory[address] = value;
}

void *CPU::STOP()
{
    this->logger->Log("CPU", "STOP");
    // Implementation for STOP 0
    // This instruction is used to halt the Game Boy CPU until an interrupt occurs.
    // The actual behavior may vary depending on the Game Boy model.
    // For simplicity, we'll consider it as a no-op (no operation) here.

    return nullptr;
}

void *CPU::LD_DE_d16()
{
    this->logger->Log("CPU", "LD_DE_d16");
    this->registers->SetRegister16(
        this->registers->d,
        this->registers->e,
        fetch16()
    );

    return (nullptr);
}

void *CPU::LD_D_d8()
{
    this->logger->Log("CPU", "LD_D_d8");
    this->registers->d = fetch8();

    return (nullptr);
}

void *CPU::LD_A_DE()
{
    this->logger->Log("CPU", "LD_A_DE");
    this->registers->a = readByte(
        this->registers->GetRegister16(
            this->registers->d,
            this->registers->e
        )
    );

    return (nullptr);
}

void *CPU::LD_E_d8()
{
    this->logger->Log("CPU", "LD_E_d8");
    this->registers->e = fetch8();

    return (nullptr);
}

void *CPU::JR_r8()
{
    this->logger->Log("CPU", "JR_r8");
    int8_t r8 = fetch8();
    this->registers->pc += r8;

    return (nullptr);
}

void CPU::add16(uint16_t dest, uint16_t value)
{
    this->logger->Log("CPU", "add16");

    uint32_t result = dest + value;

    this->flags->z = false;
    this->flags->n = false;
    this->flags->h = (dest & 0xFFF) + (value & 0xFFF) > 0xFFF;
    this->flags->c = result > 0xFFFF;

    dest = static_cast<uint16_t>(result);
}

void *CPU::ADD_HL_DE()
{
    this->logger->Log("CPU", "ADD_HL_DE");

    add16(this->registers->GetRegister16(
            this->registers->h,
            this->registers->l
        ),
        this->registers->GetRegister16(
            this->registers->d,
            this->registers->e
        )
    );

    return (nullptr);
}

void *CPU::JR_NZ_r8()
{
    this->logger->Log("CPU", "JR_NZ_r8");

    int8_t r8 = fetch8();

    if (!this->flags->z) {
        this->registers->pc += r8;
    }

    return nullptr;
}

void *CPU::LD_HL_d16()
{
    this->logger->Log("CPU", "LD_HL_d16");

    uint16_t d16 = fetch16();

    this->registers->SetRegister16(
        this->registers->h,
        this->registers->l,
        d16
    );

    return nullptr;
}

void *CPU::LD_HL_A_increment()
{
    this->logger->Log("CPU", "LD_HL_A_increment");

    uint16_t hl = 0;

    writeByte(
        this->registers->GetRegister16(this->registers->h, this->registers->l),
        this->registers->a
    );
    hl = this->registers->GetRegister16(this->registers->h, this->registers->l);
    this->registers->SetRegister16(
        this->registers->h,
        this->registers->l,
        hl += 1
    );

    return nullptr;
}
