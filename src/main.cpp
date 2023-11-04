#include "GameGirl.hpp"

void information(GameGirl *gamegirl)
{
    bool status = gamegirl->rom->status;

    std::cout << "[+] loaded rom: " << (status == 1 ? "true" : "false") << std::endl;
    if (status == true)
    {
        std::cout << "[+] path: " << gamegirl->rom->path << std::endl;
        std::cout << "[+] title: " << gamegirl->rom->title << std::endl;
        std::cout << "[+] cpu: " << &gamegirl->cpu << std::endl;
    }
}

void test(GameGirl *gamegirl)
{
    std::cout << "[+] tests: " << std::endl;
    gamegirl->cpu->INC(gamegirl->cpu->registers->b);
    gamegirl->cpu->DEC(gamegirl->cpu->registers->a);

    gamegirl->cpu->OR(gamegirl->cpu->registers->b);
    gamegirl->cpu->XOR(gamegirl->cpu->registers->b);
    gamegirl->cpu->AND(gamegirl->cpu->registers->b);

    gamegirl->cpu->ADD(gamegirl->cpu->registers->a, gamegirl->cpu->registers->b);
    gamegirl->cpu->SUB(gamegirl->cpu->registers->a, gamegirl->cpu->registers->b);
    
    gamegirl->cpu->ADC(gamegirl->cpu->registers->a, gamegirl->cpu->registers->b);
    gamegirl->cpu->SBC(gamegirl->cpu->registers->a, gamegirl->cpu->registers->b);
    
    gamegirl->cpu->CP(gamegirl->cpu->registers->a);
}

int main(int argc, char **argv)
{
    GameGirl *gamegirl = new GameGirl("rom/Pokemon - Emerald Version.gba");

    information(gamegirl);
    test(gamegirl);

    return (0);
}
