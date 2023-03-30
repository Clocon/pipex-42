/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lumorale <lumorale@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 11:46:02 by lumorale          #+#    #+#             */
/*   Updated: 2023/03/13 12:34:44 by lumorale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

/*to libft functions*/
# include "./libft/libft.h"

/* to write, read, close, access, pipe, dup, dup2, execve, fork */
# include <unistd.h>
# include <sys/types.h>
# include <sys/uio.h>

/* to exit */
# include <stdlib.h>

/* open*/
# include <fcntl.h>

/* waitpid, wait */
# include <sys/wait.h>

/* to perror */
# include <stdio.h>

# define ARGC_ERROR "Invalid number of arguments.\n"
# define CMD1_ERROR "1º Command not found\n"
# define CMD2_ERROR "2º Command not found\n"
# define INFILE_ERROR "Infile error\n"
# define OUTFILE_ERROR "Outfile error\n"
# define PIPE_ERROR "Pipe error\n"

typedef struct s_pipex
{
	pid_t	pid1;
	pid_t	pid2;
	int		fd_in;
	int		fd_out;
	int		tube[2];
	int		towait;
	char	*cmd;
	char	**paths;
	char	**args;
}	t_pipex;

/*error.c functions*/
void	argc_error(char *str);
void	err_msg(char *str);
void	err_msg_exit(char *str);

/*childs.c functions*/
void	first_child(t_pipex pipex, char **str, char **envp);
void	second_child(t_pipex pipex, char **str, char **envp);

/*free.c functions*/
void	free_matrix(char **str);
void	total_close(t_pipex *pipex);

/*split_args.c function*/
char	**split_args(char *s, char c);

#endif