#ifndef CPU6502_H
#define CPU6502_H

#ifdef __cplusplus
extern "C" {
#endif

#include <stdint.h>

#define FREQ_6502 1790000
#define OP_NUM 256
#define IRQ_VEC 0xfffe

#define set_state_carry(cpu, val) (cpu->s ^= (-(unsigned long)val ^ cpu->s) & 1UL)
#define set_state_zero(cpu, val) (cpu->s ^= (-(unsigned long)val ^ cpu->s) & (1UL << 1))
#define set_state_int(cpu, val) (cpu->s ^= (-(unsigned long)val ^ cpu->s) & (1UL << 2))
#define set_state_dec(cpu, val) (cpu->s ^= (-(unsigned long)val ^ cpu->s) & (1UL << 3))
#define set_state_brk(cpu, val) (cpu->s ^= (-(unsigned long)val ^ cpu->s) & (1UL << 4))
#define set_state_five(cpu, val) (cpu->s ^= (-(unsigned long)val ^ cpu->s) & (1UL << 5))
#define set_state_overf(cpu, val) (cpu->s ^= (-(unsigned long)val ^ cpu->s) & (1UL << 6))
#define set_state_neg(cpu, val) (cpu->s ^= (-(unsigned long)val ^ cpu->s) & (1UL << 7))

#define get_state_carry(cpu) (cpu->s & 1)
#define get_state_zero(cpu) ((cpu->s >> 1) & 1)
#define get_state_int(cpu) ((cpu->s >> 2) & 1)
#define get_state_dec(cpu) ((cpu->s >> 3) & 1)
#define get_state_brk(cpu) ((cpu->s >> 4) & 1)
#define get_state_five(cpu) ((cpu->s >> 5) & 1)
#define get_state_overf(cpu) ((cpu->s >> 6) & 1)
#define get_state_neg(cpu) ((cpu->s >> 7) & 1)


enum addressing_mode
{
    IMM, ZP, ZPX, ZPY, ABS, ABSX,
    ABSY, IND, INDX, INDY, REL, IMP, ACC
};

struct cpu6502;

struct instruction
{
    char nemonic[4];
    enum addressing_mode mode;
    uint8_t opcode;
    uint8_t bytes;
    uint8_t cycles;
    uint8_t cond_cycles;
    uint8_t flags;
    void (*func)(struct cpu6502*, struct instruction*);
};

struct cpu6502
{
    uint8_t running:1;

    uint8_t a;
    uint8_t x;
    uint8_t y;
    uint8_t s;

    uint8_t sp;
    uint16_t pc;

    uint8_t wait_cycles;

    struct instruction instructions[OP_NUM];
    struct nesmachine* nes;
};

void init6502(struct cpu6502* cpu, struct nesmachine* nes);
uint16_t disassemble6502(struct cpu6502* cpu);
void emulate_cycle6502(struct cpu6502* cpu);
void assemble6502(char* text, char* out, uint64_t* size);
void push_st_dir(struct cpu6502* cpu, uint8_t* dir);
void push_st_val(struct cpu6502* cpu, uint8_t val);
uint8_t pop_st(struct cpu6502* cpu);
void print_stack(struct cpu6502* cpu, uint8_t all_stack);
uint16_t get_addrmode_val(struct cpu6502* cpu, struct instruction* ins);

#ifdef __cplusplus
}
#endif

#endif
