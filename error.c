/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lumorale <lumorale@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 12:09:30 by lumorale          #+#    #+#             */
/*   Updated: 2023/03/10 18:07:38 by lumorale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	argc_error(char *str)
{
	printf("%s", str);
	ft_printf("Structure = ./pipex <input.txt> <cmd1> <cmd2> <output.txt>\n");
	exit(1);
}

void	err_msg(char *str)
{
	perror (str);
}

void	err_msg_exit(char *str)
{
	perror (str);
	exit(1);
}
