/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_bin.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adaloui <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/27 19:15:56 by adaloui           #+#    #+#             */
/*   Updated: 2021/10/27 19:17:21 by adaloui          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

t_cmd_data	*parse_cmd_bin_child(char **argv, char **paths, t_cmd_data *cmd)
{
	if (ft_strncmp(argv[2], "/bin/", 5) == 0)
	{
		cmd->argv = ft_split(argv[2], '/');
		if (cmd->argv[1] != NULL)
		{
			ft_strlcpy(cmd->argv[0], cmd->argv[1], ft_strlen(argv[2]));
			cmd->argv = ft_split(cmd->argv[1], ' ');
			cmd->file = get_file_location(cmd->argv[0], paths);
			return (cmd);
		}
		else
			error_cmd("zsh: command not found: ", "/bin/");
	}
	return (cmd);
}

t_cmd_data	*parse_cmd_bin_father(char **argv, char **paths, t_cmd_data *cmd)
{
	if (ft_strncmp(argv[3], "/bin/", 5) == 0)
	{
		cmd->argv2 = ft_split(argv[3], '/');
		if (cmd->argv2[1] != NULL)
		{
			ft_strlcpy(cmd->argv2[0], cmd->argv2[1], ft_strlen(argv[3]));
			cmd->argv2 = ft_split(cmd->argv2[1], ' ');
			cmd->file2 = get_file_location(cmd->argv2[0], paths);
			return (cmd);
		}
		else
			error_cmd("zsh: command not found: ", "/bin/");
	}
	return (cmd);
}
