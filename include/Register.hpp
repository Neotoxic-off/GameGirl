class Register
{
    public:
        Register();
        ~Register();

        unsigned char get_a();
        unsigned char set_a(unsigned char);

        unsigned char get_b();
        unsigned char set_b(unsigned char);

        unsigned char get_c();
        unsigned char set_c(unsigned char);

        unsigned char get_d();
        unsigned char set_d(unsigned char);

        unsigned char get_e();
        unsigned char set_e(unsigned char);

        unsigned char get_f();
        unsigned char set_f(unsigned char);

        unsigned char get_h();
        unsigned char set_h(unsigned char);

        unsigned char get_l();
        unsigned char set_l(unsigned char);

        unsigned char get_p();
        unsigned char set_p(unsigned char);

        unsigned char get_s();
        unsigned char set_s(unsigned char);

        // UNION
        unsigned short get_af();
        unsigned short set_af(unsigned char, unsigned char);

        unsigned short get_bc();
        unsigned short set_bc(unsigned char, unsigned char);

        unsigned short get_de();
        unsigned short set_de(unsigned char, unsigned char);

        unsigned short get_hl();
        unsigned short set_hl(unsigned char, unsigned char);

        unsigned short get_sp();
        unsigned short set_sp(unsigned char, unsigned char);

        unsigned short get_pc();
        unsigned short set_pc(unsigned char, unsigned char);

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
