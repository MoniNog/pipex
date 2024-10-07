/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moni <moni@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 15:53:22 by moni              #+#    #+#             */
/*   Updated: 2024/10/07 16:43:59 by moni             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

void	print_error(const char *text)
{
	perror(text);
	exit(EXIT_FAILURE);
}

char	*find_path(char *cmd, char **envp)
{
	char	**paths;
	char	*path;
	int		i;
	char	*part_path;

	i = 0;
	while (ft_strnstr(envp[i], "PATH", 4) == 0)
		i++;
	paths = ft_split(envp[i] + 5, ':');
	i = 0;
	while (paths[i])
	{
		part_path = ft_strjoin(paths[i], "/");
		path = ft_strjoin(part_path, cmd);
		free(part_path);
		if (access(path, F_OK) == 0)
			return (path);
		free(path);
		i++;
	}
	i = -1;
	while (paths[++i])
		free(paths[i]);
	free(paths);
	return (0);
}

pid_t	child_read_process(char *av, int *pipefd, char *cmd1, char *envp[])
{
	pid_t	pid1;
	int		file_in;
	char	*args1[2];

	args1[0] = cmd1;
	args1[1] = NULL;
	pid1 = fork ();
	file_in = open(av, O_RDONLY);
	if (file_in == -1)
		print_error("error opening file_in");
	if (pid1 == -1)
		print_error("fork child 1");
	if (pid1 == 0)
	{
		if (dup2(file_in, 0) == -1)
			print_error("dup2 file_in");
		close(file_in);
		if (dup2(pipefd[1], 1) == -1)
			print_error("dup2 pipefd[1]");
		close(pipefd[0]);
		close(pipefd[1]);
		cmd1 = find_path(cmd1, envp);
		if (execve(cmd1, args1, envp) == -1)
			exit(EXIT_FAILURE);
	}
	close (file_in);
	return (pid1);
}

pid_t	child_write_process(char *av, int *pipefd, char *cmd2, char *envp[])
{
	int		file_out;
	pid_t	pid2;
	char	*args2[2];

	args2[0] = cmd2;
	args2[1] = NULL;
	pid2 = fork();
	if (pid2 == -1)
		print_error("fork child 2");
	file_out = open(av, O_WRONLY | O_CREAT | O_TRUNC, 0666);
	if (file_out == -1)
		print_error("error opening file_out");
	if (pid2 == 0)
	{
		if (dup2(pipefd[0], 0) == -1)
			print_error("dup2 pipefd[0]");
		close(pipefd[0]);
		close(pipefd[1]);
		if (dup2(file_out, 1) == -1)
			print_error("dup2 file_out");
		close(file_out);
		cmd2 = find_path(cmd2, envp);
		if (execve(cmd2, args2, envp) == -1)
			exit(EXIT_FAILURE);
	}
	close(file_out);
	return (pid2);
}

int	main(int ac, char *av[], char *envp[])
{
	int		pipefd[2];
	pid_t	pid1;
	pid_t	pid2;
	char	*cmd1;
	char	*cmd2;

	if (ac != 5)
	{
		print_error("There is not exactly 4 arguments.\n");
		print_error("Try like that : <file_in> <cmd1> <cmd2> <file_out>\n");
	}
	if (pipe(pipefd) == -1)
		print_error("pipe");
	cmd1 = av[2];
	pid1 = child_read_process(av[1], pipefd, cmd1, envp);
	cmd2 = av[3];
	pid2 = child_write_process(av[4], pipefd, cmd2, envp);
	close(pipefd[0]);
	close(pipefd[1]);
	waitpid(pid1, NULL, 0);
	waitpid(pid2, NULL, 0);
	return (0);
}
