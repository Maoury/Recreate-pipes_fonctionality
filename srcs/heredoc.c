/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madiallo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/29 17:12:45 by madiallo          #+#    #+#             */
/*   Updated: 2021/11/02 16:43:31 by madiallo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

char	*get_limiter_with_nl(char *str)
{
	char	*limiter;

	limiter = ft_strjoin(str, "\n");
	if (!limiter)
		return (NULL);
	return (limiter);
}

char	*get_the_heredoc_user_input(char *limiter_without_nl, char *str)
{
	char	*tmp;
	char	*limiter;

	limiter = get_limiter_with_nl(limiter_without_nl);
	if (!limiter)
		return (NULL);
	tmp = NULL;
	while (ft_strncmp(tmp, limiter, ft_strlen(limiter)))
	{
		if (tmp)
			free (tmp);
		tmp = get_next_line(0);
		if (ft_strncmp(tmp, limiter, ft_strlen(limiter)))
			str = ft_strjoin_gnl(str, tmp);
		if (!str)
		{
			free(limiter);
			free(tmp);
			return (NULL);
		}
	}
	ft_free_the_path(NULL, tmp);
	ft_free_the_path(NULL, limiter);
	return (str);
}

int	get_heredoc_input(t_data *data, char *limiter_without_nl)
{
	int		pfd[2];
	char	*str;

	if (pipe(pfd) == -1)
		return (0);
	else
	{
		str = NULL;
		str = get_the_heredoc_user_input(limiter_without_nl, str);
		if (!str)
			return (0);
		ft_putstr_fd(str, pfd[1]);
		if (pfd[1] != -1)
			close(pfd[1]);
		ft_free_the_path(NULL, str);
		data->infile_fd = pfd[0];
		data->heredoc_switch = 1;
		return (1);
	}
}
