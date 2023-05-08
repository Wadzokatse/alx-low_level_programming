#include "main.h"
#include <stdarg.h>

/**
 * error_handler
 * @exit_code: exit code
 */

void error_handler(int exit_code, char *message, char type, ...)
{
	va_list args;

	va_start(args, type);
	if (type == 's')
		dprintf(STDERR_FILENO, message, va_arg(args, char *));
	else if (type == 'd')
		dprintf(STDERR_FILENO, message, va_arg(args, int));
	else if (type == 'N')
		dprintf(STDERR_FILENO, message, "");
	else
		dprintf(STDERR_FILENO, "Error: Does not match any type\n");
	va_end(args);
	exit(exit_code);
}

/**
 * main - copies the content of a file.
 * @argc: number of arguments
 * @argv: array of arguments
 * Return:  0 (Always)
 */

int main(int argc, char *argv[])
{
	char buffer[1024];
	int al_s, al_d;
	ssize_t bytes_read, bytes_written;

	if (argc != 3)
		error_handler(97, "Usage: cp file_from file_to\n", 'N');

	al_s = open(argv[1], O_RDONLY);
	if (al_s == -1)
		error_handler(98, "Error: Can't read from file %s\n", 's', argv[1]);

	al_d = open(argv[2], O_CREAT | O_WRONLY | O_TRUNC, 0664);
	if (al_d == -1)
		error_handler(99, "Error: Can't write to %s\n", 's', argv[2]);

	while ((bytes_read = read(al_s, buffer, 1024)) > 0)
	{
		bytes_written = write(al_d, buffer, bytes_read);
		if (bytes_written == -1)
			error_handler(99, "Error: Can't write to %s\n", 's', argv[2]);
	}

	if (bytes_read == -1)
		error_handler(98, "Error: Can't read from file %s\n", 's', argv[1]);
	if (close(al_s) == -1)
		error_handler(100, "Error: Can't close fd %d\n", 'd', al_s);
	if (close(al_d) == -1)
		error_handler(100, "Error: Can't close fd %d\n", 'd', al_d);

	return (0);
}
