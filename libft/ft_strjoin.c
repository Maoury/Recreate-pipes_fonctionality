/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madiallo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/18 15:45:45 by madiallo          #+#    #+#             */
/*   Updated: 2021/10/18 16:51:22 by madiallo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*join;
	char	*ptr;

	if (!s1 || !s2)
		return (NULL);
	join = (char *)malloc((ft_strlen(s1) + ft_strlen(s2)) * sizeof(char) + 1);
	if (!join)
		return (NULL);
	ptr = join;
	if	(s1)
		while (*s1)
			*join++ = *s1++;
	if (s2)
		while (*s2)
			*join++ = *s2++;
	*join = '\0';
	return (ptr);
}
