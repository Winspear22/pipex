/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_search_command.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adaloui <adaloui@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/16 16:40:35 by adaloui           #+#    #+#             */
/*   Updated: 2021/10/25 15:26:56 by adaloui          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	*path_add(char *location, char *cmd)
{
	char	*str;
	char	*tmp;

	str = ft_strjoin(location, "/");
	if (!str)
		return (NULL);
	tmp = str;
	str = ft_strjoin(str, cmd);
	free(tmp);
	if (!str)
		return (NULL);
	return (str);
}

char	*get_file_location(char *cmd, char **location)
{
	char	*cmd_location;
	int		fd;

	while (*location)
	{
		cmd_location = path_add(*location, cmd);
		fd = open(cmd_location, O_RDONLY);
		if (fd > 0)
			return (cmd_location);
		free(cmd_location);
		location++;
	}
	error_cmd("Error: your command does not exist.\n");
	ft_free_path(location);
	free(cmd);
	return (NULL);
}

char **ft_cut_argv(char **argv)
{
	char **cmd;

	while (argv[0])
	{
		cmd = ft_split(argv[0], '/');
		argv++;
	}
	argv[0] = cmd[1]; 
	return (argv);
}

t_cmd_data	get_all_cmd_and_files(int argc, char **argv, char **envp)
{
	t_cmd_data	*cmd;
	char		**paths;

	paths = get_cmd_location(envp);
	if (paths == NULL)
	{
		ft_free_path(paths);
		return (*cmd);
	}
	cmd = malloc(sizeof(char **) * 2 + sizeof(char *) * 2);
	if (!cmd)
	{
		free_cmd(cmd);
		return (*cmd);
	}
	cmd->argv = ft_split(argv[2], ' ');
	cmd->argv2 = ft_split(argv[3], ' ');
	if (cmd->argv[0][0] == '/')
		cmd->argv = ft_cut_argv(cmd->argv);
	if (cmd->argv2[0][0] == '/')
		cmd->argv2 = ft_cut_argv(cmd->argv2);
	cmd->file = get_file_location(cmd->argv[0], paths);
	cmd->file2 = get_file_location(cmd->argv2[0], paths);
	return (*cmd);
}
