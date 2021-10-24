/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madiallo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/18 15:48:59 by madiallo          #+#    #+#             */
/*   Updated: 2021/06/18 18:27:26 by madiallo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	const char	*temp;

	while (*s)
	{
		if (*s == (char)c)
		{
			temp = s + 1;
			while (*temp && *temp != (char)c)
				temp++;
			if (*temp != (char)c)
				return ((char *)s);
		}
		s++;
	}
	if ((char)c == 0)
		return ((char *)s);
	return (NULL);
}
