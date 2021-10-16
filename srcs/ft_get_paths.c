/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_paths.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adaloui <adaloui@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/16 21:43:13 by adaloui           #+#    #+#             */
/*   Updated: 2021/10/16 22:02:08 by adaloui          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	**get_cmd_paths(char **envp)
{
	char	**paths;
	int		i;
	int		j;

	i = -1;
	j = 0;
	while (envp[++i])
	{
		j = 0;
		while (envp[i][j])
		{
			if (ft_strnstr(&envp[i][j], "PATH", 10))
			{
				while (envp[i][j] != '/')
					envp[i] += 1;
				paths = ft_split(envp[i], ':');
				if (!paths)
					return (0);
				return (paths);
			}
			j++;
		}
	}
	return (0);
}
