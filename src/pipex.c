/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcervill <pcervill@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/04 10:32:25 by pcervill          #+#    #+#             */
/*   Updated: 2023/09/11 13:37:47 by pcervill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"

void	ft_error2(int code)
{
	perror("\033[31mError");
	exit(code);
}

int	child_process(int *fd, char *argv[], char *envp[])
{
	int	infile;

	infile = open(argv[1], 1);
	dup2(fd[1], STDOUT_FILENO);
	dup2(infile, STDIN_FILENO);
	close(fd[0]);
}

int	main(int argc, char *argv[], char *envp[])
{
	int	fd[2];
	pid_t	pid;

	if (argc < 4)
		ft_error2(1);
	if (pipe(fd) == -1)
		ft_error2(1);
	pid = fork();
	if (pid == -1)
		ft_error2(1);
	if (pid == 0)
	{
		
	}
	if (argv[0])
		return (0);
	return (0);
}


/* ft_check_arg(int argc, char *argv[])
{
	
} */
