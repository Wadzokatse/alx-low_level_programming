#include "main.h"

/**
 * read_textfile
 *
 * Return: numbers of letters printed. It fails, returns 0.
 */
ssize_t read_textfile(const char *filename, size_t letters)
{
	int al;
	ssize_t nrd, nwr;
	char *buf;

	if (!filename)
		return (0);

	al = open(filename, O_RDONLY);

	if (al == -1)
		return (0);

	buf = malloc(sizeof(char) * (letters));
	if (!buf)
		return (0);

	nrd = read(al, buf, letters);
	nwr = write(STDOUT_FILENO, buf, nrd);

	close(al);

	free(buf);

	return (nwr);
}
