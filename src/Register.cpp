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
