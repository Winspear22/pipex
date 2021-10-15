/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adaloui <adaloui@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/15 16:07:49 by adaloui           #+#    #+#             */
/*   Updated: 2021/10/15 18:08:10 by adaloui          ###   ########.fr       */
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
	else if (access(argv[1], R_OK) < 0)
	{
		ft_putstr_fd("Error : no permission to access the file \"infile\". \n", 0);
		return (0);
	}
	return (1);
}

int	main(int argc, char **argv, char **envp)
{
	if (check_arg(argc, argv) == 0) 
        return (0);
    printf("salut les gars\n."); 
   	return (0);
}
