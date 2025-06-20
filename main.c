#include "get_next_line.h"
#include <stdio.h>
#include <string.h>

int	main(void)
{
	int		fd;
	
	fd = open("text", O_CREAT | O_RDWR);
	char	*s = get_next_line(fd);
	char	*s1 = get_next_line(fd);
	printf("%s\n", s);
	printf("%s\n", s1);
	close(fd);
	free(s);
}
