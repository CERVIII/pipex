/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ch_path.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcervill <pcervill@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/18 16:27:16 by pcervill          #+#    #+#             */
/*   Updated: 2024/04/11 10:11:43 by pcervill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"

int	search_path(char **envp)
{
	int	i;

	i = 0;
	while (envp[i])
	{
		if (ft_strncmp(envp[i], "PATH=", 5) == 0)
			return (0);
		i++;
	}
	return (1);
}

char	*check_path(char *cmd, char **envp)
{
	int		i;
	char	**all_path;
	char	*section_path;
	char	*path;

	if (access(cmd, X_OK) == 0)
		return (cmd);
	if (search_path(envp) == 1)
		return (NULL);
	i = 0;
	while (ft_strnstr(envp[i], "PATH=", i) == 0)
		i++;
	all_path = ft_split(envp[i] + 6, ':');
	i = 0;
	while (all_path[i])
	{
		section_path = ft_strjoin(all_path[i], "/");
		path = ft_strjoin(section_path, cmd);
		free(section_path);
		if (access(path, F_OK) == 0)
			return (path);
		i++;
	}
	return (NULL);
}
