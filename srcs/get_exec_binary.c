/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_exec_binary.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madiallo <madiallo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/22 16:34:13 by madiallo          #+#    #+#             */
/*   Updated: 2021/12/07 19:37:08 by madiallo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

static void	path_errror(char *str)
{
	ft_putstr_fd("command not found: ", 2);
	ft_putstr_fd(str, 2);
	ft_putchar_fd('\n', 2);
}

char	**create_table_for_commands(char **argv, int argc, t_data *data)
{
	int		i;
	char	**cmd;

	i = -1;
	if (data->heredoc_switch == 1)
		argv++;
	if (argc < 4)
		return (NULL);
	cmd = (char **)malloc(sizeof(char *) * (data->nb_of_cmd + 1));
	if (!cmd)
		return (NULL);
	while (++i < data->nb_of_cmd)
	{
		cmd[i] = strdup(argv[i + 2]);
		if (!cmd[i])
		{
			ft_free_the_path(cmd, NULL);
			return (NULL);
		}
	}
	cmd[i] = 0;
	return (cmd);
}

char	*this_exec_path_already_exist(char **cmd)
{
	char	**str;
	char	*to_return;

	str = ft_split(cmd[0], ' ');
	if (!str)
		return (NULL);
	if (ft_strchr(str[0], '/' ))
	{
		to_return = ft_strdup(str[0]);
		ft_free_the_path(str, NULL);
		if (!to_return)
			return (NULL);
		return (to_return);
	}
	ft_free_the_path(str, NULL);
	return (NULL);
}

char	*ft_find_binary_exec(char *path, char **cmd)
{
	char	**list_of_path;
	int		i;
	char	*tmp;

	i = 0;
	if (!cmd[0][0])
		return (NULL);
	if (this_exec_path_already_exist(cmd))
		return (this_exec_path_already_exist(cmd));
	list_of_path = ft_split(path, ':');
	if (!list_of_path)
		return (NULL);
	while (list_of_path[i])
	{
		tmp = ft_path_exist(list_of_path[i], cmd);
		if (tmp)
		{
			ft_free_the_path(list_of_path, NULL);
			return (tmp);
		}
		i++;
	}
	ft_free_the_path(list_of_path, tmp);
	path_errror(cmd[0]);
	return (ft_strdup(cmd[0]));
}
