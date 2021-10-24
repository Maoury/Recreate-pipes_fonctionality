/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_the_path.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madiallo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/22 16:32:03 by madiallo          #+#    #+#             */
/*   Updated: 2021/10/24 18:12:18 by madiallo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	*ft_free_the_path(char **path, char *str)
{
	int i;

	i = 0;
	if (path)
	{
		while(path[i])
		{

			free(path[i]);
			i++;
		}
			path = NULL;
	}
	if (str)
		free(str);
	return (NULL);
}

char *ft_get_env (char **envp)
{
	int i = 0;
	char	*str;
	
	while (envp[i])
	{
		if (ft_strncmp("PATH=", envp[i], 5) == 0)
		{
			str = ft_strdup(envp[i] + 5);
			if(!str)
				return (NULL);
			return (str);	
		}
		i++;
	}
	return (NULL);
}

char  *ft_make_connect_path_and_cmd(char *path, char **cmd)
{
	char *str;
	char *ptr;
	char **realcmd;

	realcmd = ft_split(cmd[0], ' ');
	if (!realcmd)
		return (NULL);
	if (realcmd[0][0] == '/')
		{
			str = strdup(realcmd[0]);
			if(!str)
			{
				ft_free_the_path(realcmd, NULL);
				return (NULL);
			}
			return (str);
		}
	str = ft_strjoin(path, "/");
	if (!str)
	{
		ft_free_the_path(realcmd, NULL);
	 	return (NULL);
	}
	ptr = str;
	str = ft_strjoin(str, realcmd[0]);
	if (!str)
	{
		ft_free_the_path(realcmd, ptr);
		free (ptr);
		return (NULL);
	}
	ft_free_the_path(realcmd, ptr);
	return (str);
}

char	*ft_path_exist(char *path, char **cmd, char **envp)
{
	char *str;

	str = ft_make_connect_path_and_cmd(path, cmd);
	if (!str)
		return (0);
	if (access(str, X_OK) == 0)
		return (str);
	free (str);
	return (NULL);
}