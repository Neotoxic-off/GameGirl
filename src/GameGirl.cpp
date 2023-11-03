#include "GameGirl.hpp"

int main(int argc, char **argv)
{
    Instruction *instruction = new Instruction("LD BC, 0x%04X", NULL, 2);
    Register *_register = new Register();

    unsigned char c = _register->set_a(0x00);

    return (0);
}
