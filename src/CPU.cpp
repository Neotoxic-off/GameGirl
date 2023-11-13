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

void *CPU::NIY() {
    this->logger->Log("CPU", "NOT IMPLEMENTED YET ;w;");
    
    return (nullptr);
}

void *CPU::NOP() {
    // No operation
    
    return (nullptr);
}

void *CPU::INC_B() {
    this->registers->b++;
    updateFlags(this->registers->b);
    
    return (nullptr);
}

void *CPU::DEC_B() {
    this->registers->b--;
    updateFlags(this->registers->b);
    
    return (nullptr);
}

void *CPU::INC_C() {
    this->registers->c++;
    updateFlags(this->registers->c);
    
    return (nullptr);
}

void *CPU::DEC_C() {
    this->registers->c--;
    updateFlags(this->registers->c);
    
    return (nullptr);
}

void *CPU::INC_D() {
    this->registers->d++;
    updateFlags(this->registers->d);
    
    return (nullptr);
}

void *CPU::DEC_D() {
    this->registers->d--;
    updateFlags(this->registers->d);
    
    return (nullptr);
}

void *CPU::INC_E() {
    this->registers->e++;
    updateFlags(this->registers->e);
    
    return (nullptr);
}

void *CPU::DEC_E() {
    this->registers->e--;
    updateFlags(this->registers->e);
    
    return (nullptr);
}

void *CPU::INC_H() {
    this->registers->h++;
    updateFlags(this->registers->h);
    
    return (nullptr);
}

void *CPU::DEC_H() {
    this->registers->h--;
    updateFlags(this->registers->h);
    
    return (nullptr);
}

void *CPU::INC_L() {
    this->registers->l++;
    updateFlags(this->registers->l);
    
    return (nullptr);
}

void *CPU::DEC_L() {
    this->registers->l--;
    updateFlags(this->registers->l);
    
    return (nullptr);
}

void *CPU::INC_BC()
{
    this->registers->SetRegister16(
        this->registers->b,
        this->registers->c,
        this->registers->GetRegister16(this->registers->b, this->registers->c) + 1
    );
    
    return (nullptr);
}

void *CPU::DEC_BC()
{
    this->registers->SetRegister16(
        this->registers->b,
        this->registers->c,
        this->registers->GetRegister16(this->registers->b, this->registers->c) - 1
    );
    
    return (nullptr);
}

void *CPU::INC_DE()
{
    this->registers->SetRegister16(
        this->registers->d,
        this->registers->e,
        this->registers->GetRegister16(this->registers->d, this->registers->e) + 1
    );
    
    return (nullptr);
}

void *CPU::DEC_DE()
{
    this->registers->SetRegister16(
        this->registers->d,
        this->registers->e,
        this->registers->GetRegister16(this->registers->d, this->registers->e) - 1
    );
    
    return (nullptr);
}

void *CPU::INC_HL()
{
    this->registers->SetRegister16(
        this->registers->h,
        this->registers->l,
        this->registers->GetRegister16(this->registers->h, this->registers->l) + 1
    );
    
    return (nullptr);
}

void *CPU::DEC_HL()
{
    this->registers->SetRegister16(
        this->registers->h,
        this->registers->l,
        this->registers->GetRegister16(this->registers->h, this->registers->l) - 1
    );
    
    return (nullptr);
}

void *CPU::INC_SP()
{
    this->registers->sp++;
    
    return (nullptr);
}

void *CPU::DEC_SP()
{
    this->registers->sp--;
    
    return (nullptr);
}

void *CPU::LD_A_A() {
    // Load A into A (no operation)
    
    return (nullptr);
}

void *CPU::LD_DE_A()
{
    this->registers->SetRegister16(
        this->registers->d,
        this->registers->e,
        this->registers->a
    );
    
    return (nullptr);
}

void *CPU::RLA() {
    // Rotate A left through Carry flag
    uint8_t carry = (this->registers->a & 0x80) >> 7;
    this->registers->a = (this->registers->a << 1) | carry;
    
    return (nullptr);
}

void *CPU::RRCA() {
    // Rotate A right through Carry flag
    uint8_t carry = this->registers->a & 0x01;
    this->registers->a = (this->registers->a >> 1) | (carry << 7);
    
    return (nullptr);
}

void *CPU::RLCA() {
    // Rotate A left
    this->registers->a = (this->registers->a << 1) | (this->registers->a >> 7);
    
    return (nullptr);
}

void *CPU::RRA() {
    // Rotate A right
    this->registers->a = (this->registers->a >> 1) | (this->registers->a << 7);
    
    return (nullptr);
}

void *CPU::DAA() {
    // Decimal adjust register A
    if (this->registers->a > 0x99) {
        this->registers->a += 0x60;
    }
    if ((this->registers->a & 0x0f) > 0x09) {
        this->registers->a += 0x06;
    }
    
    return (nullptr);
}

void *CPU::CPL() {
    // Complement A register (flip all bits)
    this->registers->a = ~this->registers->a;
    
    return (nullptr);
}

void *CPU::AND_B() {
    this->registers->a &= this->registers->b;
    updateFlags(this->registers->a);
    
    return (nullptr);
}

void *CPU::AND_C() {
    this->registers->a &= this->registers->c;
    updateFlags(this->registers->a);
    
    return (nullptr);
}

void *CPU::AND_D() {
    this->registers->a &= this->registers->d;
    updateFlags(this->registers->a);
    
    return (nullptr);
}

void *CPU::AND_E() {
    this->registers->a &= this->registers->e;
    updateFlags(this->registers->a);
    
    return (nullptr);
}

void *CPU::AND_H() {
    this->registers->a &= this->registers->h;
    updateFlags(this->registers->a);
    
    return (nullptr);
}

void *CPU::AND_L() {
    this->registers->a &= this->registers->l;
    updateFlags(this->registers->a);
    
    return (nullptr);
}

void *CPU::AND_HL() {
    this->registers->a &= readByte(this->registers->GetRegister16(this->registers->h, this->registers->l));
    updateFlags(this->registers->a);
    
    return (nullptr);
}

void *CPU::AND_A() {
    // AND A with A (no operation)
    updateFlags(this->registers->a);
    
    return (nullptr);
}

void *CPU::OR_B() {
    this->registers->a |= this->registers->b;
    updateFlags(this->registers->a);
    
    return (nullptr);
}

void *CPU::OR_C() {
    this->registers->a |= this->registers->c;
    updateFlags(this->registers->a);
    
    return (nullptr);
}

void *CPU::OR_D() {
    this->registers->a |= this->registers->d;
    updateFlags(this->registers->a);
    
    return (nullptr);
}

void *CPU::OR_E() {
    this->registers->a |= this->registers->e;
    updateFlags(this->registers->a);

    return (nullptr);
}

void *CPU::OR_H() {
    this->registers->a |= this->registers->h;
    updateFlags(this->registers->a);
    
    return (nullptr);
}

void *CPU::OR_L() {
    this->registers->a |= this->registers->l;
    updateFlags(this->registers->a);
    
    return (nullptr);
}

void *CPU::OR_HL() {
    this->registers->a |= readByte(this->registers->GetRegister16(this->registers->h, this->registers->l));
    updateFlags(this->registers->a);
    
    return (nullptr);
}

void *CPU::OR_A() {
    // OR A with A (no operation)
    updateFlags(this->registers->a);
    
    return (nullptr);
}

void *CPU::CP_B() {
    compare(this->registers->b);
}

void *CPU::CP_C() {
    compare(this->registers->c);
    
    return (nullptr);
}

void *CPU::CP_D() {
    compare(this->registers->d);
    
    return (nullptr);
}

void *CPU::CP_E() {
    compare(this->registers->e);
    
    return (nullptr);
}

void *CPU::CP_H() {
    compare(this->registers->h);
    
    return (nullptr);
}

void *CPU::CP_L() {
    compare(this->registers->l);
    
    return (nullptr);
}

void *CPU::CP_HL() {
    compare(readByte(this->registers->GetRegister16(this->registers->h, this->registers->l)));
    
    return (nullptr);
}

void *CPU::CP_A() {
    compare(this->registers->a);
    
    return (nullptr);
}

void *CPU::updateFlags(uint8_t value)
{
    return (nullptr);
}

void *CPU::compare(uint8_t value) {
    return (nullptr);
}

void *CPU::add(uint8_t value) {
    return (nullptr);
}

uint8_t CPU::readByte(uint16_t addr) {
    // Implement memory read operation
    return 0;
}

void *CPU::writeByte(uint16_t addr, uint8_t value) {
    // Implement memory write operation
}

void *CPU::push16(uint16_t value) {
    return (nullptr);
}

uint16_t CPU::pop16() {
    // Implement pop operation
    return 0;
}
