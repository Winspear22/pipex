/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_execute_command.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adaloui <adaloui@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/16 16:40:55 by adaloui           #+#    #+#             */
/*   Updated: 2021/10/16 20:28:16 by adaloui          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static void	child(int	*pipefd)
{
	close(pipefd[0]);
	dup2(pipefd[1], 1);
	close(pipefd[1]);
}

static void	parent(int *pipefd, t_fd *fd)
{
	close(pipefd[1]);
	dup2(fd->fd_in, 0);
	dup2(pipefd[0], 0);
	dup2(fd->fd_out, 1);
}

void    exec_cmd(t_fd *fd)
{
    int pipe_fd[2];
    int pid1;
    int status;

    if (pipe(pipe_fd) == -1)
        return (perror("Error pipe\n"));
    pid1 = fork();
    if (pid1 < 0)
        return (perror("Error fork\n"));
    else if (pid1 == 0)
    {
        child(pipe_fd);
        execve(fd->chemin.file, &fd->chemin.argv[0], NULL);
    }       
    else if (pid1 > 0)
    {
        waitpid(pid1, &status, 0);
        parent(pipe_fd, fd);
        execve(fd->chemin.file2, &fd->chemin.argv2[0], NULL);
    }
}