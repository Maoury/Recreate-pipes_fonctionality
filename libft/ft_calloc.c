/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madiallo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/18 15:21:55 by madiallo          #+#    #+#             */
/*   Updated: 2021/07/01 05:44:25 by madiallo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	unsigned char	*ptr;

	ptr = (unsigned char *)malloc(sizeof(char) * (nmemb * size));
	if (!ptr)
		return (NULL);
	ft_bzero(ptr, (size * nmemb));
	return (ptr);
}
