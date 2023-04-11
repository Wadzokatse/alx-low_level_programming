#include "main.h"

/**
 * append_text_to_file - appends text at the end of a file
 * @filename: name for file
 * @text_content: text to put into file
 *
 * Return: 1 on success, -1 on failure
 */
int append_text_to_file(const char *filename, char *text_content)
{
	int alx;
	int nlen;
	int rwr;

	if (!filename)
		return (-1);

	alx = open(filename, O_WRONLY | O_APPEND);

	if (alx == -1)
		return (-1);

	if (text_content)
	{
		for (nlen = 0; text_content[nlen]; nlen++)
			;

		rwr = write(alx, text_content, nlen);

		if (rwr == -1)
			return (-1);
	}

	close(alx);

	return (1);
}
