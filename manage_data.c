/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage_data.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madiallo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/22 17:10:27 by madiallo          #+#    #+#             */
/*   Updated: 2021/10/24 19:15:12 by madiallo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	free_data(t_data *data)
{
	ft_free_the_path(data->cmd, data->all_path);
//	ft_free_the_path(NULL, data->good_path);
	ft_free_the_path(NULL, data->infile);
	ft_free_the_path(NULL, data->outfile);
}

int	fill_data(t_data *data, int argc, char **argv, char **envp)
{
	data->envp = envp;
	data->nb_of_cmd = argc - 3;
	if (data->nb_of_cmd < 2)
		return (0);
	data->all_path = ft_get_env(envp);
	if (!data->all_path)
		return (0);
	data->cmd = create_table_for_commands(argv, argc);
	if (!data->cmd)
		return (0);
	data->infile = strdup(argv[1]);
	if (!data->infile)
		return (0);
	data->outfile = strdup(argv[argc - 1]);
	if (!data->outfile)
		return (0);
	data->outfile_fd = create_the_output_file(data->outfile);
	data->infile_fd = open_the_input_file(data->infile);
	if (data->infile_fd == -1 || data->outfile_fd == -1)
		return (0);
	return (1);
}