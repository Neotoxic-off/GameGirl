#include "Register.hpp"

Register::Register()
{
    this->a = 0x00;
    this->b = 0x00;
    this->c = 0x00;
    this->d = 0x00;
    this->e = 0x00;
    this->f = 0x00;
    this->h = 0x00;
    this->l = 0x00;

    this->sp = 0x00;
    this->pc = 0x00;
}

Register::~Register()
{

}

uint8_t Register::GetHighByte(uint16_t value)
{
    return (static_cast<uint8_t>((value >> 8) & 0xFF));
}

uint8_t Register::GetLowByte(uint16_t value)
{
    return(static_cast<uint8_t>(value & 0xFF));
}

uint16_t Register::SetRegister16(uint8_t &a, uint8_t &b, uint16_t value)
{
    a = Register::GetHighByte(value);
    b = Register::GetLowByte(value);

    return (Register::GetRegister16(a, b));
}

uint16_t Register::GetRegister16(uint8_t &a, uint8_t &b)
{
    return (static_cast<uint16_t>((a << 8) | b));
}
