/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   close_fd.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madiallo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/22 15:52:32 by madiallo          #+#    #+#             */
/*   Updated: 2021/10/24 17:52:33 by madiallo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	close_unused_fd(int nmax, int n, int *fd[2])
{
	int i;

	i = 0;
	while (i < nmax)
	{	
		if (n - 1 != i)
			close(fd[i][0]);
		if (n != i)
			close(fd[i][1]);	
		i++;
	}		
}
void	close_used_fd(int nmax, int n, int *fd[2])
{
	int i;

	i = 0;
	while (i < nmax)
	{	
		if (n - 1 == i) 
			close(fd[i][0]);
		if (n == i) 
			close(fd[i][1]);
		i++;
	}		
}
void	close_main_process_unused_fd(int nmax, int *fd[2])
{
	int i;

	i = 0;
	while (i < nmax)
	{	
		if (nmax - 1 != i) 
			close(fd[i][0]);
		if (0 != i) 
			close(fd[i][1]);
		i++;
	}
}
void	close_main_process_used_fd(int nmax, int *fd[2])
{
	
	close(fd[0][1]);
	close(fd[nmax - 1][0]);
}