/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_and_init_fd.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adaloui <adaloui@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/16 16:40:44 by adaloui           #+#    #+#             */
/*   Updated: 2021/10/25 18:50:41 by adaloui          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	check_arg(int argc, char **argv, char **envp)
{
	if (argc != 5)
	{
		ft_putstr_fd("Error : Not enough or too much arguments ! \n", 0);
		return (0);
	}
	else if (!argv[2][0] || !argv[3][0])
	{
		ft_putstr_fd("Error : need arguments.\n", 0);
		return (0);
	}
	else if (envp[0] == NULL)
	{
		ft_putstr_fd("Error : $ENV variable is empty.\n", 0);
		return (0);
	}
	else if (access(argv[1], R_OK) == -1)
	{
		ft_putstr_fd("Error : no permission to access the file \"infile\". \n", 0);
		return (0);
	}
	else if (ft_check_arg_content(argv, envp) == 0)
		return (0);
	printf("nono");
	return (1);
}
int	fd_initialisation(t_fd *fd, int argc, char **argv)
{
	fd->fd_in = open(argv[1], O_RDONLY);
	fd->fd_out = open(argv[argc - 1], O_WRONLY | O_CREAT | O_TRUNC, 0666);
	if (fd->fd_out < 0)
	{
		ft_putstr_fd("Error, no permission to write in outfoule\n.", 0);
		return (0);
	}
	return (1);
}

int	paths_initialisation(t_fd *fd, int argc, char **argv, char **envp)
{
	fd->chemin = get_all_cmd_and_files(argc, argv, envp);
	if (fd->chemin.argv == NULL || fd->chemin.argv2 == NULL
		|| fd->chemin.file == NULL || fd->chemin.file2 == NULL)
		return (0);
	return (1);
}
