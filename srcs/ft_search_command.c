/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_search_command.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adaloui <adaloui@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/16 16:40:35 by adaloui           #+#    #+#             */
/*   Updated: 2021/10/27 14:39:14 by adaloui          ###   ########.fr       */
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
	char	*str;

	str = "Error";
	while (*location)
	{
		cmd_location = path_add(*location, cmd);
		fd = open(cmd_location, O_RDONLY);
		if (fd > 0)
		{	
			close(fd);
			return (cmd_location);
		}
		free(cmd_location);
		location++;
	}
	error_cmd("Error: your command does not exist.\n");
	return (str);
}

t_cmd_data	*parse_cmd(char **argv, char **paths, t_cmd_data *cmd)
{
	if (argv[2][0] == '/')
	{
		cmd->argv = ft_split(argv[2], '/');
		cmd->argv[0] = cmd->argv[1];
		cmd->argv[1] = NULL;
		cmd->file = get_file_location(cmd->argv[0], paths);
	}
	if (argv[3][0] == '/')
	{
		cmd->argv2 = ft_split(argv[3], '/');
		cmd->argv2[0] = cmd->argv2[1];
		cmd->argv2[1] = NULL;
		cmd->file2 = get_file_location(cmd->argv2[0], paths);
	}
	if (argv[2][0] != '/')
	{
		cmd->argv = ft_split(argv[2], ' ');
		cmd->file = get_file_location(cmd->argv[0], paths);
	}
	if (argv[3][0] != '/')
	{
		cmd->argv2 = ft_split(argv[3], ' ');
		cmd->file2 = get_file_location(cmd->argv2[0], paths);
	}
	return (cmd);
}

t_cmd_data	*init_cmd(void)
{
	t_cmd_data	*new;

	new = malloc(sizeof(t_cmd_data));
	if (new == NULL)
		return (NULL);
	new->file = NULL;
	new->file2 = NULL;
	new->argv = NULL;
	new->argv2 = NULL;
	return (new);
}

t_cmd_data	*get_all_cmd_and_files(int argc, char **argv, char **envp)
{
	t_cmd_data	*cmd;
	char		**paths;

	paths = get_cmd_location(envp);
	cmd = init_cmd();
	if (cmd == NULL)
		return (NULL);
	cmd = parse_cmd(argv, paths, cmd);
	ft_free_path(paths);
	return (cmd);
}
