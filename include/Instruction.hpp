#pragma once

    #include <cinttypes>

    class Instruction
    {
        public:
            Instruction(const char *, void *, uint8_t);
            ~Instruction();

        private:
            const char *disassembly;
            void *execute;
            uint8_t length;
    };
