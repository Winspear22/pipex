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
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (cmd->argv[i] && cmd->argv2[j])
	{
		free(cmd->argv[i]);
		free(cmd->argv2[j]);
		i++;
		j++;
	}
	free(cmd->file);
	free(cmd->file2);
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
