/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lumorale <lumorale@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 11:59:42 by lumorale          #+#    #+#             */
/*   Updated: 2023/03/09 12:22:24 by lumorale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

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

void	total_close(t_pipex *pipex)
{
	close(pipex->fd_in);
	close(pipex->fd_out);
	close(pipex->tube[0]);
	close(pipex->tube[1]);
}
