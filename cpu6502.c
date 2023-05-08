#include <string.h>
#include <stdio.h>
#include <opfuncs6502.h>
#include <cpu6502.h>
#include <nesmachine.h>

void init6502(struct cpu6502* cpu, struct nesmachine* nes)
{
    memset(cpu, 0, sizeof(struct cpu6502));
    cpu->s = 0x24;
    cpu->sp = 0xfd;
    cpu->running = 1;
    cpu->nes = nes;

    for (int i = 0; i < OP_NUM; i++)
    {
        cpu->instructions[i].opcode = i;
        cpu->instructions[i].bytes = 2;
        strcpy(cpu->instructions[i].nemonic, "???");
        cpu->instructions[i].cycles = 2;
        cpu->instructions[i].cond_cycles = 0;
        cpu->instructions[i].mode = IMM;
        cpu->instructions[i].func = XXX;
        cpu->instructions[i].flags = 0;
    }

    cpu->instructions[0x69].opcode = 0x69;
    cpu->instructions[0x69].bytes = 2;
    strcpy(cpu->instructions[0x69].nemonic, "ADC");
    cpu->instructions[0x69].cycles = 2;
    cpu->instructions[0x69].cond_cycles = 0;
    cpu->instructions[0x69].mode = IMM;
    cpu->instructions[0x69].func = ADC;
    cpu->instructions[0x69].flags = 0b1100011;

    cpu->instructions[0x65].opcode = 0x65;
    cpu->instructions[0x65].bytes = 2;
    strcpy(cpu->instructions[0x65].nemonic, "ADC");
    cpu->instructions[0x65].cycles = 3;
    cpu->instructions[0x65].cond_cycles = 0;
    cpu->instructions[0x65].mode = ZP;
    cpu->instructions[0x65].func = ADC;
    cpu->instructions[0x65].flags = 0b1100011;

    cpu->instructions[0x75].opcode = 0x75;
    cpu->instructions[0x75].bytes = 2;
    strcpy(cpu->instructions[0x75].nemonic, "ADC");
    cpu->instructions[0x75].cycles = 4;
    cpu->instructions[0x75].cond_cycles = 0;
    cpu->instructions[0x75].mode = ZPX;
    cpu->instructions[0x75].func = ADC;
    cpu->instructions[0x75].flags = 0b1100011;

    cpu->instructions[0x6d].opcode = 0x6d;
    cpu->instructions[0x6d].bytes = 3;
    strcpy(cpu->instructions[0x6d].nemonic, "ADC");
    cpu->instructions[0x6d].cycles = 4;
    cpu->instructions[0x6d].cond_cycles = 0;
    cpu->instructions[0x6d].mode = ABS;
    cpu->instructions[0x6d].func = ADC;
    cpu->instructions[0x6d].flags = 0b1100011;

    cpu->instructions[0x7d].opcode = 0x7d;
    cpu->instructions[0x7d].bytes = 3;
    strcpy(cpu->instructions[0x7d].nemonic, "ADC");
    cpu->instructions[0x7d].cycles = 4;
    cpu->instructions[0x7d].cond_cycles = 0;
    cpu->instructions[0x7d].mode = ABSX;
    cpu->instructions[0x7d].func = ADC;
    cpu->instructions[0x7d].flags = 0b1100011;

    cpu->instructions[0x79].opcode = 0x79;
    cpu->instructions[0x79].bytes = 3;
    strcpy(cpu->instructions[0x79].nemonic, "ADC");
    cpu->instructions[0x79].cycles = 4;
    cpu->instructions[0x79].cond_cycles = 0;
    cpu->instructions[0x79].mode = ABSY;
    cpu->instructions[0x79].func = ADC;
    cpu->instructions[0x79].flags = 0b1100011;

    cpu->instructions[0x61].opcode = 0x61;
    cpu->instructions[0x61].bytes = 2;
    strcpy(cpu->instructions[0x61].nemonic, "ADC");
    cpu->instructions[0x61].cycles = 6;
    cpu->instructions[0x61].cond_cycles = 0;
    cpu->instructions[0x61].mode = INDX;
    cpu->instructions[0x61].func = ADC;
    cpu->instructions[0x61].flags = 0b1100011;

    cpu->instructions[0x71].opcode = 0x71;
    cpu->instructions[0x71].bytes = 2;
    strcpy(cpu->instructions[0x71].nemonic, "ADC");
    cpu->instructions[0x71].cycles = 5;
    cpu->instructions[0x71].cond_cycles = 0;
    cpu->instructions[0x71].mode = INDY;
    cpu->instructions[0x71].func = ADC;
    cpu->instructions[0x71].flags = 0b1100011;

    cpu->instructions[0x29].opcode = 0x29;
    cpu->instructions[0x29].bytes = 2;
    strcpy(cpu->instructions[0x29].nemonic, "AND");
    cpu->instructions[0x29].cycles = 2;
    cpu->instructions[0x29].cond_cycles = 0;
    cpu->instructions[0x29].mode = IMM;
    cpu->instructions[0x29].func = AND;
    cpu->instructions[0x29].flags = 0b1000010;

    cpu->instructions[0x25].opcode = 0x25;
    cpu->instructions[0x25].bytes = 2;
    strcpy(cpu->instructions[0x25].nemonic, "AND");
    cpu->instructions[0x25].cycles = 3;
    cpu->instructions[0x25].cond_cycles = 0;
    cpu->instructions[0x25].mode = ZP;
    cpu->instructions[0x25].func = AND;
    cpu->instructions[0x25].flags = 0b1000010;

    cpu->instructions[0x35].opcode = 0x35;
    cpu->instructions[0x35].bytes = 2;
    strcpy(cpu->instructions[0x35].nemonic, "AND");
    cpu->instructions[0x35].cycles = 4;
    cpu->instructions[0x35].cond_cycles = 0;
    cpu->instructions[0x35].mode = ZPX;
    cpu->instructions[0x35].func = AND;
    cpu->instructions[0x35].flags = 0b1000010;

    cpu->instructions[0x2d].opcode = 0x2d;
    cpu->instructions[0x2d].bytes = 3;
    strcpy(cpu->instructions[0x2d].nemonic, "AND");
    cpu->instructions[0x2d].cycles = 4;
    cpu->instructions[0x2d].cond_cycles = 0;
    cpu->instructions[0x2d].mode = ABS;
    cpu->instructions[0x2d].func = AND;
    cpu->instructions[0x2d].flags = 0b1000010;

    cpu->instructions[0x3d].opcode = 0x3d;
    cpu->instructions[0x3d].bytes = 3;
    strcpy(cpu->instructions[0x3d].nemonic, "AND");
    cpu->instructions[0x3d].cycles = 4;
    cpu->instructions[0x3d].cond_cycles = 0;
    cpu->instructions[0x3d].mode = ABSX;
    cpu->instructions[0x3d].func = AND;
    cpu->instructions[0x3d].flags = 0b1000010;

    cpu->instructions[0x39].opcode = 0x39;
    cpu->instructions[0x39].bytes = 3;
    strcpy(cpu->instructions[0x39].nemonic, "AND");
    cpu->instructions[0x39].cycles = 4;
    cpu->instructions[0x39].cond_cycles = 0;
    cpu->instructions[0x39].mode = ABSY;
    cpu->instructions[0x39].func = AND;
    cpu->instructions[0x39].flags = 0b1000010;

    cpu->instructions[0x21].opcode = 0x21;
    cpu->instructions[0x21].bytes = 2;
    strcpy(cpu->instructions[0x21].nemonic, "AND");
    cpu->instructions[0x21].cycles = 6;
    cpu->instructions[0x21].cond_cycles = 0;
    cpu->instructions[0x21].mode = INDX;
    cpu->instructions[0x21].func = AND;
    cpu->instructions[0x21].flags = 0b1000010;

    cpu->instructions[0x31].opcode = 0x31;
    cpu->instructions[0x31].bytes = 2;
    strcpy(cpu->instructions[0x31].nemonic, "AND");
    cpu->instructions[0x31].cycles = 5;
    cpu->instructions[0x31].cond_cycles = 0;
    cpu->instructions[0x31].mode = INDY;
    cpu->instructions[0x31].func = AND;
    cpu->instructions[0x31].flags = 0b1000010;

    cpu->instructions[0xa].opcode = 0xa;
    cpu->instructions[0xa].bytes = 1;
    strcpy(cpu->instructions[0xa].nemonic, "ASL");
    cpu->instructions[0xa].cycles = 2;
    cpu->instructions[0xa].cond_cycles = 0;
    cpu->instructions[0xa].mode = ACC;
    cpu->instructions[0xa].func = ASL;
    cpu->instructions[0xa].flags = 0b1000011;

    cpu->instructions[0x6].opcode = 0x6;
    cpu->instructions[0x6].bytes = 2;
    strcpy(cpu->instructions[0x6].nemonic, "ASL");
    cpu->instructions[0x6].cycles = 5;
    cpu->instructions[0x6].cond_cycles = 0;
    cpu->instructions[0x6].mode = ZP;
    cpu->instructions[0x6].func = ASL;
    cpu->instructions[0x6].flags = 0b1000011;

    cpu->instructions[0x16].opcode = 0x16;
    cpu->instructions[0x16].bytes = 2;
    strcpy(cpu->instructions[0x16].nemonic, "ASL");
    cpu->instructions[0x16].cycles = 6;
    cpu->instructions[0x16].cond_cycles = 0;
    cpu->instructions[0x16].mode = ZPX;
    cpu->instructions[0x16].func = ASL;
    cpu->instructions[0x16].flags = 0b1000011;

    cpu->instructions[0xe].opcode = 0xe;
    cpu->instructions[0xe].bytes = 3;
    strcpy(cpu->instructions[0xe].nemonic, "ASL");
    cpu->instructions[0xe].cycles = 6;
    cpu->instructions[0xe].cond_cycles = 0;
    cpu->instructions[0xe].mode = ABS;
    cpu->instructions[0xe].func = ASL;
    cpu->instructions[0xe].flags = 0b1000011;

    cpu->instructions[0x1e].opcode = 0x1e;
    cpu->instructions[0x1e].bytes = 3;
    strcpy(cpu->instructions[0x1e].nemonic, "ASL");
    cpu->instructions[0x1e].cycles = 7;
    cpu->instructions[0x1e].cond_cycles = 0;
    cpu->instructions[0x1e].mode = ABSX;
    cpu->instructions[0x1e].func = ASL;
    cpu->instructions[0x1e].flags = 0b1000011;

    cpu->instructions[0x90].opcode = 0x90;
    cpu->instructions[0x90].bytes = 2;
    strcpy(cpu->instructions[0x90].nemonic, "BCC");
    cpu->instructions[0x90].cycles = 2;
    cpu->instructions[0x90].cond_cycles = 3;
    cpu->instructions[0x90].mode = REL;
    cpu->instructions[0x90].func = BCC;
    cpu->instructions[0x90].flags = 0b0;

    cpu->instructions[0xb0].opcode = 0xb0;
    cpu->instructions[0xb0].bytes = 2;
    strcpy(cpu->instructions[0xb0].nemonic, "BCS");
    cpu->instructions[0xb0].cycles = 2;
    cpu->instructions[0xb0].cond_cycles = 3;
    cpu->instructions[0xb0].mode = REL;
    cpu->instructions[0xb0].func = BCS;
    cpu->instructions[0xb0].flags = 0b0;

    cpu->instructions[0xf0].opcode = 0xf0;
    cpu->instructions[0xf0].bytes = 2;
    strcpy(cpu->instructions[0xf0].nemonic, "BEQ");
    cpu->instructions[0xf0].cycles = 2;
    cpu->instructions[0xf0].cond_cycles = 3;
    cpu->instructions[0xf0].mode = REL;
    cpu->instructions[0xf0].func = BEQ;
    cpu->instructions[0xf0].flags = 0b0;

    cpu->instructions[0x30].opcode = 0x30;
    cpu->instructions[0x30].bytes = 2;
    strcpy(cpu->instructions[0x30].nemonic, "BMI");
    cpu->instructions[0x30].cycles = 2;
    cpu->instructions[0x30].cond_cycles = 3;
    cpu->instructions[0x30].mode = REL;
    cpu->instructions[0x30].func = BMI;
    cpu->instructions[0x30].flags = 0b0;

    cpu->instructions[0xd0].opcode = 0xd0;
    cpu->instructions[0xd0].bytes = 2;
    strcpy(cpu->instructions[0xd0].nemonic, "BNE");
    cpu->instructions[0xd0].cycles = 2;
    cpu->instructions[0xd0].cond_cycles = 3;
    cpu->instructions[0xd0].mode = REL;
    cpu->instructions[0xd0].func = BNE;
    cpu->instructions[0xd0].flags = 0b0;

    cpu->instructions[0x10].opcode = 0x10;
    cpu->instructions[0x10].bytes = 2;
    strcpy(cpu->instructions[0x10].nemonic, "BPL");
    cpu->instructions[0x10].cycles = 2;
    cpu->instructions[0x10].cond_cycles = 3;
    cpu->instructions[0x10].mode = REL;
    cpu->instructions[0x10].func = BPL;
    cpu->instructions[0x10].flags = 0b0;

    cpu->instructions[0x50].opcode = 0x50;
    cpu->instructions[0x50].bytes = 2;
    strcpy(cpu->instructions[0x50].nemonic, "BVC");
    cpu->instructions[0x50].cycles = 2;
    cpu->instructions[0x50].cond_cycles = 3;
    cpu->instructions[0x50].mode = REL;
    cpu->instructions[0x50].func = BVC;
    cpu->instructions[0x50].flags = 0b0;

    cpu->instructions[0x70].opcode = 0x70;
    cpu->instructions[0x70].bytes = 2;
    strcpy(cpu->instructions[0x70].nemonic, "BVS");
    cpu->instructions[0x70].cycles = 2;
    cpu->instructions[0x70].cond_cycles = 3;
    cpu->instructions[0x70].mode = REL;
    cpu->instructions[0x70].func = BVS;
    cpu->instructions[0x70].flags = 0b0;

    cpu->instructions[0x24].opcode = 0x24;
    cpu->instructions[0x24].bytes = 2;
    strcpy(cpu->instructions[0x24].nemonic, "BIT");
    cpu->instructions[0x24].cycles = 3;
    cpu->instructions[0x24].cond_cycles = 0;
    cpu->instructions[0x24].mode = ZP;
    cpu->instructions[0x24].func = BIT;
    cpu->instructions[0x24].flags = 0b1100010;

    cpu->instructions[0x2c].opcode = 0x2c;
    cpu->instructions[0x2c].bytes = 3;
    strcpy(cpu->instructions[0x2c].nemonic, "BIT");
    cpu->instructions[0x2c].cycles = 4;
    cpu->instructions[0x2c].cond_cycles = 0;
    cpu->instructions[0x2c].mode = ABS;
    cpu->instructions[0x2c].func = BIT;
    cpu->instructions[0x2c].flags = 0b1100010;

    cpu->instructions[0x0].opcode = 0x0;
    cpu->instructions[0x0].bytes = 1;
    strcpy(cpu->instructions[0x0].nemonic, "BRK");
    cpu->instructions[0x0].cycles = 7;
    cpu->instructions[0x0].cond_cycles = 0;
    cpu->instructions[0x0].mode = IMP;
    cpu->instructions[0x0].func = BRK;
    cpu->instructions[0x0].flags = 0b0;

    cpu->instructions[0x18].opcode = 0x18;
    cpu->instructions[0x18].bytes = 1;
    strcpy(cpu->instructions[0x18].nemonic, "CLC");
    cpu->instructions[0x18].cycles = 2;
    cpu->instructions[0x18].cond_cycles = 0;
    cpu->instructions[0x18].mode = IMP;
    cpu->instructions[0x18].func = CLC;
    cpu->instructions[0x18].flags = 0b1;

    cpu->instructions[0xd8].opcode = 0xd8;
    cpu->instructions[0xd8].bytes = 1;
    strcpy(cpu->instructions[0xd8].nemonic, "CLD");
    cpu->instructions[0xd8].cycles = 2;
    cpu->instructions[0xd8].cond_cycles = 0;
    cpu->instructions[0xd8].mode = IMP;
    cpu->instructions[0xd8].func = CLD;
    cpu->instructions[0xd8].flags = 0b1000;

    cpu->instructions[0x58].opcode = 0x58;
    cpu->instructions[0x58].bytes = 1;
    strcpy(cpu->instructions[0x58].nemonic, "CLI");
    cpu->instructions[0x58].cycles = 2;
    cpu->instructions[0x58].cond_cycles = 0;
    cpu->instructions[0x58].mode = IMP;
    cpu->instructions[0x58].func = CLI;
    cpu->instructions[0x58].flags = 0b100;

    cpu->instructions[0xb8].opcode = 0xb8;
    cpu->instructions[0xb8].bytes = 1;
    strcpy(cpu->instructions[0xb8].nemonic, "CLV");
    cpu->instructions[0xb8].cycles = 2;
    cpu->instructions[0xb8].cond_cycles = 0;
    cpu->instructions[0xb8].mode = IMP;
    cpu->instructions[0xb8].func = CLV;
    cpu->instructions[0xb8].flags = 0b100000;

    cpu->instructions[0xea].opcode = 0xea;
    cpu->instructions[0xea].bytes = 1;
    strcpy(cpu->instructions[0xea].nemonic, "NOP");
    cpu->instructions[0xea].cycles = 2;
    cpu->instructions[0xea].cond_cycles = 0;
    cpu->instructions[0xea].mode = IMP;
    cpu->instructions[0xea].func = NOP;
    cpu->instructions[0xea].flags = 0b0;

    cpu->instructions[0x48].opcode = 0x48;
    cpu->instructions[0x48].bytes = 1;
    strcpy(cpu->instructions[0x48].nemonic, "PHA");
    cpu->instructions[0x48].cycles = 3;
    cpu->instructions[0x48].cond_cycles = 0;
    cpu->instructions[0x48].mode = IMP;
    cpu->instructions[0x48].func = PHA;
    cpu->instructions[0x48].flags = 0b0;

    cpu->instructions[0x68].opcode = 0x68;
    cpu->instructions[0x68].bytes = 1;
    strcpy(cpu->instructions[0x68].nemonic, "PLA");
    cpu->instructions[0x68].cycles = 4;
    cpu->instructions[0x68].cond_cycles = 0;
    cpu->instructions[0x68].mode = IMP;
    cpu->instructions[0x68].func = PLA;
    cpu->instructions[0x68].flags = 0b1000010;

    cpu->instructions[0x8].opcode = 0x8;
    cpu->instructions[0x8].bytes = 1;
    strcpy(cpu->instructions[0x8].nemonic, "PHP");
    cpu->instructions[0x8].cycles = 3;
    cpu->instructions[0x8].cond_cycles = 0;
    cpu->instructions[0x8].mode = IMP;
    cpu->instructions[0x8].func = PHP;
    cpu->instructions[0x8].flags = 0b0;

    cpu->instructions[0x28].opcode = 0x28;
    cpu->instructions[0x28].bytes = 1;
    strcpy(cpu->instructions[0x28].nemonic, "PLP");
    cpu->instructions[0x28].cycles = 4;
    cpu->instructions[0x28].cond_cycles = 0;
    cpu->instructions[0x28].mode = IMP;
    cpu->instructions[0x28].func = PLP;
    cpu->instructions[0x28].flags = 0b1111111;

    cpu->instructions[0x40].opcode = 0x40;
    cpu->instructions[0x40].bytes = 1;
    strcpy(cpu->instructions[0x40].nemonic, "RTI");
    cpu->instructions[0x40].cycles = 6;
    cpu->instructions[0x40].cond_cycles = 0;
    cpu->instructions[0x40].mode = IMP;
    cpu->instructions[0x40].func = RTI;
    cpu->instructions[0x40].flags = 0b0;

    cpu->instructions[0x60].opcode = 0x60;
    cpu->instructions[0x60].bytes = 1;
    strcpy(cpu->instructions[0x60].nemonic, "RTS");
    cpu->instructions[0x60].cycles = 6;
    cpu->instructions[0x60].cond_cycles = 0;
    cpu->instructions[0x60].mode = IMP;
    cpu->instructions[0x60].func = RTS;
    cpu->instructions[0x60].flags = 0b0;

    cpu->instructions[0x38].opcode = 0x38;
    cpu->instructions[0x38].bytes = 1;
    strcpy(cpu->instructions[0x38].nemonic, "SEC");
    cpu->instructions[0x38].cycles = 2;
    cpu->instructions[0x38].cond_cycles = 0;
    cpu->instructions[0x38].mode = IMP;
    cpu->instructions[0x38].func = SEC;
    cpu->instructions[0x38].flags = 0b1;

    cpu->instructions[0xf8].opcode = 0xf8;
    cpu->instructions[0xf8].bytes = 1;
    strcpy(cpu->instructions[0xf8].nemonic, "SED");
    cpu->instructions[0xf8].cycles = 2;
    cpu->instructions[0xf8].cond_cycles = 0;
    cpu->instructions[0xf8].mode = IMP;
    cpu->instructions[0xf8].func = SED;
    cpu->instructions[0xf8].flags = 0b1000;

    cpu->instructions[0x78].opcode = 0x78;
    cpu->instructions[0x78].bytes = 1;
    strcpy(cpu->instructions[0x78].nemonic, "SEI");
    cpu->instructions[0x78].cycles = 2;
    cpu->instructions[0x78].cond_cycles = 0;
    cpu->instructions[0x78].mode = IMP;
    cpu->instructions[0x78].func = SEI;
    cpu->instructions[0x78].flags = 0b100;

    cpu->instructions[0xaa].opcode = 0xaa;
    cpu->instructions[0xaa].bytes = 1;
    strcpy(cpu->instructions[0xaa].nemonic, "TAX");
    cpu->instructions[0xaa].cycles = 2;
    cpu->instructions[0xaa].cond_cycles = 0;
    cpu->instructions[0xaa].mode = IMP;
    cpu->instructions[0xaa].func = TAX;
    cpu->instructions[0xaa].flags = 0b1000010;

    cpu->instructions[0x8a].opcode = 0x8a;
    cpu->instructions[0x8a].bytes = 1;
    strcpy(cpu->instructions[0x8a].nemonic, "TXA");
    cpu->instructions[0x8a].cycles = 2;
    cpu->instructions[0x8a].cond_cycles = 0;
    cpu->instructions[0x8a].mode = IMP;
    cpu->instructions[0x8a].func = TXA;
    cpu->instructions[0x8a].flags = 0b1000010;

    cpu->instructions[0xa8].opcode = 0xa8;
    cpu->instructions[0xa8].bytes = 1;
    strcpy(cpu->instructions[0xa8].nemonic, "TAY");
    cpu->instructions[0xa8].cycles = 2;
    cpu->instructions[0xa8].cond_cycles = 0;
    cpu->instructions[0xa8].mode = IMP;
    cpu->instructions[0xa8].func = TAY;
    cpu->instructions[0xa8].flags = 0b1000010;

    cpu->instructions[0x98].opcode = 0x98;
    cpu->instructions[0x98].bytes = 1;
    strcpy(cpu->instructions[0x98].nemonic, "TYA");
    cpu->instructions[0x98].cycles = 2;
    cpu->instructions[0x98].cond_cycles = 0;
    cpu->instructions[0x98].mode = IMP;
    cpu->instructions[0x98].func = TYA;
    cpu->instructions[0x98].flags = 0b1000010;

    cpu->instructions[0xba].opcode = 0xba;
    cpu->instructions[0xba].bytes = 1;
    strcpy(cpu->instructions[0xba].nemonic, "TSX");
    cpu->instructions[0xba].cycles = 2;
    cpu->instructions[0xba].cond_cycles = 0;
    cpu->instructions[0xba].mode = IMP;
    cpu->instructions[0xba].func = TSX;
    cpu->instructions[0xba].flags = 0b1000010;

    cpu->instructions[0x9a].opcode = 0x9a;
    cpu->instructions[0x9a].bytes = 1;
    strcpy(cpu->instructions[0x9a].nemonic, "TXS");
    cpu->instructions[0x9a].cycles = 2;
    cpu->instructions[0x9a].cond_cycles = 0;
    cpu->instructions[0x9a].mode = IMP;
    cpu->instructions[0x9a].func = TXS;
    cpu->instructions[0x9a].flags = 0b0;

    cpu->instructions[0xc9].opcode = 0xc9;
    cpu->instructions[0xc9].bytes = 2;
    strcpy(cpu->instructions[0xc9].nemonic, "CMP");
    cpu->instructions[0xc9].cycles = 2;
    cpu->instructions[0xc9].cond_cycles = 0;
    cpu->instructions[0xc9].mode = IMM;
    cpu->instructions[0xc9].func = CMP;
    cpu->instructions[0xc9].flags = 0b1000011;

    cpu->instructions[0xc5].opcode = 0xc5;
    cpu->instructions[0xc5].bytes = 2;
    strcpy(cpu->instructions[0xc5].nemonic, "CMP");
    cpu->instructions[0xc5].cycles = 3;
    cpu->instructions[0xc5].cond_cycles = 0;
    cpu->instructions[0xc5].mode = ZP;
    cpu->instructions[0xc5].func = CMP;
    cpu->instructions[0xc5].flags = 0b1000011;

    cpu->instructions[0xd5].opcode = 0xd5;
    cpu->instructions[0xd5].bytes = 2;
    strcpy(cpu->instructions[0xd5].nemonic, "CMP");
    cpu->instructions[0xd5].cycles = 4;
    cpu->instructions[0xd5].cond_cycles = 0;
    cpu->instructions[0xd5].mode = ZPX;
    cpu->instructions[0xd5].func = CMP;
    cpu->instructions[0xd5].flags = 0b1000011;

    cpu->instructions[0xcd].opcode = 0xcd;
    cpu->instructions[0xcd].bytes = 3;
    strcpy(cpu->instructions[0xcd].nemonic, "CMP");
    cpu->instructions[0xcd].cycles = 4;
    cpu->instructions[0xcd].cond_cycles = 0;
    cpu->instructions[0xcd].mode = ABS;
    cpu->instructions[0xcd].func = CMP;
    cpu->instructions[0xcd].flags = 0b1000011;

    cpu->instructions[0xdd].opcode = 0xdd;
    cpu->instructions[0xdd].bytes = 3;
    strcpy(cpu->instructions[0xdd].nemonic, "CMP");
    cpu->instructions[0xdd].cycles = 4;
    cpu->instructions[0xdd].cond_cycles = 0;
    cpu->instructions[0xdd].mode = ABSX;
    cpu->instructions[0xdd].func = CMP;
    cpu->instructions[0xdd].flags = 0b1000011;

    cpu->instructions[0xd9].opcode = 0xd9;
    cpu->instructions[0xd9].bytes = 3;
    strcpy(cpu->instructions[0xd9].nemonic, "CMP");
    cpu->instructions[0xd9].cycles = 4;
    cpu->instructions[0xd9].cond_cycles = 0;
    cpu->instructions[0xd9].mode = ABSY;
    cpu->instructions[0xd9].func = CMP;
    cpu->instructions[0xd9].flags = 0b1000011;

    cpu->instructions[0xc1].opcode = 0xc1;
    cpu->instructions[0xc1].bytes = 2;
    strcpy(cpu->instructions[0xc1].nemonic, "CMP");
    cpu->instructions[0xc1].cycles = 6;
    cpu->instructions[0xc1].cond_cycles = 0;
    cpu->instructions[0xc1].mode = INDX;
    cpu->instructions[0xc1].func = CMP;
    cpu->instructions[0xc1].flags = 0b1000011;

    cpu->instructions[0xd1].opcode = 0xd1;
    cpu->instructions[0xd1].bytes = 2;
    strcpy(cpu->instructions[0xd1].nemonic, "CMP");
    cpu->instructions[0xd1].cycles = 5;
    cpu->instructions[0xd1].cond_cycles = 0;
    cpu->instructions[0xd1].mode = INDY;
    cpu->instructions[0xd1].func = CMP;
    cpu->instructions[0xd1].flags = 0b1000011;

    cpu->instructions[0xe0].opcode = 0xe0;
    cpu->instructions[0xe0].bytes = 2;
    strcpy(cpu->instructions[0xe0].nemonic, "CPX");
    cpu->instructions[0xe0].cycles = 2;
    cpu->instructions[0xe0].cond_cycles = 0;
    cpu->instructions[0xe0].mode = IMM;
    cpu->instructions[0xe0].func = CPX;
    cpu->instructions[0xe0].flags = 0b1000011;

    cpu->instructions[0xe4].opcode = 0xe4;
    cpu->instructions[0xe4].bytes = 2;
    strcpy(cpu->instructions[0xe4].nemonic, "CPX");
    cpu->instructions[0xe4].cycles = 3;
    cpu->instructions[0xe4].cond_cycles = 0;
    cpu->instructions[0xe4].mode = ZP;
    cpu->instructions[0xe4].func = CPX;
    cpu->instructions[0xe4].flags = 0b1000011;

    cpu->instructions[0xec].opcode = 0xec;
    cpu->instructions[0xec].bytes = 3;
    strcpy(cpu->instructions[0xec].nemonic, "CPX");
    cpu->instructions[0xec].cycles = 4;
    cpu->instructions[0xec].cond_cycles = 0;
    cpu->instructions[0xec].mode = ABS;
    cpu->instructions[0xec].func = CPX;
    cpu->instructions[0xec].flags = 0b1000011;

    cpu->instructions[0xc0].opcode = 0xc0;
    cpu->instructions[0xc0].bytes = 2;
    strcpy(cpu->instructions[0xc0].nemonic, "CPY");
    cpu->instructions[0xc0].cycles = 2;
    cpu->instructions[0xc0].cond_cycles = 0;
    cpu->instructions[0xc0].mode = IMM;
    cpu->instructions[0xc0].func = CPY;
    cpu->instructions[0xc0].flags = 0b1000011;

    cpu->instructions[0xc4].opcode = 0xc4;
    cpu->instructions[0xc4].bytes = 2;
    strcpy(cpu->instructions[0xc4].nemonic, "CPY");
    cpu->instructions[0xc4].cycles = 3;
    cpu->instructions[0xc4].cond_cycles = 0;
    cpu->instructions[0xc4].mode = ZP;
    cpu->instructions[0xc4].func = CPY;
    cpu->instructions[0xc4].flags = 0b1000011;

    cpu->instructions[0xcc].opcode = 0xcc;
    cpu->instructions[0xcc].bytes = 3;
    strcpy(cpu->instructions[0xcc].nemonic, "CPY");
    cpu->instructions[0xcc].cycles = 4;
    cpu->instructions[0xcc].cond_cycles = 0;
    cpu->instructions[0xcc].mode = ABS;
    cpu->instructions[0xcc].func = CPY;
    cpu->instructions[0xcc].flags = 0b1000011;

    cpu->instructions[0xc6].opcode = 0xc6;
    cpu->instructions[0xc6].bytes = 2;
    strcpy(cpu->instructions[0xc6].nemonic, "DEC");
    cpu->instructions[0xc6].cycles = 5;
    cpu->instructions[0xc6].cond_cycles = 0;
    cpu->instructions[0xc6].mode = ZP;
    cpu->instructions[0xc6].func = DEC;
    cpu->instructions[0xc6].flags = 0b1000010;

    cpu->instructions[0xd6].opcode = 0xd6;
    cpu->instructions[0xd6].bytes = 2;
    strcpy(cpu->instructions[0xd6].nemonic, "DEC");
    cpu->instructions[0xd6].cycles = 6;
    cpu->instructions[0xd6].cond_cycles = 0;
    cpu->instructions[0xd6].mode = ZPX;
    cpu->instructions[0xd6].func = DEC;
    cpu->instructions[0xd6].flags = 0b1000010;

    cpu->instructions[0xce].opcode = 0xce;
    cpu->instructions[0xce].bytes = 3;
    strcpy(cpu->instructions[0xce].nemonic, "DEC");
    cpu->instructions[0xce].cycles = 6;
    cpu->instructions[0xce].cond_cycles = 0;
    cpu->instructions[0xce].mode = ABS;
    cpu->instructions[0xce].func = DEC;
    cpu->instructions[0xce].flags = 0b1000010;

    cpu->instructions[0xde].opcode = 0xde;
    cpu->instructions[0xde].bytes = 3;
    strcpy(cpu->instructions[0xde].nemonic, "DEC");
    cpu->instructions[0xde].cycles = 7;
    cpu->instructions[0xde].cond_cycles = 0;
    cpu->instructions[0xde].mode = ABSX;
    cpu->instructions[0xde].func = DEC;
    cpu->instructions[0xde].flags = 0b1000010;

    cpu->instructions[0xca].opcode = 0xca;
    cpu->instructions[0xca].bytes = 1;
    strcpy(cpu->instructions[0xca].nemonic, "DEX");
    cpu->instructions[0xca].cycles = 2;
    cpu->instructions[0xca].cond_cycles = 0;
    cpu->instructions[0xca].mode = IMP;
    cpu->instructions[0xca].func = DEX;
    cpu->instructions[0xca].flags = 0b1000010;

    cpu->instructions[0x88].opcode = 0x88;
    cpu->instructions[0x88].bytes = 1;
    strcpy(cpu->instructions[0x88].nemonic, "DEY");
    cpu->instructions[0x88].cycles = 2;
    cpu->instructions[0x88].cond_cycles = 0;
    cpu->instructions[0x88].mode = IMP;
    cpu->instructions[0x88].func = DEY;
    cpu->instructions[0x88].flags = 0b1000010;

    cpu->instructions[0xe8].opcode = 0xe8;
    cpu->instructions[0xe8].bytes = 1;
    strcpy(cpu->instructions[0xe8].nemonic, "INX");
    cpu->instructions[0xe8].cycles = 2;
    cpu->instructions[0xe8].cond_cycles = 0;
    cpu->instructions[0xe8].mode = IMP;
    cpu->instructions[0xe8].func = INX;
    cpu->instructions[0xe8].flags = 0b1000010;

    cpu->instructions[0xc8].opcode = 0xc8;
    cpu->instructions[0xc8].bytes = 1;
    strcpy(cpu->instructions[0xc8].nemonic, "INY");
    cpu->instructions[0xc8].cycles = 2;
    cpu->instructions[0xc8].cond_cycles = 0;
    cpu->instructions[0xc8].mode = IMP;
    cpu->instructions[0xc8].func = INY;
    cpu->instructions[0xc8].flags = 0b1000010;

    cpu->instructions[0x49].opcode = 0x49;
    cpu->instructions[0x49].bytes = 2;
    strcpy(cpu->instructions[0x49].nemonic, "EOR");
    cpu->instructions[0x49].cycles = 2;
    cpu->instructions[0x49].cond_cycles = 0;
    cpu->instructions[0x49].mode = IMM;
    cpu->instructions[0x49].func = EOR;
    cpu->instructions[0x49].flags = 0b1000010;

    cpu->instructions[0x45].opcode = 0x45;
    cpu->instructions[0x45].bytes = 2;
    strcpy(cpu->instructions[0x45].nemonic, "EOR");
    cpu->instructions[0x45].cycles = 3;
    cpu->instructions[0x45].cond_cycles = 0;
    cpu->instructions[0x45].mode = ZP;
    cpu->instructions[0x45].func = EOR;
    cpu->instructions[0x45].flags = 0b1000010;

    cpu->instructions[0x55].opcode = 0x55;
    cpu->instructions[0x55].bytes = 2;
    strcpy(cpu->instructions[0x55].nemonic, "EOR");
    cpu->instructions[0x55].cycles = 4;
    cpu->instructions[0x55].cond_cycles = 0;
    cpu->instructions[0x55].mode = ZPX;
    cpu->instructions[0x55].func = EOR;
    cpu->instructions[0x55].flags = 0b1000010;

    cpu->instructions[0x4d].opcode = 0x4d;
    cpu->instructions[0x4d].bytes = 3;
    strcpy(cpu->instructions[0x4d].nemonic, "EOR");
    cpu->instructions[0x4d].cycles = 4;
    cpu->instructions[0x4d].cond_cycles = 0;
    cpu->instructions[0x4d].mode = ABS;
    cpu->instructions[0x4d].func = EOR;
    cpu->instructions[0x4d].flags = 0b1000010;

    cpu->instructions[0x5d].opcode = 0x5d;
    cpu->instructions[0x5d].bytes = 3;
    strcpy(cpu->instructions[0x5d].nemonic, "EOR");
    cpu->instructions[0x5d].cycles = 4;
    cpu->instructions[0x5d].cond_cycles = 0;
    cpu->instructions[0x5d].mode = ABSX;
    cpu->instructions[0x5d].func = EOR;
    cpu->instructions[0x5d].flags = 0b1000010;

    cpu->instructions[0x59].opcode = 0x59;
    cpu->instructions[0x59].bytes = 3;
    strcpy(cpu->instructions[0x59].nemonic, "EOR");
    cpu->instructions[0x59].cycles = 4;
    cpu->instructions[0x59].cond_cycles = 0;
    cpu->instructions[0x59].mode = ABSY;
    cpu->instructions[0x59].func = EOR;
    cpu->instructions[0x59].flags = 0b1000010;

    cpu->instructions[0x41].opcode = 0x41;
    cpu->instructions[0x41].bytes = 2;
    strcpy(cpu->instructions[0x41].nemonic, "EOR");
    cpu->instructions[0x41].cycles = 6;
    cpu->instructions[0x41].cond_cycles = 0;
    cpu->instructions[0x41].mode = INDX;
    cpu->instructions[0x41].func = EOR;
    cpu->instructions[0x41].flags = 0b1000010;

    cpu->instructions[0x51].opcode = 0x51;
    cpu->instructions[0x51].bytes = 2;
    strcpy(cpu->instructions[0x51].nemonic, "EOR");
    cpu->instructions[0x51].cycles = 5;
    cpu->instructions[0x51].cond_cycles = 0;
    cpu->instructions[0x51].mode = INDY;
    cpu->instructions[0x51].func = EOR;
    cpu->instructions[0x51].flags = 0b1000010;

    cpu->instructions[0xe6].opcode = 0xe6;
    cpu->instructions[0xe6].bytes = 2;
    strcpy(cpu->instructions[0xe6].nemonic, "INC");
    cpu->instructions[0xe6].cycles = 5;
    cpu->instructions[0xe6].cond_cycles = 0;
    cpu->instructions[0xe6].mode = ZP;
    cpu->instructions[0xe6].func = INC;
    cpu->instructions[0xe6].flags = 0b1000010;

    cpu->instructions[0xf6].opcode = 0xf6;
    cpu->instructions[0xf6].bytes = 2;
    strcpy(cpu->instructions[0xf6].nemonic, "INC");
    cpu->instructions[0xf6].cycles = 6;
    cpu->instructions[0xf6].cond_cycles = 0;
    cpu->instructions[0xf6].mode = ZPX;
    cpu->instructions[0xf6].func = INC;
    cpu->instructions[0xf6].flags = 0b1000010;

    cpu->instructions[0xee].opcode = 0xee;
    cpu->instructions[0xee].bytes = 3;
    strcpy(cpu->instructions[0xee].nemonic, "INC");
    cpu->instructions[0xee].cycles = 6;
    cpu->instructions[0xee].cond_cycles = 0;
    cpu->instructions[0xee].mode = ABS;
    cpu->instructions[0xee].func = INC;
    cpu->instructions[0xee].flags = 0b1000010;

    cpu->instructions[0xfe].opcode = 0xfe;
    cpu->instructions[0xfe].bytes = 3;
    strcpy(cpu->instructions[0xfe].nemonic, "INC");
    cpu->instructions[0xfe].cycles = 7;
    cpu->instructions[0xfe].cond_cycles = 0;
    cpu->instructions[0xfe].mode = ABSX;
    cpu->instructions[0xfe].func = INC;
    cpu->instructions[0xfe].flags = 0b1000010;

    cpu->instructions[0x4c].opcode = 0x4c;
    cpu->instructions[0x4c].bytes = 3;
    strcpy(cpu->instructions[0x4c].nemonic, "JMP");
    cpu->instructions[0x4c].cycles = 3;
    cpu->instructions[0x4c].cond_cycles = 0;
    cpu->instructions[0x4c].mode = ABS;
    cpu->instructions[0x4c].func = JMP;
    cpu->instructions[0x4c].flags = 0b0;

    cpu->instructions[0x6c].opcode = 0x6c;
    cpu->instructions[0x6c].bytes = 3;
    strcpy(cpu->instructions[0x6c].nemonic, "JMP");
    cpu->instructions[0x6c].cycles = 5;
    cpu->instructions[0x6c].cond_cycles = 0;
    cpu->instructions[0x6c].mode = IND;
    cpu->instructions[0x6c].func = JMP;
    cpu->instructions[0x6c].flags = 0b0;

    cpu->instructions[0x20].opcode = 0x20;
    cpu->instructions[0x20].bytes = 3;
    strcpy(cpu->instructions[0x20].nemonic, "JSR");
    cpu->instructions[0x20].cycles = 6;
    cpu->instructions[0x20].cond_cycles = 0;
    cpu->instructions[0x20].mode = ABS;
    cpu->instructions[0x20].func = JSR;
    cpu->instructions[0x20].flags = 0b0;

    cpu->instructions[0xa9].opcode = 0xa9;
    cpu->instructions[0xa9].bytes = 2;
    strcpy(cpu->instructions[0xa9].nemonic, "LDA");
    cpu->instructions[0xa9].cycles = 2;
    cpu->instructions[0xa9].cond_cycles = 0;
    cpu->instructions[0xa9].mode = IMM;
    cpu->instructions[0xa9].func = LDA;
    cpu->instructions[0xa9].flags = 0b1000010;

    cpu->instructions[0xa5].opcode = 0xa5;
    cpu->instructions[0xa5].bytes = 2;
    strcpy(cpu->instructions[0xa5].nemonic, "LDA");
    cpu->instructions[0xa5].cycles = 3;
    cpu->instructions[0xa5].cond_cycles = 0;
    cpu->instructions[0xa5].mode = ZP;
    cpu->instructions[0xa5].func = LDA;
    cpu->instructions[0xa5].flags = 0b1000010;

    cpu->instructions[0xb5].opcode = 0xb5;
    cpu->instructions[0xb5].bytes = 2;
    strcpy(cpu->instructions[0xb5].nemonic, "LDA");
    cpu->instructions[0xb5].cycles = 4;
    cpu->instructions[0xb5].cond_cycles = 0;
    cpu->instructions[0xb5].mode = ZPX;
    cpu->instructions[0xb5].func = LDA;
    cpu->instructions[0xb5].flags = 0b1000010;

    cpu->instructions[0xad].opcode = 0xad;
    cpu->instructions[0xad].bytes = 3;
    strcpy(cpu->instructions[0xad].nemonic, "LDA");
    cpu->instructions[0xad].cycles = 4;
    cpu->instructions[0xad].cond_cycles = 0;
    cpu->instructions[0xad].mode = ABS;
    cpu->instructions[0xad].func = LDA;
    cpu->instructions[0xad].flags = 0b1000010;

    cpu->instructions[0xbd].opcode = 0xbd;
    cpu->instructions[0xbd].bytes = 3;
    strcpy(cpu->instructions[0xbd].nemonic, "LDA");
    cpu->instructions[0xbd].cycles = 4;
    cpu->instructions[0xbd].cond_cycles = 0;
    cpu->instructions[0xbd].mode = ABSX;
    cpu->instructions[0xbd].func = LDA;
    cpu->instructions[0xbd].flags = 0b1000010;

    cpu->instructions[0xb9].opcode = 0xb9;
    cpu->instructions[0xb9].bytes = 3;
    strcpy(cpu->instructions[0xb9].nemonic, "LDA");
    cpu->instructions[0xb9].cycles = 4;
    cpu->instructions[0xb9].cond_cycles = 0;
    cpu->instructions[0xb9].mode = ABSY;
    cpu->instructions[0xb9].func = LDA;
    cpu->instructions[0xb9].flags = 0b1000010;

    cpu->instructions[0xa1].opcode = 0xa1;
    cpu->instructions[0xa1].bytes = 2;
    strcpy(cpu->instructions[0xa1].nemonic, "LDA");
    cpu->instructions[0xa1].cycles = 6;
    cpu->instructions[0xa1].cond_cycles = 0;
    cpu->instructions[0xa1].mode = INDX;
    cpu->instructions[0xa1].func = LDA;
    cpu->instructions[0xa1].flags = 0b1000010;

    cpu->instructions[0xb1].opcode = 0xb1;
    cpu->instructions[0xb1].bytes = 2;
    strcpy(cpu->instructions[0xb1].nemonic, "LDA");
    cpu->instructions[0xb1].cycles = 5;
    cpu->instructions[0xb1].cond_cycles = 0;
    cpu->instructions[0xb1].mode = INDY;
    cpu->instructions[0xb1].func = LDA;
    cpu->instructions[0xb1].flags = 0b1000010;

    cpu->instructions[0xa2].opcode = 0xa2;
    cpu->instructions[0xa2].bytes = 2;
    strcpy(cpu->instructions[0xa2].nemonic, "LDX");
    cpu->instructions[0xa2].cycles = 2;
    cpu->instructions[0xa2].cond_cycles = 0;
    cpu->instructions[0xa2].mode = IMM;
    cpu->instructions[0xa2].func = LDX;
    cpu->instructions[0xa2].flags = 0b1000010;

    cpu->instructions[0xa6].opcode = 0xa6;
    cpu->instructions[0xa6].bytes = 2;
    strcpy(cpu->instructions[0xa6].nemonic, "LDX");
    cpu->instructions[0xa6].cycles = 3;
    cpu->instructions[0xa6].cond_cycles = 0;
    cpu->instructions[0xa6].mode = ZP;
    cpu->instructions[0xa6].func = LDX;
    cpu->instructions[0xa6].flags = 0b1000010;

    cpu->instructions[0xb6].opcode = 0xb6;
    cpu->instructions[0xb6].bytes = 2;
    strcpy(cpu->instructions[0xb6].nemonic, "LDX");
    cpu->instructions[0xb6].cycles = 4;
    cpu->instructions[0xb6].cond_cycles = 0;
    cpu->instructions[0xb6].mode = ZPY;
    cpu->instructions[0xb6].func = LDX;
    cpu->instructions[0xb6].flags = 0b1000010;

    cpu->instructions[0xae].opcode = 0xae;
    cpu->instructions[0xae].bytes = 3;
    strcpy(cpu->instructions[0xae].nemonic, "LDX");
    cpu->instructions[0xae].cycles = 4;
    cpu->instructions[0xae].cond_cycles = 0;
    cpu->instructions[0xae].mode = ABS;
    cpu->instructions[0xae].func = LDX;
    cpu->instructions[0xae].flags = 0b1000010;

    cpu->instructions[0xbe].opcode = 0xbe;
    cpu->instructions[0xbe].bytes = 3;
    strcpy(cpu->instructions[0xbe].nemonic, "LDX");
    cpu->instructions[0xbe].cycles = 4;
    cpu->instructions[0xbe].cond_cycles = 0;
    cpu->instructions[0xbe].mode = ABSY;
    cpu->instructions[0xbe].func = LDX;
    cpu->instructions[0xbe].flags = 0b1000010;

    cpu->instructions[0xa0].opcode = 0xa0;
    cpu->instructions[0xa0].bytes = 2;
    strcpy(cpu->instructions[0xa0].nemonic, "LDY");
    cpu->instructions[0xa0].cycles = 2;
    cpu->instructions[0xa0].cond_cycles = 0;
    cpu->instructions[0xa0].mode = IMM;
    cpu->instructions[0xa0].func = LDY;
    cpu->instructions[0xa0].flags = 0b1000010;

    cpu->instructions[0xa4].opcode = 0xa4;
    cpu->instructions[0xa4].bytes = 2;
    strcpy(cpu->instructions[0xa4].nemonic, "LDY");
    cpu->instructions[0xa4].cycles = 3;
    cpu->instructions[0xa4].cond_cycles = 0;
    cpu->instructions[0xa4].mode = ZP;
    cpu->instructions[0xa4].func = LDY;
    cpu->instructions[0xa4].flags = 0b1000010;

    cpu->instructions[0xb4].opcode = 0xb4;
    cpu->instructions[0xb4].bytes = 2;
    strcpy(cpu->instructions[0xb4].nemonic, "LDY");
    cpu->instructions[0xb4].cycles = 4;
    cpu->instructions[0xb4].cond_cycles = 0;
    cpu->instructions[0xb4].mode = ZPX;
    cpu->instructions[0xb4].func = LDY;
    cpu->instructions[0xb4].flags = 0b1000010;

    cpu->instructions[0xac].opcode = 0xac;
    cpu->instructions[0xac].bytes = 3;
    strcpy(cpu->instructions[0xac].nemonic, "LDY");
    cpu->instructions[0xac].cycles = 4;
    cpu->instructions[0xac].cond_cycles = 0;
    cpu->instructions[0xac].mode = ABS;
    cpu->instructions[0xac].func = LDY;
    cpu->instructions[0xac].flags = 0b1000010;

    cpu->instructions[0xbc].opcode = 0xbc;
    cpu->instructions[0xbc].bytes = 3;
    strcpy(cpu->instructions[0xbc].nemonic, "LDY");
    cpu->instructions[0xbc].cycles = 4;
    cpu->instructions[0xbc].cond_cycles = 0;
    cpu->instructions[0xbc].mode = ABSX;
    cpu->instructions[0xbc].func = LDY;
    cpu->instructions[0xbc].flags = 0b1000010;

    cpu->instructions[0x4a].opcode = 0x4a;
    cpu->instructions[0x4a].bytes = 1;
    strcpy(cpu->instructions[0x4a].nemonic, "LSR");
    cpu->instructions[0x4a].cycles = 2;
    cpu->instructions[0x4a].cond_cycles = 0;
    cpu->instructions[0x4a].mode = ACC;
    cpu->instructions[0x4a].func = LSR;
    cpu->instructions[0x4a].flags = 0b1000011;

    cpu->instructions[0x46].opcode = 0x46;
    cpu->instructions[0x46].bytes = 2;
    strcpy(cpu->instructions[0x46].nemonic, "LSR");
    cpu->instructions[0x46].cycles = 5;
    cpu->instructions[0x46].cond_cycles = 0;
    cpu->instructions[0x46].mode = ZP;
    cpu->instructions[0x46].func = LSR;
    cpu->instructions[0x46].flags = 0b1000011;

    cpu->instructions[0x56].opcode = 0x56;
    cpu->instructions[0x56].bytes = 2;
    strcpy(cpu->instructions[0x56].nemonic, "LSR");
    cpu->instructions[0x56].cycles = 6;
    cpu->instructions[0x56].cond_cycles = 0;
    cpu->instructions[0x56].mode = ZPX;
    cpu->instructions[0x56].func = LSR;
    cpu->instructions[0x56].flags = 0b1000011;

    cpu->instructions[0x4e].opcode = 0x4e;
    cpu->instructions[0x4e].bytes = 3;
    strcpy(cpu->instructions[0x4e].nemonic, "LSR");
    cpu->instructions[0x4e].cycles = 6;
    cpu->instructions[0x4e].cond_cycles = 0;
    cpu->instructions[0x4e].mode = ABS;
    cpu->instructions[0x4e].func = LSR;
    cpu->instructions[0x4e].flags = 0b1000011;

    cpu->instructions[0x5e].opcode = 0x5e;
    cpu->instructions[0x5e].bytes = 3;
    strcpy(cpu->instructions[0x5e].nemonic, "LSR");
    cpu->instructions[0x5e].cycles = 7;
    cpu->instructions[0x5e].cond_cycles = 0;
    cpu->instructions[0x5e].mode = ABSX;
    cpu->instructions[0x5e].func = LSR;
    cpu->instructions[0x5e].flags = 0b1000011;

    cpu->instructions[0x9].opcode = 0x9;
    cpu->instructions[0x9].bytes = 2;
    strcpy(cpu->instructions[0x9].nemonic, "ORA");
    cpu->instructions[0x9].cycles = 2;
    cpu->instructions[0x9].cond_cycles = 0;
    cpu->instructions[0x9].mode = IMM;
    cpu->instructions[0x9].func = ORA;
    cpu->instructions[0x9].flags = 0b1000010;

    cpu->instructions[0x5].opcode = 0x5;
    cpu->instructions[0x5].bytes = 2;
    strcpy(cpu->instructions[0x5].nemonic, "ORA");
    cpu->instructions[0x5].cycles = 3;
    cpu->instructions[0x5].cond_cycles = 0;
    cpu->instructions[0x5].mode = ZP;
    cpu->instructions[0x5].func = ORA;
    cpu->instructions[0x5].flags = 0b1000010;

    cpu->instructions[0x15].opcode = 0x15;
    cpu->instructions[0x15].bytes = 2;
    strcpy(cpu->instructions[0x15].nemonic, "ORA");
    cpu->instructions[0x15].cycles = 4;
    cpu->instructions[0x15].cond_cycles = 0;
    cpu->instructions[0x15].mode = ZPX;
    cpu->instructions[0x15].func = ORA;
    cpu->instructions[0x15].flags = 0b1000010;

    cpu->instructions[0xd].opcode = 0xd;
    cpu->instructions[0xd].bytes = 3;
    strcpy(cpu->instructions[0xd].nemonic, "ORA");
    cpu->instructions[0xd].cycles = 4;
    cpu->instructions[0xd].cond_cycles = 0;
    cpu->instructions[0xd].mode = ABS;
    cpu->instructions[0xd].func = ORA;
    cpu->instructions[0xd].flags = 0b1000010;

    cpu->instructions[0x1d].opcode = 0x1d;
    cpu->instructions[0x1d].bytes = 3;
    strcpy(cpu->instructions[0x1d].nemonic, "ORA");
    cpu->instructions[0x1d].cycles = 4;
    cpu->instructions[0x1d].cond_cycles = 0;
    cpu->instructions[0x1d].mode = ABSX;
    cpu->instructions[0x1d].func = ORA;
    cpu->instructions[0x1d].flags = 0b1000010;

    cpu->instructions[0x19].opcode = 0x19;
    cpu->instructions[0x19].bytes = 3;
    strcpy(cpu->instructions[0x19].nemonic, "ORA");
    cpu->instructions[0x19].cycles = 4;
    cpu->instructions[0x19].cond_cycles = 0;
    cpu->instructions[0x19].mode = ABSY;
    cpu->instructions[0x19].func = ORA;
    cpu->instructions[0x19].flags = 0b1000010;

    cpu->instructions[0x1].opcode = 0x1;
    cpu->instructions[0x1].bytes = 2;
    strcpy(cpu->instructions[0x1].nemonic, "ORA");
    cpu->instructions[0x1].cycles = 6;
    cpu->instructions[0x1].cond_cycles = 0;
    cpu->instructions[0x1].mode = INDX;
    cpu->instructions[0x1].func = ORA;
    cpu->instructions[0x1].flags = 0b1000010;

    cpu->instructions[0x11].opcode = 0x11;
    cpu->instructions[0x11].bytes = 2;
    strcpy(cpu->instructions[0x11].nemonic, "ORA");
    cpu->instructions[0x11].cycles = 5;
    cpu->instructions[0x11].cond_cycles = 0;
    cpu->instructions[0x11].mode = INDY;
    cpu->instructions[0x11].func = ORA;
    cpu->instructions[0x11].flags = 0b1000010;

    cpu->instructions[0x2a].opcode = 0x2a;
    cpu->instructions[0x2a].bytes = 1;
    strcpy(cpu->instructions[0x2a].nemonic, "ROL");
    cpu->instructions[0x2a].cycles = 2;
    cpu->instructions[0x2a].cond_cycles = 0;
    cpu->instructions[0x2a].mode = ACC;
    cpu->instructions[0x2a].func = ROL;
    cpu->instructions[0x2a].flags = 0b1000011;

    cpu->instructions[0x26].opcode = 0x26;
    cpu->instructions[0x26].bytes = 2;
    strcpy(cpu->instructions[0x26].nemonic, "ROL");
    cpu->instructions[0x26].cycles = 5;
    cpu->instructions[0x26].cond_cycles = 0;
    cpu->instructions[0x26].mode = ZP;
    cpu->instructions[0x26].func = ROL;
    cpu->instructions[0x26].flags = 0b1000011;

    cpu->instructions[0x36].opcode = 0x36;
    cpu->instructions[0x36].bytes = 2;
    strcpy(cpu->instructions[0x36].nemonic, "ROL");
    cpu->instructions[0x36].cycles = 6;
    cpu->instructions[0x36].cond_cycles = 0;
    cpu->instructions[0x36].mode = ZPX;
    cpu->instructions[0x36].func = ROL;
    cpu->instructions[0x36].flags = 0b1000011;

    cpu->instructions[0x2e].opcode = 0x2e;
    cpu->instructions[0x2e].bytes = 3;
    strcpy(cpu->instructions[0x2e].nemonic, "ROL");
    cpu->instructions[0x2e].cycles = 6;
    cpu->instructions[0x2e].cond_cycles = 0;
    cpu->instructions[0x2e].mode = ABS;
    cpu->instructions[0x2e].func = ROL;
    cpu->instructions[0x2e].flags = 0b1000011;

    cpu->instructions[0x3e].opcode = 0x3e;
    cpu->instructions[0x3e].bytes = 3;
    strcpy(cpu->instructions[0x3e].nemonic, "ROL");
    cpu->instructions[0x3e].cycles = 7;
    cpu->instructions[0x3e].cond_cycles = 0;
    cpu->instructions[0x3e].mode = ABSX;
    cpu->instructions[0x3e].func = ROL;
    cpu->instructions[0x3e].flags = 0b1000011;

    cpu->instructions[0x6a].opcode = 0x6a;
    cpu->instructions[0x6a].bytes = 1;
    strcpy(cpu->instructions[0x6a].nemonic, "ROR");
    cpu->instructions[0x6a].cycles = 2;
    cpu->instructions[0x6a].cond_cycles = 0;
    cpu->instructions[0x6a].mode = ACC;
    cpu->instructions[0x6a].func = ROR;
    cpu->instructions[0x6a].flags = 0b1000011;

    cpu->instructions[0x66].opcode = 0x66;
    cpu->instructions[0x66].bytes = 2;
    strcpy(cpu->instructions[0x66].nemonic, "ROR");
    cpu->instructions[0x66].cycles = 5;
    cpu->instructions[0x66].cond_cycles = 0;
    cpu->instructions[0x66].mode = ZP;
    cpu->instructions[0x66].func = ROR;
    cpu->instructions[0x66].flags = 0b1000011;

    cpu->instructions[0x76].opcode = 0x76;
    cpu->instructions[0x76].bytes = 2;
    strcpy(cpu->instructions[0x76].nemonic, "ROR");
    cpu->instructions[0x76].cycles = 6;
    cpu->instructions[0x76].cond_cycles = 0;
    cpu->instructions[0x76].mode = ZPX;
    cpu->instructions[0x76].func = ROR;
    cpu->instructions[0x76].flags = 0b1000011;

    cpu->instructions[0x7e].opcode = 0x7e;
    cpu->instructions[0x7e].bytes = 3;
    strcpy(cpu->instructions[0x7e].nemonic, "ROR");
    cpu->instructions[0x7e].cycles = 6;
    cpu->instructions[0x7e].cond_cycles = 0;
    cpu->instructions[0x7e].mode = ABS;
    cpu->instructions[0x7e].func = ROR;
    cpu->instructions[0x7e].flags = 0b1000011;

    cpu->instructions[0x6e].opcode = 0x6e;
    cpu->instructions[0x6e].bytes = 3;
    strcpy(cpu->instructions[0x6e].nemonic, "ROR");
    cpu->instructions[0x6e].cycles = 7;
    cpu->instructions[0x6e].cond_cycles = 0;
    cpu->instructions[0x6e].mode = ABSX;
    cpu->instructions[0x6e].func = ROR;
    cpu->instructions[0x6e].flags = 0b1000011;

    cpu->instructions[0xe9].opcode = 0xe9;
    cpu->instructions[0xe9].bytes = 2;
    strcpy(cpu->instructions[0xe9].nemonic, "SBC");
    cpu->instructions[0xe9].cycles = 2;
    cpu->instructions[0xe9].cond_cycles = 0;
    cpu->instructions[0xe9].mode = IMM;
    cpu->instructions[0xe9].func = SBC;
    cpu->instructions[0xe9].flags = 0b1100011;

    cpu->instructions[0xe5].opcode = 0xe5;
    cpu->instructions[0xe5].bytes = 2;
    strcpy(cpu->instructions[0xe5].nemonic, "SBC");
    cpu->instructions[0xe5].cycles = 3;
    cpu->instructions[0xe5].cond_cycles = 0;
    cpu->instructions[0xe5].mode = ZP;
    cpu->instructions[0xe5].func = SBC;
    cpu->instructions[0xe5].flags = 0b1100011;

    cpu->instructions[0xf5].opcode = 0xf5;
    cpu->instructions[0xf5].bytes = 2;
    strcpy(cpu->instructions[0xf5].nemonic, "SBC");
    cpu->instructions[0xf5].cycles = 4;
    cpu->instructions[0xf5].cond_cycles = 0;
    cpu->instructions[0xf5].mode = ZPX;
    cpu->instructions[0xf5].func = SBC;
    cpu->instructions[0xf5].flags = 0b1100011;

    cpu->instructions[0xed].opcode = 0xed;
    cpu->instructions[0xed].bytes = 3;
    strcpy(cpu->instructions[0xed].nemonic, "SBC");
    cpu->instructions[0xed].cycles = 4;
    cpu->instructions[0xed].cond_cycles = 0;
    cpu->instructions[0xed].mode = ABS;
    cpu->instructions[0xed].func = SBC;
    cpu->instructions[0xed].flags = 0b1100011;

    cpu->instructions[0xfd].opcode = 0xfd;
    cpu->instructions[0xfd].bytes = 3;
    strcpy(cpu->instructions[0xfd].nemonic, "SBC");
    cpu->instructions[0xfd].cycles = 4;
    cpu->instructions[0xfd].cond_cycles = 0;
    cpu->instructions[0xfd].mode = ABSX;
    cpu->instructions[0xfd].func = SBC;
    cpu->instructions[0xfd].flags = 0b1100011;

    cpu->instructions[0xf9].opcode = 0xf9;
    cpu->instructions[0xf9].bytes = 3;
    strcpy(cpu->instructions[0xf9].nemonic, "SBC");
    cpu->instructions[0xf9].cycles = 4;
    cpu->instructions[0xf9].cond_cycles = 0;
    cpu->instructions[0xf9].mode = ABSY;
    cpu->instructions[0xf9].func = SBC;
    cpu->instructions[0xf9].flags = 0b1100011;

    cpu->instructions[0xe1].opcode = 0xe1;
    cpu->instructions[0xe1].bytes = 2;
    strcpy(cpu->instructions[0xe1].nemonic, "SBC");
    cpu->instructions[0xe1].cycles = 6;
    cpu->instructions[0xe1].cond_cycles = 0;
    cpu->instructions[0xe1].mode = INDX;
    cpu->instructions[0xe1].func = SBC;
    cpu->instructions[0xe1].flags = 0b1100011;

    cpu->instructions[0xf1].opcode = 0xf1;
    cpu->instructions[0xf1].bytes = 2;
    strcpy(cpu->instructions[0xf1].nemonic, "SBC");
    cpu->instructions[0xf1].cycles = 5;
    cpu->instructions[0xf1].cond_cycles = 0;
    cpu->instructions[0xf1].mode = INDY;
    cpu->instructions[0xf1].func = SBC;
    cpu->instructions[0xf1].flags = 0b1100011;

    cpu->instructions[0x85].opcode = 0x85;
    cpu->instructions[0x85].bytes = 2;
    strcpy(cpu->instructions[0x85].nemonic, "STA");
    cpu->instructions[0x85].cycles = 3;
    cpu->instructions[0x85].cond_cycles = 0;
    cpu->instructions[0x85].mode = ZP;
    cpu->instructions[0x85].func = STA;
    cpu->instructions[0x85].flags = 0b0;

    cpu->instructions[0x95].opcode = 0x95;
    cpu->instructions[0x95].bytes = 2;
    strcpy(cpu->instructions[0x95].nemonic, "STA");
    cpu->instructions[0x95].cycles = 4;
    cpu->instructions[0x95].cond_cycles = 0;
    cpu->instructions[0x95].mode = ZPX;
    cpu->instructions[0x95].func = STA;
    cpu->instructions[0x95].flags = 0b0;

    cpu->instructions[0x8d].opcode = 0x8d;
    cpu->instructions[0x8d].bytes = 3;
    strcpy(cpu->instructions[0x8d].nemonic, "STA");
    cpu->instructions[0x8d].cycles = 4;
    cpu->instructions[0x8d].cond_cycles = 0;
    cpu->instructions[0x8d].mode = ABS;
    cpu->instructions[0x8d].func = STA;
    cpu->instructions[0x8d].flags = 0b0;

    cpu->instructions[0x9d].opcode = 0x9d;
    cpu->instructions[0x9d].bytes = 3;
    strcpy(cpu->instructions[0x9d].nemonic, "STA");
    cpu->instructions[0x9d].cycles = 5;
    cpu->instructions[0x9d].cond_cycles = 0;
    cpu->instructions[0x9d].mode = ABSX;
    cpu->instructions[0x9d].func = STA;
    cpu->instructions[0x9d].flags = 0b0;

    cpu->instructions[0x99].opcode = 0x99;
    cpu->instructions[0x99].bytes = 3;
    strcpy(cpu->instructions[0x99].nemonic, "STA");
    cpu->instructions[0x99].cycles = 5;
    cpu->instructions[0x99].cond_cycles = 0;
    cpu->instructions[0x99].mode = ABSY;
    cpu->instructions[0x99].func = STA;
    cpu->instructions[0x99].flags = 0b0;

    cpu->instructions[0x81].opcode = 0x81;
    cpu->instructions[0x81].bytes = 2;
    strcpy(cpu->instructions[0x81].nemonic, "STA");
    cpu->instructions[0x81].cycles = 6;
    cpu->instructions[0x81].cond_cycles = 0;
    cpu->instructions[0x81].mode = INDX;
    cpu->instructions[0x81].func = STA;
    cpu->instructions[0x81].flags = 0b0;

    cpu->instructions[0x91].opcode = 0x91;
    cpu->instructions[0x91].bytes = 2;
    strcpy(cpu->instructions[0x91].nemonic, "STA");
    cpu->instructions[0x91].cycles = 6;
    cpu->instructions[0x91].cond_cycles = 0;
    cpu->instructions[0x91].mode = INDY;
    cpu->instructions[0x91].func = STA;
    cpu->instructions[0x91].flags = 0b0;

    cpu->instructions[0x86].opcode = 0x86;
    cpu->instructions[0x86].bytes = 2;
    strcpy(cpu->instructions[0x86].nemonic, "STX");
    cpu->instructions[0x86].cycles = 3;
    cpu->instructions[0x86].cond_cycles = 0;
    cpu->instructions[0x86].mode = ZP;
    cpu->instructions[0x86].func = STX;
    cpu->instructions[0x86].flags = 0b0;

    cpu->instructions[0x96].opcode = 0x96;
    cpu->instructions[0x96].bytes = 2;
    strcpy(cpu->instructions[0x96].nemonic, "STX");
    cpu->instructions[0x96].cycles = 4;
    cpu->instructions[0x96].cond_cycles = 0;
    cpu->instructions[0x96].mode = ZPY;
    cpu->instructions[0x96].func = STX;
    cpu->instructions[0x96].flags = 0b0;

    cpu->instructions[0x8e].opcode = 0x8e;
    cpu->instructions[0x8e].bytes = 3;
    strcpy(cpu->instructions[0x8e].nemonic, "STX");
    cpu->instructions[0x8e].cycles = 4;
    cpu->instructions[0x8e].cond_cycles = 0;
    cpu->instructions[0x8e].mode = ABS;
    cpu->instructions[0x8e].func = STX;
    cpu->instructions[0x8e].flags = 0b0;

    cpu->instructions[0x84].opcode = 0x84;
    cpu->instructions[0x84].bytes = 2;
    strcpy(cpu->instructions[0x84].nemonic, "STY");
    cpu->instructions[0x84].cycles = 3;
    cpu->instructions[0x84].cond_cycles = 0;
    cpu->instructions[0x84].mode = ZP;
    cpu->instructions[0x84].func = STY;
    cpu->instructions[0x84].flags = 0b0;

    cpu->instructions[0x94].opcode = 0x94;
    cpu->instructions[0x94].bytes = 2;
    strcpy(cpu->instructions[0x94].nemonic, "STY");
    cpu->instructions[0x94].cycles = 4;
    cpu->instructions[0x94].cond_cycles = 0;
    cpu->instructions[0x94].mode = ZPX;
    cpu->instructions[0x94].func = STY;
    cpu->instructions[0x94].flags = 0b0;

    cpu->instructions[0x8c].opcode = 0x8c;
    cpu->instructions[0x8c].bytes = 3;
    strcpy(cpu->instructions[0x8c].nemonic, "STY");
    cpu->instructions[0x8c].cycles = 4;
    cpu->instructions[0x8c].cond_cycles = 0;
    cpu->instructions[0x8c].mode = ABS;
    cpu->instructions[0x8c].func = STY;
    cpu->instructions[0x8c].flags = 0b0;
}

uint16_t get_addrmode_val(struct cpu6502* cpu, struct instruction* ins)
{
    uint8_t byte1 = get_mem(cpu->nes, cpu->pc + 1);
    uint8_t byte2 = get_mem(cpu->nes, cpu->pc + 2);
    uint16_t address = (byte2 << 8) | byte1;

    switch (ins->mode)
    {
        case REL:
            return cpu->pc + (int8_t)byte1 + ins->bytes;
        break;

        case IMM:
            if (ins->bytes == 2)
                return byte1;
            else
                return address;
        break;

        case ABS:
            return address;
        break;

        case ZP:
            return byte1;
        break;

        case IND:
        {
            if (byte1 == 0xff)
                return (get_mem(cpu->nes, address & 0xff00) << 8) | get_mem(cpu->nes, address);
            else
                return (get_mem(cpu->nes, address + 1) << 8) | get_mem(cpu->nes, address);
        }
        break;

        case ABSX:
            return address + cpu->x;
        break;

        case ABSY:
            return address + cpu->y;
        break;

        case ZPX:
            return byte1 + cpu->x;
        break;

        case ZPY:
            return byte1 + cpu->y;
        break;

        case INDX:
            return (get_mem(cpu->nes, byte1 + cpu->x + 1) << 8) | get_mem(cpu->nes, byte1 + cpu->x);
        break;

        case INDY:
            return ((get_mem(cpu->nes, byte1 + 1) << 8) | get_mem(cpu->nes, byte1) + cpu->y);
        break;
    }
}

uint16_t disassemble6502(struct cpu6502* cpu)
{
    struct instruction ins = cpu->instructions[get_mem(cpu->nes, cpu->pc)];
    printf("$%04x  %s", cpu->pc, ins.nemonic);

    uint8_t byte1 = get_mem(cpu->nes, cpu->pc + 1);
    uint8_t byte2 = get_mem(cpu->nes, cpu->pc + 2);
    uint16_t address = (byte2 << 8) | byte1;

    switch (ins.mode)
    {
        case REL:
            printf(" $%04x", cpu->pc + (int8_t)byte1 + ins.bytes);
        break;

        case IMM:
            if (ins.bytes == 2)
                printf(" #$%02x", byte1);
            else
                printf(" #$%04x", address);
        break;

        case ABS:
            printf(" $%04x", address);
        break;

        case ZP:
            printf(" $%02x", byte1);
        break;

        case IND:
            printf(" ($%04x)", address);
        break;

        case ABSX:
            printf(" $%04x,X", address);
        break;

        case ABSY:
            printf(" $%04x,Y", address);
        break;

        case ZPX:
            printf(" $%02x,X", byte1);
        break;

        case ZPY:
            printf(" $%02x,Y", byte1);
        break;

        case INDX:
            printf(" ($%02x,X)", byte1);
        break;

        case INDY:
            printf(" ($%02x),Y", byte1);
        break;
    }
    
    return ins.bytes;
}

void push_st_dir(struct cpu6502* cpu, uint8_t* dir)
{
    set_mem(cpu->nes, 0x0100 | cpu->sp, *dir);
    cpu->sp--;
}

void push_st_val(struct cpu6502* cpu, uint8_t val)
{
    set_mem(cpu->nes, 0x0100 | cpu->sp, val);
    cpu->sp--;
}

uint8_t pop_st(struct cpu6502* cpu)
{
    cpu->sp++;
    return get_mem(cpu->nes, 0x0100 | cpu->sp);
}

void emulate_cycle6502(struct cpu6502* cpu)
{
    disassemble6502(cpu);
    struct instruction* ins = &cpu->instructions[get_mem(cpu->nes, cpu->pc)];
    
    /*char statebits[9];
    statebits[8] = 0;

    for (int i = 0; i < 8; i++)
    {
        if (cpu->s & (1 << i))
            statebits[7 - i] = '1';
        else
            statebits[7 - i] = '0';
    }*/

    printf("\t\tA = $%02x  X = $%02x  Y = $%02x  P = $%02x  SP = $%02x\n",
        cpu->a, cpu->x, cpu->y, cpu->s, cpu->sp);

    ins->func(cpu, ins);
}

void print_stack(struct cpu6502* cpu, uint8_t all_stack)
{
    int newln = 0;
    printf("$ff\t");

    for (int i = 0xff; i > (all_stack? 0 : cpu->sp); i--)
    {
        if (newln == 10)
        {
            printf("\n$%02x\t", i & 0xff);
            newln = 0;
        }
        
        printf("$%02x  ", get_mem(cpu->nes, 0x0100 | i));
        newln++;
    }
}

void assemble6502(char* text, char* out, uint64_t* size)
{
}
