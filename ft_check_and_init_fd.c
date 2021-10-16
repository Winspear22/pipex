/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_and_init_fd.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adaloui <adaloui@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/16 16:40:44 by adaloui           #+#    #+#             */
/*   Updated: 2021/10/16 19:52:13 by adaloui          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	check_arg(int argc, char **argv)
{
	if (argc < 5)
	{
		ft_putstr_fd("Error : There's not enough arguments ! \n", 0);
		return (0);
	}
	else if (access(argv[1], R_OK) == -1)
	{
		ft_putstr_fd("Error : no permission to access the file \"infile\". \n", 0);
		return (0);
	}
	return (1);
}

int	fd_initialisation(t_fd *fd, int argc, char **argv)
{
	fd->fd_in = open(argv[1], O_RDONLY);
	fd->fd_out = open(argv[argc - 1], O_WRONLY | O_CREAT | O_TRUNC, 0666);
	if (fd->fd_out < 0)
	{
		ft_putstr_fd("Erreur, vous n'avez pas la permission d'ecrire dans outfile",0);
		return (0);
	}
	return (1);
}

int	paths_initialisation(t_fd *fd, int argc, char **argv, char **envp)
{
	fd->chemin = init_cmdlist(argc, argv, envp);
	if (fd->chemin.argv == NULL || fd->chemin.argv2 == NULL)
		return (0);
	return (1);
}