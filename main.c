#include "get_next_line.h"
#include <stdio.h>

int main()
{
	int fd = open("x",O_RDONLY);
	char *a = get_next_line(fd);
	printf("%s",a);
	free(a);
	a = get_next_line(fd);
	printf("%s",a);
	free(a);
	a = get_next_line(fd);
	printf("%s",a);
	free(a);
	a = get_next_line(fd);
	printf("%s",a);
	free(a);
	a = get_next_line(fd);
	printf("%s",a);
	free(a);
	a = get_next_line(fd);
	printf("%s",a);
	free(a);
	a = get_next_line(fd);
	printf("%s",a);
	free(a);
	a = get_next_line(fd);
	printf("%s",a);
	free(a);
	a = get_next_line(fd);
	printf("%s",a);
	free(a);
	a = get_next_line(fd);
	printf("%s",a);
	free(a);
	a = get_next_line(fd);
	printf("%s",a);
	free(a);
	a = get_next_line(fd);
	printf("%s",a);
	free(a);
	a = get_next_line(fd);
	printf("%s",a);
	free(a);
	
}
