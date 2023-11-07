#include "GameGirl.hpp"

void information(GameGirl *gamegirl)
{
    bool status = gamegirl->rom->status;

    std::cout << "[+] loaded rom: " << (status == 1 ? "true" : "false") << std::endl;
    if (status == true)
    {
        std::cout << "[+] path: " << gamegirl->rom->path << std::endl;
        std::cout << "[+] rom data: " << &gamegirl->rom->data << std::endl;
        std::cout << "[+] cpu: " << &gamegirl->cpu << std::endl;
        std::cout << "[+] cpu memory: " << &gamegirl->cpu->memory << std::endl;
    }
}

void disassembly(GameGirl *gamegirl)
{
    for (size_t i = 0; i < gamegirl->rom->size; i++) {
        if (gamegirl->rom->data[i] < 256) {
            std::cout << gamegirl->cpu->instructions[(uint8_t)gamegirl->rom->data[i]].disassembly << std::endl;
        } else {
            std::cout << "SKIP: 0x" << std::hex << (uint8_t)gamegirl->rom->data[i] << std::endl;
        }
    }
}

void test(GameGirl *gamegirl)
{
    gamegirl->cpu->INC(gamegirl->cpu->registers->b);
    gamegirl->cpu->DEC(gamegirl->cpu->registers->a);
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
        disassembly(gamegirl);
    } else {
        std::cout << "no rom selected: " << argv[0] << " <rom path>" << std::endl;
    }


    return (0);
}
