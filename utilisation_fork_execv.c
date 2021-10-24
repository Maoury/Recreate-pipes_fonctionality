#include <unistd.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>
int	main(int argc, char *argv[], char *env[])
{
	pid_t	pid;
	int		status;
	int 	swit;	
	if (argc > 1)
	{
		pid = fork();
		if (pid == -1)
		{
			perror("fork");
			return (1);
		}
		else if (pid == 0)
		{
			printf("je suis lexecution du pid enfant : %d\n", getpid());
			swit = execve(argv[1], argv + 1, env);
			if (swit == -1)
				perror("execve");
		}
		else
		{
			wait(NULL);
			printf("je suis le process parent bro : %d\n", getpid());
		}
	}
	return (0);
}
