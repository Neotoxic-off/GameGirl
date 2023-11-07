#include "Instruction.hpp"

Instruction::Instruction(const char *disassembly, void *execute, uint8_t length)
{
    this->disassembly = disassembly;
    this->execute = execute;
    this->length = new uint8_t(length);
}

Instruction::~Instruction()
{
    if (disassembly != nullptr) {
        delete[] disassembly;
    }
}
