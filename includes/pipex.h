#ifndef FT_PIPEX_H
# define FT_PIPEX_H

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

typedef struct s_pipex
{
	int		in_fd;
	int		out_fd;
	bool	here_doc;
	bool	is_valid_infile;
	char	**cmd_path;
	char	***cmd_args;
	int		cmd_count;
} 			t_pipex;

#endif