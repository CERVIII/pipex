/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcervill <pcervill@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/18 16:02:48 by pcervill          #+#    #+#             */
/*   Updated: 2023/09/19 09:53:43 by pcervill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"

void	ft_error2(int code)
{
	perror("\x1B[31mError\x1B[0m");
	exit(code);
}

int	open_file(char *argv, int file_in_out)
{
	int	file;

	file = 0;
	if (file_in_out == 1)
		file = open(argv, O_RDONLY);
	if (file_in_out == 2)
		file = open(argv, O_WRONLY | O_CREAT | O_TRUNC, 0777);
	if (file == -1)
		ft_error2(1);
	return (file);
}

void	command(char *argv, char *envp[])
{
	char	**cmd;

	cmd = ft_split(argv, ' ');
	if (execve(check_path(cmd[0], envp), cmd, envp) == -1)
		ft_error2(127);
}

void	child_process(int *fd, char *argv[], char *envp[])
{
	int	infile;

	infile = open_file(argv[1], 1);
	dup2(fd[1], STDOUT_FILENO);
	dup2(infile, STDIN_FILENO);
	close(fd[0]);
	close(fd[1]);
	command(argv[2], envp);
}

void	parent_process(int *fd, char *argv[], char *envp[])
{
	int	outfile;

	outfile = open_file(argv[4], 2);
	dup2(fd[0], STDIN_FILENO);
	dup2(outfile, STDOUT_FILENO);
	close(fd[1]);
	close(fd[0]);
	command(argv[3], envp);
}
