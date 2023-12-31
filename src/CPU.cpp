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

    return (nullptr);
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
    
    return (nullptr);
}

void *CPU::LD_BC_A()
{
    this->logger->Log("CPU", "LD_BC_A");
    writeByte(this->registers->GetRegister16(this->registers->b, this->registers->c), this->registers->a);
    return (nullptr);
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

    return (nullptr);
}

void *CPU::LD_a16_SP()
{
    this->logger->Log("CPU", "LD_a16_SP");
    uint16_t address = fetch16();
    write16(address, registers->sp);

    return (nullptr);
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

    return (nullptr);
}

void *CPU::LD_A_BC()
{
    this->logger->Log("CPU", "LD_A_BC");
    this->registers->a = this->registers->GetRegister16(
        this->registers->b,
        this->registers->c
    );

    return (nullptr);
}

void *CPU::LD_C_d8()
{
    this->logger->Log("CPU", "LD_C_d8");
    registers->c = fetch8();

    return (nullptr);
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

    return (nullptr);
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

    return (nullptr);
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

    return (nullptr);
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

    return (nullptr);
}

void *CPU::LD_H_d8()
{
    this->logger->Log("CPU", "LD_H_d8");
    this->registers->h = fetch8();
    return (nullptr);
}

void *CPU::JR_Z_r8()
{
    this->logger->Log("CPU", "JR_Z_r8");
    int8_t r8 = fetch8();

    if (this->flags->z) {
        this->registers->pc += r8;
    }

    return (nullptr);
}

void *CPU::ADD_HL_HL()
{
    this->logger->Log("CPU", "ADD_HL_HL");
    add16(this->registers->GetRegister16(this->registers->h, this->registers->l),
          this->registers->GetRegister16(this->registers->h, this->registers->l));
    return (nullptr);
}

void *CPU::LD_A_HL_increment()
{
    uint16_t hl = 0;

    this->logger->Log("CPU", "LD_A_HL_increment");
    this->registers->a = readByte(this->registers->GetRegister16(this->registers->h, this->registers->l));
    
    hl = this->registers->GetRegister16(this->registers->h, this->registers->l);
    this->registers->SetRegister16(
        this->registers->h,
        this->registers->l,
        hl
    );
    return (nullptr);
}

void *CPU::LD_L_d8()
{
    this->logger->Log("CPU", "LD_L_d8");
    this->registers->l = fetch8();
    return (nullptr);
}

void *CPU::JR_NC_r8()
{
    this->logger->Log("CPU", "JR_NC_r8");
    int8_t r8 = fetch8();

    if (!this->flags->c) {
        this->registers->pc += r8;
    }
    return (nullptr);
}

void *CPU::LD_SP_d16()
{
    this->logger->Log("CPU", "LD_SP_d16");
    this->registers->sp = fetch16();
    return (nullptr);
}

void *CPU::LD_HL_decrement_A()
{
    this->logger->Log("CPU", "LD_HL_decrement_A");
    uint16_t hl = 0;

    writeByte(this->registers->GetRegister16(this->registers->h, this->registers->l), this->registers->a);

    hl = this->registers->GetRegister16(this->registers->h, this->registers->l);
    this->registers->SetRegister16(this->registers->h, this->registers->l, hl--);
    return (nullptr);
}

void *CPU::LD_HL_d8()
{
    this->logger->Log("CPU", "LD_HL_d8");
    writeByte(this->registers->GetRegister16(this->registers->h, this->registers->l), fetch8());
    return (nullptr);
}

void *CPU::SCF()
{
    this->logger->Log("CPU", "SCF");
    this->flags->c = true;
    this->flags->n = false;
    this->flags->h = false;
    return (nullptr);
}

void *CPU::JR_C_r8()
{
    this->logger->Log("CPU", "JR_C_r8");
    int8_t r8 = fetch8();
    if (this->flags->c) {
        this->registers->pc += r8;
    }
    return (nullptr);
}

void *CPU::ADD_HL_SP()
{
    this->logger->Log("CPU", "ADD_HL_SP");
    add16(this->registers->GetRegister16(this->registers->h, this->registers->l),
          this->registers->sp);
    return (nullptr);
}

void *CPU::LD_A_decrement_HL()
{
    this->logger->Log("CPU", "LD_A_decrement_HL");
    uint16_t hl = 0;

    this->registers->a = readByte(this->registers->GetRegister16(this->registers->h, this->registers->l));
    hl = this->registers->GetRegister16(this->registers->h, this->registers->l);
    this->registers->SetRegister16(this->registers->h, this->registers->l, hl--);
    return (nullptr);
}

void *CPU::INC_A()
{
    this->logger->Log("CPU", "INC_A");
    this->registers->a++;
    updateFlags();
    return (nullptr);
}

void *CPU::DEC_A()
{
    this->logger->Log("CPU", "DEC_A");
    this->registers->a--;
    updateFlags();
    return (nullptr);
}

void *CPU::LD_A_d8()
{
    this->logger->Log("CPU", "LD_A_d8");
    this->registers->a = fetch8();
    return (nullptr);
}

void *CPU::CCF()
{
    this->logger->Log("CPU", "CCF");
    this->flags->c = !this->flags->c;
    this->flags->n = false;
    this->flags->h = false;

    return (nullptr);
}

void CPU::updateFlags()
{
    this->flags->z = (this->registers->a == 0);

    this->flags->n = false;

    this->flags->h = ((this->registers->a & 0x0F) == 0x0F);
    this->flags->c = false;
}

void *CPU::LD_B_B()
{
    this->logger->Log("CPU", "LD_B_B");
    this->registers->b = this->registers->b;
    updateFlags();

    return (nullptr);
}

void *CPU::LD_B_C()
{
    this->logger->Log("CPU", "LD_B_C");
    this->registers->b = this->registers->c;
    updateFlags();

    return (nullptr);
}

void *CPU::LD_B_D()
{
    this->logger->Log("CPU", "LD_B_D");
    this->registers->b = this->registers->d;
    updateFlags();

    return (nullptr);
}

void *CPU::LD_B_E()
{
    this->logger->Log("CPU", "LD_B_E");
    this->registers->b = this->registers->e;
    updateFlags();

    return (nullptr);
}

void *CPU::LD_B_H()
{
    this->logger->Log("CPU", "LD_B_H");
    this->registers->b = this->registers->h;
    updateFlags();

    return (nullptr);
}

void *CPU::LD_B_L()
{
    this->logger->Log("CPU", "LD_B_L");
    this->registers->b = this->registers->l;
    updateFlags();

    return (nullptr);
}

void *CPU::LD_B_HL()
{
    this->logger->Log("CPU", "LD_B_HL");
    this->registers->b = readByte(this->registers->GetRegister16(this->registers->h, this->registers->l));
    updateFlags();

    return (nullptr);
}

void *CPU::LD_B_A()
{
    this->logger->Log("CPU", "LD_B_A");
    this->registers->b = this->registers->a;
    updateFlags();

    return (nullptr);
}

void *CPU::LD_C_B()
{
    this->logger->Log("CPU", "LD_C_B");
    this->registers->c = this->registers->b;
    updateFlags();

    return (nullptr);
}

void *CPU::LD_C_C()
{
    this->logger->Log("CPU", "LD_C_C");
    this->registers->c = this->registers->c;
    updateFlags();

    return (nullptr);
}

void *CPU::LD_C_D()
{
    this->logger->Log("CPU", "LD_C_D");
    this->registers->c = this->registers->d;
    updateFlags();

    return (nullptr);
}

void *CPU::LD_C_E()
{
    this->logger->Log("CPU", "LD_C_D");
    this->registers->c = this->registers->e;
    updateFlags();

    return (nullptr);
}

void *CPU::LD_C_H()
{
    this->logger->Log("CPU", "LD_C_H");
    this->registers->c = this->registers->h;
    updateFlags();

    return (nullptr);
}

void *CPU::LD_C_L()
{
    this->logger->Log("CPU", "LD_C_L");
    this->registers->c = this->registers->l;
    updateFlags();

    return (nullptr);
}

void *CPU::LD_C_HL()
{
    this->logger->Log("CPU", "LD_C_HL");
    this->registers->c = readByte(
        this->registers->GetRegister16(
            this->registers->h,
            this->registers->l
        )
    );
    updateFlags();

    return (nullptr);
}

void *CPU::LD_C_A()
{
    this->logger->Log("CPU", "LD_C_A");
    this->registers->c = this->registers->a;
    updateFlags();

    return (nullptr);
}

void *CPU::LD_D_B()
{
    this->logger->Log("CPU", "LD_D_B");
    this->registers->d = this->registers->b;
    updateFlags();

    return (nullptr);
}

void *CPU::LD_D_C()
{
    this->logger->Log("CPU", "LD_D_C");
    this->registers->d = this->registers->c;
    updateFlags();
    return (nullptr);
}

void *CPU::LD_D_D()
{
    this->logger->Log("CPU", "LD_D_D");
    this->registers->d = this->registers->d;
    updateFlags();
    return (nullptr);
}

void *CPU::LD_D_E()
{
    this->logger->Log("CPU", "LD_D_E");
    this->registers->d = this->registers->e;
    updateFlags();
    return (nullptr);
}

void *CPU::LD_D_H()
{
    this->logger->Log("CPU", "LD_D_H");
    this->registers->d = this->registers->h;
    updateFlags();
    return (nullptr);
}

void *CPU::LD_D_L()
{
    this->logger->Log("CPU", "LD_D_L");
    this->registers->d = this->registers->l;
    updateFlags();

    return (nullptr);
}

void *CPU::LD_D_HL()
{
    this->logger->Log("CPU", "LD_D_HL");
    this->registers->d = readByte(this->registers->GetRegister16(this->registers->h, this->registers->l));
    updateFlags();
    return (nullptr);
}

void *CPU::LD_D_A()
{
    this->logger->Log("CPU", "LD_D_A");
    this->registers->d = this->registers->a;
    updateFlags();
    
    return (nullptr);
}

void *CPU::LD_E_B()
{
    this->logger->Log("CPU", "LD_E_B");
    this->registers->e = this->registers->b;
    updateFlags();
    
    return (nullptr);
}

void *CPU::LD_E_C()
{
    this->logger->Log("CPU", "LD_E_C");
    this->registers->e = this->registers->c;
    updateFlags();
    
    return (nullptr);
}

void *CPU::LD_E_D()
{
    this->logger->Log("CPU", "LD_E_D");
    this->registers->e = this->registers->d;
    updateFlags();
    
    return (nullptr);
}

void *CPU::LD_E_E()
{
    this->logger->Log("CPU", "LD_E_E");
    this->registers->e = this->registers->e;
    updateFlags();
    
    return (nullptr);
}

void *CPU::LD_E_H()
{
    this->logger->Log("CPU", "LD_E_H");
    this->registers->e = this->registers->h;
    updateFlags();
    
    return (nullptr);
}

void *CPU::LD_E_L()
{
    this->logger->Log("CPU", "LD_E_L");
    this->registers->e = this->registers->l;
    updateFlags();
    
    return (nullptr);
}

void *CPU::LD_E_HL()
{
    this->logger->Log("CPU", "LD_E_HL");
    this->registers->e = readByte(this->registers->GetRegister16(this->registers->h, this->registers->l));
    updateFlags();
    
    return (nullptr);
}

void *CPU::LD_E_A()
{
    this->logger->Log("CPU", "LD_E_A");
    this->registers->e = this->registers->a;
    updateFlags();
    
    return (nullptr);
}

void *CPU::LD_H_B()
{
    this->logger->Log("CPU", "LD_H_B");
    this->registers->h = this->registers->b;
    updateFlags();
    
    return (nullptr);
}

void *CPU::LD_H_C()
{
    this->logger->Log("CPU", "LD_H_C");
    this->registers->h = this->registers->c;
    updateFlags();
    
    return (nullptr);
}

void *CPU::LD_H_D()
{
    this->logger->Log("CPU", "LD_H_D");
    this->registers->h = this->registers->d;
    updateFlags();
    
    return (nullptr);
}

void *CPU::LD_H_E()
{
    this->logger->Log("CPU", "LD_H_E");
    this->registers->h = this->registers->e;
    updateFlags();
    
    return (nullptr);
}

void *CPU::LD_H_H()
{
    this->logger->Log("CPU", "LD_H_H");
    this->registers->h = this->registers->h;
    updateFlags();
    
    return (nullptr);
}

void *CPU::LD_H_L()
{
    this->logger->Log("CPU", "LD_H_L");
    this->registers->h = this->registers->l;
    updateFlags();
    
    return (nullptr);
}

void *CPU::LD_H_HL()
{
    this->logger->Log("CPU", "LD_H_HL");
    this->registers->h = readByte(
        this->registers->GetRegister16(
            this->registers->h,
            this->registers->l
        )
    );
    return (nullptr);
}

// LD H,A
void *CPU::LD_H_A()
{
    this->logger->Log("CPU", "LD_H_A");
    this->registers->h = this->registers->a;
    updateFlags();
    return (nullptr);
}

// LD L,B
void *CPU::LD_L_B()
{
    this->logger->Log("CPU", "LD_L_B");
    this->registers->l = this->registers->b;
    updateFlags();
    return (nullptr);
}

// LD L,C
void *CPU::LD_L_C()
{
    this->logger->Log("CPU", "LD_L_C");
    this->registers->l = this->registers->c;
    updateFlags();
    return (nullptr);
}

// LD L,D
void *CPU::LD_L_D()
{
    this->logger->Log("CPU", "LD_L_D");
    this->registers->l = this->registers->d;
    updateFlags();
    return (nullptr);
}

// LD L,E
void *CPU::LD_L_E()
{
    this->logger->Log("CPU", "LD_L_E");
    this->registers->l = this->registers->e;
    updateFlags();
    return (nullptr);
}

// LD L,H
void *CPU::LD_L_H()
{
    this->logger->Log("CPU", "LD_L_H");
    this->registers->l = this->registers->h;
    updateFlags();
    return (nullptr);
}

// LD L,L
void *CPU::LD_L_L()
{
    this->logger->Log("CPU", "LD_L_L");
    // No operation needed (L = L)
    return (nullptr);
}

// LD L,(HL)
void *CPU::LD_L_HL()
{
    this->logger->Log("CPU", "LD_L_HL");
    this->registers->l = readByte(
        this->registers->GetRegister16(
            this->registers->h,
            this->registers->l
        )
    );
    return (nullptr);
}

// LD L,A
void *CPU::LD_L_A()
{
    this->logger->Log("CPU", "LD_L_A");
    this->registers->l = this->registers->a;
    updateFlags();
    return (nullptr);
}

void *CPU::LD_HL_B()
{
    this->logger->Log("CPU", "LD_L_L");
    writeByte(this->registers->GetRegister16(
        this->registers->h,
        this->registers->l
    ), this->registers->b);
    return nullptr;
}

void *CPU::LD_HL_C()
{
    this->logger->Log("CPU", "LD_HL_C");
    writeByte(this->registers->GetRegister16(this->registers->h, this->registers->l), this->registers->c);
    
    return (nullptr);
}

void *CPU::LD_HL_D()
{
    this->logger->Log("CPU", "LD_HL_D");
    writeByte(this->registers->GetRegister16(this->registers->h, this->registers->l), this->registers->d);
    
    return (nullptr);
}

void *CPU::LD_HL_E()
{
    this->logger->Log("CPU", "LD_HL_E");
    writeByte(this->registers->GetRegister16(this->registers->h, this->registers->l), this->registers->e);
    
    return (nullptr);
}

void *CPU::LD_HL_H()
{
    this->logger->Log("CPU", "LD_HL_H");
    writeByte(this->registers->GetRegister16(this->registers->h, this->registers->l), this->registers->h);
    
    return (nullptr);
}

void *CPU::LD_HL_L()
{
    this->logger->Log("CPU", "LD_HL_L");
    writeByte(this->registers->GetRegister16(this->registers->h, this->registers->l), this->registers->l);
    
    return (nullptr);
}

void *CPU::HALT()
{
    this->logger->Log("CPU", "HALT");
    // Implement HALT instruction logic
    
    return (nullptr);
}

void *CPU::LD_HL_A()
{
    this->logger->Log("CPU", "LD_HL_A");
    writeByte(this->registers->GetRegister16(this->registers->h, this->registers->l), this->registers->a);
    
    return (nullptr);
}

void *CPU::LD_A_B()
{
    this->logger->Log("CPU", "LD_A_B");
    this->registers->a = this->registers->b;
    updateFlags();
    
    return (nullptr);
}

void *CPU::LD_A_C()
{
    this->logger->Log("CPU", "LD_A_C");
    this->registers->a = this->registers->c;
    updateFlags();
    
    return (nullptr);
}

void *CPU::LD_A_D()
{
    this->logger->Log("CPU", "LD_A_D");
    this->registers->a = this->registers->d;
    updateFlags();
    
    return (nullptr);
}

void *CPU::LD_A_E()
{
    this->logger->Log("CPU", "LD_A_E");
    this->registers->a = this->registers->e;
    updateFlags();
    
    return (nullptr);
}

void *CPU::LD_A_H()
{
    this->logger->Log("CPU", "LD_A_H");
    this->registers->a = this->registers->h;
    updateFlags();
    
    return (nullptr);
}

void *CPU::LD_A_L()
{
    this->logger->Log("CPU", "LD_A_L");
    this->registers->a = this->registers->l;
    updateFlags();
    
    return (nullptr);
}

void *CPU::LD_A_HL()
{
    this->logger->Log("CPU", "LD_A_HL");
    this->registers->a = readByte(this->registers->GetRegister16(this->registers->h, this->registers->l));
    updateFlags();
    
    return (nullptr);
}

void *CPU::ADD_A_B()
{
    this->logger->Log("CPU", "ADD_A_B");
    add(this->registers->b);
    
    return (nullptr);
}

void *CPU::ADD_A_C()
{
    this->logger->Log("CPU", "ADD_A_C");
    add(this->registers->c);
    
    return (nullptr);
}

void *CPU::ADD_A_D()
{
    this->logger->Log("CPU", "ADD_A_D");
    add(this->registers->d);
    
    return (nullptr);
}

void *CPU::ADD_A_E()
{
    this->logger->Log("CPU", "ADD_A_E");
    add(this->registers->e);
    
    return (nullptr);
}

void *CPU::ADD_A_H()
{
    this->logger->Log("CPU", "ADD_A_H");
    add(this->registers->h);
    
    return (nullptr);
}

void *CPU::ADD_A_L()
{
    this->logger->Log("CPU", "ADD_A_L");
    add(this->registers->l);
    
    return (nullptr);
}

void *CPU::ADD_A_HL()
{
    this->logger->Log("CPU", "ADD_A_HL");
    add(readByte(this->registers->GetRegister16(this->registers->h, this->registers->l)));
    
    return (nullptr);
}

void *CPU::ADD_A_A()
{
    this->logger->Log("CPU", "ADD_A_A");
    add(this->registers->a);
    
    return (nullptr);
}

void *CPU::ADC_A_B()
{
    this->logger->Log("CPU", "ADC_A_B");
    // Implement ADC A,B instruction logic
    // Add with carry

    return (nullptr);
}

void *CPU::ADC_A_C()
{
    this->logger->Log("CPU", "ADC_A_C");
    // Implement ADC A,C instruction logic

    return (nullptr);
}

void *CPU::ADC_A_D()
{
    this->logger->Log("CPU", "ADC_A_D");
    // Implement ADC A,D instruction logic

    return (nullptr);
}

void *CPU::ADC_A_E()
{
    this->logger->Log("CPU", "ADC_A_E");
    // Implement ADC A,E instruction logic

    return (nullptr);
}

void *CPU::ADC_A_H()
{
    this->logger->Log("CPU", "ADC_A_H");
    // Implement ADC A,H instruction logic

    return (nullptr);
}

void *CPU::ADC_A_L()
{
    this->logger->Log("CPU", "ADC_A_L");
    // Implement ADC A,L instruction logic

    return (nullptr);
}

void *CPU::ADC_A_HL()
{
    this->logger->Log("CPU", "ADC_A_HL");
    // Implement ADC A,(HL) instruction logic

    return (nullptr);
}

void *CPU::ADC_A_A()
{
    this->logger->Log("CPU", "ADC_A_A");
    // Implement ADC A,A instruction logic

    return (nullptr);
}

void *CPU::SUB_B()
{
    this->logger->Log("CPU", "SUB_B");

    this->registers->a -= this->registers->b;
    this->updateFlags(this->registers->a);

    return (nullptr);
}

void *CPU::SUB_C()
{
    this->logger->Log("CPU", "SUB_C");

    this->registers->a -= this->registers->c;
    this->updateFlags(this->registers->a);

    return (nullptr);
}

void *CPU::SUB_D()
{
    this->logger->Log("CPU", "SUB_D");

    this->registers->a -= this->registers->d;
    this->updateFlags(this->registers->a);

    return (nullptr);
}

void *CPU::SUB_E()
{
    this->logger->Log("CPU", "SUB_E");

    this->registers->a -= this->registers->e;
    this->updateFlags(this->registers->a);

    return (nullptr);
}

void *CPU::SUB_H()
{
    this->logger->Log("CPU", "SUB_H");

    this->registers->a -= this->registers->h;
    this->updateFlags(this->registers->a);

    return (nullptr);
}

void *CPU::SUB_L()
{
    this->logger->Log("CPU", "SUB_L");

    this->registers->a -= this->registers->l;
    this->updateFlags(this->registers->a);

    return (nullptr);
}

void *CPU::SUB_HL()
{
    this->logger->Log("CPU", "SUB_HL");

    this->registers->a -= this->registers->GetRegister16(
        this->registers->h,
        this->registers->l
    );
    this->updateFlags(this->registers->a);

    return (nullptr);
}

void *CPU::SUB_A()
{
    this->logger->Log("CPU", "SUB_A");

    this->registers->a -= this->registers->a;
    this->updateFlags(this->registers->a);

    return (nullptr);
}

void *CPU::XOR_A()
{
    this->logger->Log("CPU", "XOR_A");
    this->registers->a ^= this->registers->a;
    updateFlags(this->registers->a);
    
    return (nullptr);
}

void *CPU::XOR_B()
{
    this->logger->Log("CPU", "XOR_B");
    this->registers->a ^= this->registers->b;
    updateFlags(this->registers->a);
    
    return (nullptr);
}

void *CPU::XOR_C()
{
    this->logger->Log("CPU", "XOR_C");
    this->registers->a ^= this->registers->c;
    updateFlags(this->registers->a);
    
    return (nullptr);
}

void *CPU::XOR_D()
{
    this->logger->Log("CPU", "XOR_D");
    this->registers->a ^= this->registers->d;
    updateFlags(this->registers->a);
    
    return (nullptr);
}

void *CPU::XOR_E()
{
    this->logger->Log("CPU", "XOR_E");
    this->registers->a ^= this->registers->e;
    updateFlags(this->registers->a);
    
    return (nullptr);
}

void *CPU::XOR_H()
{
    this->logger->Log("CPU", "XOR_H");
    this->registers->a ^= this->registers->h;
    updateFlags(this->registers->a);
    
    return (nullptr);
}

void *CPU::XOR_L()
{
    this->logger->Log("CPU", "XOR_L");
    this->registers->a ^= this->registers->l;
    updateFlags(this->registers->a);
    
    return (nullptr);
}

void *CPU::XOR_HL()
{
    this->logger->Log("CPU", "XOR_HL");
    this->registers->a ^= this->registers->GetRegister16(this->registers->h, this->registers->l);
    updateFlags(this->registers->a);
    
    return (nullptr);
}

void *CPU::RET_NZ()
{
    this->logger->Log("CPU", "RET_NZ");
    if (this->flags->z == false) {
        this->registers->pc = this->pop16();
    }
}

void *CPU::POP_BC()
{
    this->logger->Log("CPU", "POP_BC");
    this->registers->SetRegister16(
        this->registers->b,
        this->registers->c,
        this->pop16()
    );

    return (nullptr);
}

void *CPU::JP_NZ_a16()
{
    this->logger->Log("CPU", "JP_NZ_a16");
    if (this->flags->z == false) {
        this->registers->pc = this->fetch16();
    } else {
        this->fetch16(); // Consume the immediate value
    }
}

void *CPU::JP_a16()
{
    this->logger->Log("CPU", "JP_a16");
    this->registers->pc = this->fetch16();
}

void *CPU::CALL_NZ_a16()
{
    this->logger->Log("CPU", "CALL_NZ_a16");
    if (this->flags->z == false) {
        this->CALL();
    } else {
        this->fetch16(); // Consume the immediate value
    }
}

void *CPU::PUSH_BC()
{
    this->logger->Log("CPU", "PUSH_BC");
    this->push16(
        this->registers->GetRegister16(
            this->registers->b,
            this->registers->c
        )
    );

    return (nullptr);
}

void *CPU::CALL()
{
    this->logger->Log("CPU", "CALL");
    uint16_t address = this->fetch16();

    this->push16(this->registers->pc);
    this->registers->pc = address;

    return (nullptr);
}

void CPU::updateFlagsAddition(uint16_t result, uint8_t reg)
{
    this->logger->Log("CPU", "updateFlagsAddition");
    this->flags->z = ((result & 0xFF) == 0);
    this->flags->c = (result > 0xFF);
    this->flags->h = (((reg & 0x0F) + (result & 0x0F)) > 0x0F);
    this->flags->n = (false);
}

void *CPU::ADD_A(uint8_t value)
{
    this->logger->Log("CPU", "ADD_A");
    uint16_t result = static_cast<uint16_t>(this->registers->a) + static_cast<uint16_t>(value);
    
    this->registers->a = static_cast<uint8_t>(result);

    this->updateFlagsAddition(result, this->registers->a);

    return (nullptr);
}

void *CPU::ADD_A_d8()
{
    this->logger->Log("CPU", "ADD_A_d8");
    uint8_t value = this->fetch8();
    this->ADD_A(value);
}

void *CPU::RST_00H()
{
    this->logger->Log("CPU", "RST_00H");
    this->CALLRST(0x00);
}

void *CPU::RET_Z()
{
    this->logger->Log("CPU", "RET_Z");
    if (this->flags->z == true) {
        this->registers->pc = this->pop16();
    }
}

void *CPU::RET()
{
    this->logger->Log("CPU", "RET");
    this->registers->pc = this->pop16();
}

void *CPU::JP_Z_a16()
{
    this->logger->Log("CPU", "JP_Z_a16");
    if (this->flags->z == true) {
        this->registers->pc = this->fetch16();
    } else {
        this->fetch16();
    }
}

void *CPU::PREFIX_CB()
{
    this->logger->Log("CPU", "PREFIX_CB");
    // Implement the logic for CB prefix
    // This is a placeholder, you need to implement the actual logic
}

void *CPU::CALL_Z_a16()
{
    this->logger->Log("CPU", "CALL_Z_a16");
    if (this->flags->z == true) {
        this->CALL();
    } else {
        this->fetch16();
    }
}

void *CPU::CALL_a16()
{
    this->logger->Log("CPU", "CALL_a16");
    this->CALL();
}

void *CPU::ADC_A(uint8_t value)
{
    this->logger->Log("CPU", "ADC_A");
    uint8_t carry = this->flags->c ? 1 : 0;
    uint16_t result = this->registers->a + value + carry;

    this->updateFlagsAddition(result, this->registers->a);
    this->registers->a = static_cast<uint8_t>(result);
}

void *CPU::ADC_A_d8()
{
    this->logger->Log("CPU", "ADC_A_d8");
    uint8_t value = this->fetch8();
    this->ADC_A(value);
}

void *CPU::CALLRST(uint16_t address)
{
    this->logger->Log("CPU", "CALLRST");
    this->registers->sp -= 2;
    this->write16(this->registers->sp, this->registers->pc);
    this->registers->pc = address;
}

void *CPU::RST_08H()
{
    this->logger->Log("CPU", "RST_08H");
    this->CALLRST(0x08);
}
