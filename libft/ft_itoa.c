/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madiallo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/18 15:23:18 by madiallo          #+#    #+#             */
/*   Updated: 2021/06/18 15:57:23 by madiallo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_digits(long *n, int *neg)
{
	int		digits;
	long	nb;

	digits = 0;
	if (*n < 0)
	{
		*n *= -1;
		*neg = 1;
		++digits;
	}
	if (*n == 0)
		return (1);
	nb = *n;
	while (nb)
	{
		nb /= 10;
		++digits;
	}
	return (digits);
}

char	*ft_itoa(int n)
{
	char	*ret;
	int		size;
	int		neg;
	long	nb;

	nb = (long)n;
	neg = 0;
	size = ft_digits(&nb, &neg);
	ret = (char *)malloc(sizeof(char) * (size + 1));
	if (!ret)
		return (NULL);
	ret[size] = 0;
	if (nb == 0)
		ret[0] = '0';
	while (size)
	{
		ret[--size] = (nb % 10) + '0';
		nb /= 10;
	}
	if (neg)
		ret[0] = '-';
	return (ret);
}
