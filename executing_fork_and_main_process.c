/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   executing_fork_and_main_process.c                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madiallo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/22 16:06:31 by madiallo          #+#    #+#             */
/*   Updated: 2021/10/24 20:00:57 by madiallo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int executing_fork_processes(int *fd[2], t_data *data)
{
	int n;
	int pid;

	n = 1;
//	dup2(data->infile_fd, 0);
	while (n < data->nb_of_cmd)
	{
		data->good_path = ft_find_binary_exec(data->all_path, data->cmd + (n - 1), data->envp);
			if (!data->good_path)
					return (0);
		pid = fork();
		if (pid == -1)
			return (-1);
		if (pid == 0)
		{
			close_unused_fd(data->nb_of_cmd + 1, n, fd);
			if (n == 1)
				{
					dup2(data->infile_fd, 0);
					close (fd[0][0]);
				}
			else
				dup2(fd[n - 1][0], 0);
			dup2(fd[n][1], 1);
			execve(data->good_path, ft_split(data->cmd[n - 1], ' '), data->envp);
			close_used_fd(data->nb_of_cmd + 1, n, fd);
			perror("execve");
			return 1;
		}
		n++;
	}
	data->good_path = ft_find_binary_exec(data->all_path, data->cmd + (n - 1), data->envp);
			if (!data->good_path)
					return (0);
	executing_main_process(fd, data);
	return (0) ;
}

void executing_main_process(int *fd[2], t_data *data)
{

	close_main_process_unused_fd(data->nb_of_cmd + 1, fd);
	// int x = 0;
	// write(fd[0][1], &x, sizeof(int));
	wait (NULL);
	
	dup2(fd[data->nb_of_cmd + 1][0], 0);
	dup2(data->outfile_fd, 1);
	close_main_process_used_fd(data->nb_of_cmd + 1, fd);
	execve(data->good_path, ft_split(data->cmd[data->nb_of_cmd], ' '), data->envp);

	// read(fd[data->nb_of_cmd + 1 - 1][0], &x, sizeof(int));
}