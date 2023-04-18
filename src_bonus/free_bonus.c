/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lumorale <lumorale@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 11:59:42 by lumorale          #+#    #+#             */
/*   Updated: 2023/04/18 19:23:22 by lumorale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex_bonus.h"

void	free_matrix(char **str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		free(str[i]);
		i++;
	}
	free(str);
}

void	free_arr_int(t_pipex *pipex)
{
	int	i;

	i = -1;
	while (++i < pipex->n_pipes)
	{
		free(pipex->tube[i]);
	}
	free(pipex->tube);
}

void	close_pipes(t_pipex *pipex)
{
	int	i;

	i = -1;
	while (++i < (pipex->n_pipes))
	{
		close(pipex->tube[i][0]);
		close(pipex->tube[i][1]);
	}
}

void	total_close(t_pipex *pipex)
{
	close(pipex->fd_in);
	close(pipex->fd_out);
}
