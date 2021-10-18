/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_execute_command.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adaloui <adaloui@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/16 16:40:55 by adaloui           #+#    #+#             */
/*   Updated: 2021/10/18 18:04:04 by adaloui          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	child(int *pipe_fd)
{
	close(pipe_fd[0]);
	dup2(pipe_fd[1], 1);
	close(pipe_fd[1]);
}

void	parent(int *pipe_fd, t_fd *fd)
{
	close(pipe_fd[1]);
	dup2(fd->fd_in, 0);
	dup2(pipe_fd[0], 0);
	dup2(fd->fd_out, 1);
}

void	free_child(t_fd *fd)
{
	free_cmd(&fd->chemin);
	perror("Error, cannot execute child command. \n");
}

void	free_parent(t_fd *fd)
{
	free_cmd(&fd->chemin);
	perror("Error, cannot execute father command. \n");
}

void	command_execution(t_fd *fd)
{
	int		pipe_fd[2];
	pid_t	pid1;
	int		status;

	if (pipe(pipe_fd) == -1)
		return (perror("Error cannot create pipe\n"));
	pid1 = fork();
	if (pid1 < 0)
		return (perror("Error could not fork\n"));
	else if (pid1 == 0)
	{
		child(pipe_fd);
		if (execve(fd->chemin.file, &fd->chemin.argv[0], NULL) == -1)
			free_child(fd);
	}
	else if (pid1 > 0)
	{	
		waitpid(pid1, &status, 0);
		parent(pipe_fd, fd);
		if (execve(fd->chemin.file2, &fd->chemin.argv2[0], NULL) == -1)
			free_parent(fd);
	}
}
