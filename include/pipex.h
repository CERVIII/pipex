/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcervill <pcervill@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/04 10:37:19 by pcervill          #+#    #+#             */
/*   Updated: 2024/04/10 11:02:59 by pcervill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include "./libft/libft.h"
# include <unistd.h>
# include <string.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/wait.h>
# include <fcntl.h>
# include <errno.h>

/* UTILS.C */
void	ft_error2(int code, char *err);
int		open_file(char *argv, int file_in_out);
void	command(char *argv, char *envp[]);
void	child_process(int *fd, char *argv[], char *envp[]);
void	parent_process(int *fd, char *argv[], char *envp[]);

/* CH_PATH.C */
int		search_path(char **envp);
char	*check_path(char *cmd, char **envp);

#endif