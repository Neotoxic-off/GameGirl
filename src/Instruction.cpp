#include "Instruction.hpp"

Instruction::Instruction(char *disassembly, std::function<void(void)> execute, uint8_t length)
{
    this->disassembly = disassembly;
    this->execute = execute;
    this->length = length;
}

Instruction::~Instruction()
{
    if (disassembly != nullptr) {
        delete[] disassembly;
    }
}
