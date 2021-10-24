/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_exec_binary.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madiallo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/22 16:34:13 by madiallo          #+#    #+#             */
/*   Updated: 2021/10/22 18:53:06 by madiallo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	**create_table_for_commands(char **argv, int argc)
{
	int i;
	int nb_of_command;
	char **cmd;

	i = -1;
	nb_of_command = argc - 3;
	if (argc < 4)
		return (NULL);
	cmd = (char **)malloc(sizeof(char *) * (nb_of_command + 1));
	if (!cmd)
		return (NULL);
	while (++i < nb_of_command)
	{
		cmd[i] = strdup(argv[i + 2]);
		if (!cmd[i])
		{
			ft_free_the_path(cmd, NULL);
			return (NULL);
		}
		printf("cmd[%d] = %s\n", i, cmd[i]);
	}
			printf("cmd[%d] = \n", i);

	cmd[i] = 0;
	return (cmd);
}
char	*ft_find_binary_exec(char *path, char **cmd, char **envp)
{
	char	**list_of_path;
	int 	i;
	char	*tmp;

	i = 0;
	list_of_path = ft_split(path, ':');
	if (!path)
		return (NULL);
	while (list_of_path[i])
	{
		tmp = ft_path_exist(list_of_path[i], cmd, envp);
		if (tmp)
			{
				ft_free_the_path(list_of_path, NULL);
				printf("%s", tmp);
				return (tmp);
			}
		i++;
	}
	ft_free_the_path(list_of_path, tmp);
	return (NULL);

}

int		ft_execute_command(char *path, char **cmd, char **envp)
{
	execve(path, cmd, envp);
	perror("execve");
	return (-1);
}