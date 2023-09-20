/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcervill <pcervill@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/04 10:32:25 by pcervill          #+#    #+#             */
/*   Updated: 2023/09/19 10:52:10 by pcervill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"

static void	leaks(void)
{
	system("leaks -q pipex");
}

int	main(int argc, char *argv[], char *envp[])
{
	int		fd[2];
	pid_t	pid;

	atexit(leaks);
	if (argc == 5)
	{
		if (pipe(fd) == -1)
			ft_error2(1);
		pid = fork();
		if (pid == -1)
			ft_error2(1);
		if (pid == 0)
			child_process(fd, argv, envp);
		waitpid(pid, NULL, 0);
		parent_process(fd, argv, envp);
	}
	else
		ft_error2(1);
	return (0);
}
