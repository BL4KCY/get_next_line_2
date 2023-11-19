#include <stdio.h>
#include "get_next_line_bonus.h"
#include <fcntl.h>


int main(void)
{
	int	fd = open("file.txt", O_RDONLY);
	int fd2 = open("file2.txt", O_RDONLY);
//	printf("===================================\n");
	printf("\n-------------------fd : %i------------------\n",fd);
	for (int i = 0; i < 10;i++)
	{
		char	*str = get_next_line(fd);
		// if (!str)
		// {
		// 	// printf("\n{%p} = NULL\n",str);
		// 	continue;
		// }
		printf("[fd = %i]{%p} = %s",fd,str,str);
		free(str);
	}

	printf("\n-------------------fd : %i------------------\n",fd2);
	for (int i = 0; i < 10;i++)
	{
		char	*str = get_next_line(fd2);
		// if (!str)
		// {
		// 	// printf("\n{%p} = NULL\n",str);
		// 	continue;
		// }
		printf("[fd = %i]{%p} = %s",fd2,str,str);
		free(str);
	}
	printf("\n===================================\n");
	close(fd);
	close(fd2);
}
