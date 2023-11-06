#include "Flags.hpp"

Flags::Flags()
{
    this->z = new bool(false);
    this->n = new bool(false);
    this->h = new bool(false);
    this->c = new bool(false);
}

Flags::~Flags()
{
    delete[] this->z;
    delete[] this->n;
    delete[] this->h;
    delete[] this->c;
}
