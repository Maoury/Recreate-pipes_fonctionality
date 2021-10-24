

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
// 		close_unused_fd(data.nb_of_cmd + 1, 1, fd);
// 		close (fd[0][0]);
// 		char buffer[1201];
// 		dup2(data.infile_fd, 0);
// 		read(0, buffer, sizeof(buffer));
// 	//	printf("buffer : %s\n", buffer);
// 		write(fd[1][1], buffer, ft_strlen(buffer));
// 		close (fd[1][1]);

// 		return (0);
// 	}
// 	close_unused_fd(data.nb_of_cmd + 1, 2, fd);
// 	close(fd[2][1]);
// 	wait(NULL);
// 	char buffer[1205];
// 	dup2(data.outfile_fd, 1);
// 	read(fd[1][0], buffer, sizeof(buffer));
// //	printf("buffer : %s\n", buffer);
// 	write(1, buffer, ft_strlen(buffer));
// 	close (fd[1][0]);
// 	free_pipe_fd_created(fd, data.nb_of_cmd + 1);
// 	free_data(&data);
// 	return 0;
// }