#include "pipex.h"
/*************************************/


/***********************************/
// get the PATH variable 

// this function put a '/' between absolut path and the cmd, if the user put directly absolut path, just return the cmd

// this function create  the absolute path and try to see if we have correct rights for the command

// Go find the with mutiple function :  we split et $PATH variable and we try with the command all possible path



int main (int argc, char **argv, char **envp)
{
	t_data	data;
	//data.argv = argv + 1;
	
	/*ft_execute_command*/
		fill_data(&data, argc, argv, envp);
		free_data(&data);
	//i = execve(ft_find_binary(data.path, cmd, envp), cmd, envp);
 
//	perror("execve");
	// while (data->argv[i])
	// {x
	// 	printf("%s", data->argv[i]);
	// }
	
	// while (path[i])
	// {
	// 	execve()
	// }
}