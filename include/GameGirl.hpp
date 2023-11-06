#pragma once

    #include <iostream>

    #include "Logger.hpp"
    #include "CPU.hpp"
    #include "Rom.hpp"

    class GameGirl
    {
        public:
            CPU *cpu;
            Rom *rom;
            uint8_t *memory;

            GameGirl(std::string);
            ~GameGirl();

        private:
            Logger *logger;
    };
