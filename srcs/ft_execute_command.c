/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_execute_command.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adaloui <adaloui@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/16 16:40:55 by adaloui           #+#    #+#             */
/*   Updated: 2021/10/25 15:30:35 by adaloui          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	ft_child(t_fd *folder, int *fd)
{
	close(folder->fd_out);
	dup2(folder->fd_in, STDIN_FILENO);
	dup2(fd[1], 1);
	close(folder->fd_in);
}

void	ft_parent(t_fd *folder, int *fd)
{
	close(folder->fd_in);
	dup2(fd[0], 0);
	dup2(folder->fd_out, STDOUT_FILENO);
	close(folder->fd_out);
	close(fd[0]);
	close(fd[1]);
}

void	free_child(t_fd *folder)
{
	free(folder->chemin.file);
	ft_free_path(folder->chemin.argv);
	perror("Error, cannot execute child command. \n");
}

void	free_parent(t_fd *folder)
{
	free(folder->chemin.file2);
	ft_free_path(folder->chemin.argv2);
	perror("Error, cannot execute father command. \n");
}

void	command_execution(t_fd *folder)
{
	int	fd[2];
	int	pid;
	int	status;

	pipe(fd);
	pid = fork();
	if (pid < 0)
		perror("Fork error");
	else if (pid == 0 && folder->chemin.file != NULL)
	{
		ft_child(folder, fd);
		if (execve(folder->chemin.file, folder->chemin.argv, NULL) == -1)
			free_child(folder);
	}
	else if (pid > 0 && folder->chemin.file2 != NULL)
	{
		ft_parent(folder, fd);
		if (execve(folder->chemin.file2, folder->chemin.argv2, NULL) == -1)
			free_parent(folder);
	}
}
