#pragma once

    #include <map>
    #include <iostream>

    #include "Register.hpp"
    #include "Logger.hpp"
    #include "Instruction.hpp"
    #include "Flags.hpp"

    class CPU
    {
        public:
            Logger *logger;
            Register *registers;
            Flags *flags;

            uint8_t *memory;

            std::map<char, std::string> Opcodes = {
                { 0x78, "MOV A, B" },
                { 0x81, "ADD A, C" },
                { 0x92, "SUB D" },
                { 0xC9, "RET" }
            };

            CPU(Logger *, uint8_t *);
            ~CPU();

            void *NOP();
            void *INC(uint8_t *);
            void *DEC(uint8_t *);

            void *ADD(uint8_t *, uint8_t *);
            void *SUB(uint8_t *, uint8_t *);

            void *ADC(uint8_t *, uint8_t *);
            void *SBC(uint8_t *, uint8_t *);

            void *AND(uint8_t *);
            void *XOR(uint8_t *);
            void *OR(uint8_t *);

            void *CP(uint8_t *);
            void *RET(uint8_t *);
            void *POP(uint8_t *);
            void *JP(uint8_t *);
            void *CALL(uint8_t *);
            void *PUSH(uint8_t *);
            void *RST(uint8_t *);
            void *RETI(uint8_t *);
            void *LD(uint8_t *);
            void *EI(uint8_t *);

        private:

            Instruction instructions[256] = {
                Instruction("NOP",         nullptr, 1),
                Instruction("LD BC,d16",   nullptr, 3),
                Instruction("LD (BC),A",   nullptr, 1),
                Instruction("INC BC",      nullptr, 1),
                Instruction("INC B",       nullptr, 1),
                Instruction("DEC B",       nullptr, 1),
                Instruction("LD B,d8",     nullptr, 2),
                Instruction("RLCA",        nullptr, 1),
                Instruction("LD (a16),SP", nullptr, 3),
                Instruction("ADD HL,BC",   nullptr, 1),
                Instruction("LD A,(BC)",   nullptr, 1),
                Instruction("DEC BC",      nullptr, 1),
                Instruction("INC C",       nullptr, 1),
                Instruction("DEC C",       nullptr, 1),
                Instruction("LD C,d8",     nullptr, 2),
                Instruction("RRCA",        nullptr, 1),

                Instruction("STOP 0",      nullptr, 2),
                Instruction("LD DE,d16",   nullptr, 3),
                Instruction("LD (DE),A",   nullptr, 1),
                Instruction("INC DE",      nullptr, 1),
                Instruction("INC D",       nullptr, 1),
                Instruction("DEC D",       nullptr, 1),
                Instruction("LD D,d8",     nullptr, 2),
                Instruction("RLA",         nullptr, 1),
                Instruction("JR r8",       nullptr, 2),
                Instruction("ADD HL,DE",   nullptr, 1),
                Instruction("LD A,(DE)",   nullptr, 1),
                Instruction("DEC DE",      nullptr, 1),
                Instruction("INC E",       nullptr, 1),
                Instruction("DEC E",       nullptr, 1),
                Instruction("LD E,d8",     nullptr, 2),
                Instruction("RRA",         nullptr, 1),

                Instruction("JR NZ,r8",    nullptr, 2),
                Instruction("LD HL,d16",   nullptr, 3),
                Instruction("LD (HL+),A",  nullptr, 1),
                Instruction("INC HL",      nullptr, 1),
                Instruction("INC H",       nullptr, 1),
                Instruction("DEC H",       nullptr, 1),
                Instruction("LD H,d8",     nullptr, 2),
                Instruction("DAA",         nullptr, 1),
                Instruction("JR Z,r8",     nullptr, 2),
                Instruction("ADD HL,HL",   nullptr, 1),
                Instruction("LD A,(HL+)",  nullptr, 1),
                Instruction("DEC HL",      nullptr, 1),
                Instruction("INC L",       nullptr, 1),
                Instruction("DEC L",       nullptr, 1),
                Instruction("LD L,d8",     nullptr, 2),
                Instruction("CPL",         nullptr, 1),

                Instruction("JR NC,r8",    nullptr, 2),
                Instruction("LD SP,d16",   nullptr, 3),
                Instruction("LD (HL-),A",  nullptr, 1),
                Instruction("INC SP",      nullptr, 1),
                Instruction("INC (HL)",    nullptr, 1),
                Instruction("DEC (HL)",    nullptr, 1),
                Instruction("LD (HL),d8",  nullptr, 2),
                Instruction("SCF",         nullptr, 1),
                Instruction("JR C,r8",     nullptr, 2),
                Instruction("ADD HL,SP",   nullptr, 1),
                Instruction("LD A,(HL-)",  nullptr, 1),
                Instruction("DEC SP",      nullptr, 1),
                Instruction("INC A",       nullptr, 1),
                Instruction("DEC A",       nullptr, 1),
                Instruction("LD A,d8",     nullptr, 2),
                Instruction("CCF",         nullptr, 1),

                Instruction("LD B,B",      nullptr, 1),
                Instruction("LD B,C",      nullptr, 1),
                Instruction("LD B,D",      nullptr, 1),
                Instruction("LD B,E",      nullptr, 1),
                Instruction("LD B,H",      nullptr, 1),
                Instruction("LD B,L",      nullptr, 1),
                Instruction("LD B,(HL)",   nullptr, 1),
                Instruction("LD B,A",      nullptr, 1),
                Instruction("LD C,B",      nullptr, 1),
                Instruction("LD C,C",      nullptr, 1),
                Instruction("LD C,D",      nullptr, 1),
                Instruction("LD C,E",      nullptr, 1),
                Instruction("LD C,H",      nullptr, 1),
                Instruction("LD C,L",      nullptr, 1),
                Instruction("LD C,(HL)",   nullptr, 1),
                Instruction("LD C,A",      nullptr, 1),

                Instruction("LD D,B",      nullptr, 1),
                Instruction("LD D,C",      nullptr, 1),
                Instruction("LD D,D",      nullptr, 1),
                Instruction("LD D,E",      nullptr, 1),
                Instruction("LD D,H",      nullptr, 1),
                Instruction("LD D,L",      nullptr, 1),
                Instruction("LD D,(HL)",   nullptr, 1),
                Instruction("LD D,A",      nullptr, 1),
                Instruction("LD E,B",      nullptr, 1),
                Instruction("LD E,C",      nullptr, 1),
                Instruction("LD E,D",      nullptr, 1),
                Instruction("LD E,E",      nullptr, 1),
                Instruction("LD E,H",      nullptr, 1),
                Instruction("LD E,L",      nullptr, 1),
                Instruction("LD E,(HL)",   nullptr, 1),
                Instruction("LD E,A",      nullptr, 1),

                Instruction("LD H,B",      nullptr, 1),
                Instruction("LD H,C",      nullptr, 1),
                Instruction("LD H,D",      nullptr, 1),
                Instruction("LD H,E",      nullptr, 1),
                Instruction("LD H,H",      nullptr, 1),
                Instruction("LD H,L",      nullptr, 1),
                Instruction("LD H,(HL)",   nullptr, 1),
                Instruction("LD H,A",      nullptr, 1),
                Instruction("LD L,B",      nullptr, 1),
                Instruction("LD L,C",      nullptr, 1),
                Instruction("LD L,D",      nullptr, 1),
                Instruction("LD L,E",      nullptr, 1),
                Instruction("LD L,H",      nullptr, 1),
                Instruction("LD L,L",      nullptr, 1),
                Instruction("LD L,(HL)",   nullptr, 1),
                Instruction("LD L,A",      nullptr, 1),

                Instruction("LD (HL),B",   nullptr, 1),
                Instruction("LD (HL),C",   nullptr, 1),
                Instruction("LD (HL),D",   nullptr, 1),
                Instruction("LD (HL),E",   nullptr, 1),
                Instruction("LD (HL),H",   nullptr, 1),
                Instruction("LD (HL),L",   nullptr, 1),
                Instruction("HALT",        nullptr, 1),
                Instruction("LD (HL),A",   nullptr, 1),
                Instruction("LD A,B",      nullptr, 1),
                Instruction("LD A,C",      nullptr, 1),
                Instruction("LD A,D",      nullptr, 1),
                Instruction("LD A,E",      nullptr, 1),
                Instruction("LD A,H",      nullptr, 1),
                Instruction("LD A,L",      nullptr, 1),
                Instruction("LD A,(HL)",   nullptr, 1),
                Instruction("LD A,A",      nullptr, 1),
                
                Instruction("ADD A,B",     nullptr, 1),
                Instruction("ADD A,C",     nullptr, 1),
                Instruction("ADD A,D",     nullptr, 1),
                Instruction("ADD A,E",     nullptr, 1),
                Instruction("ADD A,H",     nullptr, 1),
                Instruction("ADD A,L",     nullptr, 1),
                Instruction("ADD A,(HL)",  nullptr, 1),
                Instruction("ADD A,A",     nullptr, 1),
                Instruction("ADC A,B",     nullptr, 1),
                Instruction("ADC A,C",     nullptr, 1),
                Instruction("ADC A,D",     nullptr, 1),
                Instruction("ADC A,E",     nullptr, 1),
                Instruction("ADC A,H",     nullptr, 1),
                Instruction("ADC A,L",     nullptr, 1),
                Instruction("ADC A,(HL)",  nullptr, 1),
                Instruction("ADC A,A",     nullptr, 1),

                Instruction("SUB B",       nullptr, 1),
                Instruction("SUB C",       nullptr, 1),
                Instruction("SUB D",       nullptr, 1),
                Instruction("SUB E",       nullptr, 1),
                Instruction("SUB H",       nullptr, 1),
                Instruction("SUB L",       nullptr, 1),
                Instruction("SUB (HL)",    nullptr, 1),
                Instruction("SUB A",       nullptr, 1),
                Instruction("SBC A,B",     nullptr, 1),
                Instruction("SBC A,C",     nullptr, 1),
                Instruction("SBC A,D",     nullptr, 1),
                Instruction("SBC A,E",     nullptr, 1),
                Instruction("SBC A,H",     nullptr, 1),
                Instruction("SBC A,L",     nullptr, 1),
                Instruction("SBC A,(HL)",  nullptr, 1),
                Instruction("SBC A,A",     nullptr, 1),

                Instruction("AND B",       nullptr, 1),
                Instruction("AND C",       nullptr, 1),
                Instruction("AND D",       nullptr, 1),
                Instruction("AND E",       nullptr, 1),
                Instruction("AND H",       nullptr, 1),
                Instruction("AND L",       nullptr, 1),
                Instruction("AND (HL)",    nullptr, 1),
                Instruction("AND A",       nullptr, 1),
                Instruction("XOR B",       nullptr, 1),
                Instruction("XOR C",       nullptr, 1),
                Instruction("XOR D",       nullptr, 1),
                Instruction("XOR E",       nullptr, 1),
                Instruction("XOR H",       nullptr, 1),
                Instruction("XOR L",       nullptr, 1),
                Instruction("XOR (HL)",    nullptr, 1),
                Instruction("XOR A",       nullptr, 1),

                Instruction("OR B",        nullptr, 1),
                Instruction("OR C",        nullptr, 1),
                Instruction("OR D",        nullptr, 1),
                Instruction("OR E",        nullptr, 1),
                Instruction("OR H",        nullptr, 1),
                Instruction("OR L",        nullptr, 1),
                Instruction("OR (HL)",     nullptr, 1),
                Instruction("OR A",        nullptr, 1),
                Instruction("CP B",        nullptr, 1),
                Instruction("CP C",        nullptr, 1),
                Instruction("CP D",        nullptr, 1),
                Instruction("CP E",        nullptr, 1),
                Instruction("CP H",        nullptr, 1),
                Instruction("CP L",        nullptr, 1),
                Instruction("CP (HL)",     nullptr, 1),
                Instruction("CP A",        nullptr, 1),

                Instruction("RET NZ",      nullptr, 1),
                Instruction("POP BC",      nullptr, 1),
                Instruction("JP NZ,a16",   nullptr, 3),
                Instruction("JP a16",      nullptr, 3),
                Instruction("CALL NZ,a16", nullptr, 3),
                Instruction("PUSH BC",     nullptr, 1),
                Instruction("ADD A,d8",    nullptr, 2),
                Instruction("RST 00H",     nullptr, 1),
                Instruction("RET Z",       nullptr, 1),
                Instruction("RET",         nullptr, 1),
                Instruction("JP Z,a16",    nullptr, 3),
                Instruction("PREFIX CB",   nullptr, 1),
                Instruction("CALL Z,a16",  nullptr, 3),
                Instruction("CALL a16",    nullptr, 3),
                Instruction("ADC A,d8",    nullptr, 2),
                Instruction("RST 08H",     nullptr, 1),

                Instruction("RET NC",      nullptr, 1),
                Instruction("POP DE",      nullptr, 1),
                Instruction("JP NC,a16",   nullptr, 3),
                Instruction("",            nullptr, 0),
                Instruction("CALL NC,a16", nullptr, 3),
                Instruction("PUSH DE",     nullptr, 1),
                Instruction("SUB d8",      nullptr, 2),
                Instruction("RST 10H",     nullptr, 1),
                Instruction("RET C",       nullptr, 1),
                Instruction("RETI",        nullptr, 1),
                Instruction("JP C,a16",    nullptr, 3),
                Instruction("",            nullptr, 0),
                Instruction("CALL C,a16",  nullptr, 3),
                Instruction("",            nullptr, 0),
                Instruction("SBC A,d8",    nullptr, 2),
                Instruction("RST 18H",     nullptr, 1),

                Instruction("LDH (a8),A",  nullptr, 2),
                Instruction("POP HL",      nullptr, 1),
                Instruction("LD (C),A",    nullptr, 2),
                Instruction("",            nullptr, 0),
                Instruction("",            nullptr, 0),
                Instruction("PUSH HL",     nullptr, 1),
                Instruction("AND d8",      nullptr, 2),
                Instruction("RST 20H",     nullptr, 1),
                Instruction("ADD SP,r8",   nullptr, 2),
                Instruction("JP (HL)",     nullptr, 1),
                Instruction("LD (a16),A",  nullptr, 3),
                Instruction("",            nullptr, 0),
                Instruction("",            nullptr, 0),
                Instruction("",            nullptr, 0),
                Instruction("XOR d8",      nullptr, 2),
                Instruction("RST 28H",     nullptr, 1),

                Instruction("LDH A,(a8)",  nullptr, 2),
                Instruction("POP AF",      nullptr, 1),
                Instruction("LD A,(C)",    nullptr, 2),
                Instruction("DI",          nullptr, 1),
                Instruction("",            nullptr, 0),
                Instruction("PUSH AF",     nullptr, 1),
                Instruction("OR d8",       nullptr, 2),
                Instruction("RST 30H",     nullptr, 1),
                Instruction("LD HL,SP+r8", nullptr, 2),
                Instruction("LD SP,HL",    nullptr, 1),
                Instruction("LD A,(a16)",  nullptr, 3),
                Instruction("EI",          nullptr, 1),
                Instruction("",            nullptr, 0),
                Instruction("",            nullptr, 0),
                Instruction("CP d8",       nullptr, 2),
                Instruction("RST 38H",     nullptr, 1)
            };
    };
