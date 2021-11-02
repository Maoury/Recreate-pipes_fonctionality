/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_the_path.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madiallo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/22 16:32:03 by madiallo          #+#    #+#             */
/*   Updated: 2021/10/27 21:03:43 by madiallo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

char	*ft_free_the_path(char **path, char *str)
{
	int	i;

	i = 0;
	if (path)
	{
		while (path[i])
			i++;
		while (i < 0)
		{
			if (path[i])
				free(path[i]);
			i--;
		}
		path = NULL;
	}
	if (str)
		free(str);
	return (NULL);
}

char	*ft_get_env(char **envp)
{
	int		i;
	char	*str;

	i = 0;
	while (envp[i])
	{
		if (ft_strncmp("PATH=", envp[i], 5) == 0)
		{
			str = ft_strdup(envp[i] + 5);
			if (!str)
				return (NULL);
			return (str);
		}
		i++;
	}
	return (NULL);
}

char	*ft_make_connect_path_and_cmd(char *path, char **cmd)
{
	char	*str;
	char	*ptr;
	char	**realcmd;

	realcmd = ft_split(cmd[0], ' ');
	if (!realcmd)
		return (NULL);
	str = ft_strjoin(path, "/");
	if (!str)
	{
		ft_free_the_path(realcmd, NULL);
		return (NULL);
	}
	ptr = str;
	str = ft_strjoin(str, realcmd[0]);
	ft_free_the_path(realcmd, ptr);
	if (!str)
		return (NULL);
	return (str);
}

char	*ft_path_exist(char *path, char **cmd)
{
	char	*str;

	str = ft_make_connect_path_and_cmd(path, cmd);
	if (!str)
		return (0);
	if (access(str, X_OK) == 0)
		return (str);
	free (str);
	return (NULL);
}
