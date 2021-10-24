/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madiallo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/18 15:46:09 by madiallo          #+#    #+#             */
/*   Updated: 2021/06/18 15:46:26 by madiallo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	j;
	size_t	dstog;

	j = 0;
	i = (size_t)ft_strlen(dst);
	dstog = (size_t)ft_strlen(dst);
	while (src[j] && (j + dstog < dstsize - 1) && dstsize != 0)
	{
		dst[i] = src[j];
		i++;
		j++;
	}
	dst[i] = '\0';
	if (dstog >= dstsize)
		return ((unsigned)ft_strlen(src) + dstsize);
	else
		return ((unsigned)ft_strlen(src) + dstog);
}
