/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madiallo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/18 15:43:20 by madiallo          #+#    #+#             */
/*   Updated: 2021/10/15 19:24:40 by madiallo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	is_charset(char const s, char c)
{
	return (s == c);
}

static int	count_word(char const *str, char c)
{
	int	i;
	int	state;
	int	count;

	i = 0;
	state = 1;
	count = 0;
	while (str[i])
	{
		if (!is_charset(str[i], c) && state == 1)
		{
			count++;
			state = 0;
		}
		else
			if (is_charset(str[i], c) && state == 0)
				state = 1;
		i++;
	}
	return (count);
}

static int	word_len(char const *str, char c)
{
	int	i;

	i = 0;
	while (str[i] && !is_charset(str[i], c))
		i++;
	return (i);
}

static void	ft_do_split(char ***tab, int countword, char const *s, char c)
{
	int	i;
	int	j;

	i = 0;
	while (i < countword)
	{
		j = 0;
		while (*s && is_charset(*s, c))
			s++;
		tab[0][i] = (char *)malloc(sizeof(char) * word_len(s, c) + 1);
		if (!tab[0][i])
		{	
			while (i >= 0)
				free (tab[0][i--]);
			tab[0] = NULL;
			return ;
		}
		while (*s && !is_charset(*s, c))
			tab[0][i][j++] = *s++;
		tab[0][i][j] = '\0';
		i++;
	}
	tab[0][i] = 0;
}

char	**ft_split(char const *s, char c)
{
	int		countword;
	char	**tab;

	if (!s)
		return (0);
	countword = count_word(s, c);
	tab = (char **)malloc(sizeof(char *) * (countword + 1));
	if (!tab)
		return (0);
	ft_do_split(&tab, countword, s, c);
	return (tab);
}
