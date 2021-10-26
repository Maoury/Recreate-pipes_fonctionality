/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   action_on_files.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madiallo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/22 16:08:41 by madiallo          #+#    #+#             */
/*   Updated: 2021/10/26 17:53:29 by madiallo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"
#include <sys/fcntl.h>

int	check_if_file_exist(char *filename)
{
		return (access(filename, F_OK) == 0);
}

int	create_the_output_file(char *filename)
{
	int fd;

	if (!check_if_file_exist(filename))
	{
		fd = open(filename, O_CREAT | O_WRONLY | O_TRUNC, 0644);
		if (fd == -1)
			perror("output");
		close (fd);
	}
	fd = open(filename, O_WRONLY | O_TRUNC);
	if (fd == -1)
		perror("output1");
	return (fd);
}

int	open_the_input_file(char *filename)
{
	int fd;

		fd = open(filename, O_RDONLY);
		if (fd == -1)
			perror("input");
		return (fd);
}