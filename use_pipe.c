#include <sys/types.h>
#include <sys/wait.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>


int	main(int argc, char *argv[])
{
	int		fd[2];
	int		bytes;
	pid_t	pid;
	char 	str[] = "chakal mange les patates\n";
	char	buf[100];

	pipe(fd);

	pid = fork();
	if (pid == -1)
	{
		perror("fork");
		return (1);
	}
	if (pid == 0)
	{
		close(fd[0]);
		bytes = write(fd[1], str, 26);
		close(fd[1]);
	}
	else if (pid > 0)
	{
		
		close (fd[1]);

		bytes = read(fd[0], buf, sizeof(buf));
		printf("there is %d bytes readed\n", bytes);
		printf("Message Received : %s", buf);
		close(fd[0]);
	}
	return (0);
}
// #include <stdio.h>
// #include <stdlib.h>
// #include <string.h>
// #include <unistd.h>
// #include <sys/types.h>

// int main(void)
// {
//         int     fd[2], nbytes;
//         pid_t   childpid;
//         char    string[] = "Hello, world!\n";
//         char    readbuffer[80];

//         pipe(fd);

//         if((childpid = fork()) == -1)
//         {
//                 perror("fork");
//                 exit(1);
//         }

//         if(childpid == 0)
//         {
//                 /* Child process closes up input side of pipe */
//                 close(fd[0]);

//                 /* Send "string" through the output side of pipe */
//                 write(fd[1], string, (strlen(string)+1));
//                 exit(0);
//         }
//         else
//         {
//                 /* Parent process closes up output side of pipe */
//                 close(fd[1]);

//                 /* Read in a string from the pipe */
//                 nbytes = read(fd[0], readbuffer, sizeof(readbuffer));
//                 printf("Received string: %s", readbuffer);
//         }

//         return(0);
// }
