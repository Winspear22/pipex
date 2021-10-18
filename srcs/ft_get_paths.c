/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_paths.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adaloui <adaloui@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/16 21:43:13 by adaloui           #+#    #+#             */
/*   Updated: 2021/10/18 17:33:09 by adaloui          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	**get_cmd_location(char **envp)
{
	char	**location;

	while (*envp)
	{
		if (ft_strnstr(*envp, "PATH", 10))
		{
			while (**envp != '/')
				*envp += 1;
			location = ft_split(*envp, ':');
			if (!location)
				return (0);
			return (location);
		}
		envp++;
	}
	return (0);
}
