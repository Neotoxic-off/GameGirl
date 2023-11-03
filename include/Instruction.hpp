class Instruction
{
    public:
        Instruction(char *, void *, unsigned char);
        ~Instruction();

    private:
        char *disassembly;
        void *execute;
        unsigned char length;
};