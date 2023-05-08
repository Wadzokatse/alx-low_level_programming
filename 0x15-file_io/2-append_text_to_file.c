#include "main.h"

/**
 * append_text_to_file
 *
 * Return: 1 if the file exists. -1 if the fails does not exist or FALSE
 */
int append_text_to_file(const char *filename, char *text_content)
{
	int al;
	int newles;
	int rwr;

	if (!filename)
		return (-1);

	al = open(filename, O_WRONLY | O_APPEND);

	if (al == -1)
		return (-1);

	if (text_content)
	{
		for (newles = 0; text_content[newles]; newles++)
			;

		rwr = write(fd, text_content, newles);

		if (rwr == -1)
			return (-1);
	}

	close(al);

	return (1);
}
