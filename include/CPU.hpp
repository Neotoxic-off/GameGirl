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

            void *NIY();
            void *NOP();
            void *INC_B();
            void *DEC_B();
            void *INC_C();
            void *DEC_C();
            void *INC_D();
            void *DEC_D();
            void *INC_E();
            void *DEC_E();
            void *INC_H();
            void *DEC_H();
            void *INC_L();
            void *DEC_L();
            void *INC_BC();
            void *DEC_BC();
            void *INC_DE();
            void *DEC_DE();
            void *INC_HL();
            void *DEC_HL();
            void *INC_SP();
            void *DEC_SP();
            void *LD_A_A();
            void *LD_DE_A();
            void *RLA();
            void *RRCA();
            void *RLCA();
            void *RRA();
            void *DAA();
            void *CPL();
            void *AND_B();
            void *AND_C();
            void *AND_D();
            void *AND_E();
            void *AND_H();
            void *AND_L();
            void *AND_HL();
            void *AND_A();
            void *OR_B();
            void *OR_C();
            void *OR_D();
            void *OR_E();
            void *OR_H();
            void *OR_L();
            void *OR_HL();
            void *OR_A();
            void *CP_B();
            void *CP_C();
            void *CP_D();
            void *CP_E();
            void *CP_H();
            void *CP_L();
            void *CP_HL();
            void *CP_A();

            void *LD_BC_d16();
            void *LD_BC_A();

            uint16_t fetch16();

            void *LD_B_d8();
            void *LD_a16_SP();
            void *ADD_HL_BC();
            void *LD_A_BC();
            void *LD_C_d8();

            uint8_t fetch8();

            void write16(uint16_t, uint16_t);
            void write8(uint16_t, uint8_t);

            void *STOP();
            void *LD_DE_d16();
            void *LD_D_d8();
            void *LD_A_DE();
            void *LD_E_d8();
            void *JR_r8();
            void *ADD_HL_DE();
            void add16(uint16_t, uint16_t);

            void *JR_NZ_r8();
            void *LD_HL_d16();
            void *LD_HL_A_increment();

            void *LD_H_d8();
            void *JR_Z_r8();
            void *ADD_HL_HL();
            void *LD_A_HL_increment();
            void *LD_L_d8();

            void *JR_NC_r8();
            void *LD_SP_d16();
            void *LD_HL_decrement_A();
            void *LD_HL_d8();
            void *SCF();
            void *JR_C_r8();
            void *ADD_HL_SP();
            void *LD_A_decrement_HL();
            void *INC_A();
            void *DEC_A();
            void *LD_A_d8();
            void *CCF();

            void *LD_B_B();
            void *LD_B_C();
            void *LD_B_D();
            void *LD_B_E();
            void *LD_B_H();
            void *LD_B_L();
            void *LD_B_HL();
            void *LD_B_A();
            void *LD_C_B();
            void *LD_C_C();
            void *LD_C_D();
            void *LD_C_E();
            void *LD_C_H();
            void *LD_C_L();
            void *LD_C_HL();
            void *LD_C_A();

            void *LD_D_B();
            void *LD_D_C();
            void *LD_D_D();
            void *LD_D_E();
            void *LD_D_H();
            void *LD_D_L();
            void *LD_D_HL();
            void *LD_D_A();
            void *LD_E_B();
            void *LD_E_C();
            void *LD_E_D();
            void *LD_E_E();
            void *LD_E_H();
            void *LD_E_L();
            void *LD_E_HL();
            void *LD_E_A();

            void *LD_H_B();
            void *LD_H_C();
            void *LD_H_D();
            void *LD_H_E();
            void *LD_H_H();
            void *LD_H_L();
            void *LD_H_HL();
            void *LD_H_A();
            void *LD_L_B();
            void *LD_L_C();
            void *LD_L_D();
            void *LD_L_E();
            void *LD_L_H();
            void *LD_L_L();
            void *LD_L_HL();
            void *LD_L_A();

            void *LD_HL_B();
            void *LD_HL_C();
            void *LD_HL_D();
            void *LD_HL_E();
            void *LD_HL_H();
            void *LD_HL_L();
            void *HALT();
            void *LD_HL_A();
            void *LD_A_B();
            void *LD_A_C();
            void *LD_A_D();
            void *LD_A_E();
            void *LD_A_H();
            void *LD_A_L();
            void *LD_A_HL();

            void *ADD_A_B();
            void *ADD_A_C();
            void *ADD_A_D();
            void *ADD_A_E();
            void *ADD_A_H();
            void *ADD_A_L();
            void *ADD_A_HL();
            void *ADD_A_A();
            void *ADC_A_B();
            void *ADC_A_C();
            void *ADC_A_D();
            void *ADC_A_E();
            void *ADC_A_H();
            void *ADC_A_L();
            void *ADC_A_HL();
            void *ADC_A_A();

            void *SUB_B();
            void *SUB_C();
            void *SUB_D();
            void *SUB_E();
            void *SUB_H();
            void *SUB_L();
            void *SUB_HL();
            void *SUB_A();

            void *AND(uint8_t);
            void *XOR(uint8_t);
            void *OR(uint8_t);

            void *XOR_A();
            void *XOR_B();
            void *XOR_C();
            void *XOR_D();
            void *XOR_E();
            void *XOR_H();
            void *XOR_L();
            void *XOR_HL();

            void *RET_NZ();
            void *POP_BC();
            void *JP_NZ_a16();
            void *JP_a16();
            void *CALL_NZ_a16();
            void *PUSH_BC();
            void *ADD_A_d8();
            void *RST_00H();
            void *RET_Z();
            void *RET();
            void *JP_Z_a16();
            void *PREFIX_CB();
            void *CALL_Z_a16();
            void *CALL_a16();
            void *ADC_A_d8();
            void *RST_08H();

            void *CALL();
            void *ADD_A(uint8_t);
            void *ADC_A(uint8_t);
            void *CALLRST(uint16_t);

            void updateFlagsAddition(uint16_t, uint8_t);
            void updateFlags();

        private:
            Instruction instructions[256] = {
                Instruction("NOP",         std::bind(&CPU::NOP, this), 1),
                Instruction("LD BC,d16",   std::bind(&CPU::LD_BC_d16, this), 3),
                Instruction("LD (BC),A",   std::bind(&CPU::LD_BC_A, this), 1),
                Instruction("INC BC",      std::bind(&CPU::INC_BC, this), 1),
                Instruction("INC B",       std::bind(&CPU::INC_B, this), 1),
                Instruction("DEC B",       std::bind(&CPU::DEC_B, this), 1),
                Instruction("LD B,d8",     std::bind(&CPU::LD_B_d8, this), 2),
                Instruction("RLCA",        std::bind(&CPU::RLCA, this), 1),
                Instruction("LD (a16),SP", std::bind(&CPU::LD_a16_SP, this), 3),
                Instruction("ADD HL,BC",   std::bind(&CPU::ADD_HL_BC, this), 1),
                Instruction("LD A,(BC)",   std::bind(&CPU::LD_A_BC, this), 1),
                Instruction("DEC BC",      std::bind(&CPU::DEC_BC, this), 1),
                Instruction("INC C",       std::bind(&CPU::INC_C, this), 1),
                Instruction("DEC C",       std::bind(&CPU::DEC_C, this), 1),
                Instruction("LD C,d8",     std::bind(&CPU::LD_C_d8, this), 2),
                Instruction("RRCA",        std::bind(&CPU::RRCA, this), 1),

                Instruction("STOP 0",      std::bind(&CPU::STOP, this), 2),
                Instruction("LD DE,d16",   std::bind(&CPU::LD_DE_d16, this), 3),
                Instruction("LD (DE),A",   std::bind(&CPU::LD_DE_A, this), 1),
                Instruction("INC DE",      std::bind(&CPU::INC_DE, this), 1),
                Instruction("INC D",       std::bind(&CPU::INC_D, this), 1),
                Instruction("DEC D",       std::bind(&CPU::DEC_D, this), 1),
                Instruction("LD D,d8",     std::bind(&CPU::LD_D_d8, this), 2),
                Instruction("RLA",         std::bind(&CPU::RLA, this), 1),
                Instruction("JR r8",       std::bind(&CPU::JR_r8, this), 2),
                Instruction("ADD HL,DE",   std::bind(&CPU::ADD_HL_DE, this), 1),
                Instruction("LD A,(DE)",   std::bind(&CPU::LD_A_DE, this), 1),
                Instruction("DEC DE",      std::bind(&CPU::DEC_DE, this), 1),
                Instruction("INC E",       std::bind(&CPU::INC_E, this), 1),
                Instruction("DEC E",       std::bind(&CPU::DEC_E, this), 1),
                Instruction("LD E,d8",     std::bind(&CPU::LD_E_d8, this), 2),
                Instruction("RRA",         std::bind(&CPU::RRA, this), 1),

                Instruction("JR NZ,r8",    std::bind(&CPU::JR_NZ_r8, this), 2),
                Instruction("LD HL,d16",   std::bind(&CPU::LD_HL_d16, this), 3),
                Instruction("LD (HL+),A",  std::bind(&CPU::LD_HL_A_increment, this), 1),
                Instruction("INC HL",      std::bind(&CPU::INC_HL, this), 1),
                Instruction("INC H",       std::bind(&CPU::INC_H, this), 1),
                Instruction("DEC H",       std::bind(&CPU::DEC_H, this), 1),
                Instruction("LD H,d8",     std::bind(&CPU::LD_H_d8, this), 2),
                Instruction("DAA",         std::bind(&CPU::DAA, this), 1),
                Instruction("JR Z,r8",     std::bind(&CPU::JR_Z_r8, this), 2),
                Instruction("ADD HL,HL",   std::bind(&CPU::ADD_HL_HL, this), 1),
                Instruction("LD A,(HL+)",  std::bind(&CPU::LD_A_HL_increment, this), 1),
                Instruction("DEC HL",      std::bind(&CPU::DEC_HL, this), 1),
                Instruction("INC L",       std::bind(&CPU::INC_L, this), 1),
                Instruction("DEC L",       std::bind(&CPU::DEC_L, this), 1),
                Instruction("LD L,d8",     std::bind(&CPU::LD_L_d8, this), 2),
                Instruction("CPL",         std::bind(&CPU::CPL, this), 1),

                Instruction("JR NC,r8",    std::bind(&CPU::JR_NC_r8, this), 2),
                Instruction("LD SP,d16",   std::bind(&CPU::LD_SP_d16, this), 3),
                Instruction("LD (HL-),A",  std::bind(&CPU::LD_HL_decrement_A, this), 1),
                Instruction("INC SP",      std::bind(&CPU::INC_SP, this), 1),
                Instruction("INC (HL)",    std::bind(&CPU::INC_HL, this), 1),
                Instruction("DEC (HL)",    std::bind(&CPU::DEC_HL, this), 1),
                Instruction("LD (HL),d8",  std::bind(&CPU::LD_HL_d8, this), 2),
                Instruction("SCF",         std::bind(&CPU::SCF, this), 1),
                Instruction("JR C,r8",     std::bind(&CPU::JR_C_r8, this), 2),
                Instruction("ADD HL,SP",   std::bind(&CPU::ADD_HL_SP, this), 1),
                Instruction("LD A,(HL-)",  std::bind(&CPU::LD_A_decrement_HL, this), 1),
                Instruction("DEC SP",      std::bind(&CPU::DEC_SP, this), 1),
                Instruction("INC A",       std::bind(&CPU::INC_A, this), 1),
                Instruction("DEC A",       std::bind(&CPU::DEC_A, this), 1),
                Instruction("LD A,d8",     std::bind(&CPU::LD_A_d8, this), 2),
                Instruction("CCF",         std::bind(&CPU::CCF, this), 1),

                Instruction("LD B,B",      std::bind(&CPU::LD_B_B, this), 1),
                Instruction("LD B,C",      std::bind(&CPU::LD_B_C, this), 1),
                Instruction("LD B,D",      std::bind(&CPU::LD_B_D, this), 1),
                Instruction("LD B,E",      std::bind(&CPU::LD_B_E, this), 1),
                Instruction("LD B,H",      std::bind(&CPU::LD_B_H, this), 1),
                Instruction("LD B,L",      std::bind(&CPU::LD_B_L, this), 1),
                Instruction("LD B,(HL)",   std::bind(&CPU::LD_B_HL, this), 1),
                Instruction("LD B,A",      std::bind(&CPU::LD_B_A, this), 1),
                Instruction("LD C,B",      std::bind(&CPU::LD_C_B, this), 1),
                Instruction("LD C,C",      std::bind(&CPU::LD_C_C, this), 1),
                Instruction("LD C,D",      std::bind(&CPU::LD_C_D, this), 1),
                Instruction("LD C,E",      std::bind(&CPU::LD_C_E, this), 1),
                Instruction("LD C,H",      std::bind(&CPU::LD_C_H, this), 1),
                Instruction("LD C,L",      std::bind(&CPU::LD_C_L, this), 1),
                Instruction("LD C,(HL)",   std::bind(&CPU::LD_C_HL, this), 1),
                Instruction("LD C,A",      std::bind(&CPU::LD_C_A, this), 1),

                Instruction("LD D,B",      std::bind(&CPU::LD_D_B, this), 1),
                Instruction("LD D,C",      std::bind(&CPU::LD_D_C, this), 1),
                Instruction("LD D,D",      std::bind(&CPU::LD_D_D, this), 1),
                Instruction("LD D,E",      std::bind(&CPU::LD_D_E, this), 1),
                Instruction("LD D,H",      std::bind(&CPU::LD_D_H, this), 1),
                Instruction("LD D,L",      std::bind(&CPU::LD_D_L, this), 1),
                Instruction("LD D,(HL)",   std::bind(&CPU::LD_D_HL, this), 1),
                Instruction("LD D,A",      std::bind(&CPU::LD_D_A, this), 1),
                Instruction("LD E,B",      std::bind(&CPU::LD_E_B, this), 1),
                Instruction("LD E,C",      std::bind(&CPU::LD_E_C, this), 1),
                Instruction("LD E,D",      std::bind(&CPU::LD_E_D, this), 1),
                Instruction("LD E,E",      std::bind(&CPU::LD_E_E, this), 1),
                Instruction("LD E,H",      std::bind(&CPU::LD_E_H, this), 1),
                Instruction("LD E,L",      std::bind(&CPU::LD_E_L, this), 1),
                Instruction("LD E,(HL)",   std::bind(&CPU::LD_E_HL, this), 1),
                Instruction("LD E,A",      std::bind(&CPU::LD_E_A, this), 1),

                Instruction("LD H,B",      std::bind(&CPU::LD_H_B, this), 1),
                Instruction("LD H,C",      std::bind(&CPU::LD_H_C, this), 1),
                Instruction("LD H,D",      std::bind(&CPU::LD_H_D, this), 1),
                Instruction("LD H,E",      std::bind(&CPU::LD_H_E, this), 1),
                Instruction("LD H,H",      std::bind(&CPU::LD_H_H, this), 1),
                Instruction("LD H,L",      std::bind(&CPU::LD_H_L, this), 1),
                Instruction("LD H,(HL)",   std::bind(&CPU::LD_H_HL, this), 1),
                Instruction("LD H,A",      std::bind(&CPU::LD_H_A, this), 1),
                Instruction("LD L,B",      std::bind(&CPU::LD_L_B, this), 1),
                Instruction("LD L,C",      std::bind(&CPU::LD_L_C, this), 1),
                Instruction("LD L,D",      std::bind(&CPU::LD_L_D, this), 1),
                Instruction("LD L,E",      std::bind(&CPU::LD_L_E, this), 1),
                Instruction("LD L,H",      std::bind(&CPU::LD_L_H, this), 1),
                Instruction("LD L,L",      std::bind(&CPU::LD_L_L, this), 1),
                Instruction("LD L,(HL)",   std::bind(&CPU::LD_L_HL, this), 1),
                Instruction("LD L,A",      std::bind(&CPU::LD_L_A, this), 1),

                Instruction("LD (HL),B",   std::bind(&CPU::LD_HL_B, this), 1),
                Instruction("LD (HL),C",   std::bind(&CPU::LD_HL_C, this), 1),
                Instruction("LD (HL),D",   std::bind(&CPU::LD_HL_D, this), 1),
                Instruction("LD (HL),E",   std::bind(&CPU::LD_HL_E, this), 1),
                Instruction("LD (HL),H",   std::bind(&CPU::LD_HL_H, this), 1),
                Instruction("LD (HL),L",   std::bind(&CPU::LD_HL_L, this), 1),
                Instruction("HALT",        std::bind(&CPU::HALT, this), 1),
                Instruction("LD (HL),A",   std::bind(&CPU::LD_HL_A, this), 1),
                Instruction("LD A,B",      std::bind(&CPU::LD_A_B, this), 1),
                Instruction("LD A,C",      std::bind(&CPU::LD_A_C, this), 1),
                Instruction("LD A,D",      std::bind(&CPU::LD_A_D, this), 1),
                Instruction("LD A,E",      std::bind(&CPU::LD_A_E, this), 1),
                Instruction("LD A,H",      std::bind(&CPU::LD_A_H, this), 1),
                Instruction("LD A,L",      std::bind(&CPU::LD_A_L, this), 1),
                Instruction("LD A,(HL)",   std::bind(&CPU::LD_A_HL, this), 1),
                Instruction("LD A,A",      std::bind(&CPU::LD_A_A, this), 1),
                
                Instruction("ADD A,B",     std::bind(&CPU::ADD_A_B, this), 1),
                Instruction("ADD A,C",     std::bind(&CPU::ADD_A_C, this), 1),
                Instruction("ADD A,D",     std::bind(&CPU::ADD_A_D, this), 1),
                Instruction("ADD A,E",     std::bind(&CPU::ADD_A_E, this), 1),
                Instruction("ADD A,H",     std::bind(&CPU::ADD_A_H, this), 1),
                Instruction("ADD A,L",     std::bind(&CPU::ADD_A_L, this), 1),
                Instruction("ADD A,(HL)",  std::bind(&CPU::ADD_A_HL, this), 1),
                Instruction("ADD A,A",     std::bind(&CPU::ADD_A_A, this), 1),
                Instruction("ADC A,B",     std::bind(&CPU::ADD_A_B, this), 1),
                Instruction("ADC A,C",     std::bind(&CPU::ADD_A_C, this), 1),
                Instruction("ADC A,D",     std::bind(&CPU::ADD_A_D, this), 1),
                Instruction("ADC A,E",     std::bind(&CPU::ADD_A_E, this), 1),
                Instruction("ADC A,H",     std::bind(&CPU::ADD_A_H, this), 1),
                Instruction("ADC A,L",     std::bind(&CPU::ADD_A_L, this), 1),
                Instruction("ADC A,(HL)",  std::bind(&CPU::ADD_A_HL, this), 1),
                Instruction("ADC A,A",     std::bind(&CPU::ADD_A_A, this), 1),

                Instruction("SUB B",       std::bind(&CPU::SUB_B, this), 1),
                Instruction("SUB C",       std::bind(&CPU::SUB_C, this), 1),
                Instruction("SUB D",       std::bind(&CPU::SUB_D, this), 1),
                Instruction("SUB E",       std::bind(&CPU::SUB_E, this), 1),
                Instruction("SUB H",       std::bind(&CPU::SUB_H, this), 1),
                Instruction("SUB L",       std::bind(&CPU::SUB_L, this), 1),
                Instruction("SUB (HL)",    std::bind(&CPU::SUB_HL, this), 1),
                Instruction("SUB A",       std::bind(&CPU::NIY, this), 1),
                Instruction("SBC A,B",     std::bind(&CPU::NIY, this), 1),
                Instruction("SBC A,C",     std::bind(&CPU::NIY, this), 1),
                Instruction("SBC A,D",     std::bind(&CPU::NIY, this), 1),
                Instruction("SBC A,E",     std::bind(&CPU::NIY, this), 1),
                Instruction("SBC A,H",     std::bind(&CPU::NIY, this), 1),
                Instruction("SBC A,L",     std::bind(&CPU::NIY, this), 1),
                Instruction("SBC A,(HL)",  std::bind(&CPU::NIY, this), 1),
                Instruction("SBC A,A",     std::bind(&CPU::NIY, this), 1),

                Instruction("AND B",       std::bind(&CPU::AND_B, this), 1),
                Instruction("AND C",       std::bind(&CPU::AND_C, this), 1),
                Instruction("AND D",       std::bind(&CPU::AND_D, this), 1),
                Instruction("AND E",       std::bind(&CPU::AND_E, this), 1),
                Instruction("AND H",       std::bind(&CPU::AND_H, this), 1),
                Instruction("AND L",       std::bind(&CPU::AND_L, this), 1),
                Instruction("AND (HL)",    std::bind(&CPU::AND_HL, this), 1),
                Instruction("AND A",       std::bind(&CPU::AND_A, this), 1),
                Instruction("XOR B",       std::bind(&CPU::XOR_B, this), 1),
                Instruction("XOR C",       std::bind(&CPU::XOR_C, this), 1),
                Instruction("XOR D",       std::bind(&CPU::XOR_D, this), 1),
                Instruction("XOR E",       std::bind(&CPU::XOR_E, this), 1),
                Instruction("XOR H",       std::bind(&CPU::XOR_H, this), 1),
                Instruction("XOR L",       std::bind(&CPU::XOR_L, this), 1),
                Instruction("XOR (HL)",    std::bind(&CPU::XOR_HL, this), 1),
                Instruction("XOR A",       std::bind(&CPU::XOR_A, this), 1),

                Instruction("OR B",        std::bind(&CPU::OR_B, this), 1),
                Instruction("OR C",        std::bind(&CPU::OR_C, this), 1),
                Instruction("OR D",        std::bind(&CPU::OR_D, this), 1),
                Instruction("OR E",        std::bind(&CPU::OR_E, this), 1),
                Instruction("OR H",        std::bind(&CPU::CP_H, this), 1),
                Instruction("OR L",        std::bind(&CPU::CP_L, this), 1),
                Instruction("OR (HL)",     std::bind(&CPU::OR_HL, this), 1),
                Instruction("OR A",        std::bind(&CPU::OR_A, this), 1),
                Instruction("CP B",        std::bind(&CPU::CP_B, this), 1),
                Instruction("CP C",        std::bind(&CPU::CP_C, this), 1),
                Instruction("CP D",        std::bind(&CPU::CP_D, this), 1),
                Instruction("CP E",        std::bind(&CPU::CP_E, this), 1),
                Instruction("CP H",        std::bind(&CPU::CP_H, this), 1),
                Instruction("CP L",        std::bind(&CPU::CP_L, this), 1),
                Instruction("CP (HL)",     std::bind(&CPU::CP_HL, this), 1),
                Instruction("CP A",        std::bind(&CPU::CP_A, this), 1),

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

            void *updateFlags(uint8_t);
            void *compare(uint8_t);
            void *add(uint8_t);
            uint8_t readByte(uint16_t);
            void *writeByte(uint16_t, uint8_t);
            void *push16(uint16_t);
            uint16_t pop16();
    };
