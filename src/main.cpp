#include "GameGirl.hpp"

void information(GameGirl *gamegirl)
{
    bool status = gamegirl->rom->status;

    std::cout << "[+] loaded rom: " << (status == 1 ? "true" : "false") << std::endl;
    if (status == true)
    {
        std::cout << "[+] path: " << gamegirl->rom->path << std::endl;
        std::cout << "[+] title: " << gamegirl->rom->title << std::endl;
        std::cout << "[+] memory (" << gamegirl->memory->registers_length << ")" << std::endl;
        for (size_t i = 0; i < gamegirl->memory->registers_length; i++)
        {
            std::cout << "[+] " << i << ":\t(" << &gamegirl->memory->registers[i] << ")" << std::endl;
        }
    }
}

int main(int argc, char **argv)
{
    GameGirl *gamegirl = new GameGirl("rom/Pokemon - Emerald Version.gba");
    information(gamegirl);

    gamegirl = new GameGirl("rom/Pokemon - Fire Red Version.gba");
    information(gamegirl);

    return (0);
}
