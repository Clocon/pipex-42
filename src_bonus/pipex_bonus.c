/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lumorale <lumorale@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 12:06:41 by lumorale          #+#    #+#             */
/*   Updated: 2023/04/19 11:35:09 by lumorale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex_bonus.h"

static char	*find_path(char **envp)
{
	while (ft_strncmp("PATH", *envp, 4))
		envp++;
	return (*envp + 5);
}

static void	pipes_generator(t_pipex *pipex)
{
	int	i;

	pipex->tube = (int **)malloc(sizeof(int *) * pipex->n_pipes);
	if (!pipex->tube)
		err_msg_exit(PIPE_ERROR);
	i = -1;
	while (++i < pipex->n_pipes)
	{
		pipex->tube[i] = (int *)malloc(sizeof(int) * 2);
		if (!pipex->tube[i])
			err_msg_exit(PIPE_ERROR);
	}
	i = -1;
	while (++i < pipex->n_pipes)
	{
		if (pipe(pipex->tube[i]) < 0)
			err_msg_exit(PIPE_ERROR);
	}
}

static void	child_generator(t_pipex *pipex, char **str, char **envp, int n_pipe)
{
	int		i;

	pipes_generator(pipex);
	i = -1;
	while (++i < n_pipe)
		child(*pipex, str, envp, i);
	free_arr_int(pipex);
}

void leaks(void)
{
	system("leaks -q pipex_bonus");
}

int	main(int argc, char **str, char **envp)
{
	atexit(leaks);
	t_pipex	pipex;

	if (argc < 5)
		argc_error(ARGC_ERROR);
	pipex.fd_in = open(str[1], O_RDONLY);
	if (pipex.fd_in < 0)
		err_msg(INFILE_ERROR);
	pipex.fd_out = open(str[argc - 1], O_TRUNC | O_CREAT | O_RDWR, 0644);
	if (pipex.fd_out < 0)
		err_msg_exit(OUTFILE_ERROR);
	pipex.n_pipes = argc - 3;
	pipex.paths = ft_split(find_path(envp), ':');
	child_generator(&pipex, str, envp, argc - 3);
	wait(&pipex.towait);
	total_close(&pipex);
	free_matrix(pipex.paths);
	return (0);
}
