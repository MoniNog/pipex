#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <fcntl.h>
#include <errno.h>
#include <sys/stat.h>
#include <sys/types.h>

#include "../includes/pipex.h"

int	print_error()
{
	perror("error");
	return (1);
}

int main(int ac, char *av[], char *envp[])
{
		if (ac < 5)
		{
			fprintf(stderr, "Usage: %s <file_in> <cmd1> <cmd2> <file_out>\n", av[0]);
			return 1;
		}

int filein = open(av[1], O_RDONLY);
		if (filein == -1)
			print_error();
	if (dup2(filein, 0) == -1)
	{	
		close(filein);
		print_error();
	}
	close(filein);

int fileout = open(av[4], O_WRONLY);
   		if (fileout == -1)
			print_error();
	if (dup2(fileout, 1) == -1)
	{
		close(fileout);
		print_error();
	}
	close(fileout);

pid_t pid1 = fork();
	if (pid1 == -1)
		print_error();
	if (pid1 == 0)
	{
		char *cmd1 = av[2];
		char *args1[] = { cmd1, NULL };
		if (execve(cmd1, args1, envp) == -1)
			print_error();
	}

pid_t pid2 = fork();
	if (pid2 == -1)
		print_error();
	if (pid2 == 0)
	{
		char *cmd2 = av[3];
		char *args2[] = { cmd2, NULL };
		if (execve(cmd2, args2, envp) == -1)
			print_error();
	}

close(fileout);
	return 0;
}

// Tu dois pas donner le chemin de la commande mais le noms de la commande 
// Au lieu de recevoir /bin/grep, Tu reçois uniquement grep et ça doit fonctionner
// Tu dois aller chercher manuellement les chemin dans envp dans la variable PATH