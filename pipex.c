/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lumorale <lumorale@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 12:06:41 by lumorale          #+#    #+#             */
/*   Updated: 2023/03/14 17:26:58 by lumorale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static char	*find_path(char **envp)
{
	while (ft_strncmp("PATH", *envp, 4))
		envp++;
	return (*envp + 5);
}

int	main(int argc, char **str, char **envp)
{
	t_pipex	pipex;

	if (argc != 5)
		argc_error(ARGC_ERROR);
	pipex.fd_in = open(str[1], O_RDONLY);
	if (pipex.fd_in < 0)
		err_msg(INFILE_ERROR);
	pipex.fd_out = open(str[4], O_TRUNC | O_CREAT | O_RDWR, 0644);
	if (pipex.fd_out < 0)
		err_msg_exit(OUTFILE_ERROR);
	if (pipe(pipex.tube) < 0)
		err_msg(PIPE_ERROR);
	pipex.paths = ft_split(find_path(envp), ':');
	pipex.pid1 = fork();
	if (pipex.pid1 == 0)
		first_child(pipex, str, envp);
	second_child(pipex, str, envp);
	total_close(&pipex);
	wait(&pipex.towait);
	free_matrix(pipex.paths);
	return (0);
}
