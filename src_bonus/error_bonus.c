/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lumorale <lumorale@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 12:09:30 by lumorale          #+#    #+#             */
/*   Updated: 2023/04/19 11:36:33 by lumorale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex_bonus.h"

void	argc_error(char *str)
{
	printf("%s", str);
	ft_printf("Structure= ./pipex <input.txt> <*numbers_of_cmd> <output.txt>\n");
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
