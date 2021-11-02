/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_b2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madiallo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/02 16:40:03 by madiallo          #+#    #+#             */
/*   Updated: 2021/11/02 17:32:31 by madiallo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

int	main(int argc, char *argv[], char *envp[])
{
	int		**fd;
	t_data	data;

	if (argc >= 6)
	{
		if (!ft_strncmp(argv[1], "here_doc", ft_strlen("here_doc")))
			get_heredoc_input(&data, argv[2]);
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
		make_fork_processes(fd, &data);
		//free_pipe_fd_created(fd, data.nb_of_cmd + 1);
		free_data(&data);
		return (0);
	}
}
