/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moni <moni@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 15:53:22 by moni              #+#    #+#             */
/*   Updated: 2024/10/21 16:16:42 by moni             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

void	execute_read(int *pipefd, int file, char **cmd, char *envp[])
{
	char	*path;

	close(pipefd[0]);
	if (dup2(pipefd[1], 1) == -1)
	{
		print_error("dup2 pipefd[1]");
		close(pipefd[1]);
	}
	if (dup2(file, 0) == -1)
	{
		print_error("dup2 file_in");
		close(file);
	}
	path = find_path(cmd[0], envp);
	if (path == NULL)
	{
		ft_putstr_fd("command not found: ", 2);
		ft_putendl_fd(cmd[0], 2);
	}
	if (execve(path, cmd, envp) == -1)
		exit(EXIT_FAILURE);
}

void	execute_write(int *pipefd, int file, char **cmd, char *envp[])
{
	char	*path;

	if (dup2(pipefd[0], 0) == -1)
	{
		print_error("dup2 pipefd[0]");
		close(pipefd[0]);
	}
	if (dup2(file, 1) == -1)
	{
		print_error("dup2 file_out");
		close(file);
	}
	path = find_path(cmd[0], envp);
	if (path == NULL)
	{
		ft_putstr_fd("command not found: ", 2);
		ft_putendl_fd(cmd[0], 2);
	}
	if (execve(path, cmd, envp) == -1)
		exit(EXIT_FAILURE);
}

pid_t	child_read_process(char *file_name, int *pipefd,
	char *cmd1, char *envp[])
{
	int		file_in;
	pid_t	pid1;
	char	**cmd;

	pid1 = fork();
	if (pid1 == -1)
		print_error("fork child 1");
	file_in = open(file_name, O_RDONLY);
	if (file_in == -1)
	{
		if (access(file_name, F_OK) == -1)
			error_access(file_name);
		else
			error_kill_exit(file_in, file_name, pid1);
	}
	else
	{
		cmd = ft_split(cmd1, ' ');
		if (pid1 == 0)
			execute_read(pipefd, file_in, cmd, envp);
		close (file_in);
		free_split(cmd);
	}
	return (pid1);
}

pid_t	child_write_process(char *file_name, int *pipefd,
	char *cmd2, char *envp[])
{
	int		file_out;
	pid_t	pid2;
	char	**cmd;

	pid2 = fork();
	if (pid2 == -1)
		print_error("fork child 2");
	file_out = open(file_name, O_WRONLY | O_CREAT | O_TRUNC, 0666);
	if (file_out == -1)
	{
		ft_putstr_fd("permission denied: ", 2);
		ft_putendl_fd(file_name, 2);
		close(file_out);
		kill(pid2, SIGKILL);
		exit(EXIT_FAILURE);
	}
	else
	{
		cmd = ft_split(cmd2, ' ');
		if (pid2 == 0)
			execute_write(pipefd, file_out, cmd, envp);
		close(file_out);
		free_split(cmd);
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
	close(pipefd[1]);
	waitpid(pid1, NULL, 0);
	pid2 = child_write_process(av[4], pipefd, cmd2, envp);
	waitpid(pid2, NULL, 0);
	close(pipefd[0]);
	return (0);
}
