/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcervill <pcervill@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/04 10:32:25 by pcervill          #+#    #+#             */
/*   Updated: 2024/04/10 13:33:00 by pcervill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"

/* static void	leaks(void)
{
	system("leaks -q pipex");
} */
//		atexit(leaks);

int	main(int argc, char *argv[], char *envp[])
{
	int		fd[2];
	pid_t	pid;

	if (argc == 5)
	{
		if (pipe(fd) == -1)
			ft_error2(1, "Error: pipe");
		pid = fork();
		if (pid == -1)
			ft_error2(1, "Error: fork");
		if (pid == 0)
			child_process(fd, argv, envp);
		waitpid(pid, NULL, 0);
		parent_process(fd, argv, envp);
	}
	else
		ft_error2(1, "Error: Invalid number of arguments");
	return (0);
}
