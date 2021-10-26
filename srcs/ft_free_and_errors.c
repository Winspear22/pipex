/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_and_errors.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adaloui <adaloui@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/19 20:58:00 by adaloui           #+#    #+#             */
/*   Updated: 2021/10/19 20:59:12 by adaloui          ###   ########.fr       */
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

int	error_cmd_handling(char *message)
{
	if (1)
		write(2, message, ft_strlen(message));
	return (0);
}

void	*error_cmd(char *message)
{
	error_cmd_handling(message);
	return (NULL);
}
