#include "GameGirl.hpp"

int main(int argc, char **argv)
{
    GameGirl *gamegirl = new GameGirl();
    bool status = gamegirl->LoadRom("rom/Pokemon - Emerald Version.gba");

    std::cout << "[+] loaded rom: " << (status == 1 ? "true" : "false") << std::endl;

    return (0);
}
