#include "main.h"

/**
 * create_file - creates a file
 *
 * Return: 1 if it success. -1 if it fails.
 */
int create_file(const char *filename, char *text_content)
{
	int alx;
	int nlen;
	int rwr;

	if (!filename)
		return (-1);

	alx = open(filename, O_CREAT | O_WRONLY | O_TRUNC, 0600);

	if (alx == -1)
		return (-1);

	if (!text_content)
		text_content = "";

	for (nlen = 0; text_content[nlen]; nlen++)
		;

	rwr = write(alx, text_content, nlen);

	if (rwr == -1)
		return (-1);

	close(alx);

	return (1);
}
