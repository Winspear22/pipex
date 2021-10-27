/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_and_errors.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adaloui <adaloui@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/19 20:58:00 by adaloui           #+#    #+#             */
/*   Updated: 2021/10/27 19:16:54 by adaloui          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	free_cmd(t_cmd_data *cmd)
{
	ft_free_path(cmd->argv);
	ft_free_path(cmd->argv2);
}

void	ft_free_path(char **path)
{
	int	i;

	i = 0;
	while (path[i])
	{
		free(path[i]);
		i++;
	}
	free(path);
}

int	error_cmd_handling(char *message, char *str)
{
	if (1)
	{
		write(2, message, ft_strlen(message));
		write(2, str, ft_strlen(str));
		write(2, "\n", 1);
	}
	return (0);
}

void	*error_cmd(char *message, char *str)
{
	error_cmd_handling(message, str);
	return (NULL);
}
