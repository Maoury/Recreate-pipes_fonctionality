/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madiallo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/18 15:21:30 by madiallo          #+#    #+#             */
/*   Updated: 2021/07/01 05:21:02 by madiallo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <limits.h>
#include <stdio.h>

int	ft_atoi(const char *nptr)
{
	int		sign;
	long	res;

	res = 0;
	sign = 1;
	while (*nptr && ((*nptr >= 9 && *nptr <= 13) || *nptr == ' '))
		nptr++;
	if (*nptr && (*nptr == '+'))
		nptr++;
	else if (*nptr == '-')
	{
		sign *= -1;
		nptr++;
	}
	while (*nptr && *nptr >= '0' && *nptr <= '9')
		res = res * 10 + (*nptr++ - 48);
	return ((int)(res * sign));
}
