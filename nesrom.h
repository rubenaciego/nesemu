#ifndef NESROM_H
#define NESROM_H

#ifdef __cplusplus
extern "C" {
#endif

#include <stdint.h>

#define NES_MEMORY 0xffff
#define KB_SIZE 1024

struct nesflags6
{
    uint8_t flags;
};

struct nesheader
{
    char nesstr[4];
    uint8_t num_pgr_rom;
    uint8_t num_chr_rom;
    struct nesflags6 flags6;
    uint8_t flags7;
    uint8_t flags8;
    uint8_t flags9;
    uint8_t flags10;
    uint8_t unused[5];
};

struct nesrom
{
    uint8_t* file_mem;
    uint64_t file_size;
    struct nesheader* header;
    uint8_t* prg_rom;
};

void load_rom(struct nesrom* rom, char* file);

#ifdef __cplusplus
}
#endif

#endif
