/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madiallo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/18 15:25:16 by madiallo          #+#    #+#             */
/*   Updated: 2021/07/01 05:46:35 by madiallo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char	*s;
	unsigned char	*d;

	if (src == dest || !n)
		return ((void *)dest);
	d = (unsigned char *)dest;
	s = (unsigned char *)src;
	if (d > s)
	{
		while (n > 0)
		{
			--n;
			d[n] = s[n];
		}
	}
	else
		ft_memcpy(dest, src, n);
	return ((void *)dest);
}
