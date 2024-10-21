/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moni <moni@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 16:32:47 by moni              #+#    #+#             */
/*   Updated: 2024/10/21 16:17:39 by moni             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <stdio.h>
# include <unistd.h>
# include <stdio.h>
# include <stdbool.h>
# include <stdlib.h>
# include <unistd.h>
# include <string.h>
# include <stdio.h>
# include <sys/wait.h>
# include <fcntl.h>
# include "libft.h"
# include <signal.h>

void	error_kill_exit(int file_in, char *file_name, pid_t pid);
void	print_error(const char *text);
void	error_access(char *file_name);
char	*find_path(char *cmd, char **envp);
void	free_split(char **cmd);

#endif