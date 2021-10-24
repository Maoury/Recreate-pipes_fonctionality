/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madiallo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/18 15:45:03 by madiallo          #+#    #+#             */
/*   Updated: 2021/07/01 04:58:31 by madiallo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	char	*tab;
	char	*ptr;

	tab = (char *)malloc(sizeof(char) * ft_strlen(s) + 1);
	if (!tab)
		return (NULL);
	ptr = tab;
	while (*s)
		*tab++ = *s++;
	*tab = 0;
	return (ptr);
}
