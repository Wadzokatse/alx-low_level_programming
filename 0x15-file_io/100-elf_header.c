#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <elf.h>

/**
 * print_addr - prints address
 * @ptr: magic.
 * Return: no return.
 */
void print_addr(char *ptr)
{
	int a;
	int begin;
	char sys;

	printf("  Entry point address:               0x");

	sys = ptr[4] + '0';
	if (sys == '1')
	{
		begin = 26;
		printf("80");
		for (a = begin; a >= 22; a--)
		{
			if (ptr[a] > 0)
				printf("%x", ptr[a]);
			else if (ptr[a] < 0)
				printf("%x", 256 + ptr[a]);
		}
		if (ptr[7] == 6)
			printf("00");
	}

	if (sys == '2')
	{
		begin = 26;
		for (a = begin; a > 23; a--)
		{
			if (ptr[a] >= 0)
				printf("%02x", ptr[a]);

			else if (ptr[a] < 0)
				printf("%02x", 256 + ptr[a]);

		}
	}
	printf("\n");
}

/**
 * print_type - prints type
 * @ptr: magic.
 * Return: no return.
 */
void print_type(char *ptr)
{
	char type = ptr[16];

	if (ptr[5] == 1)
		type = ptr[16];
	else
		type = ptr[17];

	printf("  Type:                              ");
	if (type == 0)
		printf("NONE (No file type)\n");
	else if (type == 1)
		printf("REL (Relocatable file)\n");
	else if (type == 2)
		printf("EXEC (Executable file)\n");
	else if (type == 3)
		printf("DYN (Shared object file)\n");
	else if (type == 4)
		printf("CORE (Core file)\n");
	else
		printf("<unknown: %x>\n", type);
}

