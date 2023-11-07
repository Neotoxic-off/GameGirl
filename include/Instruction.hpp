#pragma once

    #include <cinttypes>

    class Instruction
    {
        public:
            const char *disassembly;
            void *execute;
            uint8_t length;

            Instruction(const char *, void *, uint8_t);
            ~Instruction();
    };
