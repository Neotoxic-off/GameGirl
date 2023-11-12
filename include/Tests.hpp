#pragma once

    #include <map>
    #include <iostream>
    #include <functional>

    #include "Logger.hpp"
    #include "CPU.hpp"
    #include "Rom.hpp"
    #include "Tests.hpp"

    class Tests
    {
        public:
            Tests();
            ~Tests();

            void TEST_Run();
            void TEST_CPU();
            void TEST_Rom();

            bool TEST_INC_B();

        private:
            Logger *logger;
            CPU *cpu;
            Rom *rom;
    };
