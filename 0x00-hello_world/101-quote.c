#include <unistd.h>
#include <string.h>
#include <errno.h>

/**
 * main - Entry point
 *
 * Return: Always 1
 */
int main(void)
{
	const char *message = "and that piece of art is useful\" - Dora Korpar, 2015-10-19\n";
	ssize_t len = strlen(message);
	ssize_t ret;

	ret = write(STDERR_FILENO, message, len);
	if (ret == -1)
	{
		/* Error occurred while writing */
		const char *error_message = strerror(errno);
		ssize_t error_len = strlen(error_message);
		write(STDERR_FILENO, error_message, error_len);
		return (1);
	}

	return (1);
}
