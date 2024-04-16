/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcervill <pcervill@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/18 16:02:48 by pcervill          #+#    #+#             */
/*   Updated: 2024/04/16 10:57:39 by pcervill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"

void	ft_error2(int code, char *err)
{
	if (code != 127)
		perror(err);
	else
		ft_putstr_fd(err, 2);
	exit(code);
	return ;
}

int	open_file(char *argv, int file_in_out)
{
	int	file;

	file = 0;
	if (file_in_out == 1)
		file = open(argv, O_RDONLY);
	if (file_in_out == 2)
		file = open(argv, O_WRONLY | O_CREAT | O_TRUNC, 0666);
	if (file == -1)
		ft_error2(1, "Error");
	return (file);
}

void	command(char *argv, char *envp[])
{
	char	**cmd;

	cmd = ft_split(argv, ' ');
	if (execve(check_path(cmd[0], envp), cmd, envp) == -1)
		ft_error2(127, "Error: command not found\n");
	return ;
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
	return ;
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
	return ;
}
