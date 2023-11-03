#include "Instruction.hpp"

Instruction::Instruction(char *disassembly, void *execute, unsigned char length)
{
    this->disassembly = disassembly;
    this->execute = execute;
    this->length = length;
}

Instruction::~Instruction()
{

}
