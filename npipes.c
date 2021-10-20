#include <unistd.h>
#include <sys/wait.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main (int argc, char *argv[], char *envp[])
{
	int **fd;
	int i;
	int nmax;
	int n;
	int	pid;

	nmax = 3;
	i = -1;
	n = 0;
	fd = malloc(sizeof(int **) * nmax);
	while(n < nmax)
		fd[n++] = malloc(sizeof(int *) * nmax);
	if (!fd)
		return (0);

	while (++i < nmax)
		if (pipe(fd[i]) < 0)
			return (1);
	n = 1;
	i = 0;
	while (n < nmax)
	{
		pid = fork();
		if (pid == 0)
		{
			int x;
			printf("good closing\n");
			while (i < nmax)
			{	
				printf("i = %d\n", i);
				if (n - 1 != i) 
					close(fd[i][0]);
				if (n != i) 
					close(fd[i][1]);
				i++;
			}
			printf("good clong\n");
			read(fd[n - 1][0], &x, sizeof(int));
			x += 5;
			write(fd[n][1], &x, sizeof(int));
			close (fd[n - 1][0]);
			close(fd[n][1]);
			return 1;
		}
		n++;
	}
	while (i < nmax)
	{	
		if (nmax - 1 != i) 
			close(fd[i][0]);
		if (0 != i) 
			close(fd[i][1]);
		i++;
	}
	int x = 0;
	write(fd[0][1], &x, sizeof(int));
	read(fd[nmax - 1][0], &x, sizeof(int));
	close(fd[0][1]);
	close(fd[nmax - 1][0]);
	printf("x = %d", x);
	return 0;

}
