#include "nesrom.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

uint8_t* load_file(uint64_t* fsize, char* filename)
{	
	FILE* file = fopen(filename, "rb");
	if (file == NULL)
	{
		printf("File error: %s\n", filename);
		exit(-1);
	}

	fseek(file, 0, SEEK_END);
	*fsize = ftell(file);
	rewind(file);

	uint8_t* buffer = (uint8_t*)malloc(*fsize);

	size_t result = fread(buffer, 1, *fsize, file);
	if (result != *fsize) 
	{
		printf("Reading error\n");
		exit(-1);
	}

	fclose(file);

    return buffer;
}

void load_rom(struct nesrom* rom, char* file)
{
	rom->file_mem = load_file(&rom->file_size, file);
    rom->header = (struct nesheader*)rom->file_mem;
    rom->prg_rom = (uint8_t*)(rom->header) + sizeof(struct nesheader);
}
