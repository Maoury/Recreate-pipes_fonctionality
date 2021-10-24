#include "../pipex.h"
void	free_pipe_fd_created(int **fd, int n_of_fd)
{
	int i;

	i = n_of_fd - 1;
	while ( i >= 0)
		free(fd[i--]);
	free(fd);
}
void	close_unused_fd(int nmax, int n, int *fd[2])
{
	int i;

	i = 0;
	while (i < nmax)
	{	
		if (n - 1 != i)
		{	
			printf("fd[%d][0] \n", i);
			close(fd[i][0]);
		}
		if (n != i)
		{	
			
			printf(" - fd[%d][1] \n", i);
			close(fd[i][1]);
	
		}	
		i++;
	}		
}
void	close_used_fd(int nmax, int n, int *fd[2])
{
	int i;

	i = 0;
	while (i < nmax)
	{	
		if (n - 1 == i) 
			close(fd[i][0]);
		if (n == i) 
			close(fd[i][1]);
		i++;
	}		
}
void	close_main_process_unused_fd(int nmax, int *fd[2])
{
	int i;

	i = 0;
	while (i < nmax)
	{	
		if (nmax - 1 != i) 
			close(fd[i][0]);
		if (0 != i) 
			close(fd[i][1]);
		i++;
	}
}
void	close_main_process_used_fd(int nmax, int *fd[2])
{
	
	close(fd[0][1]);
	close(fd[nmax - 1][0]);
}

int	**create_all_needed_fd(int n_of_fd)
{
	int i;
	int **fd;

	i = 0;
	fd = (int **)malloc(sizeof(int **) * n_of_fd);
	if (!fd)
		return (NULL);
	while (i < n_of_fd)
	{
		fd[i] = (int *)malloc(sizeof(int *) * 2);
		if (!fd[i])
		{
			free_pipe_fd_created(fd, n_of_fd);
			return (NULL);
		}
		i++;
	}
	return (fd);
}
int main (int argc, char *argv[], char *envp[])
{
	int **fd;
	int i;
	int nmax;
	int n;
	int	pid;

	nmax = 3;
	i = 0;
	n = 1;
	fd = create_all_needed_fd(nmax);
	while (i < nmax)
	{
		if (pipe(fd[i]) == -1)
			return 0;
		i++;
	}
	if (!fd)
		return (0);
	while (n < nmax)
	{
		pid = fork();
		if (pid == 0)
		{
			int x;
			close_unused_fd(nmax, n, fd);
			printf("ok\n");
			read(fd[n - 1][0], &x, sizeof(int));
			x += 5;
			write(fd[n][1], &x, sizeof(int));
			close_used_fd(nmax, n, fd);
			return 1;
		}
		n++;
	}
	close_main_process_unused_fd(nmax, fd);
	int x = 0;
	write(fd[0][1], &x, sizeof(int));
	wait (NULL);
	read(fd[nmax - 1][0], &x, sizeof(int));
	close_main_process_used_fd(nmax, fd);
	printf("x = %d", x);
	return 0;
}