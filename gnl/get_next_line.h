/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madiallo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/13 17:25:19 by madiallo          #+#    #+#             */
/*   Updated: 2021/10/29 17:11:36 by madiallo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# define BUFFER_SIZE 100000

# include <stdlib.h>
# include <fcntl.h>
# include <stdio.h>
# include <unistd.h>

char	*get_next_line(int fd);

int		ft_strlen_gnl(char *s);
char	*ft_strchr_gnl(char *s, int c);
char	*ft_strjoin_gnl(char *s1, char	*s2);
#endif
