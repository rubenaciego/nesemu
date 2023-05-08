#ifndef NESMACHINE_H
#define NESMACHINE_H

#ifdef __cplusplus
extern "C" {
#endif

#include <cpu6502.h>
#include <nesrom.h>

#define NES_MEMORY 0xffff

struct nesmachine
{
    uint8_t* memory;
    struct cpu6502 cpu;
    struct nesrom rom;
};

void init_nes(struct nesmachine* nes, char* rom);
void update_nes(struct nesmachine* nes);
void clean_nes(struct nesmachine* nes);
uint8_t get_mem(struct nesmachine* nes, uint16_t loc);
void set_mem(struct nesmachine* nes, uint16_t loc, uint8_t val);

#ifdef __cplusplus
}
#endif

#endif
