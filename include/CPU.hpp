#pragma once

    #include <map>
    #include <iostream>
    #include <unordered_map>

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

            CPU(Logger *, uint8_t *);
            ~CPU();

            uint8_t Execute(uint8_t);

        private:
            void *NIY();

            // Special
            void *NOP();
            void *STOP();
            void *HALT();

            void *RLCA();
            void *RLA();
            void *RRCA();
            void *RRA();
            void *DAA();
            void *CPL();
            void *SPHL();
            void *RETI();
            void *EI();
            void *DI();
            void *A16_SP();

            // LD
                // 8b
                void *LD_8_8(uint8_t &, uint8_t &);
                void *LD_A_A();
                void *LD_B_d8(uint8_t &);
                void *LD_C_d8(uint8_t &);
                void *LD_D_d8(uint8_t &);
                void *LD_H_d8(uint8_t &);
                void *LD_A_HL();
                void *LD_L_d8(uint8_t &);
                void *LD_A_d16(uint16_t &);
                void *LD_E_d8(uint8_t &);

                // 16b
                void *LD_16_16(uint8_t &, uint8_t &, uint16_t &);
                void *LD_d16_A(uint16_t &);
                void *LD_SP_d16(uint16_t &);
                void *LD_HL_A_d8();
                void *LD_HL_d16(uint16_t &);
                void *LD_HL_A();
                void *LD_BC_A();
                void *LD_DE_A();
                void *LD_DE_d16(uint16_t &);

            // INC
                // 8b
                void *INC(uint8_t &);
                void *INC_B();
                void *INC_C();
                void *INC_D();

                // 16b
                void *INC_DE();
                void *INC_HL();
                void *INC_SP();
                void *INC_L();
                void *INC_H();

            // DEC
                // 8b
                void *DEC(uint8_t &);
                void *DEC_D();
                void *DEC_C();
                void *DEC_L();
                void *DEC_H();

                // 16b
                void *DEC_HL();
                void *DEC_SP();
            
            // ADD
                // 8b
                void *ADD(uint8_t &, uint8_t &);
            
                // 16b
                void *ADD_HL_BC();
                void *ADD_HL_DE();
                void *ADD_HL_HL();
            
            // SUB
                // 8b
                void *SUB(uint8_t &, uint8_t &);

                // 16b
            

            // JR
                // 8b
                void *JR_r8(int8_t &);
                void *JR_Z_r8(int8_t &);
                void *JR_C_r8(int8_t &);
            
                // 16b
                void *JR_NC_r8(int8_t &);
                void *JR_NZ_r8(int8_t &);
            

            // PUSH
                // 8b
                void *PUSH_AF();
            
            // POP
                // 8b
                void *POP_AF();

            // JP
                // 8b
                void *JP(uint16_t &);
                void *JP_Z(uint16_t &);
                void *JP_C(uint16_t &);

                // 16b
                void *JP_NZ(uint16_t &);
                void *JP_NC(uint16_t &);

            // CALL
                // 8b
                void *CALL_Z(uint16_t &);
                void *CALL_C(uint16_t &);

                // 16b
                void *CALL(uint16_t &);
                void *CALL_NZ(uint16_t &);
                void *CALL_NC(uint16_t &);

            // RET
                // 8b
                void *RET();
                void *RET_Z();
                void *RET_C();

                // 16b
                void *RET_NZ();
                void *RET_NC();

            // RST
                // 8b
                void *RST(uint8_t &);
                void *RST_00();
                void *RST_08();
                void *RST_10();
                void *RST_18();
                void *RST_20();
                void *RST_28();
                void *RST_30();
                void *RST_38();

            Instruction instructions[256] = {
                Instruction("NOP",         std::bind(&CPU::NIY, this), 1),
                Instruction("LD BC,d16",   std::bind(&CPU::NIY, this), 3),
                Instruction("LD (BC),A",   std::bind(&CPU::NIY, this), 1),
                Instruction("INC BC",      std::bind(&CPU::NIY, this), 1),
                Instruction("INC B",       std::bind(&CPU::INC_B, this), 1),
                Instruction("DEC B",       std::bind(&CPU::NIY, this), 1),
                Instruction("LD B,d8",     std::bind(&CPU::NIY, this), 2),
                Instruction("RLCA",        std::bind(&CPU::RLCA, this), 1),
                Instruction("LD (a16),SP", std::bind(&CPU::NIY, this), 3),
                Instruction("ADD HL,BC",   std::bind(&CPU::NIY, this), 1),
                Instruction("LD A,(BC)",   std::bind(&CPU::NIY, this), 1),
                Instruction("DEC BC",      std::bind(&CPU::NIY, this), 1),
                Instruction("INC C",       std::bind(&CPU::INC_C, this), 1),
                Instruction("DEC C",       std::bind(&CPU::DEC_C, this), 1),
                Instruction("LD C,d8",     std::bind(&CPU::NIY, this), 2),
                Instruction("RRCA",        std::bind(&CPU::NIY, this), 1),

                Instruction("STOP 0",      std::bind(&CPU::NIY, this), 2),
                Instruction("LD DE,d16",   std::bind(&CPU::NIY, this), 3),
                Instruction("LD (DE),A",   std::bind(&CPU::NIY, this), 1),
                Instruction("INC DE",      std::bind(&CPU::NIY, this), 1),
                Instruction("INC D",       std::bind(&CPU::NIY, this), 1),
                Instruction("DEC D",       std::bind(&CPU::NIY, this), 1),
                Instruction("LD D,d8",     std::bind(&CPU::NIY, this), 2),
                Instruction("RLA",         std::bind(&CPU::NIY, this), 1),
                Instruction("JR r8",       std::bind(&CPU::NIY, this), 2),
                Instruction("ADD HL,DE",   std::bind(&CPU::NIY, this), 1),
                Instruction("LD A,(DE)",   std::bind(&CPU::NIY, this), 1),
                Instruction("DEC DE",      std::bind(&CPU::NIY, this), 1),
                Instruction("INC E",       std::bind(&CPU::NIY, this), 1),
                Instruction("DEC E",       std::bind(&CPU::NIY, this), 1),
                Instruction("LD E,d8",     std::bind(&CPU::NIY, this), 2),
                Instruction("RRA",         std::bind(&CPU::NIY, this), 1),

                Instruction("JR NZ,r8",    std::bind(&CPU::NIY, this), 2),
                Instruction("LD HL,d16",   std::bind(&CPU::NIY, this), 3),
                Instruction("LD (HL+),A",  std::bind(&CPU::NIY, this), 1),
                Instruction("INC HL",      std::bind(&CPU::NIY, this), 1),
                Instruction("INC H",       std::bind(&CPU::NIY, this), 1),
                Instruction("DEC H",       std::bind(&CPU::NIY, this), 1),
                Instruction("LD H,d8",     std::bind(&CPU::NIY, this), 2),
                Instruction("DAA",         std::bind(&CPU::NIY, this), 1),
                Instruction("JR Z,r8",     std::bind(&CPU::NIY, this), 2),
                Instruction("ADD HL,HL",   std::bind(&CPU::NIY, this), 1),
                Instruction("LD A,(HL+)",  std::bind(&CPU::NIY, this), 1),
                Instruction("DEC HL",      std::bind(&CPU::NIY, this), 1),
                Instruction("INC L",       std::bind(&CPU::NIY, this), 1),
                Instruction("DEC L",       std::bind(&CPU::NIY, this), 1),
                Instruction("LD L,d8",     std::bind(&CPU::NIY, this), 2),
                Instruction("CPL",         std::bind(&CPU::NIY, this), 1),

                Instruction("JR NC,r8",    std::bind(&CPU::NIY, this), 2),
                Instruction("LD SP,d16",   std::bind(&CPU::NIY, this), 3),
                Instruction("LD (HL-),A",  std::bind(&CPU::NIY, this), 1),
                Instruction("INC SP",      std::bind(&CPU::NIY, this), 1),
                Instruction("INC (HL)",    std::bind(&CPU::NIY, this), 1),
                Instruction("DEC (HL)",    std::bind(&CPU::NIY, this), 1),
                Instruction("LD (HL),d8",  std::bind(&CPU::NIY, this), 2),
                Instruction("SCF",         std::bind(&CPU::NIY, this), 1),
                Instruction("JR C,r8",     std::bind(&CPU::NIY, this), 2),
                Instruction("ADD HL,SP",   std::bind(&CPU::NIY, this), 1),
                Instruction("LD A,(HL-)",  std::bind(&CPU::NIY, this), 1),
                Instruction("DEC SP",      std::bind(&CPU::NIY, this), 1),
                Instruction("INC A",       std::bind(&CPU::NIY, this), 1),
                Instruction("DEC A",       std::bind(&CPU::NIY, this), 1),
                Instruction("LD A,d8",     std::bind(&CPU::NIY, this), 2),
                Instruction("CCF",         std::bind(&CPU::NIY, this), 1),

                Instruction("LD B,B",      std::bind(&CPU::NIY, this), 1),
                Instruction("LD B,C",      std::bind(&CPU::NIY, this), 1),
                Instruction("LD B,D",      std::bind(&CPU::NIY, this), 1),
                Instruction("LD B,E",      std::bind(&CPU::NIY, this), 1),
                Instruction("LD B,H",      std::bind(&CPU::NIY, this), 1),
                Instruction("LD B,L",      std::bind(&CPU::NIY, this), 1),
                Instruction("LD B,(HL)",   std::bind(&CPU::NIY, this), 1),
                Instruction("LD B,A",      std::bind(&CPU::NIY, this), 1),
                Instruction("LD C,B",      std::bind(&CPU::NIY, this), 1),
                Instruction("LD C,C",      std::bind(&CPU::NIY, this), 1),
                Instruction("LD C,D",      std::bind(&CPU::NIY, this), 1),
                Instruction("LD C,E",      std::bind(&CPU::NIY, this), 1),
                Instruction("LD C,H",      std::bind(&CPU::NIY, this), 1),
                Instruction("LD C,L",      std::bind(&CPU::NIY, this), 1),
                Instruction("LD C,(HL)",   std::bind(&CPU::NIY, this), 1),
                Instruction("LD C,A",      std::bind(&CPU::NIY, this), 1),

                Instruction("LD D,B",      std::bind(&CPU::NIY, this), 1),
                Instruction("LD D,C",      std::bind(&CPU::NIY, this), 1),
                Instruction("LD D,D",      std::bind(&CPU::NIY, this), 1),
                Instruction("LD D,E",      std::bind(&CPU::NIY, this), 1),
                Instruction("LD D,H",      std::bind(&CPU::NIY, this), 1),
                Instruction("LD D,L",      std::bind(&CPU::NIY, this), 1),
                Instruction("LD D,(HL)",   std::bind(&CPU::NIY, this), 1),
                Instruction("LD D,A",      std::bind(&CPU::NIY, this), 1),
                Instruction("LD E,B",      std::bind(&CPU::NIY, this), 1),
                Instruction("LD E,C",      std::bind(&CPU::NIY, this), 1),
                Instruction("LD E,D",      std::bind(&CPU::NIY, this), 1),
                Instruction("LD E,E",      std::bind(&CPU::NIY, this), 1),
                Instruction("LD E,H",      std::bind(&CPU::NIY, this), 1),
                Instruction("LD E,L",      std::bind(&CPU::NIY, this), 1),
                Instruction("LD E,(HL)",   std::bind(&CPU::NIY, this), 1),
                Instruction("LD E,A",      std::bind(&CPU::NIY, this), 1),

                Instruction("LD H,B",      std::bind(&CPU::NIY, this), 1),
                Instruction("LD H,C",      std::bind(&CPU::NIY, this), 1),
                Instruction("LD H,D",      std::bind(&CPU::NIY, this), 1),
                Instruction("LD H,E",      std::bind(&CPU::NIY, this), 1),
                Instruction("LD H,H",      std::bind(&CPU::NIY, this), 1),
                Instruction("LD H,L",      std::bind(&CPU::NIY, this), 1),
                Instruction("LD H,(HL)",   std::bind(&CPU::NIY, this), 1),
                Instruction("LD H,A",      std::bind(&CPU::NIY, this), 1),
                Instruction("LD L,B",      std::bind(&CPU::NIY, this), 1),
                Instruction("LD L,C",      std::bind(&CPU::NIY, this), 1),
                Instruction("LD L,D",      std::bind(&CPU::NIY, this), 1),
                Instruction("LD L,E",      std::bind(&CPU::NIY, this), 1),
                Instruction("LD L,H",      std::bind(&CPU::NIY, this), 1),
                Instruction("LD L,L",      std::bind(&CPU::NIY, this), 1),
                Instruction("LD L,(HL)",   std::bind(&CPU::NIY, this), 1),
                Instruction("LD L,A",      std::bind(&CPU::NIY, this), 1),

                Instruction("LD (HL),B",   std::bind(&CPU::NIY, this), 1),
                Instruction("LD (HL),C",   std::bind(&CPU::NIY, this), 1),
                Instruction("LD (HL),D",   std::bind(&CPU::NIY, this), 1),
                Instruction("LD (HL),E",   std::bind(&CPU::NIY, this), 1),
                Instruction("LD (HL),H",   std::bind(&CPU::NIY, this), 1),
                Instruction("LD (HL),L",   std::bind(&CPU::NIY, this), 1),
                Instruction("HALT",        std::bind(&CPU::NIY, this), 1),
                Instruction("LD (HL),A",   std::bind(&CPU::NIY, this), 1),
                Instruction("LD A,B",      std::bind(&CPU::NIY, this), 1),
                Instruction("LD A,C",      std::bind(&CPU::NIY, this), 1),
                Instruction("LD A,D",      std::bind(&CPU::NIY, this), 1),
                Instruction("LD A,E",      std::bind(&CPU::NIY, this), 1),
                Instruction("LD A,H",      std::bind(&CPU::NIY, this), 1),
                Instruction("LD A,L",      std::bind(&CPU::NIY, this), 1),
                Instruction("LD A,(HL)",   std::bind(&CPU::NIY, this), 1),
                Instruction("LD A,A",      std::bind(&CPU::LD_A_A, this), 1),
                
                Instruction("ADD A,B",     std::bind(&CPU::NIY, this), 1),
                Instruction("ADD A,C",     std::bind(&CPU::NIY, this), 1),
                Instruction("ADD A,D",     std::bind(&CPU::NIY, this), 1),
                Instruction("ADD A,E",     std::bind(&CPU::NIY, this), 1),
                Instruction("ADD A,H",     std::bind(&CPU::NIY, this), 1),
                Instruction("ADD A,L",     std::bind(&CPU::NIY, this), 1),
                Instruction("ADD A,(HL)",  std::bind(&CPU::NIY, this), 1),
                Instruction("ADD A,A",     std::bind(&CPU::NIY, this), 1),
                Instruction("ADC A,B",     std::bind(&CPU::NIY, this), 1),
                Instruction("ADC A,C",     std::bind(&CPU::NIY, this), 1),
                Instruction("ADC A,D",     std::bind(&CPU::NIY, this), 1),
                Instruction("ADC A,E",     std::bind(&CPU::NIY, this), 1),
                Instruction("ADC A,H",     std::bind(&CPU::NIY, this), 1),
                Instruction("ADC A,L",     std::bind(&CPU::NIY, this), 1),
                Instruction("ADC A,(HL)",  std::bind(&CPU::NIY, this), 1),
                Instruction("ADC A,A",     std::bind(&CPU::NIY, this), 1),

                Instruction("SUB B",       std::bind(&CPU::NIY, this), 1),
                Instruction("SUB C",       std::bind(&CPU::NIY, this), 1),
                Instruction("SUB D",       std::bind(&CPU::NIY, this), 1),
                Instruction("SUB E",       std::bind(&CPU::NIY, this), 1),
                Instruction("SUB H",       std::bind(&CPU::NIY, this), 1),
                Instruction("SUB L",       std::bind(&CPU::NIY, this), 1),
                Instruction("SUB (HL)",    std::bind(&CPU::NIY, this), 1),
                Instruction("SUB A",       std::bind(&CPU::NIY, this), 1),
                Instruction("SBC A,B",     std::bind(&CPU::NIY, this), 1),
                Instruction("SBC A,C",     std::bind(&CPU::NIY, this), 1),
                Instruction("SBC A,D",     std::bind(&CPU::NIY, this), 1),
                Instruction("SBC A,E",     std::bind(&CPU::NIY, this), 1),
                Instruction("SBC A,H",     std::bind(&CPU::NIY, this), 1),
                Instruction("SBC A,L",     std::bind(&CPU::NIY, this), 1),
                Instruction("SBC A,(HL)",  std::bind(&CPU::NIY, this), 1),
                Instruction("SBC A,A",     std::bind(&CPU::NIY, this), 1),

                Instruction("AND B",       std::bind(&CPU::NIY, this), 1),
                Instruction("AND C",       std::bind(&CPU::NIY, this), 1),
                Instruction("AND D",       std::bind(&CPU::NIY, this), 1),
                Instruction("AND E",       std::bind(&CPU::NIY, this), 1),
                Instruction("AND H",       std::bind(&CPU::NIY, this), 1),
                Instruction("AND L",       std::bind(&CPU::NIY, this), 1),
                Instruction("AND (HL)",    std::bind(&CPU::NIY, this), 1),
                Instruction("AND A",       std::bind(&CPU::NIY, this), 1),
                Instruction("XOR B",       std::bind(&CPU::NIY, this), 1),
                Instruction("XOR C",       std::bind(&CPU::NIY, this), 1),
                Instruction("XOR D",       std::bind(&CPU::NIY, this), 1),
                Instruction("XOR E",       std::bind(&CPU::NIY, this), 1),
                Instruction("XOR H",       std::bind(&CPU::NIY, this), 1),
                Instruction("XOR L",       std::bind(&CPU::NIY, this), 1),
                Instruction("XOR (HL)",    std::bind(&CPU::NIY, this), 1),
                Instruction("XOR A",       std::bind(&CPU::NIY, this), 1),

                Instruction("OR B",        std::bind(&CPU::NIY, this), 1),
                Instruction("OR C",        std::bind(&CPU::NIY, this), 1),
                Instruction("OR D",        std::bind(&CPU::NIY, this), 1),
                Instruction("OR E",        std::bind(&CPU::NIY, this), 1),
                Instruction("OR H",        std::bind(&CPU::NIY, this), 1),
                Instruction("OR L",        std::bind(&CPU::NIY, this), 1),
                Instruction("OR (HL)",     std::bind(&CPU::NIY, this), 1),
                Instruction("OR A",        std::bind(&CPU::NIY, this), 1),
                Instruction("CP B",        std::bind(&CPU::NIY, this), 1),
                Instruction("CP C",        std::bind(&CPU::NIY, this), 1),
                Instruction("CP D",        std::bind(&CPU::NIY, this), 1),
                Instruction("CP E",        std::bind(&CPU::NIY, this), 1),
                Instruction("CP H",        std::bind(&CPU::NIY, this), 1),
                Instruction("CP L",        std::bind(&CPU::NIY, this), 1),
                Instruction("CP (HL)",     std::bind(&CPU::NIY, this), 1),
                Instruction("CP A",        std::bind(&CPU::NIY, this), 1),

                Instruction("RET NZ",      std::bind(&CPU::NIY, this), 1),
                Instruction("POP BC",      std::bind(&CPU::NIY, this), 1),
                Instruction("JP NZ,a16",   std::bind(&CPU::NIY, this), 3),
                Instruction("JP a16",      std::bind(&CPU::NIY, this), 3),
                Instruction("CALL NZ,a16", std::bind(&CPU::NIY, this), 3),
                Instruction("PUSH BC",     std::bind(&CPU::NIY, this), 1),
                Instruction("ADD A,d8",    std::bind(&CPU::NIY, this), 2),
                Instruction("RST 00H",     std::bind(&CPU::NIY, this), 1),
                Instruction("RET Z",       std::bind(&CPU::NIY, this), 1),
                Instruction("RET",         std::bind(&CPU::NIY, this), 1),
                Instruction("JP Z,a16",    std::bind(&CPU::NIY, this), 3),
                Instruction("PREFIX CB",   std::bind(&CPU::NIY, this), 1),
                Instruction("CALL Z,a16",  std::bind(&CPU::NIY, this), 3),
                Instruction("CALL a16",    std::bind(&CPU::NIY, this), 3),
                Instruction("ADC A,d8",    std::bind(&CPU::NIY, this), 2),
                Instruction("RST 08H",     std::bind(&CPU::NIY, this), 1),

                Instruction("RET NC",      std::bind(&CPU::NIY, this), 1),
                Instruction("POP DE",      std::bind(&CPU::NIY, this), 1),
                Instruction("JP NC,a16",   std::bind(&CPU::NIY, this), 3),
                Instruction("",            std::bind(&CPU::NIY, this), 0),
                Instruction("CALL NC,a16", std::bind(&CPU::NIY, this), 3),
                Instruction("PUSH DE",     std::bind(&CPU::NIY, this), 1),
                Instruction("SUB d8",      std::bind(&CPU::NIY, this), 2),
                Instruction("RST 10H",     std::bind(&CPU::NIY, this), 1),
                Instruction("RET C",       std::bind(&CPU::NIY, this), 1),
                Instruction("RETI",        std::bind(&CPU::NIY, this), 1),
                Instruction("JP C,a16",    std::bind(&CPU::NIY, this), 3),
                Instruction("",            std::bind(&CPU::NIY, this), 0),
                Instruction("CALL C,a16",  std::bind(&CPU::NIY, this), 3),
                Instruction("",            std::bind(&CPU::NIY, this), 0),
                Instruction("SBC A,d8",    std::bind(&CPU::NIY, this), 2),
                Instruction("RST 18H",     std::bind(&CPU::NIY, this), 1),

                Instruction("LDH (a8),A",  std::bind(&CPU::NIY, this), 2),
                Instruction("POP HL",      std::bind(&CPU::NIY, this), 1),
                Instruction("LD (C),A",    std::bind(&CPU::NIY, this), 2),
                Instruction("",            std::bind(&CPU::NIY, this), 0),
                Instruction("",            std::bind(&CPU::NIY, this), 0),
                Instruction("PUSH HL",     std::bind(&CPU::NIY, this), 1),
                Instruction("AND d8",      std::bind(&CPU::NIY, this), 2),
                Instruction("RST 20H",     std::bind(&CPU::NIY, this), 1),
                Instruction("ADD SP,r8",   std::bind(&CPU::NIY, this), 2),
                Instruction("JP (HL)",     std::bind(&CPU::NIY, this), 1),
                Instruction("LD (a16),A",  std::bind(&CPU::NIY, this), 3),
                Instruction("",            std::bind(&CPU::NIY, this), 0),
                Instruction("",            std::bind(&CPU::NIY, this), 0),
                Instruction("",            std::bind(&CPU::NIY, this), 0),
                Instruction("XOR d8",      std::bind(&CPU::NIY, this), 2),
                Instruction("RST 28H",     std::bind(&CPU::NIY, this), 1),

                Instruction("LDH A,(a8)",  std::bind(&CPU::NIY, this), 2),
                Instruction("POP AF",      std::bind(&CPU::NIY, this), 1),
                Instruction("LD A,(C)",    std::bind(&CPU::NIY, this), 2),
                Instruction("DI",          std::bind(&CPU::NIY, this), 1),
                Instruction("",            std::bind(&CPU::NIY, this), 0),
                Instruction("PUSH AF",     std::bind(&CPU::NIY, this), 1),
                Instruction("OR d8",       std::bind(&CPU::NIY, this), 2),
                Instruction("RST 30H",     std::bind(&CPU::NIY, this), 1),
                Instruction("LD HL,SP+r8", std::bind(&CPU::NIY, this), 2),
                Instruction("LD SP,HL",    std::bind(&CPU::NIY, this), 1),
                Instruction("LD A,(a16)",  std::bind(&CPU::NIY, this), 3),
                Instruction("EI",          std::bind(&CPU::NIY, this), 1),
                Instruction("",            std::bind(&CPU::NIY, this), 0),
                Instruction("",            std::bind(&CPU::NIY, this), 0),
                Instruction("CP d8",       std::bind(&CPU::NIY, this), 2),
                Instruction("RST 38H",     std::bind(&CPU::NIY, this), 1)
            };
    };
