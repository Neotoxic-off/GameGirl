#include "Register.hpp"

Register::Register()
{
    this->a = new uint8_t(0);
    this->b = new uint8_t(0);
    this->c = new uint8_t(0);
    this->d = new uint8_t(0);
    this->e = new uint8_t(0);
    this->f = new uint8_t(0);
    this->h = new uint8_t(0);
    this->l = new uint8_t(0);

    this->sp = new uint16_t(0);
    this->pc = new uint16_t(0);
}

Register::~Register()
{

}
