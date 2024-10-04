#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

#include "../includes/pipex.h"

int main(int argc, char *argv[], char *envp[]) {
    if (argc < 2) {
        fprintf(stderr, "Usage: %s <command> [args...]\n", argv[0]);
        return 1;
    }
	int filein; 
	
	filein = open(argv[1], O_RDONLY, 0777);
	if (filein == -1) {
		printf("can't open file");
		return 1;}
	if (dup2(filein, 0) == -1) {
		perror("dup2");
		close(filein);
		return 1;
    }
    close(filein);

	int fileout; 
	
	fileout = open(argv[3], O_WRONLY, 0777);
	if (fileout == -1)
	{
		printf("can't open file");
		return 1;
	}

	if (dup2(fileout, 1) == -1)
	{
		perror("dup2");
		close(fileout);
		return 1;
    }
    close(fileout);

    // Construire le chemin complet de la commande
    char *path = "/bin/"; // Vous pouvez changer ce chemin en fonction de l'emplacement de votre commande
    char full_path[256];
    snprintf(full_path, sizeof(full_path), "%s%s", path, argv[2]);


    // Préparez les arguments pour execve
    char *args[argc-1];
    for (int i = 2; i < argc; i++) {
        args[i - 1] = argv[i];
    }
    args[argc - 2] = NULL;


    // Exécutez la commande
    if (execve(full_path, args, envp) == -1) {
        printf("ici"); // ecrit dans output.txt
		perror("execve");
        return 1;
    }

    return 0;
}

	// init_pipex;
	// check_args;
	// parse_cmd;
	// parse_args;
	// while (cmds)
	// 	exec;
	// clean_up;


// void	child_process(char **argv, char **envp, int *fd)
// {
// 	int		filein;

// 	filein = open(argv[1], O_RDONLY, 0777);
// 	if (filein == -1)
// 		error();
// 	dup2(fd[1], STDOUT_FILENO);
// 	dup2(filein, STDIN_FILENO);
// 	close(fd[0]);
// 	execute(argv[2], envp);
// }

// /* Parent process that take the data from the pipe, change the output for the
//  fileout and also close with the exec function */
// void	parent_process(char **argv, char **envp, int *fd)
// {
// 	int		fileout;

// 	fileout = open(argv[4], O_WRONLY | O_CREAT | O_TRUNC, 0777);
// 	if (fileout == -1)
// 		error();
// 	dup2(fd[0], STDIN_FILENO);
// 	dup2(fileout, STDOUT_FILENO);
// 	close(fd[1]);
// 	execute(argv[3], envp);
// }

// /* Main function that run the child and parent process or display an error
//  message if arguments are wrong */
// int	main(int argc, char **argv, char **envp)
// {
// 	int		fd[2];
// 	pid_t	pid1;

// 	if (argc == 5)
// 	{
// 		if (pipe(fd) == -1)
// 			error();
// 		pid1 = fork();
// 		if (pid1 == -1)
// 			error();
// 		if (pid1 == 0)
// 			child_process(argv, envp, fd);
// 		waitpid(pid1, NULL, 0);
// 		parent_process(argv, envp, fd);
// 	}
// 	else
// 	{
// 		ft_putstr_fd("\033[31mError: Bad arguments\n\e[0m", 2);
// 		ft_putstr_fd("Ex: ./pipex <file1> <cmd1> <cmd2> <file2>\n", 1);
// 	}
// 	return (0);
// }