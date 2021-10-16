/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adaloui <adaloui@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/15 16:07:49 by adaloui           #+#    #+#             */
/*   Updated: 2021/10/16 20:08:47 by adaloui          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	main(int argc, char **argv, char **envp)
{
	t_fd fd;

	if (check_arg(argc, argv) == 0)
		return (0);
	if (fd_initialisation(&fd, argc, argv) == 0)
		return (0);
	if (paths_initialisation(&fd, argc, argv, envp) == 0)
		return (0);

	exec_cmd(&fd);

	return (0);
}
