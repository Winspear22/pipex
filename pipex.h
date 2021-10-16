/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adaloui <adaloui@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/15 16:07:32 by adaloui           #+#    #+#             */
/*   Updated: 2021/10/16 18:51:59 by adaloui          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <unistd.h>
# include <stdio.h>
# include "libft/libft.h"
# include <fcntl.h>
# include <string.h>
# include <stdlib.h>

typedef struct s_command
{
    char    *file;
    char    *file2;
    char    **argv;
    char    **argv2;
}   t_command;

typedef struct s_fd
{
    int     fd_in;
    int     fd_out;
    t_command   chemin;
}   t_fd;

int	check_arg(int argc, char **argv);
int	fd_initialisation(t_fd *fd, int argc, char **argv);
int	paths_initialisation(t_fd *fd, int argc, char **argv, char **envp);

static char	**get_paths(char **envp);
t_command init_cmdlist(int argc, char **argv,char **envp);

void	exec_cmd(t_fd *fd);

#endif