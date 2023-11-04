#include "Memory.hpp"

Memory::Memory()
{
    this->registers_length = 16;
    this->registers = new Register[this->registers_length];
}

Memory::~Memory()
{
    delete[] this->registers;
}
