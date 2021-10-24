#include "../pipex.h"

int main(int argc, char *argv[], char *env[])
{
	int fd[2];
	int opn;
	int pid;
	int status;
	int nb_of_fork;
	int i; 

	i = 0;
	nb_of_fork = 4;
		//opn = open("infil dde", O_RDONLY);
	opn = create_the_output_file("outfile");
	if(opn == -1)
	{
		perror("fork :");
		return 0;
	}
	pipe(fd);
	char	buf[5000];
	if (argc <= 1)
		return (0);
	pid = fork();
	if (pid == -1)
	{
		perror("fork");
		return (1);
	}
	if (pid == 0)
	{
		 dup2(opn, 1);
		 //dup2(fd[1], 1);
		// write (1, "chakal", 6);
		 execve(argv[1], argv + 1, env);
	}
	// dup2(fd[0], 0);
	// status = read(0, buf, sizeof(buf));
	// wait(NULL);
	// pid = fork()
	//printf("this the line command : %s", buf);
}
