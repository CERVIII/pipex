/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcervill <pcervill@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/04 10:32:25 by pcervill          #+#    #+#             */
/*   Updated: 2024/04/15 15:41:15 by pcervill         ###   ########.fr       */
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
	pid_t	child_pid;
	pid_t	father_pid;

	if (argc != 5 || pipe(fd) == -1)
		ft_error2(1, "Error");
	child_pid = fork();
	if (child_pid == -1)
		ft_error2(1, "Error: fork");
	if (child_pid == 0)
		child_process(fd, argv, envp);
	else
	{
		father_pid = fork();
		if (father_pid == -1)
			ft_error2(1, "Error: fork");
		if (father_pid == 0)
			parent_process(fd, argv, envp);
		close(fd[0]);
		close(fd[1]);
		waitpid(child_pid, NULL, 0);
		waitpid(father_pid, NULL, 0);
	}
	return (0);
}
