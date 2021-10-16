/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_search_command.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adaloui <adaloui@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/16 16:40:35 by adaloui           #+#    #+#             */
/*   Updated: 2021/10/16 20:08:41 by adaloui          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static char	*add_pathcmd(char *path, char *cmd)
{
	char	*aux;
	char	*output;

	output = ft_strjoin(path, "/");
	if (!output)
		return (NULL);
	aux = output;
	output = ft_strjoin(output, cmd);
	free(aux);
	if (!output)
		return (NULL);
	return (output);
}

static char	*get_cmd_file(char *cmd, char **paths)
{
	char	*output;
	char	*str;
	int		fd;

	while (*paths)
	{
		str = add_pathcmd(*paths, cmd); //cmd = ls et paths = chemin de ls
		if (!str)
			return (0);
		fd = open(str, O_RDONLY);
		if (fd > 0)
		{
			close(fd);
			return (str);
		}
		close (fd);
		free (str);
		paths++;
	}
	return (0);
}
static char	**get_paths(char **envp)
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

t_command init_cmdlist(int argc, char **argv,char **envp)
{
	char *cmd_lst;
	t_command *cmd;
	char **paths;
	int i;

	i = 0;
	paths = get_paths(envp);
	if (paths == NULL)
		return (*cmd);
	cmd = malloc(sizeof(t_command));
	if (cmd != NULL)
	{
		cmd->argv = ft_split(argv[2], ' ');
		cmd->file = get_cmd_file(cmd->argv[0], paths);
		cmd->argv2 = ft_split(argv[3],  ' ');
		cmd->file2 = get_cmd_file(cmd->argv2[0], paths);
	}
	return (*cmd);
}