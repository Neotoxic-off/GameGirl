#include "GameGirl.hpp"

int main(int argc, char **argv)
{
    GameGirl *gamegirl = new GameGirl();
    bool status = gamegirl->LoadRom("rom/Pokemon - Emerald Version.gba");

    std::cout << "[+] loaded rom: " << (status == 1 ? "true" : "false") << std::endl;
    if (status == true)
    {
        std::cout << "[+] memory (" << gamegirl->memory->registers_length << ")" << std::endl;
        for (size_t i = 0; i < gamegirl->memory->registers_length; i++)
        {
            std::cout << "[+] " << i << ":\t(" << &gamegirl->memory->registers[i] << ")" << std::endl;
        }
    }

    return (0);
}
