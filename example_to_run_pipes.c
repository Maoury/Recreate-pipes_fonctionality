/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   example_to_run_pipes.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madiallo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/22 15:53:21 by madiallo          #+#    #+#             */
/*   Updated: 2021/10/24 19:30:31 by madiallo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"



int main (int argc, char *argv[], char *envp[])
{
	int **fd;
	t_data data;

	if (!fill_data(&data, argc, argv, envp))
	{
		free_data(&data);
		return (0);
	}
	fd = create_all_needed_fd(data.nb_of_cmd + 1);
	if (!fd)
	{
		free_data(&data);
		return (0);
	}
	executing_fork_processes(fd, &data);
	free_pipe_fd_created(fd, data.nb_of_cmd + 1);
	free_data(&data);
	return 0;
}

	// if (executing_fork_processes(fd, data.nb_of_cmd + 1) == -1)
	// {
	// 	free_pipe_fd_created(fd, data.nb_of_cmd + 1);
	// 	return (-1);
	// }