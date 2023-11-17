#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <limits.h>
#include <fcntl.h>

int main(void)
{
	int fd = open("file.txt", O_RDONLY);
}