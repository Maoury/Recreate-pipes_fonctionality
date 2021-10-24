/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madiallo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/18 15:24:00 by madiallo          #+#    #+#             */
/*   Updated: 2021/06/18 15:31:37 by madiallo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*newelem;

	newelem = (t_list *)malloc(sizeof(t_list));
	if (!newelem)
		return (NULL);
	newelem->next = NULL;
	newelem->content = content;
	return (newelem);
}
