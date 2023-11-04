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
            uint8_t *f;
            uint8_t *h;
            uint8_t *l;
            uint8_t *p;
            uint8_t *s;
            
            uint16_t *af;
            uint16_t *bc;
            uint16_t *de;
            uint16_t *hl;
            uint16_t *sp;
            uint16_t *pc;

            Register();
            ~Register();
    };
