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
            bool TEST_DEC_B();

            bool TEST_INC_C();
            bool TEST_DEC_C();

            bool TEST_INC_D();
            bool TEST_DEC_D();

            bool TEST_INC_E();
            bool TEST_DEC_E();

            bool TEST_INC_H();
            bool TEST_DEC_H();

            bool TEST_INC_L();
            bool TEST_DEC_L();

        private:
            Logger *logger;
            CPU *cpu;
            Rom *rom;
    };
