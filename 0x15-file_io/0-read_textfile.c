#include "main.h"

/**
 * read_textfile - reads a text file and prints it to standard output
 *
 * Return: if success return number of letter, else return 0
 */

ssize_t read_textfile(const char *filename, size_t letters)
{
	int alx;
	char *buffer;
	ssize_t bytes_read, bytes_written;

	if (filename == NULL)
		return (0);

	alx = open(filename, O_RDONLY);
	if (alx == -1)
		return (0);

	buffer = malloc(sizeof(char) * letters + 1);
	if (buffer == NULL)
		return (0);

	bytes_read = read(alx, buffer, letters);
	if (bytes_read == -1)
		return (0);

	buffer[letters + 1] = '\0';
	close(alx);

	bytes_written = write(STDOUT_FILENO, buffer, bytes_read);
	if (bytes_written == -1)
		return (0);

	free(buffer);

	return (bytes_read);
}

