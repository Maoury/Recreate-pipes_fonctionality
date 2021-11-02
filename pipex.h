/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madiallo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/27 17:58:54 by madiallo          #+#    #+#             */
/*   Updated: 2021/11/02 16:41:26 by madiallo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H
# include <sys/types.h>
# include <sys/wait.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <string.h>
# include "./libft/libft.h"
# include "./gnl/get_next_line.h"
# include <fcntl.h>

typedef struct s_data
{
	int		heredoc_switch;
	char	*infile;
	char	*outfile;
	int		outfile_fd;
	int		infile_fd;
	char	**cmd;
	char	*all_path;
	char	*good_path;
	int		nb_of_cmd;
	char	**envp;

}	t_data;
/************* FUNCTION UTILS ****************/
char	*ft_free_the_path(char **path, char *str);
char	**create_table_for_commands(char **argv, int argc, t_data *data);
void	free_pipe_fd_created(int **fd, int n_of_fd);
/************* FUNCTION FOR FILES **************/
int		create_the_output_file(char *filename, int hd_switch);
int		open_the_input_file(char *filename);
int		check_if_file_exist(char *filename);
/************ FUNCTION FOR GETTING THE EXECUTABLE **********/
char	*ft_path_exist(char *path, char **cmd);
char	*ft_make_connect_path_and_cmd(char *path, char **cmd);
char	*ft_find_binary_exec(char *path, char **cmd);
char	*ft_get_env(char **envp);
int		ft_execute_command(char *path, char **cmd, char **envp);
/********** FUNCTION FOR CREATES AND CLOSE PIPES ***********/
void	close_all_fd(int nmax, int *fd[2]);

int		**create_all_needed_fd(int n_of_fd);
int		**create_all_pipes_needed(int **fd, int n_of_fd);
int		make_fork_processes(int *fd[2], t_data *data);
void	executing_main_process(int *fd[2], t_data *data);
/****** FUNCTION FOR DATA ********/
int		fill_data(t_data *data, int argc, char **argv, char **envp);
void	free_data(t_data *data);
/********** HERE DOC FUNC *************/
int		open_outfile_for_the_heredoc(char *filename);
char	*get_the_heredoc_user_input(char *limiter_without_nl, char *str);
int		get_heredoc_input(t_data *data, char *limiter_without_nl);
char	*get_limiter_with_nl(char *str);
int		create_the_heredoc_file(char *filename);
#endif
