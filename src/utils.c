/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moni <moni@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/18 10:24:49 by moni              #+#    #+#             */
/*   Updated: 2024/10/21 16:17:51 by moni             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

void	print_error(const char *text)
{
	perror(text);
	exit(EXIT_FAILURE);
}

void	error_kill_exit(int file_in, char *file_name, pid_t pid)
{
	ft_putstr_fd("no such file or directory: ", 2);
	ft_putendl_fd(file_name, 2);
	close(file_in);
	kill(pid, SIGKILL);
	exit(EXIT_FAILURE);
}

void	error_access(char *file_name)
{
	ft_putstr_fd("permission denied: ", 2);
	ft_putendl_fd(file_name, 2);
	exit(EXIT_FAILURE);
}

void	free_split(char **cmd)
{
	int	i;

	i = 0;
	while (cmd[i] != NULL)
	{
		free(cmd[i]);
		i++;
	}
	free(cmd);
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
	return (NULL);
}
