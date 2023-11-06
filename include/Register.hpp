#pragma once

    #include <cinttypes>

    class Register
    {
        public:
            uint8_t *a;
            uint8_t *b;
            uint8_t *c;
            uint8_t *d;
            uint8_t *e;
            uint8_t *h;
            uint8_t *l;

            uint16_t *sp;
            uint16_t *pc;

            Register();
            ~Register();
    };
