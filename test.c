

// #include "pipex.h"
// #include <unistd.h>

// int main (int argc, char *argv[], char *envp[])
// {
// 	int **fd;
// 	t_data data;
// 	int pid;

// 	if (!fill_data(&data, argc, argv, envp))
// 	{
// 		free_data(&data);
// 		return (0);
// 	}
// 	fd = create_all_needed_fd(data.nb_of_cmd + 1);
// 	if (!fd)
// 	{
// 		free_data(&data);
// 		return (0);
// 	}
// 	pid = fork();
// 	if (pid == 0)
// 	{
// 		char *cmd[] = {"/bin/ls", "-l"};
// 		close_unused_fd(data.nb_of_cmd + 1, 1, fd);
// 		close (fd[0][0]);
// 		dup2(data.infile_fd, 0);
// 		dup2(fd[1][1], 1);
// 		close (fd[1][1]);
// 		execve("/bin/ls", cmd, envp);
// 		return (0);
// 	}
// 	close_unused_fd(data.nb_of_cmd + 1, 2, fd);
// 	close(fd[2][1]);
// 	wait(NULL);
// 	char *cmd[] = {"/usr/bin/wc", "-l"};

// 	dup2(fd[1][0], 0);	
// 	dup2(data.outfile_fd, 1);
// 	close (fd[1][0]);
// 	execve("/usr/bin/wc", cmd, envp);
// 	free_pipe_fd_created(fd, data.nb_of_cmd + 1);
// 	free_data(&data);
// 	return 0;
// }