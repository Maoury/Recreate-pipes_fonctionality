#include <unistd.h>
#include <sys/wait.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main (int argc, char *argv[], char *envp[])
{
    int fd[3][2];
    int i;
    int pid1;
  
    i = -1;
    while (++i < 3)
        if (pipe(fd[i]) < 0)
            return (1);
    pid1 = fork();
    if (pid1 < 0)
	    return (1);
    if (pid1 == 0) // child process
    {
	int x;
	close(fd[0][1]);
	close(fd[1][0]);
	close(fd[2][0]);
	close(fd[2][1]);
	read(fd[0][0], &x, sizeof(int));
	x += 5;
	write(fd[1][1] , &x, sizeof(int));
	close(fd[0][0]);
	close(fd[1][1]);
	return (2);
    }
   int pid2;

   pid2 = fork();
    if (pid2 < 0)	
	return (3);
    if (pid2 == 0)
    {
	int x;
	close(fd[0][0]);
	close(fd[1][1]);
	close(fd[2][0]);
	close(fd[0][1]);
	read(fd[1][0], &x, sizeof(int));
	x += 5;
	write(fd[2][1], &x, sizeof(int));
	close(fd[2][1]);
	close(fd[1][0]);
	return (4);
    }

    	int x;
	x = 0;
	close(fd[0][0]);
	close(fd[1][1]);
	close(fd[2][1]);
	close(fd[1][0]);
	write (fd[0][1], &x, sizeof(int));
//	wait(NULL);
	read(fd[2][0], &x, sizeof(int));
	printf("x = %d", x);
	close (fd[2][0]);
	close(fd[0][1]);
	return (7);
}
