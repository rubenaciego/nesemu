#include "nesmachine.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

void init_memory(struct nesmachine* nes, struct nesheader* header)
{
    nes->memory = malloc(NES_MEMORY);
}

uint8_t get_mem(struct nesmachine* nes, uint16_t loc)
{
    if (loc >= 0x800 && loc < 0x1000)
        return nes->memory[loc - 0x800];
    else if (loc >= 0x1000 && loc < 0x1800)
        return nes->memory[loc - 0x800];
    else if (loc >= 0x2008 && loc < 0x4000)
        return nes->memory[0x2000 + (loc - 0x2008) % 8];
    else if (loc >= 0xc000)
        return nes->memory[loc - 0x4000];
    else
        return nes->memory[loc];
}

void set_mem(struct nesmachine* nes, uint16_t loc, uint8_t val)
{
    int location;
    if (loc >= 0x800 && loc < 0x1000)
        location = loc - 0x800;
    else if (loc >= 0x1000 && loc < 0x1800)
        location = loc - 0x800;
    else if (loc >= 0x2008 && loc < 0x4000)
        location = 0x2000 + (loc - 0x2008) % 8;
    else if (loc >= 0xc000)
        location = loc - 0x4000;
    else
        location = loc;
    
    nes->memory[location] = val;
}

void init_nes(struct nesmachine* nes, char* rom)
{
    init_memory(nes, nes->rom.header);
    load_rom(&nes->rom, rom);
	init6502(&nes->cpu, nes);
	nes->cpu.pc = 0xC000;

    memcpy(nes->memory + 0x8000, nes->rom.prg_rom, 16 * KB_SIZE * nes->rom.header->num_pgr_rom);
}

void update_nes(struct nesmachine* nes)
{
    while (nes->cpu.running && nes->cpu.pc < NES_MEMORY)
		emulate_cycle6502(&nes->cpu);
}

void clean_nes(struct nesmachine* nes)
{
    printf("\n\n$02 = $%02x  $03 = $%02x\n", nes->memory[0x2], nes->memory[0x3]);

    free(nes->memory);
    free(nes->rom.file_mem);
}
