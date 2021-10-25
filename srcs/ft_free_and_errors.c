/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_and_errors.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adaloui <adaloui@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/19 20:58:00 by adaloui           #+#    #+#             */
/*   Updated: 2021/10/25 18:51:08 by adaloui          ###   ########.fr       */
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
		write(0, message, ft_strlen(message));
	return (0);
}

void	*error_cmd(char *message)
{
	error_cmd_handling(message);
	return (NULL);
}

int check_arg_one(char **argv, char **paths)
{
	char *file;
	char **argv1;

	file = malloc(sizeof(char *) + 1);
	argv1 = malloc(sizeof(char **) + 1);
	argv1 = ft_split(argv[2], ' ');
	file = get_file_location(argv1[0], paths);
	if (file == NULL)
	{
		free(file);
		ft_free_path(argv1);
		return (0);
	}
	free(file);
	ft_free_path(argv1);
	return (1);
}

int check_arg_two(char **argv, char **paths)
{
	char *file2;
	char **argv2;

	file2 = malloc(sizeof(char *) + 1);
	argv2 = malloc(sizeof(char **) + 1);
	argv2 = ft_split(argv[3], ' ');
	file2 = get_file_location(argv2[0], paths);
	printf("%s\n", file2);
	printf("%s\n", argv2[0]);
	if (file2 == NULL)
	{
		free(file2);
		ft_free_path(argv2);
		return (0);
	}
	free(file2);
	ft_free_path(argv2);
	return (1);
}

int	ft_check_arg_content(char **argv, char **envp)
{
	char **paths;
	int		i;
	int		j;

	paths = get_cmd_location(envp);
	if (paths == NULL)
	{
		ft_free_path(paths);
		return (0);
	}
	i = check_arg_one(argv, paths);
	j = check_arg_two(argv, paths);
	printf("%d\n", i);
	printf("%d\n", j);
	if (j == 0 && i == 0)
	{
		ft_free_path(paths);
		return (0);
	}
	return (1);
}