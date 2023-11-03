class Register
{
    public:
        Register();
        ~Register();

        unsigned char getRegisterA();
        unsigned char setRegisterA(unsigned char);

        unsigned char getRegisterB();
        unsigned char setRegisterB(unsigned char);

        unsigned char getRegisterC();
        unsigned char setRegisterC(unsigned char);

        unsigned char getRegisterD();
        unsigned char setRegisterD(unsigned char);

        unsigned char getRegisterE();
        unsigned char setRegisterE(unsigned char);

        unsigned char getRegisterF();
        unsigned char setRegisterF(unsigned char);

        unsigned char getRegisterH();
        unsigned char setRegisterH(unsigned char);

        unsigned char getRegisterL();
        unsigned char setRegisterL(unsigned char);

        unsigned char getRegisterP();
        unsigned char setRegisterP(unsigned char);

        unsigned char getRegisterS();
        unsigned char setRegisterS(unsigned char);

        // UNION
        unsigned short getRegisterAF();
        unsigned short setRegisterAF(unsigned char, unsigned char);

        unsigned short getRegisterBC();
        unsigned short setRegisterBC(unsigned char, unsigned char);

        unsigned short getRegisterDE();
        unsigned short setRegisterDE(unsigned char, unsigned char);

        unsigned short getRegisterHL();
        unsigned short setRegisterHL(unsigned char, unsigned char);

        unsigned short getRegisterSP();
        unsigned short setRegisterSP(unsigned char, unsigned char);

        unsigned short getRegisterPC();
        unsigned short setRegisterPC(unsigned char, unsigned char);

    private:
        unsigned char a;
        unsigned char b;
        unsigned char c;
        unsigned char d;
        unsigned char e;
        unsigned char f;
        unsigned char h;
        unsigned char l;
        unsigned char p;
        unsigned char s;
};
