#include <stdio.h>
#include "get_next_line.h"
#include <fcntl.h>


int main(void)
{
	int	fd = open("file.txt", O_RDONLY);
	printf("===================================\n");
	for (int i = 0; i < 10;i++)
	{
		char	*str = get_next_line(fd);
		// if (!str)
		// {
		// 	// printf("\n{%p} = NULL\n",str);
		// 	continue;
		// }
		printf("{%p} = %s",str,str);
		free(str);
	}
	printf("\n===================================\n");
	close(fd);
}
