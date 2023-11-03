#include "Register.hpp"

Register::Register()
{

}

Register::~Register()
{

}

bool validateValue(unsigned char value)
{
    return (value <= 255);
}

unsigned char Register::getRegisterA()
{
    return (this->a);
}

unsigned char Register::setRegisterA(unsigned char a)
{
    if (validateValue(a) == true)
        this->a = a;

    return (Register::getRegisterA());
}

unsigned char Register::getRegisterB()
{
    return (this->b);
}

unsigned char Register::setRegisterB(unsigned char b)
{
    if (validateValue(b) == true)
        this->b = b;

    return (Register::getRegisterB());
}

unsigned char Register::getRegisterC()
{
    return (this->c);
}

unsigned char Register::setRegisterC(unsigned char c)
{
    if (validateValue(c) == true)
        this->c = c;

    return (Register::getRegisterC());
}

unsigned char Register::getRegisterD()
{
    return (this->d);
}

unsigned char Register::setRegisterD(unsigned char d)
{
    if (validateValue(d) == true)
        this->d = d;

    return (Register::getRegisterD());
}

unsigned char Register::getRegisterE()
{
    return (this->e);
}

unsigned char Register::setRegisterE(unsigned char e)
{
    if (validateValue(e) == true)
        this->e = e;

    return (Register::getRegisterE());
}

unsigned char Register::getRegisterF()
{
    return (this->f);
}

unsigned char Register::setRegisterF(unsigned char f)
{
    if (validateValue(f) == true)
        this->f = f;

    return (Register::getRegisterF());
}

unsigned char Register::getRegisterH()
{
    return (this->h);
}

unsigned char Register::setRegisterH(unsigned char h)
{
    if (validateValue(h) == true)
        this->h = h;

    return (Register::getRegisterH());
}

unsigned char Register::getRegisterL()
{
    return (this->l);
}

unsigned char Register::setRegisterL(unsigned char l)
{
    if (validateValue(l) == true)
        this->l = l;

    return (Register::getRegisterL());
}

unsigned char Register::getRegisterP()
{
    return (this->p);
}

unsigned char Register::setRegisterP(unsigned char p)
{
    if (validateValue(p) == true)
        this->p = p;

    return (Register::getRegisterP());
}

unsigned char Register::getRegisterS()
{
    return (this->s);
}

unsigned char Register::setRegisterS(unsigned char s)
{
    if (validateValue(s) == true)
        this->s = s;

    return (Register::getRegisterS());
}

unsigned short Register::getRegisterAF()
{
    return (((unsigned short)this->a << 8) | this->f);
}

unsigned short Register::setRegisterAF(unsigned char a, unsigned char f)
{
    Register::setRegisterA(a);
    Register::setRegisterF(f);

    return (Register::getRegisterAF());
}

unsigned short Register::getRegisterBC()
{
    return (((unsigned short)this->b << 8) | this->c);
}

unsigned short Register::setRegisterBC(unsigned char b, unsigned char c)
{
    Register::setRegisterB(b);
    Register::setRegisterC(c);

    return (Register::getRegisterBC());
}


unsigned short Register::getRegisterDE()
{
    return (((unsigned short)this->d << 8) | this->e);
}

unsigned short Register::setRegisterDE(unsigned char d, unsigned char e)
{
    Register::setRegisterD(d);
    Register::setRegisterE(e);

    return (Register::getRegisterDE());
}

unsigned short Register::getRegisterHL()
{
    return (((unsigned short)this->h << 8) | this->l);
}

unsigned short Register::setRegisterHL(unsigned char h, unsigned char l)
{
    Register::setRegisterH(h);
    Register::setRegisterL(l);

    return (Register::getRegisterHL());
}

unsigned short Register::getRegisterSP()
{
    return (((unsigned short)this->s << 8) | this->p);
}

unsigned short Register::setRegisterSP(unsigned char s, unsigned char p)
{
    Register::setRegisterS(s);
    Register::setRegisterP(p);

    return (Register::getRegisterSP());
}

unsigned short Register::getRegisterPC()
{
    return (((unsigned short)this->p << 8) | this->c);
}

unsigned short Register::setRegisterPC(unsigned char p, unsigned char c)
{
    Register::setRegisterP(p);
    Register::setRegisterC(c);

    return (Register::getRegisterPC());
}
