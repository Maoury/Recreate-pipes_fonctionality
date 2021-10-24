/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madiallo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/18 15:47:49 by madiallo          #+#    #+#             */
/*   Updated: 2021/07/01 06:01:22 by madiallo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	nlen;
	size_t	i;
	size_t	c;

	if (!*needle)
		return ((char *)haystack);
	i = 0;
	nlen = ft_strlen(needle);
	while (haystack[i] && i < len)
	{
		c = 0;
		while ((i + c) < len && haystack[i + c] && haystack[i + c] == needle[c])
			c++;
		if (c == nlen)
			return ((char *)haystack + i);
		i++;
	}
	return (NULL);
}
