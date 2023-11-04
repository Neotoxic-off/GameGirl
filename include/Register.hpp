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

            uint8_t *getRegisterA();
            uint8_t *setRegisterA(uint8_t);

            uint8_t *getRegisterB();
            uint8_t *setRegisterB(uint8_t);

            uint8_t *getRegisterC();
            uint8_t *setRegisterC(uint8_t);

            uint8_t *getRegisterD();
            uint8_t *setRegisterD(uint8_t);

            uint8_t *getRegisterE();
            uint8_t *setRegisterE(uint8_t);

            uint8_t *getRegisterF();
            uint8_t *setRegisterF(uint8_t);

            uint8_t *getRegisterH();
            uint8_t *setRegisterH(uint8_t);

            uint8_t *getRegisterL();
            uint8_t *setRegisterL(uint8_t);

            uint8_t *getRegisterP();
            uint8_t *setRegisterP(uint8_t);

            uint8_t *getRegisterS();
            uint8_t *setRegisterS(uint8_t);

            // UNION
            uint16_t *getRegisterAF();
            uint16_t *setRegisterAF(uint8_t, uint8_t);

            uint16_t *getRegisterBC();
            uint16_t *setRegisterBC(uint8_t, uint8_t);

            uint16_t *getRegisterDE();
            uint16_t *setRegisterDE(uint8_t, uint8_t);

            uint16_t *getRegisterHL();
            uint16_t *setRegisterHL(uint8_t, uint8_t);

            uint16_t *getRegisterSP();
            uint16_t *setRegisterSP(uint8_t, uint8_t);

            uint16_t *getRegisterPC();
            uint16_t *setRegisterPC(uint8_t, uint8_t);

    };
