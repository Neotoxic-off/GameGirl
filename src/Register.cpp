#include "Register.hpp"

Register::Register()
{

}

Register::~Register()
{

}

unsigned char Register::get_a()
{
    return (this->a);
}

unsigned char Register::set_a(unsigned char a)
{
    this->a = a;

    return (get_a());
}

unsigned char Register::get_b()
{
    return (this->b);
}

unsigned char Register::set_b(unsigned char b)
{
    this->b = b;

    return (get_b());
}

unsigned char Register::get_c()
{
    return (this->c);
}

unsigned char Register::set_c(unsigned char c)
{
    this->c = c;

    return (get_c());
}

unsigned char Register::get_d()
{
    return (this->d);
}

unsigned char Register::set_d(unsigned char d)
{
    this->d = d;

    return (get_d());
}

unsigned char Register::get_e()
{
    return (this->e);
}

unsigned char Register::set_e(unsigned char e)
{
    this->e = e;

    return (get_e());
}

unsigned char Register::get_f()
{
    return (this->f);
}

unsigned char Register::set_f(unsigned char f)
{
    this->e = f;

    return (get_f());
}

unsigned char Register::get_h()
{
    return (this->h);
}

unsigned char Register::set_h(unsigned char h)
{
    this->h = h;

    return (get_h());
}

unsigned char Register::get_l()
{
    return (this->l);
}

unsigned char Register::set_l(unsigned char l)
{
    this->l = l;

    return (get_l());
}

unsigned char Register::get_p()
{
    return (this->p);
}

unsigned char Register::set_p(unsigned char p)
{
    this->p = p;

    return (get_p());
}

unsigned char Register::get_s()
{
    return (this->s);
}

unsigned char Register::set_s(unsigned char s)
{
    this->s = s;

    return (get_s());
}

unsigned short Register::get_af()
{
    return (((unsigned short)this->a << 8) | this->f);
}

unsigned short Register::set_af(unsigned char a, unsigned char f)
{
    set_a(a);
    set_f(f);

    return (get_af());
}

unsigned short Register::get_bc()
{
    return (((unsigned short)this->b << 8) | this->c);
}

unsigned short Register::set_bc(unsigned char b, unsigned char c)
{
    set_b(b);
    set_c(c);

    return (get_bc());
}


unsigned short Register::get_de()
{
    return (((unsigned short)this->d << 8) | this->e);
}

unsigned short Register::set_de(unsigned char d, unsigned char e)
{
    set_d(d);
    set_e(e);

    return (get_de());
}

unsigned short Register::get_hl()
{
    return (((unsigned short)this->h << 8) | this->l);
}

unsigned short Register::set_hl(unsigned char h, unsigned char l)
{
    set_h(h);
    set_l(l);

    return (get_hl());
}

unsigned short Register::get_sp()
{
    return (((unsigned short)this->s << 8) | this->p);
}

unsigned short Register::set_sp(unsigned char s, unsigned char p)
{
    set_s(s);
    set_p(p);

    return (get_sp());
}

unsigned short Register::get_pc()
{
    return (((unsigned short)this->p << 8) | this->c);
}

unsigned short Register::set_pc(unsigned char p, unsigned char c)
{
    set_p(p);
    set_p(c);

    return (get_pc());
}
