#pragma once

    #include <cinttypes>

    class Instruction
    {
        public:
            Instruction(char *, void *, uint8_t);
            ~Instruction();

        private:
            char *disassembly;
            void *execute;
            uint8_t length;
    };