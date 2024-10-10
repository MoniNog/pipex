/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moni <moni@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 15:53:22 by moni              #+#    #+#             */
/*   Updated: 2024/10/10 18:50:27 by moni             ###   ########.fr       */
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

void	execute(int *pipefd, int file, char *cmd, char *envp[])
{
	char	*args[2];

	args[0] = cmd;
	args[1] = NULL;
	if (dup2(pipefd[0], 0) == -1)
		print_error("dup2 pipefd[0]");
	close(pipefd[0]);
	close(pipefd[1]);
	if (dup2(file, 1) == -1)
		print_error("dup2 file_out");
	close(file);
	if (find_path(cmd, envp) == 0)
	{	
		ft_putstr_fd("command not found: ", 2);
		ft_putendl_fd(cmd, 2);
	}
	else
		cmd = find_path(cmd, envp);
	if (execve(cmd, args, envp) == -1)
		exit(EXIT_FAILURE);
}

pid_t	child_read_process(char *av, int *pipefd, char *cmd1, char *envp[])
{
	int		file_in;
	pid_t	pid1;

	pid1 = fork();
	if (pid1 == -1)
		print_error("fork child 1");
	if (open(av, O_RDONLY) == -1)
	{	
		ft_putstr_fd("no such file or directory: ", 2);
		ft_putendl_fd(av, 2);
		kill(pid1, SIGKILL);
		exit(EXIT_FAILURE);
	}
	else
	{
		file_in = open(av, O_RDONLY);
		if (pid1 == 0)
			execute(pipefd, file_in, cmd1, envp);
		close (file_in);
	}
	return (pid1);
}

pid_t	child_write_process(char *av, int *pipefd, char *cmd2, char *envp[])
{
	int		file_out;
	pid_t	pid2;

	pid2 = fork();
	if (pid2 == -1)
		print_error("fork child 2");
	if (open(av, O_RDONLY) == -1)
	{	
		ft_putstr_fd("no such file or directory: ", 2);
		ft_putendl_fd(av, 2);
		kill(pid2, SIGKILL);
		exit(EXIT_FAILURE);
	}
	else
	{
		file_out = open(av, O_WRONLY | O_CREAT | O_TRUNC, 0666);
		if (pid2 == 0)
			execute(pipefd, file_out, cmd2, envp);
		close(file_out);
	}
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
	cmd2 = av[3];
	pid1 = child_read_process(av[1], pipefd, cmd1, envp);
	pid2 = child_write_process(av[4], pipefd, cmd2, envp);
	waitpid(pid1, NULL, 0);
	waitpid(pid2, NULL, 0);
	close(pipefd[0]);
	close(pipefd[1]);
	return (0);
}
