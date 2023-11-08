#pragma once

    #include <cinttypes>

    class Register
    {
        public:
            uint8_t a;
            uint8_t b;
            uint8_t c;
            uint8_t d;
            uint8_t e;
            uint8_t f;
            uint8_t h;
            uint8_t l;

            uint16_t sp;
            uint16_t pc;

            Register();
            ~Register();

            uint16_t GetRegister16(uint8_t &, uint8_t &);
            uint16_t SetRegister16(uint8_t &, uint8_t &, uint16_t);

        private:
            uint8_t GetHighByte(uint16_t);
            uint8_t GetLowByte(uint16_t);
    };
