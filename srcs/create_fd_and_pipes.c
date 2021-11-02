/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_fd_and_pipes.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madiallo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/22 15:54:48 by madiallo          #+#    #+#             */
/*   Updated: 2021/10/27 20:25:53 by madiallo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

int	**create_all_needed_fd(int n_of_fd)
{
	int	i;
	int	**fd;

	i = 0;
	fd = (int **)malloc(sizeof(int *) * n_of_fd);
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
	if (create_all_pipes_needed(fd, n_of_fd) == 0)
	{
		free_pipe_fd_created(fd, n_of_fd);
		return (NULL);
	}
	return (fd);
}

int	**create_all_pipes_needed(int **fd, int n_of_fd)
{
	int	i;

	i = 0;
	while (i < n_of_fd)
	{
		if (pipe(fd[i]) == -1)
			return (0);
		i++;
	}
	return (fd);
}

void	free_pipe_fd_created(int **fd, int n_of_fd)
{
	int	i;

	i = n_of_fd - 1;
	close_all_fd(n_of_fd, fd);
	while (i >= 0)
		free(fd[i--]);
	free(fd);
}
