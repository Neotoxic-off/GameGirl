#include "Instruction.hpp"

Instruction::Instruction(const char *disassembly, std::function<void(void)> execute, uint8_t length)
{
    this->disassembly = disassembly;
    this->execute = execute;
    this->length = length;
}

Instruction::~Instruction()
{
    delete[] disassembly;
}
