/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_search_command.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adaloui <adaloui@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/16 16:40:35 by adaloui           #+#    #+#             */
/*   Updated: 2021/10/19 21:23:18 by adaloui          ###   ########.fr       */
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

char	*get_file_location(char *cmd, char **location, t_cmd_data *cmd2)
{
	char	*cmd_location;
	int		fd;

	while (*location)
	{
		cmd_location = path_add(*location, cmd);
		if (!cmd_location)
			return (error_cmd("You need to write a command.\n"));
		fd = open(cmd_location, O_RDONLY);
		if (fd > 0)
			return (cmd_location);
		free (cmd_location);
		location++;
	}
	//free_cmd(cmd2);
	error_cmd("Error: your command does not exist.\n");
	//exit (0);
	return (NULL);
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
	cmd = malloc(sizeof(t_cmd_data));
	if (!cmd)
	{
		free_cmd(cmd);
		return (*cmd);
	}
	cmd->argv = ft_split(argv[2], ' ');
	cmd->file = get_file_location(cmd->argv[0], paths, cmd);
	cmd->argv2 = ft_split(argv[3], ' ');
	cmd->file2 = get_file_location(cmd->argv2[0], paths, cmd);
	if (!cmd->file || !cmd->file2)
	{
		free_cmd(cmd);
		exit(0);
	}
	return (*cmd);
}
