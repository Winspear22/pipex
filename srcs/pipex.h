/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adaloui <adaloui@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/15 16:07:32 by adaloui           #+#    #+#             */
/*   Updated: 2021/10/17 19:52:11 by adaloui          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <unistd.h>
# include <stdio.h>
# include "../libft/libft.h"
# include <fcntl.h>
# include <sys/wait.h>
# include <string.h>
# include <stdlib.h>

typedef struct s_cmd_data
{
	char	*file;
	char	*file2;
	char	**argv;
	char	**argv2;
}				t_cmd_data;

typedef struct s_fd
{
	int				fd_in;
	int				fd_out;
	t_cmd_data		chemin;
}				t_fd;

int			check_arg(int argc, char **argv);
int			fd_initialisation(t_fd *fd, int argc, char **argv);
int			paths_initialisation(t_fd *fd, int argc, char **argv, char **envp);

static char	**get_paths(char **envp);
t_cmd_data	get_all_cmd_and_files(int argc, char **argv, char **envp);

void		command_execution(t_fd *fd);

char		**get_cmd_location(char **envp);

#endif
