/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage_data.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madiallo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/22 17:10:27 by madiallo          #+#    #+#             */
/*   Updated: 2021/11/02 16:21:13 by madiallo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

void	free_data(t_data *data)
{
	ft_free_the_path(data->cmd, data->all_path);
	if (data->outfile_fd >= 0)
		close(data->outfile_fd);
	if (data->infile_fd >= 0)
		close(data->infile_fd);
	if (data)
		free(data);
}

static int	manage_data_error(t_data *data)
{
	if (!data)
		return (0);
	if (!data->all_path)
		return (0);
	if (data->infile_fd == -1 || data->outfile_fd == -1)
		return (0);
	if (!data->cmd)
		return (0);
	if (data->nb_of_cmd < 2)
		return (0);
	return (1);
}

int	fill_data(t_data *data, int argc, char **argv, char **envp)
{
	if (data)
	{
		data->envp = envp;
		data->nb_of_cmd = argc - 3;
		if (data->heredoc_switch != 1)
			data->heredoc_switch = 0;
		if (data->heredoc_switch == 1)
			data->nb_of_cmd = argc - 4;
		data->all_path = ft_get_env(envp);
		data->cmd = create_table_for_commands(argv, argc, data);
		data->infile = argv[1];
		data->outfile = argv[argc - 1];
		data->outfile_fd = create_the_output_file(data->outfile,
				data->heredoc_switch);
		if (data->heredoc_switch != 1)
			data->infile_fd = open_the_input_file(data->infile);
	}
	return (manage_data_error(data));
}
