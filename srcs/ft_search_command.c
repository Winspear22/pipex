/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_search_command.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adaloui <adaloui@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/16 16:40:35 by adaloui           #+#    #+#             */
/*   Updated: 2021/10/17 19:56:10 by adaloui          ###   ########.fr       */
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
	int		i;

	i = 0;
	while (*location)
	{
		cmd_location = path_add(*location, cmd);
		if (!cmd_location)
			return (0);
		fd = open(cmd_location, O_RDONLY);
		if (fd > 0)
			return (cmd_location);
		free (cmd_location);
		location++;
	}
	return (0);
}

t_cmd_data	get_all_cmd_and_files(int argc, char **argv, char **envp)
{
	t_cmd_data	*cmd;
	char		**paths;

	paths = get_cmd_location(envp);
	if (paths == NULL)
		return (*cmd);
	cmd = malloc(sizeof(t_cmd_data));
	if (cmd != NULL)
	{
		cmd->argv = ft_split(argv[2], ' ');
		cmd->file = get_file_location(cmd->argv[0], paths);
		cmd->argv2 = ft_split(argv[3], ' ');
		cmd->file2 = get_file_location(cmd->argv2[0], paths);
	}
	return (*cmd);
}
