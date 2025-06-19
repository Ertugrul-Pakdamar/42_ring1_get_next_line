#include "get_next_line.h"
#include <stdio.h>

int	main(void)
{
	int	fd;

	fd = open("text", O_CREAT | O_RDWR);
	printf("%s\n", get_next_line(fd));
	printf("%s\n", get_next_line(fd));
	printf("%s\n", get_next_line(fd));
	/*
	get_next_line(fd);
	get_next_line(fd);
	get_next_line(fd);*/
}
