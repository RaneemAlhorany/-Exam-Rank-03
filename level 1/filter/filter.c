// to test it write in the shell : bash tester.sh

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <errno.h>

#define BUFFER_SIZE 1024

int	len(char *str)
{
	int i = 0;
	while (str[i])
		i++;
	return (i);
}

void	err(void)
{
	write(2, "Error: ", 7);
	perror("");
	exit(1);
}

int	cmp(char *s1, char *s2, int len)
{
	int i = 0;
	while (i < len)
	{
		if (s1[i] != s2[i])
			return (0);
		i++;
	}
	return (1);
}

int	main(int argc, char **argv)
{
	char	buffer[BUFFER_SIZE];
	char	*window;
	
	int		pattern_len;
	int		window_len = 0;
	int		bytes_read;
	int		buf_index;
	int		shift_index;

	if (argc != 2 || !argv[1][0])
		return (1);

	pattern_len = len(argv[1]);

	if (!(window = malloc(pattern_len)))
		err();

		
	bytes_read = read(0, buffer, BUFFER_SIZE);

	while (bytes_read > 0)
	{
		buf_index = 0;
		while (buf_index < bytes_read)
		{
			window[window_len++] = buffer[buf_index++];

			if (window_len >= pattern_len &&
				cmp(window + window_len - pattern_len, argv[1], pattern_len))
			{
				shift_index = 0;
				while (shift_index ++ < pattern_len)
					write(1, "*", 1);
				window_len -= pattern_len;
			}

			if (window_len >= pattern_len)
			{
				write(1, &window[0], 1);
				shift_index = 1;
				while (shift_index < window_len)
				{
					window[shift_index - 1] = window[shift_index];
					shift_index++;
				}
				window_len --;
			}
		}
		bytes_read = read(0, buffer, BUFFER_SIZE);
	}

	if (bytes_read < 0)
		err();

	write(1, window, window_len);
	free(window);
}


