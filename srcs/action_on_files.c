/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   action_on_files.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madiallo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/27 20:52:20 by madiallo          #+#    #+#             */
/*   Updated: 2021/11/02 16:38:48 by madiallo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

int	check_if_file_exist(char *filename)
{
	return (access(filename, F_OK) == 0);
}

int	create_the_output_file(char *filename, int hd_switch)
{
	int	fd;

	if (hd_switch == 1)
		return (open_outfile_for_the_heredoc(filename));
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

int	open_outfile_for_the_heredoc(char *filename)
{
	int	fd;

	if (!check_if_file_exist(filename))
	{
		fd = open(filename, O_CREAT | O_RDWR | O_APPEND, 0644);
		if (fd == -1)
			perror("output");
		close (fd);
	}
	fd = open(filename, O_WRONLY | O_APPEND);
	if (fd == -1)
		perror("output1");
	return (fd);
}

int	open_the_input_file(char *filename)
{
	int	fd;

	fd = open(filename, O_RDONLY);
	if (fd == -1)
		perror("input");
	return (fd);
}
