#pragma once

    #include <cinttypes>
    #include <functional>

    class Instruction
    {
        public:
            char *disassembly;
            std::function<void(void)> execute;
            uint8_t length;

            Instruction(char *, std::function<void(void)>, uint8_t);
            ~Instruction();
    };
