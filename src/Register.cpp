#include "Register.hpp"

Register::Register()
{

}

Register::~Register()
{

}

bool validateValue(uint8_t value)
{
    return (value <= 255);
}

uint8_t Register::getRegisterA()
{
    return (this->a);
}

uint8_t Register::setRegisterA(uint8_t a)
{
    if (validateValue(a) == true)
        this->a = a;

    return (Register::getRegisterA());
}

uint8_t Register::getRegisterB()
{
    return (this->b);
}

uint8_t Register::setRegisterB(uint8_t b)
{
    if (validateValue(b) == true)
        this->b = b;

    return (Register::getRegisterB());
}

uint8_t Register::getRegisterC()
{
    return (this->c);
}

uint8_t Register::setRegisterC(uint8_t c)
{
    if (validateValue(c) == true)
        this->c = c;

    return (Register::getRegisterC());
}

uint8_t Register::getRegisterD()
{
    return (this->d);
}

uint8_t Register::setRegisterD(uint8_t d)
{
    if (validateValue(d) == true)
        this->d = d;

    return (Register::getRegisterD());
}

uint8_t Register::getRegisterE()
{
    return (this->e);
}

uint8_t Register::setRegisterE(uint8_t e)
{
    if (validateValue(e) == true)
        this->e = e;

    return (Register::getRegisterE());
}

uint8_t Register::getRegisterF()
{
    return (this->f);
}

uint8_t Register::setRegisterF(uint8_t f)
{
    if (validateValue(f) == true)
        this->f = f;

    return (Register::getRegisterF());
}

uint8_t Register::getRegisterH()
{
    return (this->h);
}

uint8_t Register::setRegisterH(uint8_t h)
{
    if (validateValue(h) == true)
        this->h = h;

    return (Register::getRegisterH());
}

uint8_t Register::getRegisterL()
{
    return (this->l);
}

uint8_t Register::setRegisterL(uint8_t l)
{
    if (validateValue(l) == true)
        this->l = l;

    return (Register::getRegisterL());
}

uint8_t Register::getRegisterP()
{
    return (this->p);
}

uint8_t Register::setRegisterP(uint8_t p)
{
    if (validateValue(p) == true)
        this->p = p;

    return (Register::getRegisterP());
}

uint8_t Register::getRegisterS()
{
    return (this->s);
}

uint8_t Register::setRegisterS(uint8_t s)
{
    if (validateValue(s) == true)
        this->s = s;

    return (Register::getRegisterS());
}

uint16_t Register::getRegisterAF()
{
    return (((uint16_t)this->a << 8) | this->f);
}

uint16_t Register::setRegisterAF(uint8_t a, uint8_t f)
{
    Register::setRegisterA(a);
    Register::setRegisterF(f);

    return (Register::getRegisterAF());
}

uint16_t Register::getRegisterBC()
{
    return (((uint16_t)this->b << 8) | this->c);
}

uint16_t Register::setRegisterBC(uint8_t b, uint8_t c)
{
    Register::setRegisterB(b);
    Register::setRegisterC(c);

    return (Register::getRegisterBC());
}


uint16_t Register::getRegisterDE()
{
    return (((uint16_t)this->d << 8) | this->e);
}

uint16_t Register::setRegisterDE(uint8_t d, uint8_t e)
{
    Register::setRegisterD(d);
    Register::setRegisterE(e);

    return (Register::getRegisterDE());
}

uint16_t Register::getRegisterHL()
{
    return (((uint16_t)this->h << 8) | this->l);
}

uint16_t Register::setRegisterHL(uint8_t h, uint8_t l)
{
    Register::setRegisterH(h);
    Register::setRegisterL(l);

    return (Register::getRegisterHL());
}

uint16_t Register::getRegisterSP()
{
    return (((uint16_t)this->s << 8) | this->p);
}

uint16_t Register::setRegisterSP(uint8_t s, uint8_t p)
{
    Register::setRegisterS(s);
    Register::setRegisterP(p);

    return (Register::getRegisterSP());
}

uint16_t Register::getRegisterPC()
{
    return (((uint16_t)this->p << 8) | this->c);
}

uint16_t Register::setRegisterPC(uint8_t p, uint8_t c)
{
    Register::setRegisterP(p);
    Register::setRegisterC(c);

    return (Register::getRegisterPC());
}
