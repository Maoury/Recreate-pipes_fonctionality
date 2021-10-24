/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madiallo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/18 15:46:49 by madiallo          #+#    #+#             */
/*   Updated: 2021/07/01 05:22:34 by madiallo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*tab;
	int		i;

	i = -1;
	if (!s || !f)
		return (NULL);
	tab = ft_strdup(s);
	if (!tab)
		return (NULL);
	while (s[++i])
		tab[i] = f(i, s[i]);
	return (tab);
}
