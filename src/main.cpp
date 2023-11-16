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

void disassembler(GameGirl *gamegirl)
{
    bool bypass = true;
    size_t limit = 50;
    uint8_t padding = 0;

    for (size_t i = 0; i < gamegirl->rom->size; i++) {
        if (bypass == true && i >= limit)
            break;
        padding = gamegirl->cpu->Execute((uint8_t)gamegirl->rom->data[i]);
        i += padding;
    }
}

bool validate_args(int argc, char **argv)
{
    return (argc == 2);
}

int main(int argc, char **argv)
{
    std::string test_flag = std::string("run_tests");
    char *rom = nullptr;
    GameGirl *gamegirl = nullptr;

    if (validate_args(argc, argv) == true) {
        rom = argv[1];
        if (std::string(rom) == test_flag) {
            gamegirl = new GameGirl();
            gamegirl->tests->TEST_Run();
        } else {
            gamegirl = new GameGirl(rom);
            information(gamegirl);
            disassembler(gamegirl);
        }
    } else {
        std::cout << "no rom selected: " << argv[0] << " <rom path>" << std::endl;
    }

    return (0);
}
