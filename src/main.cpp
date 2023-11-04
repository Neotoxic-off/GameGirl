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
    gamegirl->cpu->POP(gamegirl->cpu->registers->a);
}

bool validate_args(int argc, char **argv)
{
    return (argc == 2);
}

int main(int argc, char **argv)
{
    char *rom = nullptr;
    GameGirl *gamegirl = nullptr;

    if (validate_args(argc, argv) == true) {
        rom = argv[1];
        gamegirl = new GameGirl(rom);
        information(gamegirl);
        test(gamegirl);
    } else {
        std::cout << "no rom selected: " << argv[0] << " <rom path>" << std::endl;
    }


    return (0);
}
