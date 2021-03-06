/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   executing_fork_and_main_process.c                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madiallo <madiallo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/22 16:06:31 by madiallo          #+#    #+#             */
/*   Updated: 2021/12/07 19:40:53 by madiallo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

int	execute_forks_process(t_data *data, int *fd[2], int n)
{
	char	**good_cmd;

	if (n == 1)
		dup2(data->infile_fd, 0);
	else
		dup2(fd[n - 1][0], 0);
	if (n == data->nb_of_cmd)
	{
		dup2(fd[data->nb_of_cmd - 1][0], 0);
		dup2(data->outfile_fd, 1);
	}
	else
		dup2(fd[n][1], 1);
	close_all_fd(data->nb_of_cmd, fd);
	good_cmd = ft_split(data->cmd[n - 1], ' ');
	if (ft_strchr(data->good_path, '/'))
	{
		execve(data->good_path, good_cmd, data->envp);
		perror("pipex :");
	}
	free_pipe_fd_created(fd, data->nb_of_cmd + 1);
	ft_free_the_path(good_cmd, data->good_path);
	free_data(data);
	exit(127);
}

int	make_fork_processes(int *fd[2], t_data *data)
{
	int	n;
	int	pid;

	n = 1;
	while (n < data->nb_of_cmd + 1)
	{
		data->good_path = ft_find_binary_exec(data->all_path,
				data->cmd + (n - 1));
		pid = fork();
		if (pid == -1)
		{
			perror("fork :");
			return (-1);
		}
		if (pid == 0)
			execute_forks_process(data, fd, n);
		ft_free_the_path(NULL, data->good_path);
		n++;
	}
	return (0);
}
