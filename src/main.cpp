#include "GameGirl.hpp"

void information(GameGirl *gamegirl)
{
    bool status = gamegirl->rom->status;

    std::cout << "[+] loaded rom: " << (status == 1 ? "true" : "false") << std::endl;
    if (status == true)
    {
        std::cout << "[+] path: " << gamegirl->rom->path << std::endl;
        std::cout << "[+] title: " << gamegirl->rom->title << std::endl;
        std::cout << "[+] cpu (" << &gamegirl->cpu << ")" << std::endl;
        std::cout << "[+] cpu NORMAL A: '" << static_cast<int>(*(gamegirl->cpu->registers->a)) << "'" << std::endl;
        gamegirl->cpu->INC(gamegirl->cpu->registers->a);
        std::cout << "[+] cpu    INC A: '" << static_cast<int>(*(gamegirl->cpu->registers->a)) << "'" << std::endl;
        gamegirl->cpu->DEC(gamegirl->cpu->registers->a);
        std::cout << "[+] cpu    DEC A: '" << static_cast<int>(*(gamegirl->cpu->registers->a)) << "'" << std::endl;
    }
}

int main(int argc, char **argv)
{
    GameGirl *gamegirl = new GameGirl("rom/Pokemon - Emerald Version.gba");
    information(gamegirl);

    return (0);
}
