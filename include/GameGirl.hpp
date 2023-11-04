#pragma once

    #include <iostream>

    #include "Logger.hpp"
    #include "Memory.hpp"
    #include "Rom.hpp"

    class GameGirl
    {
        public:
            Memory *memory;
            Rom *rom;

            GameGirl(std::string);
            ~GameGirl();

        private:
            Logger *logger;
    };
