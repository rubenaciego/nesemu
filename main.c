#include <stdio.h>
#include <nesmachine.h>

int main(int argc, char* argv[])
{
	if (argc != 2)
	{
		printf("No NES ROM specified\n");
		return -1;
	}

	struct nesmachine nes;
	init_nes(&nes, argv[1]);

	update_nes(&nes);
	clean_nes(&nes);

    return 0;
}
