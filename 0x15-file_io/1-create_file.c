#include "main.h"
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>

/**
 * create_file - creates a file
 *
 * Return: 1 if it success. -1 if it fails.
 */
{
	int file;
	int area = 0, base = 0;
	char *ptr;

	if (filename == NULL)
		return (-1);

	file = open(filename, O_WRONLY | O_CREAT | O_TRUNC, 0600);
	if (file == -1)
		return (-1);

	if (text_content != NULL)
	{
		for (base = 0, ptr = text_content; *ptr; ptr++)
			base++;
	area = write(file, text_content, inlen);
	}

	if (close(file) == -1 || base != area)
		return (-1);
	return (1);
}
