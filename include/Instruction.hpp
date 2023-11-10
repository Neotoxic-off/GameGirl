#pragma once

    #include <cinttypes>
    #include <functional>

    class Instruction
    {
        public:
            const char *disassembly;
            std::function<void(void)> execute;
            uint8_t length;

            Instruction(const char *, std::function<void(void)>, uint8_t);
            ~Instruction();
    };
