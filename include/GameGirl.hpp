#pragma once

    #include <iostream>
    #include <string>

    #include "Logger.hpp"
    #include "CPU.hpp"
    #include "Rom.hpp"
    #include "Tests.hpp"

    class GameGirl
    {
        public:
            CPU *cpu;
            Rom *rom;

            Tests *tests;

            GameGirl();
            GameGirl(std::string);
            ~GameGirl();

        private:
            Logger *logger;
    };
