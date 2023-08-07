#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

#define BUFFER_SIZE 1024

int validate_arguments(int argc, char *argv[]);
int open_source_file(const char *filename);
int open_destination_file(const char *filename);
void copy_content(int fd_from, int fd_to);

/**
 * main - Entry point for the program.
 * @argc: The number of command-line arguments.
 * @argv: An array of pointers to the arguments.
 * Return: 0 on success, various error codes on failure.
 */
int main(int argc, char *argv[])
{
	int fd_from, fd_to;

	if (validate_arguments(argc, argv) == -1)
		return (97);

	fd_from = open_source_file(argv[1]);
	if (fd_from == -1)
		return (98);

	fd_to = open_destination_file(argv[2]);
	if (fd_to == -1)
	{
		close(fd_from);
		return (99);
	}

	copy_content(fd_from, fd_to);

	close(fd_from);
	close(fd_to);

	return (0);
}

/**
 * validate_arguments - Validates the command-line arguments.
 * @argc: The number of command-line arguments.
 * @argv: An array of pointers to the arguments.
 * Return: 0 on success, -1 on failure.
 */
int validate_arguments(int argc, char *argv[])
{
	if (argc != 3)
	{
		dprintf(STDERR_FILENO, "Usage: %s file_from file_to\n", argv[0]);
		return (-1);
	}
	return (0);
}

/**
 * open_source_file - Opens the source file for reading.
 * @filename: The name of the source file.
 * Return: The file descriptor on success, -1 on failure.
 */
int open_source_file(const char *filename)
{
	int fd_from = open(filename, O_RDONLY);

	if (fd_from == -1)
		dprintf(STDERR_FILENO, "Error: Can't read from file %s\n", filename);
	return (fd_from);
}

/**
 * open_destination_file - Opens the destination file for writing.
 * @filename: The name of the destination file.
 * Return: The file descriptor on success, -1 on failure.
 */
int open_destination_file(const char *filename)
{
	int fd_to = open(filename, O_WRONLY | O_CREAT | O_TRUNC, 0664);

	if (fd_to == -1)
		dprintf(STDERR_FILENO, "Error: Can't write to %s\n", filename);
	return (fd_to);
}

/**
 * copy_content - Copies content from one file to another.
 * @fd_from: The file descriptor of the source file.
 * @fd_to: The file descriptor of the destination file.
 */
void copy_content(int fd_from, int fd_to)
{
	char buffer[BUFFER_SIZE];
	ssize_t bytes_read, bytes_written;

	while ((bytes_read = read(fd_from, buffer, BUFFER_SIZE)) > 0)
	{
		bytes_written = write(fd_to, buffer, bytes_read);
		if (bytes_written != bytes_read)
		{
			dprintf(STDERR_FILENO, "Error: Can't write to destination file\n");
			exit(99);
		}
	}

	if (bytes_read == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't read from source file\n");
		exit(98);
	}
}

