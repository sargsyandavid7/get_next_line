#include "get_next_line.h"
#include <stdio.h>

int main()
{
	int fd = open("x",O_RDONLY);
	printf("%s",get_next_line(fd));
	printf("%s",get_next_line(fd));
	printf("%s",get_next_line(fd));
	printf("%s",get_next_line(fd));

}
