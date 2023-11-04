#pragma once

    #include <fstream>
    #include <iostream>

    #include "Logger.hpp"
    #include "Memory.hpp"

    class GameGirl
    {
        public:
            Memory *memory;

            GameGirl();
            ~GameGirl();

            bool LoadRom(std::string);

        private:
            char *romData;

            Logger *logger;
    };
